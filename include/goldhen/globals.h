/*
 * globals.h - the payload's mutable globals.
 *
 * Both halves keep the running firmware code in a global.  The loader's copy
 * lives at a fixed address in its own image and starts out with a placeholder,
 * which loader_init() overwrites.  The payload's copy lives in its .bss and is
 * set by init_ksdk().
 */
#ifndef GOLDHEN_GLOBALS_H
#define GOLDHEN_GLOBALS_H

#include <goldhen/types.h>

/*
 * Loader side.  The loader image is based at 0x926200000 and its trailer
 * holds two words that start out pre-filled with ASCII characters:
 *
 *   0x9262473D0  firmware code; loader_init() sets it to 0, then get_firmware()
 *                writes the running firmware code into it.
 *   0x9262473D8  scratch word.  get_kbase() writes the kernel base here, then
 *                resolve_imports() adds the last import offset to it, so it ends
 *                up holding the SBL_KEYMGR_BUF_GVA address.  See kernel.h.
 */
#define g_firmware_version (*(volatile uint16_t *)0x9262473d0u)
#define g_kernel_base (*(volatile uint64_t *)0x9262473d8u)

/*
 * Payload side: the same firmware code, written by init_ksdk() and read by every
 * per-firmware dispatcher in offsets.c.
 */
extern uint16_t firmware_version;

#endif /* GOLDHEN_GLOBALS_H */
