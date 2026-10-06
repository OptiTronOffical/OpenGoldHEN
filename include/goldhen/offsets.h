/*
 * offsets.h - per-firmware kernel offset tables.
 *
 * GoldHEN supports a fixed set of PS4 firmware revisions.  For each one the
 * payload carries four tables of kernel_base-relative offsets, because the
 * layout of the kernel changes between releases.  The tables themselves are
 * generated data (include/goldhen/tables/); this header declares their shapes
 * and the accessors that copy them out.
 *
 * The firmware code is the value the kernel reports and is written here in
 * hexadecimal, which is how GoldHEN's own dispatchers compare it: 0x1f9 is
 * firmware 5.05, 0x29f is 6.71, and so on.  The table names use the decimal
 * digits of that code (505, 671, ...).
 */
#ifndef GOLDHEN_OFFSETS_H
#define GOLDHEN_OFFSETS_H

#include <goldhen/types.h>

/* Number of entries in each table kind.  Fixed by the consumers:
 * resolve_imports()/map_functions() read exactly 77 kernel offsets, and the
 * GoldHEN hook installer copies its block with a rep movsd of 114 dwords. */
#define KSDK_OFFSET_COUNT 77
#define INSTALLER_OFFSET_COUNT 5
#define GOLDHEN_OFFSET_COUNT 114
#define PROC_OFFSET_COUNT 4

/*
 * Kernel installer patch description.
 *
 * Byte layout is not a plain u32 array: a 16-bit field sits immediately
 * after the first 32-bit one, leaving two bytes of padding.
 *
 *   offset  size  meaning
 *   0x00    4     patch site, relative to the kernel base
 *   0x04    2     length of the patch body
 *   0x06    2     padding
 *   0x08    4     patch operand 0
 *   0x0c    4     patch operand 1
 *   0x10    4     patch operand 2
 */
struct installer_patch {
    uint32_t target;
    uint16_t length;
    uint16_t _pad;
    uint32_t operand0;
    uint32_t operand1;
    uint32_t operand2;
};

/*
 * Process-structure field offsets used by the jailbreak.  Returned by value,
 * which on the SysV ABI means the four words travel in RAX:RDX.
 */
struct proc_offsets {
    uint32_t field[PROC_OFFSET_COUNT];
};

/* ---- accessors -------------------------------------------------------- */
/* Each copies its table into the caller's buffer and returns that buffer,
 * matching the original functions, which received the destination in RDI. */

#define DECLARE_TABLE_ACCESSORS(kind, count)                                   \
    uint32_t *kind##_505(uint32_t out[count]);                                 \
    uint32_t *kind##_671(uint32_t out[count]);                                 \
    uint32_t *kind##_672(uint32_t out[count]);                                 \
    uint32_t *kind##_702(uint32_t out[count]);                                 \
    uint32_t *kind##_750(uint32_t out[count]);                                 \
    uint32_t *kind##_751(uint32_t out[count]);                                 \
    uint32_t *kind##_755(uint32_t out[count]);                                 \
    uint32_t *kind##_800(uint32_t out[count]);                                 \
    uint32_t *kind##_801(uint32_t out[count]);                                 \
    uint32_t *kind##_803(uint32_t out[count]);                                 \
    uint32_t *kind##_850(uint32_t out[count]);                                 \
    uint32_t *kind##_852(uint32_t out[count]);                                 \
    uint32_t *kind##_900(uint32_t out[count]);                                 \
    uint32_t *kind##_903(uint32_t out[count]);                                 \
    uint32_t *kind##_904(uint32_t out[count]);                                 \
    uint32_t *kind##_950(uint32_t out[count]);                                 \
    uint32_t *kind##_951(uint32_t out[count]);                                 \
    uint32_t *kind##_960(uint32_t out[count]);                                 \
    uint32_t *kind##_1000(uint32_t out[count]);                                \
    uint32_t *kind##_1001(uint32_t out[count]);                                \
    uint32_t *kind##_1050(uint32_t out[count]);                                \
    uint32_t *kind##_1070(uint32_t out[count]);                                \
    uint32_t *kind##_1071(uint32_t out[count]);                                \
    uint32_t *kind##_1100(uint32_t out[count]);                                \
    uint32_t *kind##_1102(uint32_t out[count]);                                \
    uint32_t *kind##_1150(uint32_t out[count]);                                \
    uint32_t *kind##_1152(uint32_t out[count]);                                \
    uint32_t *kind##_1200(uint32_t out[count]);                                \
    uint32_t *kind##_1202(uint32_t out[count]);                                \
    uint32_t *kind##_1250(uint32_t out[count]);                                \
    uint32_t *kind##_1252(uint32_t out[count]);                                \
    uint32_t *kind##_1300(uint32_t out[count])

DECLARE_TABLE_ACCESSORS(ksdk_offsets, KSDK_OFFSET_COUNT);
DECLARE_TABLE_ACCESSORS(installer_offsets, INSTALLER_OFFSET_COUNT);
DECLARE_TABLE_ACCESSORS(goldhen_offsets, GOLDHEN_OFFSET_COUNT);

#define DECLARE_PROC_OFFSETS()                                                 \
    struct proc_offsets proc_offsets_505(void);                                \
    struct proc_offsets proc_offsets_671(void);                                \
    struct proc_offsets proc_offsets_672(void);                                \
    struct proc_offsets proc_offsets_702(void);                                \
    struct proc_offsets proc_offsets_750(void);                                \
    struct proc_offsets proc_offsets_751(void);                                \
    struct proc_offsets proc_offsets_755(void);                                \
    struct proc_offsets proc_offsets_800(void);                                \
    struct proc_offsets proc_offsets_801(void);                                \
    struct proc_offsets proc_offsets_803(void);                                \
    struct proc_offsets proc_offsets_850(void);                                \
    struct proc_offsets proc_offsets_852(void);                                \
    struct proc_offsets proc_offsets_900(void);                                \
    struct proc_offsets proc_offsets_903(void);                                \
    struct proc_offsets proc_offsets_904(void);                                \
    struct proc_offsets proc_offsets_950(void);                                \
    struct proc_offsets proc_offsets_951(void);                                \
    struct proc_offsets proc_offsets_960(void);                                \
    struct proc_offsets proc_offsets_1000(void);                               \
    struct proc_offsets proc_offsets_1001(void);                               \
    struct proc_offsets proc_offsets_1050(void);                               \
    struct proc_offsets proc_offsets_1071(void);                               \
    struct proc_offsets proc_offsets_1100(void);                               \
    struct proc_offsets proc_offsets_1102(void);                               \
    struct proc_offsets proc_offsets_1152(void);                               \
    struct proc_offsets proc_offsets_1202(void);                               \
    struct proc_offsets proc_offsets_1252(void);                               \
    struct proc_offsets proc_offsets_1300(void)

DECLARE_PROC_OFFSETS();

/* ---- dispatchers ------------------------------------------------------
 * Choose the table for the running firmware.  `firmware` is the code returned
 * by get_firmware(); the destination buffer is filled in place.
 */
uint32_t *get_ksdk_offsets(uint32_t out[KSDK_OFFSET_COUNT], uint16_t firmware);
uint32_t *get_installer_offsets(uint32_t out[INSTALLER_OFFSET_COUNT],
                                uint16_t firmware);
uint32_t *get_goldhen_offsets(uint32_t out[GOLDHEN_OFFSET_COUNT],
                              uint16_t firmware);
struct proc_offsets get_proc_offsets(uint16_t firmware);

#endif /* GOLDHEN_OFFSETS_H */
