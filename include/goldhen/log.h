/*
 * log.h - how GoldHEN reports what it is doing.
 *
 * There is no hosted C library here.  The payload reaches the kernel console
 * through the `printf` pointer that map_functions() resolves (declared in
 * kernel.h) and shows user-visible messages through its own notify(), which
 * wraps sceKernelSendNotificationRequest.  The loader, which runs before any of
 * that exists, prints through its import table slot IMP_PRINTF (also kernel.h).
 *
 * So this header declares nothing: it exists to record the convention and the
 * tag every status line carries.
 *
 * Messages the user sees are short and prefixed, e.g.
 *
 *     [GoldHEN] FakePKG hooks installed!
 *     [GoldHEN] SceShellCore patches installed!
 *     [GoldHEN] All done!
 *
 * The format strings live in the payload's .rodata, not here.
 */
#ifndef GOLDHEN_LOG_H
#define GOLDHEN_LOG_H

/* Prefix for every line GoldHEN prints to the kernel console. */
#define GOLDHEN_TAG "[GoldHEN] "

/* The tag as a complete format string, for the common no-argument case. */
#define GOLDHEN_TAG_LINE "[GoldHEN] %s\n"

#endif /* GOLDHEN_LOG_H */
