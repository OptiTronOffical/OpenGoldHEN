/*
 * offsets.c - per-firmware kernel offset tables and their dispatchers (loader side).
 */

#include <goldhen/types.h>

/*
 * get_installer_offsets
 *
 * Dispatch installer offset table per firmware
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
uint32_t * get_installer_offsets(uint32_t out[INSTALLER_OFFSET_COUNT],
                                uint16_t firmware) {
  s64 lVar1;
  u16 reg_si;
  u32 *reg_rdi;
  
  if ((reg_si & 0xfffd) == 0x1f9) {
    installer_offsets_505();
  }
  else if (reg_si == 0x29f) {
    installer_offsets_671();
  }
  else if (reg_si == 0x2a0) {
    installer_offsets_672();
  }
  else if ((u16)(reg_si - 700) < 3) {
    installer_offsets_702();
  }
  else if (reg_si == 0x2ee) {
    installer_offsets_750();
  }
  else if (reg_si == 0x2ef) {
    installer_offsets_751();
  }
  else if (reg_si == 0x2f3) {
    installer_offsets_755();
  }
  else if (reg_si == 800) {
    installer_offsets_800();
  }
  else if (reg_si == 0x321) {
    installer_offsets_801();
  }
  else if (reg_si == 0x323) {
    installer_offsets_803();
  }
  else if (reg_si == 0x352) {
    installer_offsets_850();
  }
  else if (reg_si == 0x354) {
    installer_offsets_852();
  }
  else if (reg_si == 900) {
    installer_offsets_900();
  }
  else if (reg_si == 0x387) {
    installer_offsets_903();
  }
  else if (reg_si == 0x388) {
    installer_offsets_904();
  }
  else if (reg_si == 0x3b6) {
    installer_offsets_950();
  }
  else if (reg_si == 0x3b7) {
    installer_offsets_951();
  }
  else if (reg_si == 0x3c0) {
    installer_offsets_960();
  }
  else if (reg_si == 1000) {
    installer_offsets_1000();
  }
  else if (reg_si == 0x3e9) {
    installer_offsets_1001();
  }
  else if (reg_si == 0x41a) {
    installer_offsets_1050();
  }
  else if ((u16)(reg_si - 0x42e) < 2) {
    installer_offsets_1070();
  }
  else if (reg_si == 0x44c) {
    installer_offsets_1100();
  }
  else if (reg_si == 0x44e) {
    installer_offsets_1102();
  }
  else if ((reg_si - 0x47e & 0xfffd) == 0) {
    installer_offsets_1150();
  }
  else if ((reg_si & 0xfffd) == 0x4b0) {
    installer_offsets_1200();
  }
  else if ((reg_si - 0x4e2 & 0xfffd) == 0) {
    installer_offsets_1250();
  }
  else if (reg_si == 0x514) {
    installer_offsets_1300();
  }
  else {
    for (lVar1 = 5; lVar1 != 0; lVar1 = lVar1 + -1) {
      *reg_rdi = 0;
      reg_rdi = reg_rdi + 1;
    }
  }
  return;
}

/*
 * get_ksdk_offsets
 *
 * Dispatch ksdk offset table per firmware
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
uint32_t * get_ksdk_offsets(uint32_t out[KSDK_OFFSET_COUNT], uint16_t firmware) {
  s64 lVar1;
  u16 reg_si;
  u32 *reg_rdi;
  
  if ((reg_si & 0xfffd) == 0x1f9) {
    ksdk_offsets_505();
  }
  else if (reg_si == 0x29f) {
    ksdk_offsets_671();
  }
  else if (reg_si == 0x2a0) {
    ksdk_offsets_672();
  }
  else if ((u16)(reg_si - 700) < 3) {
    ksdk_offsets_702();
  }
  else if (reg_si == 0x2ee) {
    ksdk_offsets_750();
  }
  else if (reg_si == 0x2ef) {
    ksdk_offsets_751();
  }
  else if (reg_si == 0x2f3) {
    ksdk_offsets_755();
  }
  else if (reg_si == 800) {
    ksdk_offsets_800();
  }
  else if (reg_si == 0x321) {
    ksdk_offsets_801();
  }
  else if (reg_si == 0x323) {
    ksdk_offsets_803();
  }
  else if (reg_si == 0x352) {
    ksdk_offsets_850();
  }
  else if (reg_si == 0x354) {
    ksdk_offsets_852();
  }
  else if (reg_si == 900) {
    ksdk_offsets_900();
  }
  else if (reg_si == 0x387) {
    ksdk_offsets_903();
  }
  else if (reg_si == 0x388) {
    ksdk_offsets_904();
  }
  else if (reg_si == 0x3b6) {
    ksdk_offsets_950();
  }
  else if (reg_si == 0x3b7) {
    ksdk_offsets_951();
  }
  else if (reg_si == 0x3c0) {
    ksdk_offsets_960();
  }
  else if (reg_si == 1000) {
    ksdk_offsets_1000();
  }
  else if (reg_si == 0x3e9) {
    ksdk_offsets_1001();
  }
  else if (reg_si == 0x41a) {
    ksdk_offsets_1050();
  }
  else if ((u16)(reg_si - 0x42e) < 2) {
    ksdk_offsets_1070();
  }
  else if (reg_si == 0x44c) {
    ksdk_offsets_1100();
  }
  else if (reg_si == 0x44e) {
    ksdk_offsets_1102();
  }
  else if ((reg_si - 0x47e & 0xfffd) == 0) {
    ksdk_offsets_1150();
  }
  else if ((reg_si & 0xfffd) == 0x4b0) {
    ksdk_offsets_1200();
  }
  else if ((reg_si - 0x4e2 & 0xfffd) == 0) {
    ksdk_offsets_1250();
  }
  else if (reg_si == 0x514) {
    ksdk_offsets_1300();
  }
  else {
    for (lVar1 = 0x4d; lVar1 != 0; lVar1 = lVar1 + -1) {
      *reg_rdi = 0;
      reg_rdi = reg_rdi + 1;
    }
  }
  return;
}

/*
 * installer_offsets_1000
 *
 * Write installer kernel-offset table for firmware 1000
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1000(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0xc51d7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x33b1140033b10c;
  reg_rdi[4] = 0x472d2d;
  return;
}

/*
 * installer_offsets_1001
 *
 * Write installer kernel-offset table for firmware 1001
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1001(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0xc51d7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x33b1140033b10c;
  reg_rdi[4] = 0x472d2d;
  return;
}

/*
 * installer_offsets_1050
 *
 * Write installer kernel-offset table for firmware 1050
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1050(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x450f67;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x428a3400428a2c;
  reg_rdi[4] = 0xd737d;
  return;
}

/*
 * installer_offsets_1070
 *
 * Write installer kernel-offset table for firmware 1070
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1070(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x450f67;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x428a3400428a2c;
  reg_rdi[4] = 0xd737d;
  return;
}

/*
 * installer_offsets_1100
 *
 * Write installer kernel-offset table for firmware 1100
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1100(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x2fccb7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x245ee400245edc;
  reg_rdi[4] = 0x2dddfd;
  return;
}

/*
 * installer_offsets_1102
 *
 * Write installer kernel-offset table for firmware 1102
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1102(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x2fccd7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x245f0400245efc;
  reg_rdi[4] = 0x2dde1d;
  return;
}

/*
 * installer_offsets_1150
 *
 * Write installer kernel-offset table for firmware 1150
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1150(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x2e0287;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x4658740046586c;
  reg_rdi[4] = 0x2bd3ad;
  return;
}

/*
 * installer_offsets_1200
 *
 * Write installer kernel-offset table for firmware 1200
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1200(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x2e04c7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x465ab400465aac;
  reg_rdi[4] = 0x2bd48d;
  return;
}

/*
 * installer_offsets_1250
 *
 * Write installer kernel-offset table for firmware 1250
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1250(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x2e0507;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x465af400465aec;
  reg_rdi[4] = 0x2bd4cd;
  return;
}

/*
 * installer_offsets_1300
 *
 * Write installer kernel-offset table for firmware 1300
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_1300(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x2e0527;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x465b1400465b0c;
  reg_rdi[4] = 0x2bd4ed;
  return;
}

/*
 * installer_offsets_505
 *
 * Write installer kernel-offset table for firmware 505
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_505(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x43612a;
  *(u16 *)(reg_rdi + 1) = 0x38eb;
  *(u64 *)(reg_rdi + 2) = 0xfcd56000fcd48;
  reg_rdi[4] = 0x1ea53d;
  return;
}

/*
 * installer_offsets_671
 *
 * Write installer kernel-offset table for firmware 671
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_671(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x123367;
  *(u16 *)(reg_rdi + 1) = 0x38eb;
  *(u64 *)(reg_rdi + 2) = 0x250803002507f5;
  reg_rdi[4] = 0x3c15bd;
  return;
}

/*
 * installer_offsets_672
 *
 * Write installer kernel-offset table for firmware 672
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_672(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x123367;
  *(u16 *)(reg_rdi + 1) = 0x38eb;
  *(u64 *)(reg_rdi + 2) = 0x250803002507f5;
  reg_rdi[4] = 0x3c15bd;
  return;
}

/*
 * installer_offsets_702
 *
 * Write installer kernel-offset table for firmware 702
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_702(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0xbc817;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1171c6001171be;
  reg_rdi[4] = 0x2f04d;
  return;
}

/*
 * installer_offsets_750
 *
 * Write installer kernel-offset table for firmware 750
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_750(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x26f827;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1754b4001754ac;
  reg_rdi[4] = 0x28f80d;
  return;
}

/*
 * installer_offsets_751
 *
 * Write installer kernel-offset table for firmware 751
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_751(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x26f827;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1754b4001754ac;
  reg_rdi[4] = 0x28f80d;
  return;
}

/*
 * installer_offsets_755
 *
 * Write installer kernel-offset table for firmware 755
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_755(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x26f827;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1754b4001754ac;
  reg_rdi[4] = 0x28f80d;
  return;
}

/*
 * installer_offsets_800
 *
 * Write installer kernel-offset table for firmware 800
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_800(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x430bc7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1b4c40001b4bc;
  reg_rdi[4] = 0x25e1cd;
  return;
}

/*
 * installer_offsets_801
 *
 * Write installer kernel-offset table for firmware 801
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_801(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x430bc7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1b4c40001b4bc;
  reg_rdi[4] = 0x25e1cd;
  return;
}

/*
 * installer_offsets_803
 *
 * Write installer kernel-offset table for firmware 803
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_803(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x430bc7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x1b4c40001b4bc;
  reg_rdi[4] = 0x25e1cd;
  return;
}

/*
 * installer_offsets_850
 *
 * Write installer kernel-offset table for firmware 850
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_850(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x15d657;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x219a7400219a6c;
  reg_rdi[4] = 0x3a40fd;
  return;
}

/*
 * installer_offsets_852
 *
 * Write installer kernel-offset table for firmware 852
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_852(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x15d657;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x219a7400219a6c;
  reg_rdi[4] = 0x3a40fd;
  return;
}

/*
 * installer_offsets_900
 *
 * Write installer kernel-offset table for firmware 900
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_900(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0xb7b17;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x37bf440037bf3c;
  reg_rdi[4] = 0x2714bd;
  return;
}

/*
 * installer_offsets_903
 *
 * Write installer kernel-offset table for firmware 903
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_903(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0xb7ac7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x37a1440037a13c;
  reg_rdi[4] = 0x27113d;
  return;
}

/*
 * installer_offsets_904
 *
 * Write installer kernel-offset table for firmware 904
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_904(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0xb7ac7;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x37a1440037a13c;
  reg_rdi[4] = 0x27113d;
  return;
}

/*
 * installer_offsets_950
 *
 * Write installer kernel-offset table for firmware 950
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_950(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x205557;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x188aa400188a9c;
  reg_rdi[4] = 0x201ccd;
  return;
}

/*
 * installer_offsets_951
 *
 * Write installer kernel-offset table for firmware 951
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_951(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x205557;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x188aa400188a9c;
  reg_rdi[4] = 0x201ccd;
  return;
}

/*
 * installer_offsets_960
 *
 * Write installer kernel-offset table for firmware 960
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void installer_offsets_960(void)

{
  u32 *reg_rdi;
  
  *reg_rdi = 0x205557;
  *(u16 *)(reg_rdi + 1) = 0x3beb;
  *(u64 *)(reg_rdi + 2) = 0x188aa400188a9c;
  reg_rdi[4] = 0x201ccd;
  return;
}

/*
 * ksdk_offsets_1000
 *
 * Write ksdk kernel-offset table for firmware 1000
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1000(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0xc50f0000001c0;
  reg_rdi[1] = 0x109d2000109a60;
  reg_rdi[2] = 0x472d2000109c20;
  reg_rdi[3] = 0x1099400003e6f0;
  reg_rdi[4] = 0x2e03400033b040;
  reg_rdi[5] = 0x182f000286350;
  reg_rdi[6] = 0xa9c40000a9a80;
  reg_rdi[7] = 0x38d07000480ce0;
  reg_rdi[8] = 0x38d0c00038d6b0;
  reg_rdi[9] = 0x391eb00038fb70;
  reg_rdi[10] = 0x38e27000390130;
  reg_rdi[0xb] = 0x38cf900038cf20;
  reg_rdi[0xc] = 0x26c7d00044dc40;
  reg_rdi[0xd] = 0x2269a00026c890;
  reg_rdi[0xe] = 0x4733c0003f7490;
  reg_rdi[0xf] = 0x1219b000472e20;
  reg_rdi[0x10] = 0xc53f00045f2a0;
  reg_rdi[0x11] = 0xf33d0000c5330;
  reg_rdi[0x12] = 0x62cb000013a3d0;
  reg_rdi[0x13] = 0x3b9e000006ca20;
  reg_rdi[0x14] = 0x621220003ba030;
  reg_rdi[0x15] = 0x620df000621560;
  reg_rdi[0x16] = 0x624ca0006194a0;
  reg_rdi[0x17] = 0x63f51000641e30;
  reg_rdi[0x18] = 0x63d790006415f0;
  reg_rdi[0x19] = 0xa5d100062dbe0;
  reg_rdi[0x1a] = 0x208b0000207d90;
  reg_rdi[0x1b] = 0x2085e0002089f0;
  reg_rdi[0x1c] = 0x22e2cc00040ba10;
  reg_rdi[0x1d] = 0x63653000373b80;
  reg_rdi[0x1e] = 0x1532c0001a78a78;
  reg_rdi[0x1f] = 0x111b8b00227bef8;
  reg_rdi[0x20] = 0x22d9b4001b25bd0;
  reg_rdi[0x21] = 0x266004001102d90;
  reg_rdi[0x22] = 0x22e4aec0155ec48;
  reg_rdi[0x23] = 0x2646258000068b1;
  reg_rdi[0x24] = 0x26583b80267c088;
  reg_rdi[0x25] = 0x265c000026583c8;
  *(u32 *)(reg_rdi + 0x26) = 0x265c808;
  return;
}

/*
 * ksdk_offsets_1001
 *
 * Write ksdk kernel-offset table for firmware 1001
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1001(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0xc50f0000001c0;
  reg_rdi[1] = 0x109d2000109a60;
  reg_rdi[2] = 0x472d2000109c20;
  reg_rdi[3] = 0x1099400003e6f0;
  reg_rdi[4] = 0x2e03400033b040;
  reg_rdi[5] = 0x182f000286350;
  reg_rdi[6] = 0xa9c40000a9a80;
  reg_rdi[7] = 0x38d07000480ce0;
  reg_rdi[8] = 0x38d0c00038d6b0;
  reg_rdi[9] = 0x391eb00038fb70;
  reg_rdi[10] = 0x38e27000390130;
  reg_rdi[0xb] = 0x38cf900038cf20;
  reg_rdi[0xc] = 0x26c7d00044dc40;
  reg_rdi[0xd] = 0x2269a00026c890;
  reg_rdi[0xe] = 0x4733c0003f7490;
  reg_rdi[0xf] = 0x1219b000472e20;
  reg_rdi[0x10] = 0xc53f00045f2a0;
  reg_rdi[0x11] = 0xf33d0000c5330;
  reg_rdi[0x12] = 0x62cb000013a3d0;
  reg_rdi[0x13] = 0x3b9e000006ca20;
  reg_rdi[0x14] = 0x621220003ba030;
  reg_rdi[0x15] = 0x620df000621560;
  reg_rdi[0x16] = 0x624ca0006194a0;
  reg_rdi[0x17] = 0x63f51000641e30;
  reg_rdi[0x18] = 0x63d790006415f0;
  reg_rdi[0x19] = 0xa5d100062dbe0;
  reg_rdi[0x1a] = 0x208b0000207d90;
  reg_rdi[0x1b] = 0x2085e0002089f0;
  reg_rdi[0x1c] = 0x22e2cc00040ba10;
  reg_rdi[0x1d] = 0x63653000373b80;
  reg_rdi[0x1e] = 0x1532c0001a78a78;
  reg_rdi[0x1f] = 0x111b8b00227bef8;
  reg_rdi[0x20] = 0x22d9b4001b25bd0;
  reg_rdi[0x21] = 0x266004001102d90;
  reg_rdi[0x22] = 0x22e4aec0155ec48;
  reg_rdi[0x23] = 0x2646258000068b1;
  reg_rdi[0x24] = 0x26583b80267c088;
  reg_rdi[0x25] = 0x265c000026583c8;
  *(u32 *)(reg_rdi + 0x26) = 0x265c808;
  return;
}

/*
 * ksdk_offsets_1050
 *
 * Write ksdk kernel-offset table for firmware 1050
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1050(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x450e80000001c0;
  reg_rdi[1] = 0x36e3e00036e120;
  reg_rdi[2] = 0xd73700036e2e0;
  reg_rdi[3] = 0x2a0200000d090;
  reg_rdi[4] = 0x160da000428960;
  reg_rdi[5] = 0x3384e0003fd7c0;
  reg_rdi[6] = 0x97960000977a0;
  reg_rdi[7] = 0x4762d00045d6d0;
  reg_rdi[8] = 0x47632000476910;
  reg_rdi[9] = 0x47b11000478dd0;
  reg_rdi[10] = 0x4774d000479390;
  reg_rdi[0xb] = 0x4761f000476180;
  reg_rdi[0xc] = 0x300a80004244a0;
  reg_rdi[0xd] = 0xed02000300b40;
  reg_rdi[0xe] = 0xd7a10002fdb20;
  reg_rdi[0xf] = 0x1ddda0000d7470;
  reg_rdi[0x10] = 0x45118000465e10;
  reg_rdi[0x11] = 0x1d4950004510c0;
  reg_rdi[0x12] = 0x622f5000441bb0;
  reg_rdi[0x13] = 0x33ee6000350360;
  reg_rdi[0x14] = 0x6256700033f090;
  reg_rdi[0x15] = 0x625240006259b0;
  reg_rdi[0x16] = 0x6229100061b3c0;
  reg_rdi[0x17] = 0x63dc3000644430;
  reg_rdi[0x18] = 0x63beb000643bf0;
  reg_rdi[0x19] = 0x1f452000630550;
  reg_rdi[0x1a] = 0x3ac200003ab490;
  reg_rdi[0x1b] = 0x3abce0003ac0f0;
  reg_rdi[0x1c] = 0x1b240580000aaf0;
  reg_rdi[0x1d] = 0x63765000489a30;
  reg_rdi[0x1e] = 0x1a5fe3001a3bca0;
  reg_rdi[0x1f] = 0x111b910022a9250;
  reg_rdi[0x20] = 0x2269f3001bf81f0;
  reg_rdi[0x21] = 0x26796c0011029c0;
  reg_rdi[0x22] = 0x1c6c85c01541e78;
  reg_rdi[0x23] = 0x2646ca800050ded;
  reg_rdi[0x24] = 0x26608580265c310;
  reg_rdi[0x25] = 0x266400002660868;
  *(u32 *)(reg_rdi + 0x26) = 0x2664808;
  return;
}

/*
 * ksdk_offsets_1070
 *
 * Write ksdk kernel-offset table for firmware 1070
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1070(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x450e80000001c0;
  reg_rdi[1] = 0x36e3e00036e120;
  reg_rdi[2] = 0xd73700036e2e0;
  reg_rdi[3] = 0x2a0200000d090;
  reg_rdi[4] = 0x160da000428960;
  reg_rdi[5] = 0x3384e0003fd7c0;
  reg_rdi[6] = 0x97960000977a0;
  reg_rdi[7] = 0x4762d00045d6d0;
  reg_rdi[8] = 0x47632000476910;
  reg_rdi[9] = 0x47b11000478dd0;
  reg_rdi[10] = 0x4774d000479390;
  reg_rdi[0xb] = 0x4761f000476180;
  reg_rdi[0xc] = 0x300a80004244a0;
  reg_rdi[0xd] = 0xed02000300b40;
  reg_rdi[0xe] = 0xd7a10002fdb20;
  reg_rdi[0xf] = 0x1ddda0000d7470;
  reg_rdi[0x10] = 0x45118000465e10;
  reg_rdi[0x11] = 0x1d4950004510c0;
  reg_rdi[0x12] = 0x622f5000441bb0;
  reg_rdi[0x13] = 0x33ee6000350360;
  reg_rdi[0x14] = 0x6256700033f090;
  reg_rdi[0x15] = 0x625240006259b0;
  reg_rdi[0x16] = 0x6229100061b3c0;
  reg_rdi[0x17] = 0x63dc3000644430;
  reg_rdi[0x18] = 0x63beb000643bf0;
  reg_rdi[0x19] = 0x1f452000630550;
  reg_rdi[0x1a] = 0x3ac200003ab490;
  reg_rdi[0x1b] = 0x3abce0003ac0f0;
  reg_rdi[0x1c] = 0x1b240580000aaf0;
  reg_rdi[0x1d] = 0x63765000489a30;
  reg_rdi[0x1e] = 0x1a5fe3001a3bca0;
  reg_rdi[0x1f] = 0x111b910022a9250;
  reg_rdi[0x20] = 0x2269f3001bf81f0;
  reg_rdi[0x21] = 0x26796c0011029c0;
  reg_rdi[0x22] = 0x1c6c85c01541e78;
  reg_rdi[0x23] = 0x2646ca800050ded;
  reg_rdi[0x24] = 0x26608580265c310;
  reg_rdi[0x25] = 0x266400002660868;
  *(u32 *)(reg_rdi + 0x26) = 0x2664808;
  return;
}

/*
 * ksdk_offsets_1100
 *
 * Write ksdk kernel-offset table for firmware 1100
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1100(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x2fcbd0000001c0;
  reg_rdi[1] = 0x1a44e0001a4220;
  reg_rdi[2] = 0x2dddf0001a43e0;
  reg_rdi[3] = 0x948b0000482d0;
  reg_rdi[4] = 0x21dc4000245e10;
  reg_rdi[5] = 0x295170003663e0;
  reg_rdi[6] = 0xe33c0000e3200;
  reg_rdi[7] = 0x3578b000198060;
  reg_rdi[8] = 0x35790000357ef0;
  reg_rdi[9] = 0x35c7100035a3b0;
  reg_rdi[10] = 0x358ab00035a970;
  reg_rdi[0xb] = 0x3577d000357760;
  reg_rdi[0xc] = 0xc0660003838a0;
  reg_rdi[0xd] = 0x43e440000c0720;
  reg_rdi[0xe] = 0x2de490002c5740;
  reg_rdi[0xf] = 0x313b10002ddef0;
  reg_rdi[0x10] = 0x2fced0002bbfd0;
  reg_rdi[0x11] = 0x279960002fce10;
  reg_rdi[0x12] = 0x61d900002d1ca0;
  reg_rdi[0x13] = 0x2deaa0003c8060;
  reg_rdi[0x14] = 0x625df0002decd0;
  reg_rdi[0x15] = 0x6259c000626130;
  reg_rdi[0x16] = 0x62edc00061af60;
  reg_rdi[0x17] = 0x640740006437d0;
  reg_rdi[0x18] = 0x63e9c000642f90;
  reg_rdi[0x19] = 0x3d0e900062f810;
  reg_rdi[0x1a] = 0xc3eb0000c3140;
  reg_rdi[0x1b] = 0xc3990000c3da0;
  reg_rdi[0x1c] = 0x22b6ad000337cb0;
  reg_rdi[0x1d] = 0x637ff0000790a0;
  reg_rdi[0x1e] = 0x15415b00152cff8;
  reg_rdi[0x1f] = 0x111f830021ff130;
  reg_rdi[0x20] = 0x22d0a9802116640;
  reg_rdi[0x21] = 0x266018001101760;
  reg_rdi[0x22] = 0x21622dc0155cc48;
  reg_rdi[0x23] = 0x264668800071a21;
  reg_rdi[0x24] = 0x26606e80264c080;
  reg_rdi[0x25] = 0x2664000026606f8;
  *(u32 *)(reg_rdi + 0x26) = 0x2664808;
  return;
}

/*
 * ksdk_offsets_1102
 *
 * Write ksdk kernel-offset table for firmware 1102
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1102(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x2fcbf0000001c0;
  reg_rdi[1] = 0x1a4500001a4240;
  reg_rdi[2] = 0x2dde10001a4400;
  reg_rdi[3] = 0x948b0000482d0;
  reg_rdi[4] = 0x21dc6000245e30;
  reg_rdi[5] = 0x29519000366400;
  reg_rdi[6] = 0xe33c0000e3200;
  reg_rdi[7] = 0x3578d000198080;
  reg_rdi[8] = 0x35792000357f10;
  reg_rdi[9] = 0x35c7300035a3d0;
  reg_rdi[10] = 0x358ad00035a990;
  reg_rdi[0xb] = 0x3577f000357780;
  reg_rdi[0xc] = 0xc0660003838c0;
  reg_rdi[0xd] = 0x43e3d0000c0720;
  reg_rdi[0xe] = 0x2de4b0002c5760;
  reg_rdi[0xf] = 0x313b30002ddf10;
  reg_rdi[0x10] = 0x2fcef0002bbff0;
  reg_rdi[0x11] = 0x279980002fce30;
  reg_rdi[0x12] = 0x61d8a0002d1cc0;
  reg_rdi[0x13] = 0x2deac0003c8080;
  reg_rdi[0x14] = 0x625d90002decf0;
  reg_rdi[0x15] = 0x625960006260d0;
  reg_rdi[0x16] = 0x62ed600061af00;
  reg_rdi[0x17] = 0x6406e000643770;
  reg_rdi[0x18] = 0x63e96000642f30;
  reg_rdi[0x19] = 0x3d0eb00062f7b0;
  reg_rdi[0x1a] = 0xc3eb0000c3140;
  reg_rdi[0x1b] = 0xc3990000c3da0;
  reg_rdi[0x1c] = 0x22b6ad000337cd0;
  reg_rdi[0x1d] = 0x637f90000790a0;
  reg_rdi[0x1e] = 0x15415b00152cff8;
  reg_rdi[0x1f] = 0x111f830021ff130;
  reg_rdi[0x20] = 0x22d0a9802116640;
  reg_rdi[0x21] = 0x266018001101760;
  reg_rdi[0x22] = 0x21622dc0155cc48;
  reg_rdi[0x23] = 0x264668800071a21;
  reg_rdi[0x24] = 0x26606e80264c080;
  reg_rdi[0x25] = 0x2664000026606f8;
  *(u32 *)(reg_rdi + 0x26) = 0x2664808;
  return;
}

/*
 * ksdk_offsets_1150
 *
 * Write ksdk kernel-offset table for firmware 1150
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1150(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x2e01a0000001c0;
  reg_rdi[1] = 0x97e000009520;
  reg_rdi[2] = 0x2bd3a0000096e0;
  reg_rdi[3] = 0x394060001fa060;
  reg_rdi[4] = 0x36a8f0004657a0;
  reg_rdi[5] = 0x4c6c000140250;
  reg_rdi[6] = 0xa3a00000a3840;
  reg_rdi[7] = 0x2f6e70003a1b30;
  reg_rdi[8] = 0x2f6ec0002f74b0;
  reg_rdi[9] = 0x2fbcd0002f9970;
  reg_rdi[10] = 0x2f8070002f9f30;
  reg_rdi[0xb] = 0x2f6d90002f6d20;
  reg_rdi[0xc] = 0x1dffe000365d60;
  reg_rdi[0xd] = 0x224030001e00a0;
  reg_rdi[0xe] = 0x2bda400021cb70;
  reg_rdi[0xf] = 0x3c60d0002bd4a0;
  reg_rdi[0x10] = 0x2e04a0003a8010;
  reg_rdi[0x11] = 0xf0060002e03e0;
  reg_rdi[0x12] = 0x6264a0001f8c60;
  reg_rdi[0x13] = 0x340bf00021bb20;
  reg_rdi[0x14] = 0x62adf000340e20;
  reg_rdi[0x15] = 0x62a9c00062b130;
  reg_rdi[0x16] = 0x6245000061bd60;
  reg_rdi[0x17] = 0x63f6800063cd70;
  reg_rdi[0x18] = 0x63d9000063c530;
  reg_rdi[0x19] = 0x3b2b400062f720;
  reg_rdi[0x1a] = 0x1d45e0001d3870;
  reg_rdi[0x1b] = 0x1d40c0001d44d0;
  reg_rdi[0x1c] = 0x22d1f300046f750;
  reg_rdi[0x1d] = 0x638070001d9fe0;
  reg_rdi[0x1e] = 0x1520d0001a47f40;
  reg_rdi[0x1f] = 0x111fa18022d1d50;
  reg_rdi[0x20] = 0x1b2853802136e90;
  reg_rdi[0x21] = 0x26542c001102b70;
  reg_rdi[0x22] = 0x21d278c0153d6c8;
  reg_rdi[0x23] = 0x2647350000704d5;
  reg_rdi[0x24] = 0x26680400265c080;
  reg_rdi[0x25] = 0x266c00002668050;
  *(u32 *)(reg_rdi + 0x26) = 0x266c808;
  return;
}

/*
 * ksdk_offsets_1200
 *
 * Write ksdk kernel-offset table for firmware 1200
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1200(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x2e03e0000001c0;
  reg_rdi[1] = 0x97e000009520;
  reg_rdi[2] = 0x2bd480000096e0;
  reg_rdi[3] = 0x3942a0001fa140;
  reg_rdi[4] = 0x36ab30004659e0;
  reg_rdi[5] = 0x4c6c000140250;
  reg_rdi[6] = 0xa3a00000a3840;
  reg_rdi[7] = 0x2f70b0003a1d70;
  reg_rdi[8] = 0x2f7100002f76f0;
  reg_rdi[9] = 0x2fbf10002f9bb0;
  reg_rdi[10] = 0x2f82b0002fa170;
  reg_rdi[0xb] = 0x2f6fd0002f6f60;
  reg_rdi[0xc] = 0x1dffe000365fa0;
  reg_rdi[0xd] = 0x224110001e00a0;
  reg_rdi[0xe] = 0x2bdb200021cc50;
  reg_rdi[0xf] = 0x3c6310002bd580;
  reg_rdi[0x10] = 0x2e06e0003a8250;
  reg_rdi[0x11] = 0xf0060002e0620;
  reg_rdi[0x12] = 0x6266e0001f8d40;
  reg_rdi[0x13] = 0x340e300021bc00;
  reg_rdi[0x14] = 0x62b03000341060;
  reg_rdi[0x15] = 0x62ac000062b370;
  reg_rdi[0x16] = 0x6247400061bfa0;
  reg_rdi[0x17] = 0x63f8c00063cfb0;
  reg_rdi[0x18] = 0x63db400063c770;
  reg_rdi[0x19] = 0x3b2d800062f960;
  reg_rdi[0x1a] = 0x1d45e0001d3870;
  reg_rdi[0x1b] = 0x1d40c0001d44d0;
  reg_rdi[0x1c] = 0x22d1f300046f990;
  reg_rdi[0x1d] = 0x6382b0001d9fe0;
  reg_rdi[0x1e] = 0x1520d0001a47f40;
  reg_rdi[0x1f] = 0x111fa18022d1d50;
  reg_rdi[0x20] = 0x1b2853802136e90;
  reg_rdi[0x21] = 0x26542c001102b70;
  reg_rdi[0x22] = 0x21d278c0153d6c8;
  reg_rdi[0x23] = 0x264735000047b31;
  reg_rdi[0x24] = 0x26680400265c080;
  reg_rdi[0x25] = 0x266c00002668050;
  *(u32 *)(reg_rdi + 0x26) = 0x266c808;
  return;
}

/*
 * ksdk_offsets_1250
 *
 * Write ksdk kernel-offset table for firmware 1250
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1250(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x2e0420000001c0;
  reg_rdi[1] = 0x97e000009520;
  reg_rdi[2] = 0x2bd4c0000096e0;
  reg_rdi[3] = 0x3942e0001fa180;
  reg_rdi[4] = 0x36ab7000465a20;
  reg_rdi[5] = 0x4c6c000140290;
  reg_rdi[6] = 0xa3a00000a3840;
  reg_rdi[7] = 0x2f70f0003a1db0;
  reg_rdi[8] = 0x2f7140002f7730;
  reg_rdi[9] = 0x2fbf50002f9bf0;
  reg_rdi[10] = 0x2f82f0002fa1b0;
  reg_rdi[0xb] = 0x2f7010002f6fa0;
  reg_rdi[0xc] = 0x1e002000365fe0;
  reg_rdi[0xd] = 0x224150001e00e0;
  reg_rdi[0xe] = 0x2bdb600021cc90;
  reg_rdi[0xf] = 0x3c6350002bd5c0;
  reg_rdi[0x10] = 0x2e0720003a8290;
  reg_rdi[0x11] = 0xf0060002e0660;
  reg_rdi[0x12] = 0x626720001f8d80;
  reg_rdi[0x13] = 0x340e700021bc40;
  reg_rdi[0x14] = 0x62b070003410a0;
  reg_rdi[0x15] = 0x62ac400062b3b0;
  reg_rdi[0x16] = 0x6247800061bfe0;
  reg_rdi[0x17] = 0x63f9600063d050;
  reg_rdi[0x18] = 0x63dbe00063c810;
  reg_rdi[0x19] = 0x3b2dc00062f9a0;
  reg_rdi[0x1a] = 0x1d4620001d38b0;
  reg_rdi[0x1b] = 0x1d4100001d4510;
  reg_rdi[0x1c] = 0x22d1f300046f9d0;
  reg_rdi[0x1d] = 0x6382f0001da020;
  reg_rdi[0x1e] = 0x1520d0001a47f40;
  reg_rdi[0x1f] = 0x111fa18022d1d50;
  reg_rdi[0x20] = 0x1b2853802136e90;
  reg_rdi[0x21] = 0x26542c001102b70;
  reg_rdi[0x22] = 0x21d278c0153d6c8;
  reg_rdi[0x23] = 0x264735000047b31;
  reg_rdi[0x24] = 0x26680400265c080;
  reg_rdi[0x25] = 0x266c00002668050;
  *(u32 *)(reg_rdi + 0x26) = 0x266c808;
  return;
}

/*
 * ksdk_offsets_1300
 *
 * Write ksdk kernel-offset table for firmware 1300
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_1300(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x2e0440000001c0;
  reg_rdi[1] = 0x97e000009520;
  reg_rdi[2] = 0x2bd4e0000096e0;
  reg_rdi[3] = 0x394300001fa1a0;
  reg_rdi[4] = 0x36ab9000465a40;
  reg_rdi[5] = 0x4c6c000140290;
  reg_rdi[6] = 0xa3a00000a3840;
  reg_rdi[7] = 0x2f7110003a1dd0;
  reg_rdi[8] = 0x2f7160002f7750;
  reg_rdi[9] = 0x2fbf70002f9c10;
  reg_rdi[10] = 0x2f8310002fa1d0;
  reg_rdi[0xb] = 0x2f7030002f6fc0;
  reg_rdi[0xc] = 0x1e004000366000;
  reg_rdi[0xd] = 0x224170001e0100;
  reg_rdi[0xe] = 0x2bdb800021ccb0;
  reg_rdi[0xf] = 0x3c6370002bd5e0;
  reg_rdi[0x10] = 0x2e0740003a82b0;
  reg_rdi[0x11] = 0xf0060002e0680;
  reg_rdi[0x12] = 0x626770001f8da0;
  reg_rdi[0x13] = 0x340e900021bc60;
  reg_rdi[0x14] = 0x62b0c0003410c0;
  reg_rdi[0x15] = 0x62ac900062b400;
  reg_rdi[0x16] = 0x6247d00061c030;
  reg_rdi[0x17] = 0x63f9b00063d0a0;
  reg_rdi[0x18] = 0x63dc300063c860;
  reg_rdi[0x19] = 0x3b2de00062f9f0;
  reg_rdi[0x1a] = 0x1d4640001d38d0;
  reg_rdi[0x1b] = 0x1d4120001d4530;
  reg_rdi[0x1c] = 0x22d1f300046f9f0;
  reg_rdi[0x1d] = 0x638340001da040;
  reg_rdi[0x1e] = 0x1520d0001a47f40;
  reg_rdi[0x1f] = 0x111fa18022d1d50;
  reg_rdi[0x20] = 0x1b2853802136e90;
  reg_rdi[0x21] = 0x26542c001102b70;
  reg_rdi[0x22] = 0x21d278c0153d6c8;
  reg_rdi[0x23] = 0x2647350000361cd;
  reg_rdi[0x24] = 0x26680400265c080;
  reg_rdi[0x25] = 0x266c00002668050;
  *(u32 *)(reg_rdi + 0x26) = 0x266c808;
  return;
}

/*
 * ksdk_offsets_505
 *
 * Write ksdk kernel-offset table for firmware 505
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_505(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x436040000001c0;
  reg_rdi[1] = 0x10e5900010e250;
  reg_rdi[2] = 0x1ea5300010e460;
  reg_rdi[3] = 0x50ac0003205c0;
  reg_rdi[4] = 0x3b71a0000fcc80;
  reg_rdi[5] = 0x1be1f0003fb920;
  reg_rdi[6] = 0xf5fd0000f5e10;
  reg_rdi[7] = 0x19f1400010d390;
  reg_rdi[8] = 0x19f1900019f760;
  reg_rdi[9] = 0x1a3a50001a19d0;
  reg_rdi[10] = 0x1a0280001a1f60;
  reg_rdi[0xb] = 0x19f0600019eff0;
  reg_rdi[0xc] = 0x1bff900030d150;
  reg_rdi[0xd] = 0x1ec400001c0090;
  reg_rdi[0xe] = 0x1eab400017dfb0;
  reg_rdi[0xf] = 0x1b8fe0001ea630;
  reg_rdi[0x10] = 0x4363500003c0b0;
  reg_rdi[0x11] = 0x34187000436280;
  reg_rdi[0x12] = 0x61efa0002d55b0;
  reg_rdi[0x13] = 0x3a2bd0001fd7d0;
  reg_rdi[0x14] = 0x62d780003a2e00;
  reg_rdi[0x15] = 0x62e2a00062db10;
  reg_rdi[0x16] = 0x623fc00061d7f0;
  reg_rdi[0x17] = 0x642b400063cd40;
  reg_rdi[0x18] = 0x6418e00063c4f0;
  reg_rdi[0x19] = 0x117e000632540;
  reg_rdi[0x1a] = 0x138b7000137df0;
  reg_rdi[0x1b] = 0x13864000138a60;
  reg_rdi[0x1c] = 0x1ac5158000ecac0;
  reg_rdi[0x1d] = 0x6385f000428e50;
  reg_rdi[0x1e] = 0x14b4110019eceb0;
  reg_rdi[0x1f] = 0x10986a001ac60e0;
  reg_rdi[0x20] = 0x2382ff8022c1a70;
  reg_rdi[0x21] = 0x274c0400107c610;
  reg_rdi[0x22] = 0x2381b8c014c9d48;
  reg_rdi[0x23] = 0x271e20800013460;
  reg_rdi[0x24] = 0x27445480271e5d8;
  reg_rdi[0x25] = 0x274800002744558;
  *(u32 *)(reg_rdi + 0x26) = 0x2748800;
  return;
}

/*
 * ksdk_offsets_671
 *
 * Write ksdk kernel-offset table for firmware 671
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_671(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x123280000001c0;
  reg_rdi[1] = 0xdad00000d7a0;
  reg_rdi[2] = 0x3c15b00000d9a0;
  reg_rdi[3] = 0x207e40001687d0;
  reg_rdi[4] = 0x2433e000250730;
  reg_rdi[5] = 0x4a6fb00022a080;
  reg_rdi[6] = 0x42880000426c0;
  reg_rdi[7] = 0x44cd4000206d50;
  reg_rdi[8] = 0x44cd900044d330;
  reg_rdi[9] = 0x451bf00044f8a0;
  reg_rdi[10] = 0x44def00044fe60;
  reg_rdi[0xb] = 0x44cc600044cbf0;
  reg_rdi[0xc] = 0x36b6e00010ee10;
  reg_rdi[0xd] = 0x402e800036b7d0;
  reg_rdi[0xe] = 0x3c1c50004817f0;
  reg_rdi[0xf] = 0x39b6e0003c16b0;
  reg_rdi[0x10] = 0x12359000329010;
  reg_rdi[0x11] = 0x35410001234c0;
  reg_rdi[0x12] = 0x64152000335b70;
  reg_rdi[0x13] = 0x3c0320001d6050;
  reg_rdi[0x14] = 0x649800003c0550;
  reg_rdi[0x15] = 0x6493d000649b80;
  reg_rdi[0x16] = 0x646e0000637ae0;
  reg_rdi[0x17] = 0x6602600065e010;
  reg_rdi[0x18] = 0x65e4900065d7a0;
  reg_rdi[0x19] = 0x233c700064cc20;
  reg_rdi[0x1a] = 0x8ae200008a0a0;
  reg_rdi[0x1b] = 0x8a8f00008ad10;
  reg_rdi[0x1c] = 0x22c0cd8003f8710;
  reg_rdi[0x1d] = 0x654c4000469b40;
  reg_rdi[0x1e] = 0x1540eb001a6eb18;
  reg_rdi[0x1f] = 0x113e5180220dfc0;
  reg_rdi[0x20] = 0x22bbe8002300320;
  reg_rdi[0x21] = 0x2678cc00111e000;
  reg_rdi[0x22] = 0x220c0cc0156a588;
  reg_rdi[0x23] = 0x266ac680009d11d;
  reg_rdi[0x24] = 0x269457002679040;
  reg_rdi[0x25] = 0x269800002694580;
  *(u32 *)(reg_rdi + 0x26) = 0x2698808;
  return;
}

/*
 * ksdk_offsets_672
 *
 * Write ksdk kernel-offset table for firmware 672
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_672(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x123280000001c0;
  reg_rdi[1] = 0xdad00000d7a0;
  reg_rdi[2] = 0x3c15b00000d9a0;
  reg_rdi[3] = 0x207e40001687d0;
  reg_rdi[4] = 0x2433e000250730;
  reg_rdi[5] = 0x4a6fb00022a080;
  reg_rdi[6] = 0x42880000426c0;
  reg_rdi[7] = 0x44cd4000206d50;
  reg_rdi[8] = 0x44cd900044d330;
  reg_rdi[9] = 0x451bf00044f8a0;
  reg_rdi[10] = 0x44def00044fe60;
  reg_rdi[0xb] = 0x44cc600044cbf0;
  reg_rdi[0xc] = 0x36b6e00010ee10;
  reg_rdi[0xd] = 0x402e800036b7d0;
  reg_rdi[0xe] = 0x3c1c50004817f0;
  reg_rdi[0xf] = 0x39b6e0003c16b0;
  reg_rdi[0x10] = 0x12359000329010;
  reg_rdi[0x11] = 0x35410001234c0;
  reg_rdi[0x12] = 0x64152000335b70;
  reg_rdi[0x13] = 0x3c0320001d6050;
  reg_rdi[0x14] = 0x649800003c0550;
  reg_rdi[0x15] = 0x6493d000649b80;
  reg_rdi[0x16] = 0x646e0000637ae0;
  reg_rdi[0x17] = 0x6602600065e010;
  reg_rdi[0x18] = 0x65e4900065d7a0;
  reg_rdi[0x19] = 0x233c700064cc20;
  reg_rdi[0x1a] = 0x8ae200008a0a0;
  reg_rdi[0x1b] = 0x8a8f00008ad10;
  reg_rdi[0x1c] = 0x22c0cd8003f8710;
  reg_rdi[0x1d] = 0x654c4000469b40;
  reg_rdi[0x1e] = 0x1540eb001a6eb18;
  reg_rdi[0x1f] = 0x113e5180220dfc0;
  reg_rdi[0x20] = 0x22bbe8002300320;
  reg_rdi[0x21] = 0x2678cc00111e000;
  reg_rdi[0x22] = 0x220c0cc0156a588;
  reg_rdi[0x23] = 0x266ac680009d11d;
  reg_rdi[0x24] = 0x269457002679040;
  reg_rdi[0x25] = 0x269800002694580;
  *(u32 *)(reg_rdi + 0x26) = 0x2698808;
  return;
}

/*
 * ksdk_offsets_702
 *
 * Write ksdk kernel-offset table for firmware 702
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_702(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0xbc730000001c0;
  reg_rdi[1] = 0x301b7000301840;
  reg_rdi[2] = 0x2f04000301a40;
  reg_rdi[3] = 0x207500002dfc20;
  reg_rdi[4] = 0x93ff0001170f0;
  reg_rdi[5] = 0x842e00016eee0;
  reg_rdi[6] = 0x1ae1f0001ae030;
  reg_rdi[7] = 0x25fb90002cd780;
  reg_rdi[8] = 0x25fbe000260190;
  reg_rdi[9] = 0x264a5000262700;
  reg_rdi[10] = 0x260d6000262cc0;
  reg_rdi[0xb] = 0x25fab00025fa50;
  reg_rdi[0xc] = 0x2cebf000043e80;
  reg_rdi[0xd] = 0x483810002cece0;
  reg_rdi[0xe] = 0x2f6e000005740;
  reg_rdi[0xf] = 0x3dabe00002f140;
  reg_rdi[0x10] = 0xbca30000f9e40;
  reg_rdi[0x11] = 0x10c900000bc970;
  reg_rdi[0x12] = 0x64700000205f50;
  reg_rdi[0x13] = 0x1da410001dd540;
  reg_rdi[0x14] = 0x648650001da640;
  reg_rdi[0x15] = 0x648220006489d0;
  reg_rdi[0x16] = 0x63e230006376a0;
  reg_rdi[0x17] = 0x65c34000660a90;
  reg_rdi[0x18] = 0x65a56000660210;
  reg_rdi[0x19] = 0x1cb9300064c110;
  reg_rdi[0x1a] = 0xc4ee0000c4170;
  reg_rdi[0x1b] = 0xc49c0000c4dd0;
  reg_rdi[0x1c] = 0x21f07780021d3e0;
  reg_rdi[0x1d] = 0x653ac000118660;
  reg_rdi[0x1e] = 0x1a7ae5001a6eaa0;
  reg_rdi[0x1f] = 0x113e398021c8ee0;
  reg_rdi[0x20] = 0x1b48318022c5750;
  reg_rdi[0x21] = 0x268840001125660;
  reg_rdi[0x22] = 0x21f42ac01555bd8;
  reg_rdi[0x23] = 0x2669e480006b192;
  reg_rdi[0x24] = 0x2698848026945c0;
  reg_rdi[0x25] = 0x269c00002698858;
  *(u32 *)(reg_rdi + 0x26) = 0x269c808;
  return;
}

/*
 * ksdk_offsets_750
 *
 * Write ksdk kernel-offset table for firmware 750
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_750(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x26f740000001c0;
  reg_rdi[1] = 0x1d69a0001d6680;
  reg_rdi[2] = 0x28f800001d6870;
  reg_rdi[3] = 0x31d2500008d6f0;
  reg_rdi[4] = 0x2e8bc0001753e0;
  reg_rdi[5] = 0x47ab6000086e80;
  reg_rdi[6] = 0xd17c0000d1600;
  reg_rdi[7] = 0x2fc430000d28e0;
  reg_rdi[8] = 0x2fc480002fca70;
  reg_rdi[9] = 0x3012f0002fefa0;
  reg_rdi[10] = 0x2fd640002ff560;
  reg_rdi[0xb] = 0x2fc350002fc2e0;
  reg_rdi[0xc] = 0x4a526000361310;
  reg_rdi[0xd] = 0xd3670004a5350;
  reg_rdi[0xe] = 0x28fea0003b0250;
  reg_rdi[0xf] = 0xbf6700028f900;
  reg_rdi[0x10] = 0x26fa400021b800;
  reg_rdi[0x11] = 0x459fb00026f980;
  reg_rdi[0x12] = 0x63f10000274740;
  reg_rdi[0x13] = 0x21f810001517f0;
  reg_rdi[0x14] = 0x643b200021fa40;
  reg_rdi[0x15] = 0x6436f000643e80;
  reg_rdi[0x16] = 0x63e3e000634a40;
  reg_rdi[0x17] = 0x657a300065c8e0;
  reg_rdi[0x18] = 0x655c500065c090;
  reg_rdi[0x19] = 0x364d800064a1a0;
  reg_rdi[0x1a] = 0xe6700000d8f0;
  reg_rdi[0x1b] = 0xe1400000e550;
  reg_rdi[0x1c] = 0x213c7c00012d8d0;
  reg_rdi[0x1d] = 0x651b20002a1530;
  reg_rdi[0x1e] = 0x1556da001564910;
  reg_rdi[0x1f] = 0x113b728021405b8;
  reg_rdi[0x20] = 0x213c82801b463e0;
  reg_rdi[0x21] = 0x268090001122340;
  reg_rdi[0x22] = 0x216212c015a8fc8;
  reg_rdi[0x23] = 0x266264800004fd4;
  reg_rdi[0x24] = 0x26842380267c040;
  reg_rdi[0x25] = 0x268800002684248;
  *(u32 *)(reg_rdi + 0x26) = 0x2688808;
  return;
}

/*
 * ksdk_offsets_751
 *
 * Write ksdk kernel-offset table for firmware 751
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_751(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x26f740000001c0;
  reg_rdi[1] = 0x1d69a0001d6680;
  reg_rdi[2] = 0x28f800001d6870;
  reg_rdi[3] = 0x31d2500008d6f0;
  reg_rdi[4] = 0x2e8bc0001753e0;
  reg_rdi[5] = 0x47ab6000086e80;
  reg_rdi[6] = 0xd17c0000d1600;
  reg_rdi[7] = 0x2fc430000d28e0;
  reg_rdi[8] = 0x2fc480002fca70;
  reg_rdi[9] = 0x3012f0002fefa0;
  reg_rdi[10] = 0x2fd640002ff560;
  reg_rdi[0xb] = 0x2fc350002fc2e0;
  reg_rdi[0xc] = 0x4a526000361310;
  reg_rdi[0xd] = 0xd3670004a5350;
  reg_rdi[0xe] = 0x28fea0003b0250;
  reg_rdi[0xf] = 0xbf6700028f900;
  reg_rdi[0x10] = 0x26fa400021b800;
  reg_rdi[0x11] = 0x459fb00026f980;
  reg_rdi[0x12] = 0x63f10000274740;
  reg_rdi[0x13] = 0x21f810001517f0;
  reg_rdi[0x14] = 0x643b200021fa40;
  reg_rdi[0x15] = 0x6436f000643e80;
  reg_rdi[0x16] = 0x63e3e000634a40;
  reg_rdi[0x17] = 0x657a300065c8e0;
  reg_rdi[0x18] = 0x655c500065c090;
  reg_rdi[0x19] = 0x364d800064a1a0;
  reg_rdi[0x1a] = 0xe6700000d8f0;
  reg_rdi[0x1b] = 0xe1400000e550;
  reg_rdi[0x1c] = 0x213c7c00012d8d0;
  reg_rdi[0x1d] = 0x651b20002a1530;
  reg_rdi[0x1e] = 0x1556da001564910;
  reg_rdi[0x1f] = 0x113b728021405b8;
  reg_rdi[0x20] = 0x213c82801b463e0;
  reg_rdi[0x21] = 0x268090001122340;
  reg_rdi[0x22] = 0x216212c015a8fc8;
  reg_rdi[0x23] = 0x26626480001f842;
  reg_rdi[0x24] = 0x26842380267c040;
  reg_rdi[0x25] = 0x268800002684248;
  *(u32 *)(reg_rdi + 0x26) = 0x2688808;
  return;
}

/*
 * ksdk_offsets_755
 *
 * Write ksdk kernel-offset table for firmware 755
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_755(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x26f740000001c0;
  reg_rdi[1] = 0x1d69a0001d6680;
  reg_rdi[2] = 0x28f800001d6870;
  reg_rdi[3] = 0x31d2500008d6f0;
  reg_rdi[4] = 0x2e8bc0001753e0;
  reg_rdi[5] = 0x47ab6000086e80;
  reg_rdi[6] = 0xd17c0000d1600;
  reg_rdi[7] = 0x2fc430000d28e0;
  reg_rdi[8] = 0x2fc480002fca70;
  reg_rdi[9] = 0x3012f0002fefa0;
  reg_rdi[10] = 0x2fd640002ff560;
  reg_rdi[0xb] = 0x2fc350002fc2e0;
  reg_rdi[0xc] = 0x4a526000361310;
  reg_rdi[0xd] = 0xd3670004a5350;
  reg_rdi[0xe] = 0x28fea0003b0250;
  reg_rdi[0xf] = 0xbf6700028f900;
  reg_rdi[0x10] = 0x26fa400021b800;
  reg_rdi[0x11] = 0x459fb00026f980;
  reg_rdi[0x12] = 0x63f10000274740;
  reg_rdi[0x13] = 0x21f810001517f0;
  reg_rdi[0x14] = 0x643b200021fa40;
  reg_rdi[0x15] = 0x6436f000643e80;
  reg_rdi[0x16] = 0x63e3e000634a40;
  reg_rdi[0x17] = 0x657a300065c8e0;
  reg_rdi[0x18] = 0x655c500065c090;
  reg_rdi[0x19] = 0x364d800064a1a0;
  reg_rdi[0x1a] = 0xe6700000d8f0;
  reg_rdi[0x1b] = 0xe1400000e550;
  reg_rdi[0x1c] = 0x213c7c00012d8d0;
  reg_rdi[0x1d] = 0x651b20002a1530;
  reg_rdi[0x1e] = 0x1556da001564910;
  reg_rdi[0x1f] = 0x113b728021405b8;
  reg_rdi[0x20] = 0x213c82801b463e0;
  reg_rdi[0x21] = 0x268090001122340;
  reg_rdi[0x22] = 0x216212c015a8fc8;
  reg_rdi[0x23] = 0x26626480001f842;
  reg_rdi[0x24] = 0x26842380267c040;
  reg_rdi[0x25] = 0x268800002684248;
  *(u32 *)(reg_rdi + 0x26) = 0x2688808;
  return;
}

/*
 * ksdk_offsets_800
 *
 * Write ksdk kernel-offset table for firmware 800
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_800(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x430ae0000001c0;
  reg_rdi[1] = 0x46fab00046f7f0;
  reg_rdi[2] = 0x25e1c00046f9b0;
  reg_rdi[3] = 0x195a90000f6c60;
  reg_rdi[4] = 0x2f60900001b3f0;
  reg_rdi[5] = 0x26fa50003381d0;
  reg_rdi[6] = 0x43a5000043a340;
  reg_rdi[7] = 0x3e768000155560;
  reg_rdi[8] = 0x3e76d0003e7cc0;
  reg_rdi[9] = 0x3ec4c0003ea180;
  reg_rdi[10] = 0x3e8880003ea740;
  reg_rdi[0xb] = 0x3e75a0003e7530;
  reg_rdi[0xc] = 0x1714b000173770;
  reg_rdi[0xd] = 0x26e27000171570;
  reg_rdi[0xe] = 0x25e86000439c10;
  reg_rdi[0xf] = 0x1846d00025e2c0;
  reg_rdi[0x10] = 0x430de00014f8a0;
  reg_rdi[0x11] = 0x1778c000430d20;
  reg_rdi[0x12] = 0x61cba000126b90;
  reg_rdi[0x13] = 0x1665b00038f5a0;
  reg_rdi[0x14] = 0x61e250001667e0;
  reg_rdi[0x15] = 0x61de200061e590;
  reg_rdi[0x16] = 0x627fb000619be0;
  reg_rdi[0x17] = 0x63eed000642780;
  reg_rdi[0x18] = 0x63d14000641f40;
  reg_rdi[0x19] = 0x1d57c00062f6e0;
  reg_rdi[0x1a] = 0x46ed400046dfd0;
  reg_rdi[0x1b] = 0x46e8200046ec30;
  reg_rdi[0x1c] = 0x2221fd8001c7740;
  reg_rdi[0x1d] = 0x636c2000459880;
  reg_rdi[0x1e] = 0x1a77e100155d190;
  reg_rdi[0x1f] = 0x111a7d001b243e0;
  reg_rdi[0x20] = 0x1b244e001b8c730;
  reg_rdi[0x21] = 0x266c500010fc4d0;
  reg_rdi[0x22] = 0x2229cac01577f28;
  reg_rdi[0x23] = 0x263fae8000e629c;
  reg_rdi[0x24] = 0x264884802644008;
  reg_rdi[0x25] = 0x264c00002648858;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}

/*
 * ksdk_offsets_801
 *
 * Write ksdk kernel-offset table for firmware 801
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_801(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x430ae0000001c0;
  reg_rdi[1] = 0x46fab00046f7f0;
  reg_rdi[2] = 0x25e1c00046f9b0;
  reg_rdi[3] = 0x195a90000f6c60;
  reg_rdi[4] = 0x2f60900001b3f0;
  reg_rdi[5] = 0x26fa50003381d0;
  reg_rdi[6] = 0x43a5000043a340;
  reg_rdi[7] = 0x3e768000155560;
  reg_rdi[8] = 0x3e76d0003e7cc0;
  reg_rdi[9] = 0x3ec4c0003ea180;
  reg_rdi[10] = 0x3e8880003ea740;
  reg_rdi[0xb] = 0x3e75a0003e7530;
  reg_rdi[0xc] = 0x1714b000173770;
  reg_rdi[0xd] = 0x26e27000171570;
  reg_rdi[0xe] = 0x25e86000439c10;
  reg_rdi[0xf] = 0x1846d00025e2c0;
  reg_rdi[0x10] = 0x430de00014f8a0;
  reg_rdi[0x11] = 0x1778c000430d20;
  reg_rdi[0x12] = 0x61cba000126b90;
  reg_rdi[0x13] = 0x1665b00038f5a0;
  reg_rdi[0x14] = 0x61e250001667e0;
  reg_rdi[0x15] = 0x61de200061e590;
  reg_rdi[0x16] = 0x627fb000619be0;
  reg_rdi[0x17] = 0x63eed000642780;
  reg_rdi[0x18] = 0x63d14000641f40;
  reg_rdi[0x19] = 0x1d57c00062f6e0;
  reg_rdi[0x1a] = 0x46ed400046dfd0;
  reg_rdi[0x1b] = 0x46e8200046ec30;
  reg_rdi[0x1c] = 0x2221fd8001c7740;
  reg_rdi[0x1d] = 0x636c2000459880;
  reg_rdi[0x1e] = 0x1a77e100155d190;
  reg_rdi[0x1f] = 0x111a7d001b243e0;
  reg_rdi[0x20] = 0x1b244e001b8c730;
  reg_rdi[0x21] = 0x266c500010fc4d0;
  reg_rdi[0x22] = 0x2229cac01577f28;
  reg_rdi[0x23] = 0x263fae8000e629c;
  reg_rdi[0x24] = 0x264884802644008;
  reg_rdi[0x25] = 0x264c00002648858;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}

/*
 * ksdk_offsets_803
 *
 * Write ksdk kernel-offset table for firmware 803
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_803(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x430ae0000001c0;
  reg_rdi[1] = 0x46fab00046f7f0;
  reg_rdi[2] = 0x25e1c00046f9b0;
  reg_rdi[3] = 0x195a90000f6c60;
  reg_rdi[4] = 0x2f60900001b3f0;
  reg_rdi[5] = 0x26fa50003381d0;
  reg_rdi[6] = 0x43a5000043a340;
  reg_rdi[7] = 0x3e768000155560;
  reg_rdi[8] = 0x3e76d0003e7cc0;
  reg_rdi[9] = 0x3ec4c0003ea180;
  reg_rdi[10] = 0x3e8880003ea740;
  reg_rdi[0xb] = 0x3e75a0003e7530;
  reg_rdi[0xc] = 0x1714b000173770;
  reg_rdi[0xd] = 0x26e27000171570;
  reg_rdi[0xe] = 0x25e86000439c10;
  reg_rdi[0xf] = 0x1846d00025e2c0;
  reg_rdi[0x10] = 0x430de00014f8a0;
  reg_rdi[0x11] = 0x1778c000430d20;
  reg_rdi[0x12] = 0x61cba000126b90;
  reg_rdi[0x13] = 0x1665b00038f5a0;
  reg_rdi[0x14] = 0x61e250001667e0;
  reg_rdi[0x15] = 0x61de200061e590;
  reg_rdi[0x16] = 0x627fb000619be0;
  reg_rdi[0x17] = 0x63eed000642780;
  reg_rdi[0x18] = 0x63d14000641f40;
  reg_rdi[0x19] = 0x1d57c00062f6e0;
  reg_rdi[0x1a] = 0x46ed400046dfd0;
  reg_rdi[0x1b] = 0x46e8200046ec30;
  reg_rdi[0x1c] = 0x2221fd8001c7740;
  reg_rdi[0x1d] = 0x636c2000459880;
  reg_rdi[0x1e] = 0x1a77e100155d190;
  reg_rdi[0x1f] = 0x111a7d001b243e0;
  reg_rdi[0x20] = 0x1b244e001b8c730;
  reg_rdi[0x21] = 0x266c500010fc4d0;
  reg_rdi[0x22] = 0x2229cac01577f28;
  reg_rdi[0x23] = 0x263fae8000e629c;
  reg_rdi[0x24] = 0x264884802644008;
  reg_rdi[0x25] = 0x264c00002648858;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}

/*
 * ksdk_offsets_850
 *
 * Write ksdk kernel-offset table for firmware 850
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_850(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x15d570000001c0;
  reg_rdi[1] = 0xb5d00000b5a40;
  reg_rdi[2] = 0x3a40f0000b5c00;
  reg_rdi[3] = 0x20f280003d6710;
  reg_rdi[4] = 0x270c40002199a0;
  reg_rdi[5] = 0x3924400027c590;
  reg_rdi[6] = 0x2bb0d0002baf10;
  reg_rdi[7] = 0x1486d00040b420;
  reg_rdi[8] = 0x14872000148d10;
  reg_rdi[9] = 0x14d5100014b1d0;
  reg_rdi[10] = 0x1498d00014b790;
  reg_rdi[0xb] = 0x1485f000148580;
  reg_rdi[0xc] = 0x81d2000131b50;
  reg_rdi[0xd] = 0x1ed3d000081de0;
  reg_rdi[0xe] = 0x3a479000456420;
  reg_rdi[0xf] = 0x3cf6d0003a41f0;
  reg_rdi[0x10] = 0x15d87000156e00;
  reg_rdi[0x11] = 0x1bf100015d7b0;
  reg_rdi[0x12] = 0x6295b000073d90;
  reg_rdi[0x13] = 0x2639a000487240;
  reg_rdi[0x14] = 0x620d0000263bd0;
  reg_rdi[0x15] = 0x6208d000621040;
  reg_rdi[0x16] = 0x62ee900061b030;
  reg_rdi[0x17] = 0x640030006421d0;
  reg_rdi[0x18] = 0x63e2b000641990;
  reg_rdi[0x19] = 0x2936900062f8e0;
  reg_rdi[0x1a] = 0x1138000010610;
  reg_rdi[0x1b] = 0x10e6000011270;
  reg_rdi[0x1c] = 0x1bd77b8000db870;
  reg_rdi[0x1d] = 0x6380c0001cea20;
  reg_rdi[0x1e] = 0x1528ff00153ae88;
  reg_rdi[0x1f] = 0x111a8f001c64228;
  reg_rdi[0x20] = 0x1bd72d801c66150;
  reg_rdi[0x21] = 0x264c040010fc5c0;
  reg_rdi[0x22] = 0x1c3d48c01583618;
  reg_rdi[0x23] = 0x2646238000c810d;
  reg_rdi[0x24] = 0x26500780266ca40;
  reg_rdi[0x25] = 0x265400002650088;
  *(u32 *)(reg_rdi + 0x26) = 0x2654808;
  return;
}

/*
 * ksdk_offsets_852
 *
 * Write ksdk kernel-offset table for firmware 852
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_852(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x15d570000001c0;
  reg_rdi[1] = 0xb5d00000b5a40;
  reg_rdi[2] = 0x3a40f0000b5c00;
  reg_rdi[3] = 0x20f280003d6710;
  reg_rdi[4] = 0x270c40002199a0;
  reg_rdi[5] = 0x3924400027c590;
  reg_rdi[6] = 0x2bb0d0002baf10;
  reg_rdi[7] = 0x1486d00040b420;
  reg_rdi[8] = 0x14872000148d10;
  reg_rdi[9] = 0x14d5100014b1d0;
  reg_rdi[10] = 0x1498d00014b790;
  reg_rdi[0xb] = 0x1485f000148580;
  reg_rdi[0xc] = 0x81d2000131b50;
  reg_rdi[0xd] = 0x1ed3d000081de0;
  reg_rdi[0xe] = 0x3a479000456420;
  reg_rdi[0xf] = 0x3cf6d0003a41f0;
  reg_rdi[0x10] = 0x15d87000156e00;
  reg_rdi[0x11] = 0x1bf100015d7b0;
  reg_rdi[0x12] = 0x6295b000073d90;
  reg_rdi[0x13] = 0x2639a000487240;
  reg_rdi[0x14] = 0x620d0000263bd0;
  reg_rdi[0x15] = 0x6208d000621040;
  reg_rdi[0x16] = 0x62ee900061b030;
  reg_rdi[0x17] = 0x640030006421d0;
  reg_rdi[0x18] = 0x63e2b000641990;
  reg_rdi[0x19] = 0x2936900062f8e0;
  reg_rdi[0x1a] = 0x1138000010610;
  reg_rdi[0x1b] = 0x10e6000011270;
  reg_rdi[0x1c] = 0x1bd77b8000db870;
  reg_rdi[0x1d] = 0x6380c0001cea20;
  reg_rdi[0x1e] = 0x1528ff00153ae88;
  reg_rdi[0x1f] = 0x111a8f001c64228;
  reg_rdi[0x20] = 0x1bd72d801c66150;
  reg_rdi[0x21] = 0x264c040010fc5c0;
  reg_rdi[0x22] = 0x1c3d48c01583618;
  reg_rdi[0x23] = 0x2646238000c810d;
  reg_rdi[0x24] = 0x26500780266ca40;
  reg_rdi[0x25] = 0x265400002650088;
  *(u32 *)(reg_rdi + 0x26) = 0x2654808;
  return;
}

/*
 * ksdk_offsets_900
 *
 * Write ksdk kernel-offset table for firmware 900
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_900(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0xb7a30000001c0;
  reg_rdi[1] = 0x301de000301b20;
  reg_rdi[2] = 0x2714b000301ce0;
  reg_rdi[3] = 0x271e20001496c0;
  reg_rdi[4] = 0x30f4500037be70;
  reg_rdi[5] = 0x1ed67000453ea0;
  reg_rdi[6] = 0x43e7d00043e610;
  reg_rdi[7] = 0x7bb800029a380;
  reg_rdi[8] = 0x7bbd00007c1c0;
  reg_rdi[9] = 0x809c00007e680;
  reg_rdi[10] = 0x7cd800007ec40;
  reg_rdi[0xb] = 0x7baa00007ba30;
  reg_rdi[0xc] = 0x2196d00041eb00;
  reg_rdi[0xd] = 0xf837000219790;
  reg_rdi[0xe] = 0x271b5000487ab0;
  reg_rdi[0xf] = 0x124750002715b0;
  reg_rdi[0x10] = 0xb7d300041e380;
  reg_rdi[0x11] = 0x3a1b30000b7c70;
  reg_rdi[0x12] = 0x6252d000445060;
  reg_rdi[0x13] = 0x1ff2d0004628b0;
  reg_rdi[0x14] = 0x61f690001ff500;
  reg_rdi[0x15] = 0x61f2600061f9d0;
  reg_rdi[0x16] = 0x6249700061ced0;
  reg_rdi[0x17] = 0x641c60006441e0;
  reg_rdi[0x18] = 0x63fee0006439a0;
  reg_rdi[0x19] = 0x8bcd000630c40;
  reg_rdi[0x1a] = 0x97750000969e0;
  reg_rdi[0x1b] = 0x9723000097640;
  reg_rdi[0x1c] = 0x21f1128002d6eb0;
  reg_rdi[0x1d] = 0x6391600016cf90;
  reg_rdi[0x1e] = 0x15621e00152bf60;
  reg_rdi[0x1f] = 0x111f87002268d48;
  reg_rdi[0x20] = 0x1b946e0021eff20;
  reg_rdi[0x21] = 0x26541c001100310;
  reg_rdi[0x22] = 0x1b50bec01579df8;
  reg_rdi[0x23] = 0x2646ca80004c7ad;
  reg_rdi[0x24] = 0x26482380264db40;
  reg_rdi[0x25] = 0x264c00002648248;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}

/*
 * ksdk_offsets_903
 *
 * Write ksdk kernel-offset table for firmware 903
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_903(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0xb79e0000001c0;
  reg_rdi[1] = 0x301a70003017b0;
  reg_rdi[2] = 0x27113000301970;
  reg_rdi[3] = 0x271aa000149670;
  reg_rdi[4] = 0x30f0f00037a070;
  reg_rdi[5] = 0x1ed62000451da0;
  reg_rdi[6] = 0x43c6f00043c530;
  reg_rdi[7] = 0x7bb800029a000;
  reg_rdi[8] = 0x7bbd00007c1c0;
  reg_rdi[9] = 0x809c00007e680;
  reg_rdi[10] = 0x7cd800007ec40;
  reg_rdi[0xb] = 0x7baa00007ba30;
  reg_rdi[0xc] = 0x2193a00041ca70;
  reg_rdi[0xd] = 0xf832000219460;
  reg_rdi[0xe] = 0x2717d0004859b0;
  reg_rdi[0xf] = 0x12470000271230;
  reg_rdi[0x10] = 0xb7ce00041c2f0;
  reg_rdi[0x11] = 0x39fd30000b7c20;
  reg_rdi[0x12] = 0x62329000442f80;
  reg_rdi[0x13] = 0x1ff000004607b0;
  reg_rdi[0x14] = 0x61d650001ff230;
  reg_rdi[0x15] = 0x61d2200061d990;
  reg_rdi[0x16] = 0x6229300061ae90;
  reg_rdi[0x17] = 0x63fc20006421a0;
  reg_rdi[0x18] = 0x63dea000641960;
  reg_rdi[0x19] = 0x8bcd00062ec00;
  reg_rdi[0x1a] = 0x97750000969e0;
  reg_rdi[0x1b] = 0x9723000097640;
  reg_rdi[0x1c] = 0x21ed128002d6b30;
  reg_rdi[0x1d] = 0x6371200016cf40;
  reg_rdi[0x1e] = 0x155e1e001527f60;
  reg_rdi[0x1f] = 0x111b84002264d48;
  reg_rdi[0x20] = 0x1b906e0021ebf20;
  reg_rdi[0x21] = 0x26501c0010fc310;
  reg_rdi[0x22] = 0x1b4cbec01575df8;
  reg_rdi[0x23] = 0x2642ca80005325b;
  reg_rdi[0x24] = 0x264423802649b40;
  reg_rdi[0x25] = 0x264800002644248;
  *(u32 *)(reg_rdi + 0x26) = 0x2648808;
  return;
}

/*
 * ksdk_offsets_904
 *
 * Write ksdk kernel-offset table for firmware 904
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_904(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0xb79e0000001c0;
  reg_rdi[1] = 0x301a70003017b0;
  reg_rdi[2] = 0x27113000301970;
  reg_rdi[3] = 0x271aa000149670;
  reg_rdi[4] = 0x30f0f00037a070;
  reg_rdi[5] = 0x1ed62000451da0;
  reg_rdi[6] = 0x43c6f00043c530;
  reg_rdi[7] = 0x7bb800029a000;
  reg_rdi[8] = 0x7bbd00007c1c0;
  reg_rdi[9] = 0x809c00007e680;
  reg_rdi[10] = 0x7cd800007ec40;
  reg_rdi[0xb] = 0x7baa00007ba30;
  reg_rdi[0xc] = 0x2193a00041ca70;
  reg_rdi[0xd] = 0xf832000219460;
  reg_rdi[0xe] = 0x2717d0004859b0;
  reg_rdi[0xf] = 0x12470000271230;
  reg_rdi[0x10] = 0xb7ce00041c2f0;
  reg_rdi[0x11] = 0x39fd30000b7c20;
  reg_rdi[0x12] = 0x62329000442f80;
  reg_rdi[0x13] = 0x1ff000004607b0;
  reg_rdi[0x14] = 0x61d650001ff230;
  reg_rdi[0x15] = 0x61d2200061d990;
  reg_rdi[0x16] = 0x6229300061ae90;
  reg_rdi[0x17] = 0x63fc20006421a0;
  reg_rdi[0x18] = 0x63dea000641960;
  reg_rdi[0x19] = 0x8bcd00062ec00;
  reg_rdi[0x1a] = 0x97750000969e0;
  reg_rdi[0x1b] = 0x9723000097640;
  reg_rdi[0x1c] = 0x21ed128002d6b30;
  reg_rdi[0x1d] = 0x6371200016cf40;
  reg_rdi[0x1e] = 0x155e1e001527f60;
  reg_rdi[0x1f] = 0x111b84002264d48;
  reg_rdi[0x20] = 0x1b906e0021ebf20;
  reg_rdi[0x21] = 0x26501c0010fc310;
  reg_rdi[0x22] = 0x1b4cbec01575df8;
  reg_rdi[0x23] = 0x2642ca80005325b;
  reg_rdi[0x24] = 0x264423802649b40;
  reg_rdi[0x25] = 0x264800002644248;
  *(u32 *)(reg_rdi + 0x26) = 0x2648808;
  return;
}

/*
 * ksdk_offsets_950
 *
 * Write ksdk kernel-offset table for firmware 950
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_950(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x205470000001c0;
  reg_rdi[1] = 0x29d5f00029d330;
  reg_rdi[2] = 0x201cc00029d4f0;
  reg_rdi[3] = 0x47cb80000c1720;
  reg_rdi[4] = 0x3f1980001889d0;
  reg_rdi[5] = 0x1ec43000062120;
  reg_rdi[6] = 0x42bd000042bb40;
  reg_rdi[7] = 0x191d3000331df0;
  reg_rdi[8] = 0x191d8000192370;
  reg_rdi[9] = 0x196b7000194830;
  reg_rdi[10] = 0x192f3000194df0;
  reg_rdi[0xb] = 0x191c5000191be0;
  reg_rdi[0xc] = 0x2bdda000479620;
  reg_rdi[0xd] = 0x285720002bde60;
  reg_rdi[0xe] = 0x20236000248480;
  reg_rdi[0xf] = 0x1360b000201dc0;
  reg_rdi[0x10] = 0x205770000b1850;
  reg_rdi[0x11] = 0x463060002056b0;
  reg_rdi[0x12] = 0x61f6d00021b230;
  reg_rdi[0x13] = 0x3681a00005f060;
  reg_rdi[0x14] = 0x619df0003683d0;
  reg_rdi[0x15] = 0x6199c00061a130;
  reg_rdi[0x16] = 0x61f3f000613c30;
  reg_rdi[0x17] = 0x635d200063b1b0;
  reg_rdi[0x18] = 0x633fa00063a970;
  reg_rdi[0x19] = 0x32640006276e0;
  reg_rdi[0x1a] = 0x455ba000454e30;
  reg_rdi[0x1b] = 0x45568000455a90;
  reg_rdi[0x1c] = 0x21458800014e430;
  reg_rdi[0x1d] = 0x62fec000331850;
  reg_rdi[0x1e] = 0x1a4ecb001a50be0;
  reg_rdi[0x1f] = 0x11137d002147830;
  reg_rdi[0x20] = 0x221d2a0021a6c30;
  reg_rdi[0x21] = 0x263aec0010f92f0;
  reg_rdi[0x22] = 0x21baf4c01542948;
  reg_rdi[0x23] = 0x263a6d000015a6d;
  reg_rdi[0x24] = 0x2648b7802658650;
  reg_rdi[0x25] = 0x264c00002648b88;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}

/*
 * ksdk_offsets_951
 *
 * Write ksdk kernel-offset table for firmware 951
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_951(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x205470000001c0;
  reg_rdi[1] = 0x29d5f00029d330;
  reg_rdi[2] = 0x201cc00029d4f0;
  reg_rdi[3] = 0x47cb80000c1720;
  reg_rdi[4] = 0x3f1980001889d0;
  reg_rdi[5] = 0x1ec43000062120;
  reg_rdi[6] = 0x42bd000042bb40;
  reg_rdi[7] = 0x191d3000331df0;
  reg_rdi[8] = 0x191d8000192370;
  reg_rdi[9] = 0x196b7000194830;
  reg_rdi[10] = 0x192f3000194df0;
  reg_rdi[0xb] = 0x191c5000191be0;
  reg_rdi[0xc] = 0x2bdda000479620;
  reg_rdi[0xd] = 0x285720002bde60;
  reg_rdi[0xe] = 0x20236000248480;
  reg_rdi[0xf] = 0x1360b000201dc0;
  reg_rdi[0x10] = 0x205770000b1850;
  reg_rdi[0x11] = 0x463060002056b0;
  reg_rdi[0x12] = 0x61f6d00021b230;
  reg_rdi[0x13] = 0x3681a00005f060;
  reg_rdi[0x14] = 0x619df0003683d0;
  reg_rdi[0x15] = 0x6199c00061a130;
  reg_rdi[0x16] = 0x61f3f000613c30;
  reg_rdi[0x17] = 0x635d200063b1b0;
  reg_rdi[0x18] = 0x633fa00063a970;
  reg_rdi[0x19] = 0x32640006276e0;
  reg_rdi[0x1a] = 0x455ba000454e30;
  reg_rdi[0x1b] = 0x45568000455a90;
  reg_rdi[0x1c] = 0x21458800014e430;
  reg_rdi[0x1d] = 0x62fec000331850;
  reg_rdi[0x1e] = 0x1a4ecb001a50be0;
  reg_rdi[0x1f] = 0x11137d002147830;
  reg_rdi[0x20] = 0x221d2a0021a6c30;
  reg_rdi[0x21] = 0x263aec0010f92f0;
  reg_rdi[0x22] = 0x21baf4c01542948;
  reg_rdi[0x23] = 0x263a6d000015a6d;
  reg_rdi[0x24] = 0x2648b7802658650;
  reg_rdi[0x25] = 0x264c00002648b88;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}

/*
 * ksdk_offsets_960
 *
 * Write ksdk kernel-offset table for firmware 960
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void ksdk_offsets_960(void)

{
  u64 *reg_rdi;
  
  *reg_rdi = 0x205470000001c0;
  reg_rdi[1] = 0x29d5f00029d330;
  reg_rdi[2] = 0x201cc00029d4f0;
  reg_rdi[3] = 0x47cb80000c1720;
  reg_rdi[4] = 0x3f1980001889d0;
  reg_rdi[5] = 0x1ec43000062120;
  reg_rdi[6] = 0x42bd000042bb40;
  reg_rdi[7] = 0x191d3000331df0;
  reg_rdi[8] = 0x191d8000192370;
  reg_rdi[9] = 0x196b7000194830;
  reg_rdi[10] = 0x192f3000194df0;
  reg_rdi[0xb] = 0x191c5000191be0;
  reg_rdi[0xc] = 0x2bdda000479620;
  reg_rdi[0xd] = 0x285720002bde60;
  reg_rdi[0xe] = 0x20236000248480;
  reg_rdi[0xf] = 0x1360b000201dc0;
  reg_rdi[0x10] = 0x205770000b1850;
  reg_rdi[0x11] = 0x463060002056b0;
  reg_rdi[0x12] = 0x61f6d00021b230;
  reg_rdi[0x13] = 0x3681a00005f060;
  reg_rdi[0x14] = 0x619df0003683d0;
  reg_rdi[0x15] = 0x6199c00061a130;
  reg_rdi[0x16] = 0x61f3f000613c30;
  reg_rdi[0x17] = 0x635d200063b1b0;
  reg_rdi[0x18] = 0x633fa00063a970;
  reg_rdi[0x19] = 0x32640006276e0;
  reg_rdi[0x1a] = 0x455ba000454e30;
  reg_rdi[0x1b] = 0x45568000455a90;
  reg_rdi[0x1c] = 0x21458800014e430;
  reg_rdi[0x1d] = 0x62fec000331850;
  reg_rdi[0x1e] = 0x1a4ecb001a50be0;
  reg_rdi[0x1f] = 0x11137d002147830;
  reg_rdi[0x20] = 0x221d2a0021a6c30;
  reg_rdi[0x21] = 0x263aec0010f92f0;
  reg_rdi[0x22] = 0x21baf4c01542948;
  reg_rdi[0x23] = 0x263a6d000015a6d;
  reg_rdi[0x24] = 0x2648b7802658650;
  reg_rdi[0x25] = 0x264c00002648b88;
  *(u32 *)(reg_rdi + 0x26) = 0x264c808;
  return;
}
