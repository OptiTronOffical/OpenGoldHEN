/*
 * loader.h - the loader's functions and the data it owns.
 *
 * The loader is the small x86-64 image at the start of goldhen.bin
 * (offsets 0x0..0x6480, virtual base 0x926200000).  The exploit copies it into
 * kernel memory and jumps to its base; from there it finds the kernel, resolves
 * its import table, patches the kernel's sysent table, decompresses the embedded
 * kpayload and calls its entry point.  docs/FORMAT.md has the whole chain.
 *
 * Everything here is reached through absolute addresses, because the loader is
 * a flat image linked at a fixed base rather than a relocatable object: its
 * globals live at fixed vaddrs (globals.h), its kernel imports through fixed
 * GOT slots (kernel.h), and its own functions are addressed by their vaddr.
 *
 * The per-firmware tables and their dispatchers live in offsets.h; the inflate
 * family (puff.c) is declared in the sources that own it, except for
 * puff_codes(), which the loader's decompression step calls directly.
 */
#ifndef GOLDHEN_LOADER_H
#define GOLDHEN_LOADER_H

#include <stdbool.h>

#include <goldhen/types.h>
#include <goldhen/elf.h>
#include <goldhen/kernel.h>
#include <goldhen/globals.h>
#include <goldhen/log.h>

/* ---- the embedded kpayload blob ---------------------------------------
 * The compressed kpayload follows the loader in goldhen.bin: the zlib stream
 * occupies file offsets 0x6480..0x46CEC and its length is the u32 just past the
 * end of the stream, at 0x46CEC.  Both are read from absolute loader addresses
 * and both are read-only data.
 */
#define kpayload_zlib_size (*(const volatile u32 *)0x926246cecu)
#define kpayload_zlib ((const u8 *)0x926206480u)

/* ---- callable forms of the GOT slots (kernel.h) ------------------------
 * kernel.h declares each import slot as a `void *` lvalue, because the loader
 * does not know the kernel's types.  These typedefs give the call sites a real
 * function type; cast the slot with one of them to call through it.
 */
typedef int (*kprintf_fn)(const char *fmt, ...);
typedef void *(*kmemcpy_fn)(void *dest, const void *src, size_t n);
typedef void *(*kmemset_fn)(void *dest, int c, size_t n);
typedef int (*kmemcmp_fn)(const void *a, const void *b, size_t n);
typedef void *(*kmalloc_fn)(size_t size, void *type, int flags);
typedef kaddr_t (*kmem_alloc_fn)(void *map, size_t size);
typedef int (*ksysent_fn)(void *td, void *args);

/* The loader prints through its printf import, so every call site is
 *
 *     ((kprintf_fn)IMP_PRINTF)("...");
 *
 * log.h's loader_printf() is not that function - the loader has no such symbol,
 * only the import slot. */

/* ---- entry -------------------------------------------------------------
 * entry_stub is the address the exploit jumps to; it is a five-byte jump to
 * payload_entry_check.
 */
void entry_stub(void);

/* The loader's real entry.  Runs goldhen_main() when it was entered from kernel
 * code, and otherwise re-enters itself through the syscall gate. */
void payload_entry_check(void);

/* Drive the whole install: loader_init(), then either re-arm the already
 * installed GoldHEN or install it.  Always returns 0. */
int goldhen_main(void);

/* Print the banner and install the kpayload.  True when the install failed. */
bool install_goldhen(void);

/* Decompress the embedded kpayload, decode its ELF and call its entry point.
 * True when the kpayload could not be started. */
bool load_and_start_kpayload(void);

/* ---- kpayload loading --------------------------------------------------
 * All four take the decompressed kpayload ELF and the address it was copied to.
 * They return 0 on success; elf_load and its helpers return a small stage code
 * on failure (see the individual files).
 */
int elf_check_and_measure(Elf64_Ehdr *ehdr, u64 *out_size);
int elf_map_segments(Elf64_Ehdr *ehdr, u8 *load_base);
int elf_apply_relocations(Elf64_Ehdr *ehdr, u8 *load_base);
int elf_load(Elf64_Ehdr *elf, u64 elf_size, kaddr_t load_base, u64 alloc_size,
             kaddr_t *entry_out);

/* The inflate entry point (puff.c).  Produces `out` from `in` and returns the
 * number of bytes produced; the rest of the family is declared where it is
 * defined. */
int puff_codes(u8 *out, const u8 *in, u32 in_size);

/* Check the Adler-32 trailer of the kpayload stream against the decompressed
 * bytes, and report how many bytes puff_codes() produced (-1 on mismatch). */
int verify_adler32(u8 *out, const u8 *zlib_stream, u32 zlib_size);

/* kmem_alloc() with page rounding, through the loader's import table. */
kaddr_t call_import_4600(u64 size);

/* malloc() with the kernel's M_TEMP pool, through the loader's import table. */
void *call_import_4630(u32 size);

/* ---- kernel setup ------------------------------------------------------ */
/* Zero the firmware global and resolve every kernel import for it.  Returns 1
 * when the running firmware is not one GoldHEN knows. */
int loader_init(u64 param_1);

/* Read the running firmware code out of the kernel's release string.  Returns 0
 * when the string was not found. */
u32 get_firmware_version(u64 param_1, u64 param_2, u64 param_3);

/* Kernel base, from LSTAR. */
kaddr_t get_kbase(void);

/* Fill the import table (the GOT slots in kernel.h) from the ksdk offsets of
 * `firmware`.  Returns 1 when those offsets are all zero, i.e. the firmware is
 * unsupported. */
int resolve_imports(u16 firmware);

/* Turn CR0.WP off, patch the kernel's installer entry to jump to GoldHEN's own
 * installer, and turn CR0.WP back on. */
void patch_kernel_installer(void);

/* Call the kernel function the loader installed at IMP_SYSENTS + 0x2588, with a
 * two-word argument block, and return its result through the current thread's
 * return-value slot. */
int kcall_2588(u64 code, u64 arg);

/* True when the loader's sysent hook is already installed. */
bool goldhen_is_loaded(void);

/* Print the ASCII-art banner and the credit block. */
void print_banner(u64 param_1);

/* ---- primitives -------------------------------------------------------- */
/* True when `p` is a kernel address: its top 17 bits are all set. */
int is_kernel_pointer(kaddr_t p);

/* The syscall instruction, FreeBSD argument order (number in RDI, ...). */
long syscall0(long nr, ...);


/* GOT-backed imports, callable through their typed pointers */
#define imp_memcpy ((void *(*)(void *, const void *, size_t))IMP_MEMCPY)
#define imp_memset ((void *(*)(void *, int, size_t))IMP_MEMSET)
#define imp_memcmp ((int (*)(const void *, const void *, size_t))IMP_MEMCMP)
#define imp_printf ((int (*)(const char *, ...))IMP_PRINTF)

#endif /* GOLDHEN_LOADER_H */
