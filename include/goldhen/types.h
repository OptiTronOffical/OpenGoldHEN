/*
 * types.h - freestanding scalar types for the GoldHEN payload.
 *
 * The payload is compiled freestanding for a PS4 kernel: no libc headers, no
 * runtime.  Only fixed-width scalars and a handful of helper macros are
 * available, so this header is the whole type vocabulary of the codebase.

 */
#ifndef GOLDHEN_TYPES_H
#define GOLDHEN_TYPES_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

/* A kernel virtual address.  The PS4 kernel lives in the high canonical half;
 * is_kernel_pointer() tests exactly that property. */
typedef uintptr_t kaddr_t;

#ifndef NULL
#define NULL ((void *)0)
#endif

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

/* Round `v` up to the next multiple of `a`, which must be a power of two. */
#define ALIGN_UP(v, a) (((v) + ((a) - 1)) & ~((u64)(a) - 1))

/* The payload's own memcpy; see src/kpayload/00106014__memcpy.c. */
void *_memcpy(void *dest, const void *src, size_t n);

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;

#include <goldhen/data.h>


/* leading-zero count, as the decompiler's LZCOUNT intrinsic */
static inline u32 __lzcount(u64 x)
{
    return x ? (u32)__builtin_clzll(x) : 64;
}

/* ELF64 structures, as used by the loader's minimal reader */
typedef struct { u8 e_ident[16]; u16 e_type; u16 e_machine; u32 e_version; u64 e_entry;
                 u64 e_phoff; u64 e_shoff; u32 e_flags; u16 e_ehsize; u16 e_phentsize;
                 u16 e_phnum; u16 e_shentsize; u16 e_shnum; u16 e_shstrndx; } Elf64_Ehdr;
typedef struct { u32 p_type; u32 p_flags; u64 p_offset; u64 p_vaddr; u64 p_paddr;
                 u64 p_filesz; u64 p_memsz; u64 p_align; } Elf64_Phdr;
typedef struct { u32 sh_name; u32 sh_type; u64 sh_flags; u64 sh_addr; u64 sh_offset;
                 u64 sh_size; u32 sh_link; u32 sh_info; u64 sh_addralign;
                 u64 sh_entsize; } Elf64_Shdr;
typedef struct { u64 r_offset; u64 r_info; s64 r_addend; } Elf64_Rela;

#ifndef true
#define true 1
#define false 0
#endif

#include <goldhen/kernel.h>

/* GOT-backed imports, callable through their typed pointers */
#define imp_memcpy ((void *(*)(void *, const void *, size_t))IMP_MEMCPY)
#define imp_memset ((void *(*)(void *, int, size_t))IMP_MEMSET)
#define imp_memcmp ((int (*)(const void *, const void *, size_t))IMP_MEMCMP)
#define imp_printf ((int (*)(const char *, ...))IMP_PRINTF)
#define imp_strlen ((size_t (*)(const char *))IMP_STRLEN)

#endif /* GOLDHEN_TYPES_H */
