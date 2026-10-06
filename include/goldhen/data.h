/*
 * data.h - the payload's named data objects.
 *
 * The payload addresses its data (module blobs, patch bodies, strings,
 * inflate tables, saved sysent slots, settings flags) by absolute address.
 * Each object below is one of those addresses, named: pointer form for
 * objects used by address, lvalue form for objects read or written in place.
 */
#ifndef GOLDHEN_DATA_H
#define GOLDHEN_DATA_H

#include <goldhen/types.h>

#define g_bytes_001879cc ((volatile u8 *)0x1879ccu)
#define g_bytes_001879d0 (*(volatile u64 *)0x1879d0u)
#define g_bytes_00187c4c (*(volatile u64 *)0x187c4cu)
#define g_bytes_00187c50 ((volatile u8 *)0x187c50u)
#define g_bytes_00187c54 (*(volatile u64 *)0x187c54u)
#define g_bytes_00187e68 (*(volatile u64 *)0x187e68u)
#define g_bytes_00187e6c ((volatile u8 *)0x187e6cu)
#define g_bytes_00187e70 (*(volatile u64 *)0x187e70u)
#define g_bytes_00187f9c (*(volatile u64 *)0x187f9cu)
#define g_bytes_00188140 ((volatile u8 *)0x188140u)
#define g_bytes_00188144 (*(volatile u64 *)0x188144u)
#define g_bytes_001881c8 (*(volatile u64 *)0x1881c8u)
#define g_kernel_got_base (*(volatile u64 *)0x926247428u)
#define puff_code_offsets (*(volatile u64 *)0x926246cf8u)
#define puff_dist_base ((volatile u8 *)0x9262471a0u)
#define puff_dist_extra ((volatile u8 *)0x9262471e0u)
#define puff_len_base ((volatile u8 *)0x926247200u)
#define puff_len_extra ((volatile u8 *)0x926247240u)
#define puff_order ((volatile u8 *)0x926247260u)

#endif /* GOLDHEN_DATA_H */
