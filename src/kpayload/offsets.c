/*
 * offsets.c - per-firmware kernel offset tables and their dispatchers (payload side).
 */

#include <goldhen/types.h>

/* get_goldhen_offsets @ 0x10602b size=559 */
u32 * get_goldhen_offsets(u32 *param_1,u16 param_2)

{
  s64 lVar1;
  u32 *puVar2;
  
  if ((param_2 & 0xfffd) == 0x1f9) {
    goldhen_offsets_505();
  }
  else if (param_2 == 0x29f) {
    goldhen_offsets_671();
  }
  else if (param_2 == 0x2a0) {
    goldhen_offsets_672();
  }
  else if ((u16)(param_2 - 700) < 3) {
    goldhen_offsets_702();
  }
  else if (param_2 == 0x2ee) {
    goldhen_offsets_750();
  }
  else if (param_2 == 0x2ef) {
    goldhen_offsets_751();
  }
  else if (param_2 == 0x2f3) {
    goldhen_offsets_755();
  }
  else if (param_2 == 800) {
    goldhen_offsets_800();
  }
  else if (param_2 == 0x321) {
    goldhen_offsets_801();
  }
  else if (param_2 == 0x323) {
    goldhen_offsets_803();
  }
  else if (param_2 == 0x352) {
    goldhen_offsets_850();
  }
  else if (param_2 == 0x354) {
    goldhen_offsets_852();
  }
  else if (param_2 == 900) {
    goldhen_offsets_900();
  }
  else if (param_2 == 0x387) {
    goldhen_offsets_903();
  }
  else if (param_2 == 0x388) {
    goldhen_offsets_904();
  }
  else if (param_2 == 0x3b6) {
    goldhen_offsets_950();
  }
  else if (param_2 == 0x3b7) {
    goldhen_offsets_951();
  }
  else if (param_2 == 0x3c0) {
    goldhen_offsets_960();
  }
  else if (param_2 == 1000) {
    goldhen_offsets_1000();
  }
  else if (param_2 == 0x3e9) {
    goldhen_offsets_1001();
  }
  else if (param_2 == 0x41a) {
    goldhen_offsets_1050();
  }
  else if ((u16)(param_2 - 0x42e) < 2) {
    goldhen_offsets_1071();
  }
  else if (param_2 == 0x44c) {
    goldhen_offsets_1100();
  }
  else if (param_2 == 0x44e) {
    goldhen_offsets_1102();
  }
  else if ((param_2 - 0x47e & 0xfffd) == 0) {
    goldhen_offsets_1152();
  }
  else if ((param_2 & 0xfffd) == 0x4b0) {
    goldhen_offsets_1202();
  }
  else if ((param_2 - 0x4e2 & 0xfffd) == 0) {
    goldhen_offsets_1252();
  }
  else if (param_2 == 0x514) {
    goldhen_offsets_1300();
  }
  else {
    puVar2 = param_1;
    for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return param_1;
}

/* get_installer_offsets @ 0x10625a size=559 */
u32 * get_installer_offsets(u32 *param_1,u16 param_2)

{
  s64 lVar1;
  u32 *puVar2;
  
  if ((param_2 & 0xfffd) == 0x1f9) {
    installer_offsets_505();
  }
  else if (param_2 == 0x29f) {
    installer_offsets_671();
  }
  else if (param_2 == 0x2a0) {
    installer_offsets_672();
  }
  else if ((u16)(param_2 - 700) < 3) {
    installer_offsets_702();
  }
  else if (param_2 == 0x2ee) {
    installer_offsets_750();
  }
  else if (param_2 == 0x2ef) {
    installer_offsets_751();
  }
  else if (param_2 == 0x2f3) {
    installer_offsets_755();
  }
  else if (param_2 == 800) {
    installer_offsets_800();
  }
  else if (param_2 == 0x321) {
    installer_offsets_801();
  }
  else if (param_2 == 0x323) {
    installer_offsets_803();
  }
  else if (param_2 == 0x352) {
    installer_offsets_850();
  }
  else if (param_2 == 0x354) {
    installer_offsets_852();
  }
  else if (param_2 == 900) {
    installer_offsets_900();
  }
  else if (param_2 == 0x387) {
    installer_offsets_903();
  }
  else if (param_2 == 0x388) {
    installer_offsets_904();
  }
  else if (param_2 == 0x3b6) {
    installer_offsets_950();
  }
  else if (param_2 == 0x3b7) {
    installer_offsets_951();
  }
  else if (param_2 == 0x3c0) {
    installer_offsets_960();
  }
  else if (param_2 == 1000) {
    installer_offsets_1000();
  }
  else if (param_2 == 0x3e9) {
    installer_offsets_1001();
  }
  else if (param_2 == 0x41a) {
    installer_offsets_1050();
  }
  else if ((u16)(param_2 - 0x42e) < 2) {
    installer_offsets_1071();
  }
  else if (param_2 == 0x44c) {
    installer_offsets_1100();
  }
  else if (param_2 == 0x44e) {
    installer_offsets_1102();
  }
  else if ((param_2 - 0x47e & 0xfffd) == 0) {
    installer_offsets_1152();
  }
  else if ((param_2 & 0xfffd) == 0x4b0) {
    installer_offsets_1202();
  }
  else if ((param_2 - 0x4e2 & 0xfffd) == 0) {
    installer_offsets_1252();
  }
  else if (param_2 == 0x514) {
    installer_offsets_1300();
  }
  else {
    puVar2 = param_1;
    for (lVar1 = 5; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return param_1;
}

/* get_ksdk_offsets @ 0x106489 size=559 */
u32 * get_ksdk_offsets(u32 *param_1,u16 param_2)

{
  s64 lVar1;
  u32 *puVar2;
  
  if ((param_2 & 0xfffd) == 0x1f9) {
    ksdk_offsets_505();
  }
  else if (param_2 == 0x29f) {
    ksdk_offsets_671();
  }
  else if (param_2 == 0x2a0) {
    ksdk_offsets_672();
  }
  else if ((u16)(param_2 - 700) < 3) {
    ksdk_offsets_702();
  }
  else if (param_2 == 0x2ee) {
    ksdk_offsets_750();
  }
  else if (param_2 == 0x2ef) {
    ksdk_offsets_751();
  }
  else if (param_2 == 0x2f3) {
    ksdk_offsets_755();
  }
  else if (param_2 == 800) {
    ksdk_offsets_800();
  }
  else if (param_2 == 0x321) {
    ksdk_offsets_801();
  }
  else if (param_2 == 0x323) {
    ksdk_offsets_803();
  }
  else if (param_2 == 0x352) {
    ksdk_offsets_850();
  }
  else if (param_2 == 0x354) {
    ksdk_offsets_852();
  }
  else if (param_2 == 900) {
    ksdk_offsets_900();
  }
  else if (param_2 == 0x387) {
    ksdk_offsets_903();
  }
  else if (param_2 == 0x388) {
    ksdk_offsets_904();
  }
  else if (param_2 == 0x3b6) {
    ksdk_offsets_950();
  }
  else if (param_2 == 0x3b7) {
    ksdk_offsets_951();
  }
  else if (param_2 == 0x3c0) {
    ksdk_offsets_960();
  }
  else if (param_2 == 1000) {
    ksdk_offsets_1000();
  }
  else if (param_2 == 0x3e9) {
    ksdk_offsets_1001();
  }
  else if (param_2 == 0x41a) {
    ksdk_offsets_1050();
  }
  else if ((u16)(param_2 - 0x42e) < 2) {
    ksdk_offsets_1071();
  }
  else if (param_2 == 0x44c) {
    ksdk_offsets_1100();
  }
  else if (param_2 == 0x44e) {
    ksdk_offsets_1102();
  }
  else if ((param_2 - 0x47e & 0xfffd) == 0) {
    ksdk_offsets_1152();
  }
  else if ((param_2 & 0xfffd) == 0x4b0) {
    ksdk_offsets_1202();
  }
  else if ((param_2 - 0x4e2 & 0xfffd) == 0) {
    ksdk_offsets_1252();
  }
  else if (param_2 == 0x514) {
    ksdk_offsets_1300();
  }
  else {
    puVar2 = param_1;
    for (lVar1 = 0x4d; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return param_1;
}

/* get_proc_offsets @ 0x1066b8 size=425 */
u64 get_proc_offsets(u16 param_1)

{
  u64 uVar1;
  
  if ((param_1 & 0xfffd) == 0x1f9) {
    uVar1 = proc_offsets_505();
    return uVar1;
  }
  if (param_1 == 0x29f) {
    uVar1 = proc_offsets_671();
    return uVar1;
  }
  if (param_1 == 0x2a0) {
    uVar1 = proc_offsets_672();
    return uVar1;
  }
  if ((u16)(param_1 - 700) < 3) {
    uVar1 = proc_offsets_702();
    return uVar1;
  }
  if (param_1 == 0x2ee) {
    uVar1 = proc_offsets_750();
    return uVar1;
  }
  if (param_1 == 0x2ef) {
    uVar1 = proc_offsets_751();
    return uVar1;
  }
  if (param_1 == 0x2f3) {
    uVar1 = proc_offsets_755();
    return uVar1;
  }
  if (param_1 == 800) {
    uVar1 = proc_offsets_800();
    return uVar1;
  }
  if (param_1 == 0x321) {
    uVar1 = proc_offsets_801();
    return uVar1;
  }
  if (param_1 == 0x323) {
    uVar1 = proc_offsets_803();
    return uVar1;
  }
  if (param_1 == 0x352) {
    uVar1 = proc_offsets_850();
    return uVar1;
  }
  if (param_1 == 0x354) {
    uVar1 = proc_offsets_852();
    return uVar1;
  }
  if (param_1 == 900) {
    uVar1 = proc_offsets_900();
    return uVar1;
  }
  if (param_1 == 0x387) {
    uVar1 = proc_offsets_903();
    return uVar1;
  }
  if (param_1 == 0x388) {
    uVar1 = proc_offsets_904();
    return uVar1;
  }
  if (param_1 == 0x3b6) {
    uVar1 = proc_offsets_950();
    return uVar1;
  }
  if (param_1 == 0x3b7) {
    uVar1 = proc_offsets_951();
    return uVar1;
  }
  if (param_1 == 0x3c0) {
    uVar1 = proc_offsets_960();
    return uVar1;
  }
  if (param_1 == 1000) {
    uVar1 = proc_offsets_1000();
    return uVar1;
  }
  if (param_1 == 0x3e9) {
    uVar1 = proc_offsets_1001();
    return uVar1;
  }
  if (param_1 == 0x41a) {
    uVar1 = proc_offsets_1050();
    return uVar1;
  }
  if ((u16)(param_1 - 0x42e) < 2) {
    uVar1 = proc_offsets_1071();
    return uVar1;
  }
  if (param_1 == 0x44c) {
    uVar1 = proc_offsets_1100();
    return uVar1;
  }
  if (param_1 == 0x44e) {
    uVar1 = proc_offsets_1102();
    return uVar1;
  }
  if ((param_1 - 0x47e & 0xfffd) == 0) {
    uVar1 = proc_offsets_1152();
    return uVar1;
  }
  if ((param_1 & 0xfffd) == 0x4b0) {
    uVar1 = proc_offsets_1202();
    return uVar1;
  }
  if ((param_1 - 0x4e2 & 0xfffd) == 0) {
    uVar1 = proc_offsets_1252();
    return uVar1;
  }
  if (param_1 == 0x514) {
    uVar1 = proc_offsets_1300();
    return uVar1;
  }
  return 0;
}

/* goldhen_offsets_1000 @ 0x106ae1 size=882 */
u32 * goldhen_offsets_1000(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ed9ce004ec908;
  local_f8 = 0x64a510006926e0;
  local_f0 = 0x19025f0064a540;
  local_d8 = 0x90c3c031;
  local_c4 = 0xa5cd00039207b;
  local_bc = 0xef2c1000a5cf0;
  local_b4 = 0x472f7300472f67;
  local_ac = 0x472e7e00472e72;
  local_a4 = 0x47341f00473413;
  local_1d8 = 0x63a94e0063a7fc;
  local_1d0 = 0x63bdc90063b0e6;
  local_1c8 = 0x6408180063fbdd;
  local_1c0 = 0x6223dd00624d45;
  local_1b8 = 0x64bade0064ad10;
  local_1b0 = 0x68e6fa0068e4c9;
  local_90 = 0x765620003bf3a4;
  local_88 = 0x450e56000a5c60;
  local_80 = 0x3bc2aa003bc2a1;
  local_78 = 0x636565003bc2b3;
  local_70 = 0x61ed200063657b;
  local_e8 = 0x4ceb;
  local_e0 = 0x1bea40;
  local_60 = 0x2af8d0;
  local_98 = 0x48bf20;
  local_68 = 0x61ec00;
  local_17c = 0x8260;
  local_1a0 = g_bytes_00185e90;
  local_198 = 0xec2282;
  local_180 = 5;
  _memcpy(local_190,g_bytes_001969e8,5);
  local_178 = 0xecb70000ecb55;
  local_170 = 0x8594b40016b694;
  local_168 = 0xa08094008a85f2;
  local_160 = 0x247e4c0016b6c2;
  local_158 = 0xa080c2008594e2;
  local_150 = 0x3d26af0031b310;
  local_138 = 8;
  _memcpy(local_148,g_bytes_001969ee,8);
  local_134 = 0xfb08b9;
  local_130 = 0x604ffd009f15e1;
  local_128 = 0xcf8b600738319;
  local_120 = 0x3bf74000d919e0;
  local_118 = 0x80a6f0003c29f0;
  local_108 = 0x3bf7a700134a90;
  local_58 = 0x8a4300008a430;
  local_50 = 0x132f00008e830;
  local_48 = 0x13e2000014c20;
  local_40 = 0x106d000013310;
  local_38 = 0x1373000013e40;
  local_30 = 0x1426000005800;
  local_28 = 0x22350000137d0;
  local_110 = 0x6dd510;
  local_20 = 0x14300;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1001 @ 0x1070fc size=882 */
u32 * goldhen_offsets_1001(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ed9ce004ec908;
  local_f8 = 0x64a510006926e0;
  local_f0 = 0x19025f0064a540;
  local_d8 = 0x90c3c031;
  local_c4 = 0xa5cd00039207b;
  local_bc = 0xef2c1000a5cf0;
  local_b4 = 0x472f7300472f67;
  local_ac = 0x472e7e00472e72;
  local_a4 = 0x47341f00473413;
  local_1d8 = 0x63a94e0063a7fc;
  local_1d0 = 0x63bdc90063b0e6;
  local_1c8 = 0x6408180063fbdd;
  local_1c0 = 0x6223dd00624d45;
  local_1b8 = 0x64bade0064ad10;
  local_1b0 = 0x68e6fa0068e4c9;
  local_90 = 0x765620003bf3a4;
  local_88 = 0x450e56000a5c60;
  local_80 = 0x3bc2aa003bc2a1;
  local_78 = 0x636565003bc2b3;
  local_70 = 0x61ed200063657b;
  local_e8 = 0x4ceb;
  local_e0 = 0x1bea40;
  local_60 = 0x2af8d0;
  local_98 = 0x48bf20;
  local_68 = 0x61ec00;
  local_17c = 0x8260;
  local_1a0 = g_bytes_00185e90;
  local_198 = 0xec2282;
  local_180 = 5;
  _memcpy(local_190,g_bytes_001969f7,5);
  local_178 = 0xecb70000ecb55;
  local_170 = 0x8594c40016b6a4;
  local_168 = 0xa080b4008a8602;
  local_160 = 0x247e5c0016b6d2;
  local_158 = 0xa080e2008594f2;
  local_150 = 0x3d26bf0031b320;
  local_138 = 8;
  _memcpy(local_148,g_bytes_001969fd,8);
  local_134 = 0xfb08d9;
  local_130 = 0x60500d009f1601;
  local_128 = 0xcf8b600738329;
  local_120 = 0x3bf75000d91a00;
  local_118 = 0x80a700003c2a00;
  local_108 = 0x3bf7b700134a90;
  local_58 = 0x8a4300008a430;
  local_50 = 0x132f00008e830;
  local_48 = 0x13e2000014c20;
  local_40 = 0x106d000013310;
  local_38 = 0x1373000013e40;
  local_30 = 0x1426000005800;
  local_28 = 0x22350000137d0;
  local_110 = 0x6dd520;
  local_20 = 0x14300;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1050 @ 0x107717 size=905 */
u32 * goldhen_offsets_1050(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e7e6e004e6da8;
  local_f8 = 0x64e930006c4c00;
  local_f0 = 0x2130880064e960;
  local_d8 = 0x90c3c031;
  local_d0 = 0x21302300213013;
  local_c8 = 0x47b2ec00213043;
  local_c0 = 0x1f4500001f44e0;
  local_b8 = 0xd75b70019e151;
  local_b0 = 0xd74c2000d75c3;
  local_a8 = 0xd7a63000d74ce;
  local_1d8 = 0x6412ce0064117c;
  local_1d0 = 0x64274900641a66;
  local_1c8 = 0x63ef380063e2fd;
  local_1c0 = 0x62682d006229b5;
  local_1b8 = 0x64c64e0064b880;
  local_1b0 = 0x6b5c2a006b59f9;
  local_90 = 0x7673d000345e04;
  local_88 = 0xdaa46001f4470;
  local_80 = 0x342d0a00342d01;
  local_78 = 0x63768500342d13;
  local_70 = 0x6282700063769b;
  local_e8 = 0x13ae9;
  local_e0 = 0x2dab60;
  local_a0 = 0xd7a6f;
  local_60 = 0x230350;
  local_98 = 0x48d2a0;
  local_68 = 0x628150;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_00188cb0;
  local_198 = 0xec7b12;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a06,5);
  local_178 = 0xeca10000ec9f5;
  local_170 = 0x85bab40016b664;
  local_168 = 0xa0ca84008abce2;
  local_160 = 0x249b0c0016b692;
  local_158 = 0xa0cab20085bae2;
  local_150 = 0x3d544f0031e890;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a0c,8);
  local_134 = 0xfb5d59;
  local_130 = 0x606b7d009f5fd1;
  local_128 = 0xcf8760073a629;
  local_118 = 0x80c5a0003c4ba0;
  local_108 = 0x3c195700134a50;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134000008e830;
  local_48 = 0x13f7000017d80;
  local_40 = 0x1066000013420;
  local_38 = 0x1384000013f90;
  local_30 = 0x143b00001be60;
  local_28 = 0x29950000138e0;
  local_120 = 0xd962d0;
  local_110 = 0x6df170;
  local_20 = 0x14450;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1071 @ 0x107d49 size=905 */
u32 * goldhen_offsets_1071(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e7e6e004e6da8;
  local_f8 = 0x64e930006c4c00;
  local_f0 = 0x2130880064e960;
  local_d8 = 0x90c3c031;
  local_d0 = 0x21302300213013;
  local_c8 = 0x47b2ec00213043;
  local_c0 = 0x1f4500001f44e0;
  local_b8 = 0xd75b70019e151;
  local_b0 = 0xd74c2000d75c3;
  local_a8 = 0xd7a63000d74ce;
  local_1d8 = 0x6412ce0064117c;
  local_1d0 = 0x64274900641a66;
  local_1c8 = 0x63ef380063e2fd;
  local_1c0 = 0x62682d006229b5;
  local_1b8 = 0x64c64e0064b880;
  local_1b0 = 0x6b5c2a006b59f9;
  local_90 = 0x7673d000345e04;
  local_88 = 0xdaa46001f4470;
  local_80 = 0x342d0a00342d01;
  local_78 = 0x63768500342d13;
  local_70 = 0x6282700063769b;
  local_e8 = 0x13ae9;
  local_e0 = 0x2dab60;
  local_a0 = 0xd7a6f;
  local_60 = 0x230350;
  local_98 = 0x48d2a0;
  local_68 = 0x628150;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_00188cb0;
  local_198 = 0xec7b12;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a15,5);
  local_178 = 0xeca10000ec9f5;
  local_170 = 0x85bab40016b664;
  local_168 = 0xa0ca84008abce2;
  local_160 = 0x249b0c0016b692;
  local_158 = 0xa0cab20085bae2;
  local_150 = 0x3d544f0031e890;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a1b,8);
  local_134 = 0xfb5d99;
  local_130 = 0x606b7d009f5fd1;
  local_128 = 0xcf8760073a629;
  local_118 = 0x80c5a0003c4ba0;
  local_108 = 0x3c195700134a50;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134000008e830;
  local_48 = 0x13f7000017d80;
  local_40 = 0x1066000013420;
  local_38 = 0x1384000013f90;
  local_30 = 0x143b00001be60;
  local_28 = 0x29950000138e0;
  local_120 = 0xd962d0;
  local_110 = 0x6df170;
  local_20 = 0x14450;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1100 @ 0x10837b size=911 */
u32 * goldhen_offsets_1100(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ef3ee004ee328;
  local_f8 = 0x64bfd000684eb0;
  local_f0 = 0x1e4ca80064c000;
  local_d8 = 0x90c3c031;
  local_d0 = 0x1e4c43001e4c33;
  local_c8 = 0x35c8ec001e4c63;
  local_c0 = 0x3d0e70003d0e50;
  local_b8 = 0x2de03700157f91;
  local_b0 = 0x2ddf42002de043;
  local_a8 = 0x2de4e3002ddf4e;
  local_1d8 = 0x63d28e0063d13c;
  local_1d0 = 0x63e7090063da26;
  local_1c8 = 0x641a4800640e0d;
  local_1c0 = 0x626fad0062ee65;
  local_1b8 = 0x64dffe0064d230;
  local_1b0 = 0x6995ea006993b9;
  local_90 = 0x76d210003b11a4;
  local_88 = 0x28ff26003d0de0;
  local_80 = 0x3ae10e003ae105;
  local_78 = 0x638025003ae117;
  local_70 = 0x6244200063803b;
  local_e8 = 0x13ae9;
  local_e0 = 0x88ce0;
  local_a0 = 0x2de4ef;
  local_60 = 0x42bce0;
  local_98 = 0x48de50;
  local_68 = 0x624300;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_0018b110;
  local_198 = 0xecab92;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a24,5);
  local_178 = 0xeccd0000eccb5;
  local_170 = 0x86bd240016b664;
  local_168 = 0xa1d6c4008bc022;
  local_160 = 0x249e0c0016b692;
  local_158 = 0xa1d6f20086bd52;
  local_150 = 0x3d7c9f0031f070;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a2a,8);
  local_134 = 0xfc8439;
  local_130 = 0x60e17d00a06c11;
  local_128 = 0xcf876007456e9;
  local_120 = 0x3c414000da7d00;
  local_118 = 0x81c150003c73f0;
  local_108 = 0x3c41a700134a50;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134a00008e830;
  local_48 = 0x1401000015990;
  local_40 = 0xe800000134c0;
  local_38 = 0x138e000014030;
  local_30 = 0x1445000020d90;
  local_28 = 0xa03000013980;
  local_110 = 0x6e9360;
  local_20 = 0x144f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1102 @ 0x1089b3 size=911 */
u32 * goldhen_offsets_1102(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ef37e004ee2b8;
  local_f8 = 0x64bf7000684e50;
  local_f0 = 0x1e4cc80064bfa0;
  local_d8 = 0x90c3c031;
  local_d0 = 0x1e4c63001e4c53;
  local_c8 = 0x35c90c001e4c83;
  local_c0 = 0x3d0e90003d0e70;
  local_b8 = 0x2de05700157fb1;
  local_b0 = 0x2ddf62002de063;
  local_a8 = 0x2de503002ddf6e;
  local_1d8 = 0x63d22e0063d0dc;
  local_1d0 = 0x63e6a90063d9c6;
  local_1c8 = 0x6419e800640dad;
  local_1c0 = 0x626f4d0062ee05;
  local_1b8 = 0x64df9e0064d1d0;
  local_1b0 = 0x69958a00699359;
  local_90 = 0x76d1d0003b11c4;
  local_88 = 0x28ff46003d0e00;
  local_80 = 0x3ae12e003ae125;
  local_78 = 0x637fc5003ae137;
  local_70 = 0x6243c000637fdb;
  local_e8 = 0x13ae9;
  local_e0 = 0x88ce0;
  local_a0 = 0x2de50f;
  local_60 = 0x42bcc0;
  local_98 = 0x48dde0;
  local_68 = 0x6242a0;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_0018b110;
  local_198 = 0xecab92;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a33,5);
  local_178 = 0xeccd0000eccb5;
  local_170 = 0x86bd240016b664;
  local_168 = 0xa1d6c4008bc022;
  local_160 = 0x249e0c0016b692;
  local_158 = 0xa1d6f20086bd52;
  local_150 = 0x3d7c9f0031f070;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a39,8);
  local_134 = 0xfc8439;
  local_130 = 0x60e17d00a06c11;
  local_128 = 0xcf876007456e9;
  local_120 = 0x3c414000da7d00;
  local_118 = 0x81c150003c73f0;
  local_108 = 0x3c41a700134a50;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134a00008e830;
  local_48 = 0x1401000015990;
  local_40 = 0xe800000134c0;
  local_38 = 0x138e000014030;
  local_30 = 0x1445000020d90;
  local_28 = 0xa03000013980;
  local_110 = 0x6e9360;
  local_20 = 0x144f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1152 @ 0x108feb size=911 */
u32 * goldhen_offsets_1152(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e95ce004e8508;
  local_f8 = 0x64e8f00069d550;
  local_f0 = 0x1b77180064e920;
  local_d8 = 0x90c3c031;
  local_d0 = 0x1b76b3001b76a3;
  local_c8 = 0x2fbeac001b76d3;
  local_c0 = 0x3b2b20003b2b00;
  local_b8 = 0x2bd5e7001fc361;
  local_b0 = 0x2bd4f2002bd5f3;
  local_a8 = 0x2bda93002bd4fe;
  local_1d8 = 0x641e9e00641d4c;
  local_1d0 = 0x64331900642636;
  local_1c8 = 0x6409880063fd4d;
  local_1c0 = 0x62bfad006245a5;
  local_1b8 = 0x64d06e0064c2a0;
  local_1b0 = 0x6a2b4a006a2919;
  local_90 = 0x76b37000477a14;
  local_88 = 0x30f66003b2a90;
  local_80 = 0x47497e00474975;
  local_78 = 0x6380a500474987;
  local_70 = 0x627d70006380bb;
  local_e8 = 0x4ceb;
  local_e0 = 0x3bd620;
  local_a0 = 0x2bda9f;
  local_60 = 0xf1b50;
  local_98 = 0x48cdc0;
  local_68 = 0x627c50;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_0018b110;
  local_198 = 0xec6f92;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a42,5);
  local_178 = 0xed1f0000ed1d5;
  local_170 = 0x870e440016e004;
  local_168 = 0xa228b4008c1142;
  local_160 = 0x24c72c0016e032;
  local_158 = 0xa228e200870e72;
  local_150 = 0x3dc64f00321990;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a48,8);
  local_134 = 0xfce619;
  local_130 = 0x612b6d00a0be01;
  local_128 = 0xd22160074ab39;
  local_120 = 0x3c8ae000dad2f0;
  local_118 = 0x8212c0003cbd90;
  local_108 = 0x3c8b47001373f0;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134a00008e830;
  local_48 = 0x1401000013580;
  local_40 = 0xd380000134c0;
  local_38 = 0x138e000014030;
  local_30 = 0x1445000010230;
  local_28 = 0x22a8000013980;
  local_110 = 0x6edf30;
  local_20 = 0x144f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1202 @ 0x109623 size=911 */
u32 * goldhen_offsets_1202(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e980e004e8748;
  local_f8 = 0x64eb300069d9a0;
  local_f0 = 0x1b77180064eb60;
  local_d8 = 0x90c3c031;
  local_d0 = 0x1b76b3001b76a3;
  local_c8 = 0x2fc0ec001b76d3;
  local_c0 = 0x3b2d60003b2d40;
  local_b8 = 0x2bd6c7001fc441;
  local_b0 = 0x2bd5d2002bd6d3;
  local_a8 = 0x2bdb73002bd5de;
  local_1d8 = 0x6420de00641f8c;
  local_1d0 = 0x64355900642876;
  local_1c8 = 0x640bc80063ff8d;
  local_1c0 = 0x62c1ed006247e5;
  local_1b8 = 0x64d2ae0064c4e0;
  local_1b0 = 0x6a2fca006a2d99;
  local_90 = 0x76b7f000477c54;
  local_88 = 0x30f66003b2cd0;
  local_80 = 0x474bbe00474bb5;
  local_78 = 0x6382e500474bc7;
  local_70 = 0x627fb0006382fb;
  local_e8 = 0x13ae9;
  local_e0 = 0x3bd860;
  local_a0 = 0x2bdb7f;
  local_60 = 0xf1b50;
  local_98 = 0x48d000;
  local_68 = 0x627e90;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_0018b310;
  local_198 = 0xec7012;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a51,5);
  local_178 = 0xed210000ed1f5;
  local_170 = 0x8737540016f5a4;
  local_168 = 0xa27304008c3a52;
  local_160 = 0x24e14c0016f5d2;
  local_158 = 0xa2733200873782;
  local_150 = 0x3de23f003233b0;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a57,8);
  local_134 = 0xfcfdf9;
  local_130 = 0x61475d00a10851;
  local_128 = 0xd22160074ccc9;
  local_120 = 0x3ca50000dae610;
  local_118 = 0x8238f0003cd7b0;
  local_108 = 0x3ca567001389a0;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134a00008e830;
  local_48 = 0x1401000007a00;
  local_40 = 0xeda0000134c0;
  local_38 = 0x138e000014030;
  local_30 = 0x1445000009700;
  local_28 = 0xa62000013980;
  local_110 = 0x6ef9e0;
  local_20 = 0x144f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1252 @ 0x109c5b size=911 */
u32 * goldhen_offsets_1252(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e984e004e8788;
  local_f8 = 0x64ebd00069da40;
  local_f0 = 0x1b77580064ec00;
  local_d8 = 0x90c3c031;
  local_d0 = 0x1b76f3001b76e3;
  local_c8 = 0x2fc12c001b7713;
  local_c0 = 0x3b2da0003b2d80;
  local_b8 = 0x2bd707001fc481;
  local_b0 = 0x2bd612002bd713;
  local_a8 = 0x2bdbb3002bd61e;
  local_1d8 = 0x64217e0064202c;
  local_1d0 = 0x6435f900642916;
  local_1c8 = 0x640c680064002d;
  local_1c0 = 0x62c22d00624825;
  local_1b8 = 0x64d34e0064c580;
  local_1b0 = 0x6a306a006a2e39;
  local_90 = 0x76b8b000477c94;
  local_88 = 0x30f66003b2d10;
  local_80 = 0x474bfe00474bf5;
  local_78 = 0x63832500474c07;
  local_70 = 0x627ff00063833b;
  local_e8 = 0x13de9;
  local_e0 = 0x3bd8a0;
  local_a0 = 0x2bdbbf;
  local_60 = 0xf1b50;
  local_98 = 0x48d040;
  local_68 = 0x627ed0;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_0018b3b0;
  local_198 = 0xec88c2;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a60,5);
  local_178 = 0xed210000ed1f5;
  local_170 = 0x8746440016f5a4;
  local_168 = 0xa28224008c4962;
  local_160 = 0x24e11c0016f5d2;
  local_158 = 0xa2825200874672;
  local_150 = 0x3de07f00323380;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a66,8);
  local_134 = 0xfd0e19;
  local_130 = 0x61465d00a11771;
  local_128 = 0xd22160074d099;
  local_120 = 0x3ca34000daf5c0;
  local_118 = 0x8243b0003cd5f0;
  local_108 = 0x3ca3a7001389a0;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134a00008e830;
  local_48 = 0x14010000069d0;
  local_40 = 0x6e20000134c0;
  local_38 = 0x138e000014030;
  local_30 = 0x1445000009710;
  local_28 = 0xcae000013980;
  local_110 = 0x6efcd0;
  local_20 = 0x144f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_1300 @ 0x10a293 size=911 */
u32 * goldhen_offsets_1300(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e986e004e87a8;
  local_f8 = 0x64ec200069db00;
  local_f0 = 0x1b77580064ec50;
  local_d8 = 0x90c3c031;
  local_d0 = 0x1b76f3001b76e3;
  local_c8 = 0x2fc14c001b7713;
  local_c0 = 0x3b2dc0003b2da0;
  local_b8 = 0x2bd727001fc4a1;
  local_b0 = 0x2bd632002bd733;
  local_a8 = 0x2bdbd3002bd63e;
  local_1d8 = 0x6421ce0064207c;
  local_1d0 = 0x64364900642966;
  local_1c8 = 0x640cb80064007d;
  local_1c0 = 0x62c27d00624875;
  local_1b8 = 0x64d39e0064c5d0;
  local_1b0 = 0x6a312a006a2ef9;
  local_90 = 0x76ba3000477cb4;
  local_88 = 0x30f66003b2d30;
  local_80 = 0x474c1e00474c15;
  local_78 = 0x63837500474c27;
  local_70 = 0x6280400063838b;
  local_e8 = 0x4ceb;
  local_e0 = 0x3bd8c0;
  local_a0 = 0x2bdbdf;
  local_60 = 0xf1b50;
  local_98 = 0x48d060;
  local_68 = 0x627f20;
  local_17c = 0x82a0;
  local_1a0 = g_bytes_0018b3b0;
  local_198 = 0xec8902;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a6f,5);
  local_178 = 0xed210000ed1f5;
  local_170 = 0x8746740016f5a4;
  local_168 = 0xa28244008c4992;
  local_160 = 0x24e11c0016f5d2;
  local_158 = 0xa28272008746a2;
  local_150 = 0x3de07f00323380;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a75,8);
  local_134 = 0xfd0e59;
  local_130 = 0x61465d00a11791;
  local_128 = 0xd22160074d0c9;
  local_120 = 0x3ca34000daf5e0;
  local_118 = 0x8243e0003cd5f0;
  local_108 = 0x3ca3a7001389a0;
  local_58 = 0x8e4300008e430;
  local_50 = 0x134a00008e830;
  local_48 = 0x140100000fec0;
  local_40 = 0x15f40000134c0;
  local_38 = 0x138e000014030;
  local_30 = 0x1445000029f30;
  local_28 = 0x2797000013980;
  local_110 = 0x6efd00;
  local_20 = 0x144f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_505 @ 0x10a8cb size=855 */
u32 * goldhen_offsets_505(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u64 local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u32 local_10c;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c0;
  u64 local_b8;
  u32 local_ac;
  u32 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4fa15c004f9048;
  local_f8 = 0x64b2b0006a2700;
  local_f0 = 0x237f3a0064b2d0;
  local_e8 = 0x8b4890000001c1e9;
  local_d8 = 0x90c3c031;
  local_c0 = 0x117c0000117b0;
  local_b8 = 0x1ea7670013f03f;
  local_1d8 = 0x63e3a10063e25d;
  local_1d0 = 0x63f7180063eafc;
  local_1c8 = 0x643da20064318b;
  local_1c0 = 0x62e96d00624065;
  local_1b8 = 0x64d4ff0064c720;
  local_1b0 = 0x6aad04006aaad5;
  local_90 = 0x7673e000194875;
  local_88 = 0x5081200011730;
  local_80 = 0x1921530019214a;
  local_78 = 0x6386270019215c;
  local_70 = 0x629b3000638639;
  local_e0 = 0x2b2620;
  local_ac = 0x1ea682;
  local_a4 = 0x1eab93;
  local_60 = 0x4f8c0;
  local_98 = 0x49da10;
  local_68 = 0x629a80;
  local_17c = 0x7b00;
  local_1a0 = 0x1a8fa0;
  local_198 = 0xee638e;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a7e,5);
  local_178 = 0x3c35a0003c33f;
  local_170 = 0x79980b0016d05b;
  local_168 = 0x94715b007e5a13;
  local_160 = 0x23747b0016d087;
  local_158 = 0x94718700799837;
  local_150 = 0x3e060200319a53;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a84,8);
  local_134 = 0xea96a7;
  local_130 = 0x593c7d009312a1;
  local_128 = 0xcb8c6006abe39;
  local_120 = 0x3ccb1000c791a0;
  local_118 = 0x75aef0003cf8d0;
  local_108 = 0x3ccb7900130a71;
  local_58 = 0x84c2000084c20;
  local_50 = 0x1266000089030;
  local_48 = 0x131900001e730;
  local_40 = 0xfa8000012680;
  local_38 = 0x12aa0000131b0;
  local_30 = 0x135d0000098c0;
  local_28 = 0xe0c000012b40;
  local_10c = 0x13097f;
  local_20 = 0x13670;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_671 @ 0x10aecb size=887 */
u32 * goldhen_offsets_671(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u64 local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x508d5c00507b09;
  local_f8 = 0x66aeb0006a8eb0;
  local_f0 = 0x1d895a0066aee0;
  local_e8 = 0x8b4890000001c7e9;
  local_d8 = 0x90c3c031;
  local_c0 = 0x233c5000233c40;
  local_b8 = 0x3c17f7000ad2e4;
  local_b0 = 0x3c1702003c1803;
  local_a8 = 0x3c1ca3003c170e;
  local_1d8 = 0x65930f006591bc;
  local_1d0 = 0x65a75800659ac6;
  local_1c8 = 0x6615710066092a;
  local_1c0 = 0x64aa3d00646ea5;
  local_1b8 = 0x66a31300669500;
  local_1b0 = 0x6ce141006cdf15;
  local_90 = 0x784120003cece1;
  local_88 = 0x2d265600233bd0;
  local_80 = 0x3cbbe9003cbbe0;
  local_78 = 0x654c75003cbbf2;
  local_70 = 0x63cdb000654c8b;
  local_e0 = 0x41a2d0;
  local_a0 = 0x3c1caf;
  local_60 = 0x394690;
  local_98 = 0x4aa310;
  local_68 = 0x63cc90;
  local_17c = 0x84e0;
  local_1a0 = 0x1a0900;
  local_198 = 0xec8291;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a8d,5);
  local_178 = 0x10c6ef0010c6d4;
  local_170 = 0x8355a200189602;
  local_168 = 0xa12af2008803f2;
  local_160 = 0x25410700189630;
  local_158 = 0xa12b20008355d0;
  local_150 = 0x3efcf00033943e;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196a93,8);
  local_134 = 0xfd2b51;
  local_130 = 0x606a0d009fb270;
  local_128 = 0xdd2a600726829;
  local_120 = 0x3db69000dddcb0;
  local_118 = 0x7ea100003decc0;
  local_110 = 0x149afd006d3d20;
  local_108 = 0x3db6f800149bf0;
  local_58 = 0x43542000435420;
  local_50 = 0x13a4000435830;
  local_48 = 0x145700001fd20;
  local_40 = 0x1054000013a60;
  local_38 = 0x13e8000014590;
  local_30 = 0x149b00000a0f0;
  local_28 = 0xeac000013f20;
  local_20 = 0x14a50;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_672 @ 0x10b4eb size=887 */
u32 * goldhen_offsets_672(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u64 local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x508d5c00507b09;
  local_f8 = 0x66aeb0006a8eb0;
  local_f0 = 0x1d895a0066aee0;
  local_e8 = 0x8b4890000001c7e9;
  local_d8 = 0x90c3c031;
  local_c0 = 0x233c5000233c40;
  local_b8 = 0x3c17f7000ad2e4;
  local_b0 = 0x3c1702003c1803;
  local_a8 = 0x3c1ca3003c170e;
  local_1d8 = 0x65930f006591bc;
  local_1d0 = 0x65a75800659ac6;
  local_1c8 = 0x6615710066092a;
  local_1c0 = 0x64aa3d00646ea5;
  local_1b8 = 0x66a31300669500;
  local_1b0 = 0x6ce141006cdf15;
  local_90 = 0x784120003cece1;
  local_88 = 0x2d265600233bd0;
  local_80 = 0x3cbbe9003cbbe0;
  local_78 = 0x654c75003cbbf2;
  local_70 = 0x63cdb000654c8b;
  local_e0 = 0x41a2d0;
  local_a0 = 0x3c1caf;
  local_60 = 0x394690;
  local_98 = 0x4aa310;
  local_68 = 0x63cc90;
  local_17c = 0x84e0;
  local_1a0 = 0x1a0900;
  local_198 = 0xec8291;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196a9c,5);
  local_178 = 0x10c6ef0010c6d4;
  local_170 = 0x83564200189602;
  local_168 = 0xa12b9200880492;
  local_160 = 0x25410700189630;
  local_158 = 0xa12bc000835670;
  local_150 = 0x3efcf00033943e;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196aa2,8);
  local_134 = 0xfd2bf1;
  local_130 = 0x606a0d009fb311;
  local_128 = 0xdd2a6007268c9;
  local_120 = 0x3db69000dddd50;
  local_118 = 0x7ea1a0003decc0;
  local_110 = 0x149afd006d3d20;
  local_108 = 0x3db6f800149bf0;
  local_58 = 0x43542000435420;
  local_50 = 0x13a4000435830;
  local_48 = 0x145700001fd20;
  local_40 = 0x1054000013a60;
  local_38 = 0x13e8000014590;
  local_30 = 0x149b00000a0f0;
  local_28 = 0xeac000013f20;
  local_20 = 0x14a50;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_702 @ 0x10bb0b size=894 */
u32 * goldhen_offsets_702(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x50296c005016fa;
  local_f8 = 0x668270006be880;
  local_f0 = 0x9547b006682a0;
  local_e8 = 0x8b4890000001bde9;
  local_d8 = 0x90c3c031;
  local_c4 = 0x1cb8f000264c08;
  local_bc = 0x1d40bb001cb910;
  local_b4 = 0x2f2930002f287;
  local_ac = 0x2f19e0002f192;
  local_a4 = 0x2f73f0002f733;
  local_1d8 = 0x65eacf0065e97c;
  local_1d0 = 0x65fef80065f256;
  local_1c8 = 0x65d6690065ca0d;
  local_1c0 = 0x64989d0063e2d5;
  local_1b8 = 0x66985e00668a50;
  local_1b0 = 0x6b557c006b534b;
  local_90 = 0x7889e0000c1f9a;
  local_88 = 0x2761c6001cb880;
  local_80 = 0xbee7a000bee71;
  local_78 = 0x653af5000bee83;
  local_70 = 0x63b1c000653b0b;
  local_e0 = 0x2f2c20;
  local_60 = 0x34ac10;
  local_98 = 0x4aaed0;
  local_68 = 0x63b0a0;
  local_17c = 0x83d0;
  local_1a0 = g_bytes_00191220;
  local_198 = 0xecc9a1;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196aab,5);
  local_178 = 0x10b35e0010b343;
  local_170 = 0x7f5d0000174260;
  local_168 = 0x9ce10000840132;
  local_160 = 0x23a6fc0017428a;
  local_158 = 0x9ce12a007f5d2a;
  local_150 = 0x3c590000318fe1;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196ab1,8);
  local_134 = 0xf5e9b1;
  local_130 = 0x5c6aad009b6c41;
  local_128 = 0xd61f6006e85a9;
  local_120 = 0x3b3ad000d629a0;
  local_118 = 0x7aaed0003b6270;
  local_110 = 0x13ce3d00695aa0;
  local_108 = 0x3b3b380013cf20;
  local_58 = 0x8d4200008d420;
  local_50 = 0x136e00008d830;
  local_48 = 0x142100001f9b0;
  local_40 = 0x103c000013700;
  local_38 = 0x13b2000014230;
  local_30 = 0x1465000009ff0;
  local_28 = 0xe99000013bc0;
  local_20 = 0x146f0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_750 @ 0x10c132 size=923 */
u32 * goldhen_offsets_750(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u8 *local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x50059c004ff322;
  local_f8 = 0x668140006dd970;
  local_f0 = 0x4523c400668170;
  local_e8 = 0x8b4890000001c8e9;
  local_d8 = 0x90c3c031;
  local_d0 = 0x45235300452343;
  local_c8 = 0x3014c800452373;
  local_c0 = 0x364d6000364d40;
  local_b8 = 0x28fa47000dced1;
  local_b0 = 0x28f9520028fa53;
  local_a8 = 0x28fef30028f95e;
  local_1d8 = 0x65a66e0065a51c;
  local_1d0 = 0x65bae90065ae06;
  local_1c8 = 0x658d48006580fd;
  local_1c0 = 0x644cfd0063e485;
  local_1b8 = 0x66759e006667d0;
  local_1b0 = 0x6d9958006d9727;
  local_90 = 0x77f96000218af4;
  local_88 = 0x31a8f600364cd0;
  local_80 = 0x21597a00215971;
  local_78 = 0x651b5500215983;
  local_70 = 0x6378a000651b6b;
  local_e0 = 0x29a30;
  local_a0 = 0x28feff;
  local_60 = str_j_1y_g_k_g_1_k_b_1g_1o_0_1g_;
  local_98 = 0x4a6c70;
  local_68 = 0x637780;
  local_17c = 0x8300;
  local_1a0 = g_bytes_0018e120;
  local_198 = 0xec6491;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196aba,5);
  local_178 = 0x10a1550010a13a;
  local_170 = 0x7fbf7000168a90;
  local_168 = 0x9d31d00084afb2;
  local_160 = 0x23ce4800168aba;
  local_158 = 0x9d31fa007fbf9a;
  local_150 = 0x3c244f00316bc3;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196ac0,8);
  local_134 = 0xf66891;
  local_130 = 0x5bcf2d009bc1c1;
  local_128 = 0xcd6b6006e7d29;
  local_120 = 0x3b0ae000d57ee0;
  local_118 = 0x7ae020003b3200;
  local_110 = 0x132f9d006951f0;
  local_108 = 0x3b0b4700133080;
  local_58 = 0x8d4200008d420;
  local_50 = 0x136300008d830;
  local_48 = 0x141600001fa70;
  local_40 = 0x1038000013650;
  local_38 = 0x13a7000014180;
  local_30 = 0x145a000009f10;
  local_28 = 0xe96000013b10;
  local_20 = 0x14640;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_751 @ 0x10c776 size=923 */
u32 * goldhen_offsets_751(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u8 *local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x50059c004ff322;
  local_f8 = 0x668140006dd9a0;
  local_f0 = 0x4523c400668170;
  local_e8 = 0x8b4890000001c8e9;
  local_d8 = 0x90c3c031;
  local_d0 = 0x45235300452343;
  local_c8 = 0x3014c800452373;
  local_c0 = 0x364d6000364d40;
  local_b8 = 0x28fa47000dced1;
  local_b0 = 0x28f9520028fa53;
  local_a8 = 0x28fef30028f95e;
  local_1d8 = 0x65a66e0065a51c;
  local_1d0 = 0x65bae90065ae06;
  local_1c8 = 0x658d48006580fd;
  local_1c0 = 0x644cfd0063e485;
  local_1b8 = 0x66759e006667d0;
  local_1b0 = 0x6d9988006d9757;
  local_90 = 0x77f9a000218af4;
  local_88 = 0x31a8f600364cd0;
  local_80 = 0x21597a00215971;
  local_78 = 0x651b5500215983;
  local_70 = 0x6378a000651b6b;
  local_e0 = 0x29a30;
  local_a0 = 0x28feff;
  local_60 = str_j_1y_g_k_g_1_k_b_1g_1o_0_1g_;
  local_98 = 0x4a6c70;
  local_68 = 0x637780;
  local_17c = 0x8300;
  local_1a0 = g_bytes_0018e120;
  local_198 = 0xec66e1;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196ac9,5);
  local_178 = 0x10a1550010a13a;
  local_170 = 0x7fbf0000168a90;
  local_168 = 0x9d31500084af42;
  local_160 = 0x23ce4800168aba;
  local_158 = 0x9d317a007fbf2a;
  local_150 = 0x3c244f00316bc3;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196acf,8);
  local_134 = 0xf66811;
  local_130 = 0x5bcf2d009bc141;
  local_128 = 0xcd6b6006e7d29;
  local_120 = 0x3b0ae000d57e60;
  local_118 = 0x7adfb0003b3200;
  local_110 = 0x132f9d006951f0;
  local_108 = 0x3b0b4700133080;
  local_58 = 0x8d4200008d420;
  local_50 = 0x136300008d830;
  local_48 = 0x141600001fa70;
  local_40 = 0x1038000013650;
  local_38 = 0x13a7000014180;
  local_30 = 0x145a000009f10;
  local_28 = 0xe96000013b10;
  local_20 = 0x14640;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_755 @ 0x10cdba size=894 */
u32 * goldhen_offsets_755(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u8 *local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x50059c004ff322;
  local_f8 = 0x668140006dd9a0;
  local_f0 = 0x4523c400668170;
  local_e8 = 0x8b4890000001c8e9;
  local_d8 = 0x90c3c031;
  local_c4 = 0x364d40003014c8;
  local_bc = 0xdced100364d60;
  local_b4 = 0x28fa530028fa47;
  local_ac = 0x28f95e0028f952;
  local_a4 = 0x28feff0028fef3;
  local_1d8 = 0x65a66e0065a51c;
  local_1d0 = 0x65bae90065ae06;
  local_1c8 = 0x658d48006580fd;
  local_1c0 = 0x644cfd0063e485;
  local_1b8 = 0x66759e006667d0;
  local_1b0 = 0x6d9988006d9757;
  local_90 = 0x77f9a000218af4;
  local_88 = 0x31a8f600364cd0;
  local_80 = 0x21597a00215971;
  local_78 = 0x651b5500215983;
  local_70 = 0x6378a000651b6b;
  local_e0 = 0x29a30;
  local_60 = str_j_1y_g_k_g_1_k_b_1g_1o_0_1g_;
  local_98 = 0x4a6c70;
  local_68 = 0x637780;
  local_17c = 0x8300;
  local_1a0 = g_bytes_0018e120;
  local_198 = 0xec66e1;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196ad8,5);
  local_178 = 0x10a1550010a13a;
  local_170 = 0x7fbf0000168a90;
  local_168 = 0x9d31500084af42;
  local_160 = 0x23ce4800168aba;
  local_158 = 0x9d317a007fbf2a;
  local_150 = 0x3c244f00316bc3;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196ade,8);
  local_134 = 0xf66831;
  local_130 = 0x5bcf2d009bc141;
  local_128 = 0xcd6b6006e7d29;
  local_120 = 0x3b0ae000d57e60;
  local_118 = 0x7adfb0003b3200;
  local_110 = 0x132f9d006951f0;
  local_108 = 0x3b0b4700133080;
  local_58 = 0x8d4200008d420;
  local_50 = 0x136300008d830;
  local_48 = 0x141600001fa70;
  local_40 = 0x1038000013650;
  local_38 = 0x13a7000014180;
  local_30 = 0x145a000009f10;
  local_28 = 0xe96000013b10;
  local_20 = 0x14640;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_800 @ 0x10d3e1 size=888 */
u32 * goldhen_offsets_800(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e584c004e45d8;
  local_f8 = 0x64df0000681dd0;
  local_f0 = 0x31953f0064df30;
  local_d8 = 0x90c3c031;
  local_c4 = 0x1d5780003ec68b;
  local_bc = 0xfed61001d57a0;
  local_b4 = 0x25e4130025e407;
  local_ac = 0x25e31e0025e312;
  local_a4 = 0x25e8bf0025e8b3;
  local_1d8 = 0x63ba0e0063b8bc;
  local_1d0 = 0x63ce890063c1a6;
  local_1c8 = 0x6401d80063f59d;
  local_1c0 = 0x61f40d00628055;
  local_1b8 = 0x64d35e0064c590;
  local_1b0 = 0x68d73a0068d509;
  local_90 = 0x766df0002856f4;
  local_88 = 0x1b0b6001d5710;
  local_80 = 0x2825fa002825f1;
  local_78 = 0x636c5500282603;
  local_70 = 0x62d71000636c6b;
  local_e8 = 0x4ceb;
  local_e0 = 0x951c0;
  local_60 = 0x1dc290;
  local_98 = 0x48da70;
  local_68 = 0x62d5f0;
  local_17c = 0x82f0;
  local_1a0 = g_bytes_00187300;
  local_198 = 0xedb201;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196ae7,5);
  local_178 = 0x10c4e60010c4cb;
  local_170 = 0x84cfd000168d20;
  local_168 = 0xa235e00089c132;
  local_160 = 0x24297800168d4a;
  local_158 = 0xa2360a0084cffa;
  local_150 = 0x3d1a2f0031c503;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196aed,8);
  local_134 = 0xfc61f1;
  local_130 = 0x60756d00a0c5c1;
  local_128 = 0xcf3f60072d5b9;
  local_120 = 0x3c028000da7480;
  local_118 = 0x7fa6f0003c2970;
  local_110 = 0x133480006d9f80;
  local_108 = 0x3c02e700133570;
  local_58 = 0x8d4200008d420;
  local_50 = 0x135d00008d830;
  local_48 = 0x141000001f920;
  local_40 = 0x10270000135f0;
  local_38 = 0x13a1000014120;
  local_30 = 0x1454000009f60;
  local_28 = 0xe85000013ab0;
  local_20 = 0x145e0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_801 @ 0x10da02 size=917 */
u32 * goldhen_offsets_801(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e584c004e45d8;
  local_f8 = 0x64df0000681dd0;
  local_f0 = 0x31953f0064df30;
  local_d8 = 0x90c3c031;
  local_d0 = 0x3192d3003192c3;
  local_c8 = 0x3ec68b003192f3;
  local_c0 = 0x1d57a0001d5780;
  local_b8 = 0x25e407000fed61;
  local_b0 = 0x25e3120025e413;
  local_a8 = 0x25e8b30025e31e;
  local_1d8 = 0x63ba0e0063b8bc;
  local_1d0 = 0x63ce890063c1a6;
  local_1c8 = 0x6401d80063f59d;
  local_1c0 = 0x61f40d00628055;
  local_1b8 = 0x64d35e0064c590;
  local_1b0 = 0x68d73a0068d509;
  local_90 = 0x766df0002856f4;
  local_88 = 0x1b0b6001d5710;
  local_80 = 0x2825fa002825f1;
  local_78 = 0x636c5500282603;
  local_70 = 0x62d71000636c6b;
  local_e8 = 0x4ceb;
  local_e0 = 0x951c0;
  local_a0 = 0x25e8bf;
  local_60 = 0x1dc290;
  local_98 = 0x48da70;
  local_68 = 0x62d5f0;
  local_17c = 0x82f0;
  local_1a0 = g_bytes_00187300;
  local_198 = 0xedb1b1;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196af6,5);
  local_178 = 0x10c4e60010c4cb;
  local_170 = 0x84cfd000168d20;
  local_168 = 0xa235e00089c132;
  local_160 = 0x24297800168d4a;
  local_158 = 0xa2360a0084cffa;
  local_150 = 0x3d1a2f0031c503;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196afc,8);
  local_134 = 0xfc61f1;
  local_130 = 0x60756d00a0c5c1;
  local_128 = 0xcf3f60072d5b9;
  local_120 = 0x3c028000da7480;
  local_118 = 0x7fa6f0003c2970;
  local_110 = 0x133480006d9f80;
  local_108 = 0x3c02e700133570;
  local_58 = 0x8d4200008d420;
  local_50 = 0x135d00008d830;
  local_48 = 0x141000001f920;
  local_40 = 0x10270000135f0;
  local_38 = 0x13a1000014120;
  local_30 = 0x1454000009f60;
  local_28 = 0xe85000013ab0;
  local_20 = 0x145e0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_803 @ 0x10e040 size=917 */
u32 * goldhen_offsets_803(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e584c004e45d8;
  local_f8 = 0x64df0000681dd0;
  local_f0 = 0x31953f0064df30;
  local_d8 = 0x90c3c031;
  local_d0 = 0x3192d3003192c3;
  local_c8 = 0x3ec68b003192f3;
  local_c0 = 0x1d57a0001d5780;
  local_b8 = 0x25e407000fed61;
  local_b0 = 0x25e3120025e413;
  local_a8 = 0x25e8b30025e31e;
  local_1d8 = 0x63ba0e0063b8bc;
  local_1d0 = 0x63ce890063c1a6;
  local_1c8 = 0x6401d80063f59d;
  local_1c0 = 0x61f40d00628055;
  local_1b8 = 0x64d35e0064c590;
  local_1b0 = 0x68d73a0068d509;
  local_90 = 0x766df0002856f4;
  local_88 = 0x1b0b6001d5710;
  local_80 = 0x2825fa002825f1;
  local_78 = 0x636c5500282603;
  local_70 = 0x62d71000636c6b;
  local_e8 = 0x4ceb;
  local_e0 = 0x951c0;
  local_a0 = 0x25e8bf;
  local_60 = 0x1dc290;
  local_98 = 0x48da70;
  local_68 = 0x62d5f0;
  local_17c = 0x82f0;
  local_1a0 = g_bytes_00187300;
  local_198 = 0xedb6b1;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b05,5);
  local_178 = 0x10c4e60010c4cb;
  local_170 = 0x84d08000168d20;
  local_168 = 0xa236a00089c1e2;
  local_160 = 0x24297800168d4a;
  local_158 = 0xa236ca0084d0aa;
  local_150 = 0x3d1a2f0031c503;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b0b,8);
  local_134 = 0xfc62b1;
  local_130 = 0x60761d00a0c681;
  local_128 = 0xcf3f60072d669;
  local_120 = 0x3c028000da7540;
  local_118 = 0x7fa7a0003c2970;
  local_110 = 0x133480006da030;
  local_108 = 0x3c02e700133570;
  local_58 = 0x8d4200008d420;
  local_50 = 0x135d00008d830;
  local_48 = 0x141000001f920;
  local_40 = 0x10270000135f0;
  local_38 = 0x13a1000014120;
  local_30 = 0x1454000009f60;
  local_28 = 0xe85000013ab0;
  local_20 = 0x145e0;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_850 @ 0x10e67e size=917 */
u32 * goldhen_offsets_850(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4eb36c004ea0f8;
  local_f8 = 0x64dc6000683f40;
  local_f0 = 0x17c2f0064dc90;
  local_d8 = 0x90c3c031;
  local_d0 = 0x179c3000179b3;
  local_c8 = 0x14d6db000179e3;
  local_c0 = 0x29367000293650;
  local_b8 = 0x3a433700084411;
  local_b0 = 0x3a4242003a4343;
  local_a8 = 0x3a47e3003a424e;
  local_1d8 = 0x64258e0064243c;
  local_1d0 = 0x643a0900642d26;
  local_1c8 = 0x641338006406fd;
  local_1c0 = 0x621ebd0062ef35;
  local_1b8 = 0x64d0be0064c2f0;
  local_1b0 = 0x6a095a006a0729;
  local_90 = 0x76ceb000215154;
  local_88 = 0x164e36002935e0;
  local_80 = 0x21205a00212051;
  local_78 = 0x6380f500212063;
  local_70 = 0x624b300063810b;
  local_e8 = 0x4ceb;
  local_e0 = 0x3ad040;
  local_a0 = 0x3a47ef;
  local_60 = 0xb3970;
  local_98 = 0x48d550;
  local_68 = 0x624a10;
  local_17c = 0x8380;
  local_1a0 = g_bytes_001888c0;
  local_198 = 0xeda401;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b14,5);
  local_178 = 0xfc5e6000fc5cb;
  local_170 = 0x84f5a00016c3d0;
  local_168 = 0xa15c800089e962;
  local_160 = 0x2471080016c3fa;
  local_158 = 0xa15caa0084f5ca;
  local_150 = 0x3d3adf00320713;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b1a,8);
  local_134 = 0xfbc331;
  local_130 = 0x607c8d009feb91;
  local_128 = 0xcfca60072fa29;
  local_120 = 0x3c1df000d9b890;
  local_118 = 0x7fdd60003c44c0;
  local_110 = 0x136e60006dc090;
  local_108 = 0x3c1e5700136f50;
  local_58 = 0x8943000089430;
  local_50 = 0x136600008d830;
  local_48 = 0x1419000018d50;
  local_40 = 0x86c000013680;
  local_38 = 0x13aa0000141b0;
  local_30 = 0x145d0000286a0;
  local_28 = 0x26a0000013b40;
  local_20 = 0x14670;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_852 @ 0x10ecbc size=917 */
u32 * goldhen_offsets_852(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4eb36c004ea0f8;
  local_f8 = 0x64dc6000683f40;
  local_f0 = 0x17c2f0064dc90;
  local_d8 = 0x90c3c031;
  local_d0 = 0x179c3000179b3;
  local_c8 = 0x14d6db000179e3;
  local_c0 = 0x29367000293650;
  local_b8 = 0x3a433700084411;
  local_b0 = 0x3a4242003a4343;
  local_a8 = 0x3a47e3003a424e;
  local_1d8 = 0x64258e0064243c;
  local_1d0 = 0x643a0900642d26;
  local_1c8 = 0x641338006406fd;
  local_1c0 = 0x621ebd0062ef35;
  local_1b8 = 0x64d0be0064c2f0;
  local_1b0 = 0x6a095a006a0729;
  local_90 = 0x76ceb000215154;
  local_88 = 0x164e36002935e0;
  local_80 = 0x21205a00212051;
  local_78 = 0x6380f500212063;
  local_70 = 0x624b300063810b;
  local_e8 = 0x4ceb;
  local_e0 = 0x3ad040;
  local_a0 = 0x3a47ef;
  local_60 = 0xb3970;
  local_98 = 0x48d550;
  local_68 = 0x624a10;
  local_17c = 0x8380;
  local_1a0 = g_bytes_001888c0;
  local_198 = 0xeda401;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b23,5);
  local_178 = 0xfc5e6000fc5cb;
  local_170 = 0x84f5c00016c3d0;
  local_168 = 0xa15ca00089e982;
  local_160 = 0x2471080016c3fa;
  local_158 = 0xa15cca0084f5ea;
  local_150 = 0x3d3adf00320713;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b29,8);
  local_134 = 0xfbc371;
  local_130 = 0x607cad009febb1;
  local_128 = 0xcfca60072fa49;
  local_120 = 0x3c1df000d9b8b0;
  local_118 = 0x7fdd80003c44c0;
  local_110 = 0x136e60006dc0b0;
  local_108 = 0x3c1e5700136f50;
  local_58 = 0x8943000089430;
  local_50 = 0x136600008d830;
  local_48 = 0x1419000018d50;
  local_40 = 0x86c000013680;
  local_38 = 0x13aa0000141b0;
  local_30 = 0x145d0000286b0;
  local_28 = 0x26a1000013b40;
  local_20 = 0x14670;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_900 @ 0x10f2fa size=888 */
u32 * goldhen_offsets_900(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ea12f004e8e48;
  local_f8 = 0x650430006885c0;
  local_f0 = 0x23b67f00650460;
  local_d8 = 0x90c3c031;
  local_c4 = 0x8bc9000080b8b;
  local_bc = 0x1680510008bcb0;
  local_b4 = 0x271703002716f7;
  local_ac = 0x27160e00271602;
  local_a4 = 0x271baf00271ba3;
  local_1d8 = 0x64488e0064473c;
  local_1d0 = 0x645d0900645026;
  local_1c8 = 0x642f680064232d;
  local_1c0 = 0x62084d00624a15;
  local_1b8 = 0x64ee3e0064e070;
  local_1b0 = 0x6c412a006c3ef9;
  local_90 = 0x767e300005f824;
  local_88 = 0x3ab7060008bc20;
  local_80 = 0x5c72a0005c721;
  local_78 = 0x6391950005c733;
  local_70 = 0x626d30006391ab;
  local_e8 = 0x4ceb;
  local_e0 = 0x221b40;
  local_60 = 0x255e10;
  local_98 = 0x48d900;
  local_68 = 0x626c10;
  local_17c = 0x8380;
  local_1a0 = g_bytes_00188c10;
  local_198 = 0xee55c1;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b32,5);
  local_178 = 0x1003b60010039b;
  local_170 = 0x8621d40016eaa4;
  local_168 = 0xa27bd4008afbc2;
  local_160 = 0x249f7b0016ead2;
  local_158 = 0xa27c0200862202;
  local_150 = 0x3d7aff0032079b;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b38,8);
  local_134 = 0xfd3211;
  local_130 = 0x6180fd00a10a81;
  local_128 = 0xd186600743299;
  local_120 = 0x3c5e4000db0b60;
  local_118 = 0x810fc0003c8540;
  local_110 = 0x138da0006efec0;
  local_108 = 0x3c5ea700138e90;
  local_58 = 0x8e4300008e430;
  local_50 = 0x136600008e830;
  local_48 = 0x14190000087f0;
  local_40 = 0x1a58000013680;
  local_38 = 0x13aa0000141b0;
  local_30 = 0x145d0000204c0;
  local_28 = 0x1be1000013b40;
  local_20 = 0x14670;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_903 @ 0x10f91b size=917 */
u32 * goldhen_offsets_903(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e802f004e6d48;
  local_f8 = 0x64e3f000686580;
  local_f0 = 0x23b34f0064e420;
  local_d8 = 0x90c3c031;
  local_d0 = 0x23b0e30023b0d3;
  local_c8 = 0x80b8b0023b103;
  local_c0 = 0x8bcb00008bc90;
  local_b8 = 0x27137700168001;
  local_b0 = 0x27128200271383;
  local_a8 = 0x2718230027128e;
  local_1d8 = 0x64284e006426fc;
  local_1d0 = 0x643cc900642fe6;
  local_1c8 = 0x640f28006402ed;
  local_1c0 = 0x61e80d006229d5;
  local_1b8 = 0x64cdfe0064c030;
  local_1b0 = 0x6c20ea006c1eb9;
  local_90 = 0x765df00005f824;
  local_88 = 0x3a99060008bc20;
  local_80 = 0x5c72a0005c721;
  local_78 = 0x6371550005c733;
  local_70 = 0x624cf00063716b;
  local_e8 = 0x4ceb;
  local_e0 = 0x221810;
  local_a0 = 0x27182f;
  local_60 = 0x255ae0;
  local_98 = 0x48b800;
  local_68 = 0x624bd0;
  local_17c = 0x8380;
  local_1a0 = g_bytes_00188c10;
  local_198 = 0xee5651;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b41,5);
  local_178 = 0x1003b60010039b;
  local_170 = 0x8647440016f014;
  local_168 = 0xa2a254008b2232;
  local_160 = 0x24a4eb0016f042;
  local_158 = 0xa2a28200864772;
  local_150 = 0x3da06f00321f2b;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b47,8);
  local_134 = 0xfd5bd1;
  local_130 = 0x61a66d00a13101;
  local_128 = 0xd195600745809;
  local_120 = 0x3c83b000db31e0;
  local_118 = 0x813530003caab0;
  local_110 = 0x139310006f2430;
  local_108 = 0x3c841700139400;
  local_58 = 0x8e4300008e430;
  local_50 = 0x136600008e830;
  local_48 = 0x14190000087f0;
  local_40 = 0x1a58000013680;
  local_38 = 0x13aa0000141b0;
  local_30 = 0x145d0000204c0;
  local_28 = 0x1be1000013b40;
  local_20 = 0x14670;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_904 @ 0x10ff59 size=917 */
u32 * goldhen_offsets_904(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  u8 *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4e802f004e6d48;
  local_f8 = 0x64e3f000686580;
  local_f0 = 0x23b34f0064e420;
  local_d8 = 0x90c3c031;
  local_d0 = 0x23b0e30023b0d3;
  local_c8 = 0x80b8b0023b103;
  local_c0 = 0x8bcb00008bc90;
  local_b8 = 0x27137700168001;
  local_b0 = 0x27128200271383;
  local_a8 = 0x2718230027128e;
  local_1d8 = 0x64284e006426fc;
  local_1d0 = 0x643cc900642fe6;
  local_1c8 = 0x640f28006402ed;
  local_1c0 = 0x61e80d006229d5;
  local_1b8 = 0x64cdfe0064c030;
  local_1b0 = 0x6c20ea006c1eb9;
  local_90 = 0x765df00005f824;
  local_88 = 0x3a99060008bc20;
  local_80 = 0x5c72a0005c721;
  local_78 = 0x6371550005c733;
  local_70 = 0x624cf00063716b;
  local_e8 = 0x4ceb;
  local_e0 = 0x221810;
  local_a0 = 0x27182f;
  local_60 = 0x255ae0;
  local_98 = 0x48b800;
  local_68 = 0x624bd0;
  local_17c = 0x8380;
  local_1a0 = g_bytes_00188c10;
  local_198 = 0xee5651;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b50,5);
  local_178 = 0x1003b60010039b;
  local_170 = 0x8647740016f014;
  local_168 = 0xa2a274008b2262;
  local_160 = 0x24a4eb0016f042;
  local_158 = 0xa2a2a2008647a2;
  local_150 = 0x3da06f00321f2b;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b56,8);
  local_134 = 0xfd5bf1;
  local_130 = 0x61a69d00a13121;
  local_128 = 0xd195600745839;
  local_120 = 0x3c83b000db3200;
  local_118 = 0x813560003caab0;
  local_110 = 0x139310006f2460;
  local_108 = 0x3c841700139400;
  local_58 = 0x8e4300008e430;
  local_50 = 0x136600008e830;
  local_48 = 0x14190000087f0;
  local_40 = 0x1a58000013680;
  local_38 = 0x13aa0000141b0;
  local_30 = 0x145d0000204c0;
  local_28 = 0x1be1000013b40;
  local_20 = 0x14670;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_950 @ 0x110597 size=911 */
u32 * goldhen_offsets_950(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  char *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ea06f004e9038;
  local_f8 = 0x643ea0006aac00;
  local_f0 = 0x19fedf00643ed0;
  local_d8 = 0x90c3c031;
  local_d0 = 0x19fc730019fc63;
  local_c8 = 0x196d3b0019fc93;
  local_c0 = 0x3262000032600;
  local_b8 = 0x201f0700124aa1;
  local_b0 = 0x201e1200201f13;
  local_a8 = 0x2023b300201e1e;
  local_1d8 = 0x63923e006390ec;
  local_1d0 = 0x63a6b9006399d6;
  local_1c8 = 0x637028006363ed;
  local_1c0 = 0x61afad0061f495;
  local_1b8 = 0x646b9e00645dd0;
  local_1b0 = 0x6a6c1a006a69e9;
  local_90 = 0x7603c00029ae74;
  local_88 = 0x115ee600032590;
  local_80 = 0x297d7a00297d71;
  local_78 = 0x62fef500297d83;
  local_70 = 0x624fa00062ff0b;
  local_e8 = 0x4ceb;
  local_e0 = 0x11960;
  local_a0 = 0x2023bf;
  local_60 = 0x1b49f0;
  local_98 = 0x48c820;
  local_68 = 0x624e80;
  local_17c = 0x8260;
  local_1a0 = "ntScene";
  local_198 = 0xeefc61;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b5f,5);
  local_178 = 0xea0d0000ea0b5;
  local_170 = 0x861be40016c364;
  local_168 = 0xa10e04008b07e2;
  local_160 = 0x248fec0016c392;
  local_158 = 0xa10e3200861c12;
  local_150 = 0x3d3b2f0031c2e1;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b65,8);
  local_134 = 0xfbb8d9;
  local_130 = 0x60f71d009fa351;
  local_128 = 0xcf68600740949;
  local_120 = 0x3c0bc000d982d0;
  local_118 = 0x812e30003c3e70;
  local_108 = 0x3c0c2700135760;
  local_58 = 0x8a4300008a430;
  local_50 = 0x132f00008e830;
  local_48 = 0x13e200000aa60;
  local_40 = 0x241e000013310;
  local_38 = 0x1373000013e40;
  local_30 = 0x1426000017160;
  local_28 = 0x7170000137d0;
  local_110 = 0x6e7a50;
  local_20 = 0x14300;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_951 @ 0x110bcf size=911 */
u32 * goldhen_offsets_951(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  char *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_d0;
  u64 local_c8;
  u64 local_c0;
  u64 local_b8;
  u64 local_b0;
  u64 local_a8;
  u32 local_a0;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ea06f004e9038;
  local_f8 = 0x643ea0006aac00;
  local_f0 = 0x19fedf00643ed0;
  local_d8 = 0x90c3c031;
  local_d0 = 0x19fc730019fc63;
  local_c8 = 0x196d3b0019fc93;
  local_c0 = 0x3262000032600;
  local_b8 = 0x201f0700124aa1;
  local_b0 = 0x201e1200201f13;
  local_a8 = 0x2023b300201e1e;
  local_1d8 = 0x63923e006390ec;
  local_1d0 = 0x63a6b9006399d6;
  local_1c8 = 0x637028006363ed;
  local_1c0 = 0x61afad0061f495;
  local_1b8 = 0x646b9e00645dd0;
  local_1b0 = 0x6a6c1a006a69e9;
  local_90 = 0x7603c00029ae74;
  local_88 = 0x115ee600032590;
  local_80 = 0x297d7a00297d71;
  local_78 = 0x62fef500297d83;
  local_70 = 0x624fa00062ff0b;
  local_e8 = 0x4ceb;
  local_e0 = 0x11960;
  local_a0 = 0x2023bf;
  local_60 = 0x1b49f0;
  local_98 = 0x48c820;
  local_68 = 0x624e80;
  local_17c = 0x8260;
  local_1a0 = "ntScene";
  local_198 = 0xeefc61;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b6e,5);
  local_178 = 0xea0d0000ea0b5;
  local_170 = 0x861c140016c364;
  local_168 = 0xa10e24008b0812;
  local_160 = 0x24901c0016c392;
  local_158 = 0xa10e5200861c42;
  local_150 = 0x3d3b5f0031c311;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b74,8);
  local_134 = 0xfbb939;
  local_130 = 0x60f74d009fa371;
  local_128 = 0xcf68600740979;
  local_120 = 0x3c0bf000d982f0;
  local_118 = 0x812e60003c3ea0;
  local_108 = 0x3c0c5700135760;
  local_58 = 0x8a4300008a430;
  local_50 = 0x132f00008e830;
  local_48 = 0x13e200000aa60;
  local_40 = 0x241e000013310;
  local_38 = 0x1373000013e40;
  local_30 = 0x1426000017160;
  local_28 = 0x7170000137d0;
  local_110 = 0x6e7a80;
  local_20 = 0x14300;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* goldhen_offsets_960 @ 0x111207 size=882 */
u32 * goldhen_offsets_960(u32 *param_1)

{
  s64 lVar1;
  u32 *puVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 local_1e0 [2];
  u64 local_1d8;
  u64 local_1d0;
  u64 local_1c8;
  u64 local_1c0;
  u64 local_1b8;
  u64 local_1b0;
  char *local_1a0;
  u64 local_198;
  u8 local_190 [16];
  u8 local_180;
  u32 local_17c;
  u64 local_178;
  u64 local_170;
  u64 local_168;
  u64 local_160;
  u64 local_158;
  u64 local_150;
  u8 local_148 [16];
  u8 local_138;
  u32 local_134;
  u64 local_130;
  u64 local_128;
  u64 local_120;
  u64 local_118;
  u64 local_110;
  u64 local_108;
  u64 local_100;
  u64 local_f8;
  u64 local_f0;
  u64 local_e8;
  u32 local_e0;
  u64 local_d8;
  u64 local_c4;
  u64 local_bc;
  u64 local_b4;
  u64 local_ac;
  u64 local_a4;
  u64 local_98;
  u64 local_90;
  u64 local_88;
  u64 local_80;
  u64 local_78;
  u64 local_70;
  u32 local_68;
  u64 local_60;
  u64 local_58;
  u64 local_50;
  u64 local_48;
  u64 local_40;
  u64 local_38;
  u64 local_30;
  u64 local_28;
  u32 local_20;
  
  bVar4 = 0;
  local_100 = 0x4ea06f004e9038;
  local_f8 = 0x643ea0006aac00;
  local_f0 = 0x19fedf00643ed0;
  local_d8 = 0x90c3c031;
  local_c4 = 0x3260000196d3b;
  local_bc = 0x124aa100032620;
  local_b4 = 0x201f1300201f07;
  local_ac = 0x201e1e00201e12;
  local_a4 = 0x2023bf002023b3;
  local_1d8 = 0x63923e006390ec;
  local_1d0 = 0x63a6b9006399d6;
  local_1c8 = 0x637028006363ed;
  local_1c0 = 0x61afad0061f495;
  local_1b8 = 0x646b9e00645dd0;
  local_1b0 = 0x6a6c1a006a69e9;
  local_90 = 0x7603c00029ae74;
  local_88 = 0x115ee600032590;
  local_80 = 0x297d7a00297d71;
  local_78 = 0x62fef500297d83;
  local_70 = 0x624fa00062ff0b;
  local_e8 = 0x4ceb;
  local_e0 = 0x11960;
  local_60 = 0x1b49f0;
  local_98 = 0x48c820;
  local_68 = 0x624e80;
  local_17c = 0x8260;
  local_1a0 = "ntScene";
  local_198 = 0xeeff41;
  local_180 = 5;
  _memcpy(local_190,g_bytes_00196b7d,5);
  local_178 = 0xea0d0000ea0b5;
  local_170 = 0x8630a40016cd64;
  local_168 = 0xa122c4008b1ca2;
  local_160 = 0x24a35c0016cd92;
  local_158 = 0xa122f2008630d2;
  local_150 = 0x3d4e9f0031d651;
  local_138 = 8;
  _memcpy(local_148,g_bytes_00196b83,8);
  local_134 = 0xfbd319;
  local_130 = 0x610aed009fb811;
  local_128 = 0xcf77600741e09;
  local_120 = 0x3c1f3000d99b00;
  local_118 = 0x8142f0003c51e0;
  local_108 = 0x3c1f9700136160;
  local_58 = 0x8a4300008a430;
  local_50 = 0x132f00008e830;
  local_48 = 0x13e200000aa60;
  local_40 = 0x241e000013310;
  local_38 = 0x1373000013e40;
  local_30 = 0x1426000017160;
  local_28 = 0x7170000137d0;
  local_110 = 0x6e8e20;
  local_20 = 0x14300;
  puVar2 = local_1e0;
  puVar3 = param_1;
  for (lVar1 = 0x72; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (u64)bVar4 * -2 + 1;
    puVar3 = puVar3 + (u64)bVar4 * -2 + 1;
  }
  return param_1;
}

/* installer_offsets_1000 @ 0x106e53 size=41 */
u32 * installer_offsets_1000(u32 *param_1)

{
  *param_1 = 0xc51d7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x33b1140033b10c;
  param_1[4] = 0x472d2d;
  return param_1;
}

/* installer_offsets_1001 @ 0x10746e size=41 */
u32 * installer_offsets_1001(u32 *param_1)

{
  *param_1 = 0xc51d7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x33b1140033b10c;
  param_1[4] = 0x472d2d;
  return param_1;
}

/* installer_offsets_1050 @ 0x107aa0 size=41 */
u32 * installer_offsets_1050(u32 *param_1)

{
  *param_1 = 0x450f67;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x428a3400428a2c;
  param_1[4] = 0xd737d;
  return param_1;
}

/* installer_offsets_1071 @ 0x1080d2 size=41 */
u32 * installer_offsets_1071(u32 *param_1)

{
  *param_1 = 0x450f67;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x428a3400428a2c;
  param_1[4] = 0xd737d;
  return param_1;
}

/* installer_offsets_1100 @ 0x10870a size=41 */
u32 * installer_offsets_1100(u32 *param_1)

{
  *param_1 = 0x2fccb7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x245ee400245edc;
  param_1[4] = 0x2dddfd;
  return param_1;
}

/* installer_offsets_1102 @ 0x108d42 size=41 */
u32 * installer_offsets_1102(u32 *param_1)

{
  *param_1 = 0x2fccd7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x245f0400245efc;
  param_1[4] = 0x2dde1d;
  return param_1;
}

/* installer_offsets_1152 @ 0x10937a size=41 */
u32 * installer_offsets_1152(u32 *param_1)

{
  *param_1 = 0x2e0287;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x4658740046586c;
  param_1[4] = 0x2bd3ad;
  return param_1;
}

/* installer_offsets_1202 @ 0x1099b2 size=41 */
u32 * installer_offsets_1202(u32 *param_1)

{
  *param_1 = 0x2e04c7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x465ab400465aac;
  param_1[4] = 0x2bd48d;
  return param_1;
}

/* installer_offsets_1252 @ 0x109fea size=41 */
u32 * installer_offsets_1252(u32 *param_1)

{
  *param_1 = 0x2e0507;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x465af400465aec;
  param_1[4] = 0x2bd4cd;
  return param_1;
}

/* installer_offsets_1300 @ 0x10a622 size=41 */
u32 * installer_offsets_1300(u32 *param_1)

{
  *param_1 = 0x2e0527;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x465b1400465b0c;
  param_1[4] = 0x2bd4ed;
  return param_1;
}

/* installer_offsets_505 @ 0x10ac22 size=41 */
u32 * installer_offsets_505(u32 *param_1)

{
  *param_1 = 0x43612a;
  *(u16 *)(param_1 + 1) = 0x38eb;
  *(u64 *)(param_1 + 2) = 0xfcd56000fcd48;
  param_1[4] = 0x1ea53d;
  return param_1;
}

/* installer_offsets_671 @ 0x10b242 size=41 */
u32 * installer_offsets_671(u32 *param_1)

{
  *param_1 = 0x123367;
  *(u16 *)(param_1 + 1) = 0x38eb;
  *(u64 *)(param_1 + 2) = 0x250803002507f5;
  param_1[4] = 0x3c15bd;
  return param_1;
}

/* installer_offsets_672 @ 0x10b862 size=41 */
u32 * installer_offsets_672(u32 *param_1)

{
  *param_1 = 0x123367;
  *(u16 *)(param_1 + 1) = 0x38eb;
  *(u64 *)(param_1 + 2) = 0x250803002507f5;
  param_1[4] = 0x3c15bd;
  return param_1;
}

/* installer_offsets_702 @ 0x10be89 size=41 */
u32 * installer_offsets_702(u32 *param_1)

{
  *param_1 = 0xbc817;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1171c6001171be;
  param_1[4] = 0x2f04d;
  return param_1;
}

/* installer_offsets_750 @ 0x10c4cd size=41 */
u32 * installer_offsets_750(u32 *param_1)

{
  *param_1 = 0x26f827;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1754b4001754ac;
  param_1[4] = 0x28f80d;
  return param_1;
}

/* installer_offsets_751 @ 0x10cb11 size=41 */
u32 * installer_offsets_751(u32 *param_1)

{
  *param_1 = 0x26f827;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1754b4001754ac;
  param_1[4] = 0x28f80d;
  return param_1;
}

/* installer_offsets_755 @ 0x10d138 size=41 */
u32 * installer_offsets_755(u32 *param_1)

{
  *param_1 = 0x26f827;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1754b4001754ac;
  param_1[4] = 0x28f80d;
  return param_1;
}

/* installer_offsets_800 @ 0x10d759 size=41 */
u32 * installer_offsets_800(u32 *param_1)

{
  *param_1 = 0x430bc7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1b4c40001b4bc;
  param_1[4] = 0x25e1cd;
  return param_1;
}

/* installer_offsets_801 @ 0x10dd97 size=41 */
u32 * installer_offsets_801(u32 *param_1)

{
  *param_1 = 0x430bc7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1b4c40001b4bc;
  param_1[4] = 0x25e1cd;
  return param_1;
}

/* installer_offsets_803 @ 0x10e3d5 size=41 */
u32 * installer_offsets_803(u32 *param_1)

{
  *param_1 = 0x430bc7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x1b4c40001b4bc;
  param_1[4] = 0x25e1cd;
  return param_1;
}

/* installer_offsets_850 @ 0x10ea13 size=41 */
u32 * installer_offsets_850(u32 *param_1)

{
  *param_1 = 0x15d657;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x219a7400219a6c;
  param_1[4] = 0x3a40fd;
  return param_1;
}

/* installer_offsets_852 @ 0x10f051 size=41 */
u32 * installer_offsets_852(u32 *param_1)

{
  *param_1 = 0x15d657;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x219a7400219a6c;
  param_1[4] = 0x3a40fd;
  return param_1;
}

/* installer_offsets_900 @ 0x10f672 size=41 */
u32 * installer_offsets_900(u32 *param_1)

{
  *param_1 = 0xb7b17;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x37bf440037bf3c;
  param_1[4] = 0x2714bd;
  return param_1;
}

/* installer_offsets_903 @ 0x10fcb0 size=41 */
u32 * installer_offsets_903(u32 *param_1)

{
  *param_1 = 0xb7ac7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x37a1440037a13c;
  param_1[4] = 0x27113d;
  return param_1;
}

/* installer_offsets_904 @ 0x1102ee size=41 */
u32 * installer_offsets_904(u32 *param_1)

{
  *param_1 = 0xb7ac7;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x37a1440037a13c;
  param_1[4] = 0x27113d;
  return param_1;
}

/* installer_offsets_950 @ 0x110926 size=41 */
u32 * installer_offsets_950(u32 *param_1)

{
  *param_1 = 0x205557;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x188aa400188a9c;
  param_1[4] = 0x201ccd;
  return param_1;
}

/* installer_offsets_951 @ 0x110f5e size=41 */
u32 * installer_offsets_951(u32 *param_1)

{
  *param_1 = 0x205557;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x188aa400188a9c;
  param_1[4] = 0x201ccd;
  return param_1;
}

/* installer_offsets_960 @ 0x111579 size=41 */
u32 * installer_offsets_960(u32 *param_1)

{
  *param_1 = 0x205557;
  *(u16 *)(param_1 + 1) = 0x3beb;
  *(u64 *)(param_1 + 2) = 0x188aa400188a9c;
  param_1[4] = 0x201ccd;
  return param_1;
}

/* ksdk_offsets_1000 @ 0x106861 size=615 */
void ksdk_offsets_1000(u64 *param_1)

{
  *param_1 = 0xc50f0000001c0;
  param_1[1] = 0x109d2000109a60;
  param_1[2] = 0x472d2000109c20;
  param_1[3] = 0x1099400003e6f0;
  param_1[4] = 0x2e03400033b040;
  param_1[5] = 0x182f000286350;
  param_1[6] = 0xa9c40000a9a80;
  param_1[7] = 0x38d07000480ce0;
  param_1[8] = 0x38d0c00038d6b0;
  param_1[9] = 0x391eb00038fb70;
  param_1[10] = 0x38e27000390130;
  param_1[0xb] = 0x38cf900038cf20;
  param_1[0xc] = 0x26c7d00044dc40;
  param_1[0xd] = 0x2269a00026c890;
  param_1[0xe] = 0x4733c0003f7490;
  param_1[0xf] = 0x1219b000472e20;
  param_1[0x10] = 0xc53f00045f2a0;
  param_1[0x11] = 0xf33d0000c5330;
  param_1[0x12] = 0x62cb000013a3d0;
  param_1[0x13] = 0x3b9e000006ca20;
  param_1[0x14] = 0x621220003ba030;
  param_1[0x15] = 0x620df000621560;
  param_1[0x16] = 0x624ca0006194a0;
  param_1[0x17] = 0x63f51000641e30;
  param_1[0x18] = 0x63d790006415f0;
  param_1[0x19] = 0xa5d100062dbe0;
  param_1[0x1a] = 0x208b0000207d90;
  param_1[0x1b] = 0x2085e0002089f0;
  param_1[0x1c] = 0x22e2cc00040ba10;
  param_1[0x1d] = 0x63653000373b80;
  param_1[0x1e] = 0x1532c0001a78a78;
  param_1[0x1f] = 0x111b8b00227bef8;
  param_1[0x20] = 0x22d9b4001b25bd0;
  param_1[0x21] = 0x266004001102d90;
  param_1[0x22] = 0x22e4aec0155ec48;
  param_1[0x23] = 0x2646258000068b1;
  param_1[0x24] = 0x26583b80267c088;
  param_1[0x25] = 0x265c000026583c8;
  *(u32 *)(param_1 + 0x26) = 0x265c808;
  return;
}

/* ksdk_offsets_1001 @ 0x106e7c size=615 */
void ksdk_offsets_1001(u64 *param_1)

{
  *param_1 = 0xc50f0000001c0;
  param_1[1] = 0x109d2000109a60;
  param_1[2] = 0x472d2000109c20;
  param_1[3] = 0x1099400003e6f0;
  param_1[4] = 0x2e03400033b040;
  param_1[5] = 0x182f000286350;
  param_1[6] = 0xa9c40000a9a80;
  param_1[7] = 0x38d07000480ce0;
  param_1[8] = 0x38d0c00038d6b0;
  param_1[9] = 0x391eb00038fb70;
  param_1[10] = 0x38e27000390130;
  param_1[0xb] = 0x38cf900038cf20;
  param_1[0xc] = 0x26c7d00044dc40;
  param_1[0xd] = 0x2269a00026c890;
  param_1[0xe] = 0x4733c0003f7490;
  param_1[0xf] = 0x1219b000472e20;
  param_1[0x10] = 0xc53f00045f2a0;
  param_1[0x11] = 0xf33d0000c5330;
  param_1[0x12] = 0x62cb000013a3d0;
  param_1[0x13] = 0x3b9e000006ca20;
  param_1[0x14] = 0x621220003ba030;
  param_1[0x15] = 0x620df000621560;
  param_1[0x16] = 0x624ca0006194a0;
  param_1[0x17] = 0x63f51000641e30;
  param_1[0x18] = 0x63d790006415f0;
  param_1[0x19] = 0xa5d100062dbe0;
  param_1[0x1a] = 0x208b0000207d90;
  param_1[0x1b] = 0x2085e0002089f0;
  param_1[0x1c] = 0x22e2cc00040ba10;
  param_1[0x1d] = 0x63653000373b80;
  param_1[0x1e] = 0x1532c0001a78a78;
  param_1[0x1f] = 0x111b8b00227bef8;
  param_1[0x20] = 0x22d9b4001b25bd0;
  param_1[0x21] = 0x266004001102d90;
  param_1[0x22] = 0x22e4aec0155ec48;
  param_1[0x23] = 0x2646258000068b1;
  param_1[0x24] = 0x26583b80267c088;
  param_1[0x25] = 0x265c000026583c8;
  *(u32 *)(param_1 + 0x26) = 0x265c808;
  return;
}

/* ksdk_offsets_1050 @ 0x107497 size=615 */
void ksdk_offsets_1050(u64 *param_1)

{
  *param_1 = 0x450e80000001c0;
  param_1[1] = 0x36e3e00036e120;
  param_1[2] = 0xd73700036e2e0;
  param_1[3] = 0x2a0200000d090;
  param_1[4] = 0x160da000428960;
  param_1[5] = 0x3384e0003fd7c0;
  param_1[6] = 0x97960000977a0;
  param_1[7] = 0x4762d00045d6d0;
  param_1[8] = 0x47632000476910;
  param_1[9] = 0x47b11000478dd0;
  param_1[10] = 0x4774d000479390;
  param_1[0xb] = 0x4761f000476180;
  param_1[0xc] = 0x300a80004244a0;
  param_1[0xd] = 0xed02000300b40;
  param_1[0xe] = 0xd7a10002fdb20;
  param_1[0xf] = 0x1ddda0000d7470;
  param_1[0x10] = 0x45118000465e10;
  param_1[0x11] = 0x1d4950004510c0;
  param_1[0x12] = 0x622f5000441bb0;
  param_1[0x13] = 0x33ee6000350360;
  param_1[0x14] = 0x6256700033f090;
  param_1[0x15] = 0x625240006259b0;
  param_1[0x16] = 0x6229100061b3c0;
  param_1[0x17] = 0x63dc3000644430;
  param_1[0x18] = 0x63beb000643bf0;
  param_1[0x19] = 0x1f452000630550;
  param_1[0x1a] = 0x3ac200003ab490;
  param_1[0x1b] = 0x3abce0003ac0f0;
  param_1[0x1c] = 0x1b240580000aaf0;
  param_1[0x1d] = 0x63765000489a30;
  param_1[0x1e] = 0x1a5fe3001a3bca0;
  param_1[0x1f] = 0x111b910022a9250;
  param_1[0x20] = 0x2269f3001bf81f0;
  param_1[0x21] = 0x26796c0011029c0;
  param_1[0x22] = 0x1c6c85c01541e78;
  param_1[0x23] = 0x2646ca800050ded;
  param_1[0x24] = 0x26608580265c310;
  param_1[0x25] = 0x266400002660868;
  *(u32 *)(param_1 + 0x26) = 0x2664808;
  return;
}

/* ksdk_offsets_1071 @ 0x107ac9 size=615 */
void ksdk_offsets_1071(u64 *param_1)

{
  *param_1 = 0x450e80000001c0;
  param_1[1] = 0x36e3e00036e120;
  param_1[2] = 0xd73700036e2e0;
  param_1[3] = 0x2a0200000d090;
  param_1[4] = 0x160da000428960;
  param_1[5] = 0x3384e0003fd7c0;
  param_1[6] = 0x97960000977a0;
  param_1[7] = 0x4762d00045d6d0;
  param_1[8] = 0x47632000476910;
  param_1[9] = 0x47b11000478dd0;
  param_1[10] = 0x4774d000479390;
  param_1[0xb] = 0x4761f000476180;
  param_1[0xc] = 0x300a80004244a0;
  param_1[0xd] = 0xed02000300b40;
  param_1[0xe] = 0xd7a10002fdb20;
  param_1[0xf] = 0x1ddda0000d7470;
  param_1[0x10] = 0x45118000465e10;
  param_1[0x11] = 0x1d4950004510c0;
  param_1[0x12] = 0x622f5000441bb0;
  param_1[0x13] = 0x33ee6000350360;
  param_1[0x14] = 0x6256700033f090;
  param_1[0x15] = 0x625240006259b0;
  param_1[0x16] = 0x6229100061b3c0;
  param_1[0x17] = 0x63dc3000644430;
  param_1[0x18] = 0x63beb000643bf0;
  param_1[0x19] = 0x1f452000630550;
  param_1[0x1a] = 0x3ac200003ab490;
  param_1[0x1b] = 0x3abce0003ac0f0;
  param_1[0x1c] = 0x1b240580000aaf0;
  param_1[0x1d] = 0x63765000489a30;
  param_1[0x1e] = 0x1a5fe3001a3bca0;
  param_1[0x1f] = 0x111b910022a9250;
  param_1[0x20] = 0x2269f3001bf81f0;
  param_1[0x21] = 0x26796c0011029c0;
  param_1[0x22] = 0x1c6c85c01541e78;
  param_1[0x23] = 0x2646ca800050ded;
  param_1[0x24] = 0x26608580265c310;
  param_1[0x25] = 0x266400002660868;
  *(u32 *)(param_1 + 0x26) = 0x2664808;
  return;
}

/* ksdk_offsets_1100 @ 0x1080fb size=615 */
void ksdk_offsets_1100(u64 *param_1)

{
  *param_1 = 0x2fcbd0000001c0;
  param_1[1] = 0x1a44e0001a4220;
  param_1[2] = 0x2dddf0001a43e0;
  param_1[3] = 0x948b0000482d0;
  param_1[4] = 0x21dc4000245e10;
  param_1[5] = 0x295170003663e0;
  param_1[6] = 0xe33c0000e3200;
  param_1[7] = 0x3578b000198060;
  param_1[8] = 0x35790000357ef0;
  param_1[9] = 0x35c7100035a3b0;
  param_1[10] = 0x358ab00035a970;
  param_1[0xb] = 0x3577d000357760;
  param_1[0xc] = 0xc0660003838a0;
  param_1[0xd] = 0x43e440000c0720;
  param_1[0xe] = 0x2de490002c5740;
  param_1[0xf] = 0x313b10002ddef0;
  param_1[0x10] = 0x2fced0002bbfd0;
  param_1[0x11] = 0x279960002fce10;
  param_1[0x12] = 0x61d900002d1ca0;
  param_1[0x13] = 0x2deaa0003c8060;
  param_1[0x14] = 0x625df0002decd0;
  param_1[0x15] = 0x6259c000626130;
  param_1[0x16] = 0x62edc00061af60;
  param_1[0x17] = 0x640740006437d0;
  param_1[0x18] = 0x63e9c000642f90;
  param_1[0x19] = 0x3d0e900062f810;
  param_1[0x1a] = 0xc3eb0000c3140;
  param_1[0x1b] = 0xc3990000c3da0;
  param_1[0x1c] = 0x22b6ad000337cb0;
  param_1[0x1d] = 0x637ff0000790a0;
  param_1[0x1e] = 0x15415b00152cff8;
  param_1[0x1f] = 0x111f830021ff130;
  param_1[0x20] = 0x22d0a9802116640;
  param_1[0x21] = 0x266018001101760;
  param_1[0x22] = 0x21622dc0155cc48;
  param_1[0x23] = 0x264668800071a21;
  param_1[0x24] = 0x26606e80264c080;
  param_1[0x25] = 0x2664000026606f8;
  *(u32 *)(param_1 + 0x26) = 0x2664808;
  return;
}

/* ksdk_offsets_1102 @ 0x108733 size=615 */
void ksdk_offsets_1102(u64 *param_1)

{
  *param_1 = 0x2fcbf0000001c0;
  param_1[1] = 0x1a4500001a4240;
  param_1[2] = 0x2dde10001a4400;
  param_1[3] = 0x948b0000482d0;
  param_1[4] = 0x21dc6000245e30;
  param_1[5] = 0x29519000366400;
  param_1[6] = 0xe33c0000e3200;
  param_1[7] = 0x3578d000198080;
  param_1[8] = 0x35792000357f10;
  param_1[9] = 0x35c7300035a3d0;
  param_1[10] = 0x358ad00035a990;
  param_1[0xb] = 0x3577f000357780;
  param_1[0xc] = 0xc0660003838c0;
  param_1[0xd] = 0x43e3d0000c0720;
  param_1[0xe] = 0x2de4b0002c5760;
  param_1[0xf] = 0x313b30002ddf10;
  param_1[0x10] = 0x2fcef0002bbff0;
  param_1[0x11] = 0x279980002fce30;
  param_1[0x12] = 0x61d8a0002d1cc0;
  param_1[0x13] = 0x2deac0003c8080;
  param_1[0x14] = 0x625d90002decf0;
  param_1[0x15] = 0x625960006260d0;
  param_1[0x16] = 0x62ed600061af00;
  param_1[0x17] = 0x6406e000643770;
  param_1[0x18] = 0x63e96000642f30;
  param_1[0x19] = 0x3d0eb00062f7b0;
  param_1[0x1a] = 0xc3eb0000c3140;
  param_1[0x1b] = 0xc3990000c3da0;
  param_1[0x1c] = 0x22b6ad000337cd0;
  param_1[0x1d] = 0x637f90000790a0;
  param_1[0x1e] = 0x15415b00152cff8;
  param_1[0x1f] = 0x111f830021ff130;
  param_1[0x20] = 0x22d0a9802116640;
  param_1[0x21] = 0x266018001101760;
  param_1[0x22] = 0x21622dc0155cc48;
  param_1[0x23] = 0x264668800071a21;
  param_1[0x24] = 0x26606e80264c080;
  param_1[0x25] = 0x2664000026606f8;
  *(u32 *)(param_1 + 0x26) = 0x2664808;
  return;
}

/* ksdk_offsets_1152 @ 0x108d6b size=615 */
void ksdk_offsets_1152(u64 *param_1)

{
  *param_1 = 0x2e01a0000001c0;
  param_1[1] = 0x97e000009520;
  param_1[2] = 0x2bd3a0000096e0;
  param_1[3] = 0x394060001fa060;
  param_1[4] = 0x36a8f0004657a0;
  param_1[5] = 0x4c6c000140250;
  param_1[6] = 0xa3a00000a3840;
  param_1[7] = 0x2f6e70003a1b30;
  param_1[8] = 0x2f6ec0002f74b0;
  param_1[9] = 0x2fbcd0002f9970;
  param_1[10] = 0x2f8070002f9f30;
  param_1[0xb] = 0x2f6d90002f6d20;
  param_1[0xc] = 0x1dffe000365d60;
  param_1[0xd] = 0x224030001e00a0;
  param_1[0xe] = 0x2bda400021cb70;
  param_1[0xf] = 0x3c60d0002bd4a0;
  param_1[0x10] = 0x2e04a0003a8010;
  param_1[0x11] = 0xf0060002e03e0;
  param_1[0x12] = 0x6264a0001f8c60;
  param_1[0x13] = 0x340bf00021bb20;
  param_1[0x14] = 0x62adf000340e20;
  param_1[0x15] = 0x62a9c00062b130;
  param_1[0x16] = 0x6245000061bd60;
  param_1[0x17] = 0x63f6800063cd70;
  param_1[0x18] = 0x63d9000063c530;
  param_1[0x19] = 0x3b2b400062f720;
  param_1[0x1a] = 0x1d45e0001d3870;
  param_1[0x1b] = 0x1d40c0001d44d0;
  param_1[0x1c] = 0x22d1f300046f750;
  param_1[0x1d] = 0x638070001d9fe0;
  param_1[0x1e] = 0x1520d0001a47f40;
  param_1[0x1f] = 0x111fa18022d1d50;
  param_1[0x20] = 0x1b2853802136e90;
  param_1[0x21] = 0x26542c001102b70;
  param_1[0x22] = 0x21d278c0153d6c8;
  param_1[0x23] = 0x2647350000704d5;
  param_1[0x24] = 0x26680400265c080;
  param_1[0x25] = 0x266c00002668050;
  *(u32 *)(param_1 + 0x26) = 0x266c808;
  return;
}

/* ksdk_offsets_1202 @ 0x1093a3 size=615 */
void ksdk_offsets_1202(u64 *param_1)

{
  *param_1 = 0x2e03e0000001c0;
  param_1[1] = 0x97e000009520;
  param_1[2] = 0x2bd480000096e0;
  param_1[3] = 0x3942a0001fa140;
  param_1[4] = 0x36ab30004659e0;
  param_1[5] = 0x4c6c000140250;
  param_1[6] = 0xa3a00000a3840;
  param_1[7] = 0x2f70b0003a1d70;
  param_1[8] = 0x2f7100002f76f0;
  param_1[9] = 0x2fbf10002f9bb0;
  param_1[10] = 0x2f82b0002fa170;
  param_1[0xb] = 0x2f6fd0002f6f60;
  param_1[0xc] = 0x1dffe000365fa0;
  param_1[0xd] = 0x224110001e00a0;
  param_1[0xe] = 0x2bdb200021cc50;
  param_1[0xf] = 0x3c6310002bd580;
  param_1[0x10] = 0x2e06e0003a8250;
  param_1[0x11] = 0xf0060002e0620;
  param_1[0x12] = 0x6266e0001f8d40;
  param_1[0x13] = 0x340e300021bc00;
  param_1[0x14] = 0x62b03000341060;
  param_1[0x15] = 0x62ac000062b370;
  param_1[0x16] = 0x6247400061bfa0;
  param_1[0x17] = 0x63f8c00063cfb0;
  param_1[0x18] = 0x63db400063c770;
  param_1[0x19] = 0x3b2d800062f960;
  param_1[0x1a] = 0x1d45e0001d3870;
  param_1[0x1b] = 0x1d40c0001d44d0;
  param_1[0x1c] = 0x22d1f300046f990;
  param_1[0x1d] = 0x6382b0001d9fe0;
  param_1[0x1e] = 0x1520d0001a47f40;
  param_1[0x1f] = 0x111fa18022d1d50;
  param_1[0x20] = 0x1b2853802136e90;
  param_1[0x21] = 0x26542c001102b70;
  param_1[0x22] = 0x21d278c0153d6c8;
  param_1[0x23] = 0x264735000047b31;
  param_1[0x24] = 0x26680400265c080;
  param_1[0x25] = 0x266c00002668050;
  *(u32 *)(param_1 + 0x26) = 0x266c808;
  return;
}

/* ksdk_offsets_1252 @ 0x1099db size=615 */
void ksdk_offsets_1252(u64 *param_1)

{
  *param_1 = 0x2e0420000001c0;
  param_1[1] = 0x97e000009520;
  param_1[2] = 0x2bd4c0000096e0;
  param_1[3] = 0x3942e0001fa180;
  param_1[4] = 0x36ab7000465a20;
  param_1[5] = 0x4c6c000140290;
  param_1[6] = 0xa3a00000a3840;
  param_1[7] = 0x2f70f0003a1db0;
  param_1[8] = 0x2f7140002f7730;
  param_1[9] = 0x2fbf50002f9bf0;
  param_1[10] = 0x2f82f0002fa1b0;
  param_1[0xb] = 0x2f7010002f6fa0;
  param_1[0xc] = 0x1e002000365fe0;
  param_1[0xd] = 0x224150001e00e0;
  param_1[0xe] = 0x2bdb600021cc90;
  param_1[0xf] = 0x3c6350002bd5c0;
  param_1[0x10] = 0x2e0720003a8290;
  param_1[0x11] = 0xf0060002e0660;
  param_1[0x12] = 0x626720001f8d80;
  param_1[0x13] = 0x340e700021bc40;
  param_1[0x14] = 0x62b070003410a0;
  param_1[0x15] = 0x62ac400062b3b0;
  param_1[0x16] = 0x6247800061bfe0;
  param_1[0x17] = 0x63f9600063d050;
  param_1[0x18] = 0x63dbe00063c810;
  param_1[0x19] = 0x3b2dc00062f9a0;
  param_1[0x1a] = 0x1d4620001d38b0;
  param_1[0x1b] = 0x1d4100001d4510;
  param_1[0x1c] = 0x22d1f300046f9d0;
  param_1[0x1d] = 0x6382f0001da020;
  param_1[0x1e] = 0x1520d0001a47f40;
  param_1[0x1f] = 0x111fa18022d1d50;
  param_1[0x20] = 0x1b2853802136e90;
  param_1[0x21] = 0x26542c001102b70;
  param_1[0x22] = 0x21d278c0153d6c8;
  param_1[0x23] = 0x264735000047b31;
  param_1[0x24] = 0x26680400265c080;
  param_1[0x25] = 0x266c00002668050;
  *(u32 *)(param_1 + 0x26) = 0x266c808;
  return;
}

/* ksdk_offsets_1300 @ 0x10a013 size=615 */
void ksdk_offsets_1300(u64 *param_1)

{
  *param_1 = 0x2e0440000001c0;
  param_1[1] = 0x97e000009520;
  param_1[2] = 0x2bd4e0000096e0;
  param_1[3] = 0x394300001fa1a0;
  param_1[4] = 0x36ab9000465a40;
  param_1[5] = 0x4c6c000140290;
  param_1[6] = 0xa3a00000a3840;
  param_1[7] = 0x2f7110003a1dd0;
  param_1[8] = 0x2f7160002f7750;
  param_1[9] = 0x2fbf70002f9c10;
  param_1[10] = 0x2f8310002fa1d0;
  param_1[0xb] = 0x2f7030002f6fc0;
  param_1[0xc] = 0x1e004000366000;
  param_1[0xd] = 0x224170001e0100;
  param_1[0xe] = 0x2bdb800021ccb0;
  param_1[0xf] = 0x3c6370002bd5e0;
  param_1[0x10] = 0x2e0740003a82b0;
  param_1[0x11] = 0xf0060002e0680;
  param_1[0x12] = 0x626770001f8da0;
  param_1[0x13] = 0x340e900021bc60;
  param_1[0x14] = 0x62b0c0003410c0;
  param_1[0x15] = 0x62ac900062b400;
  param_1[0x16] = 0x6247d00061c030;
  param_1[0x17] = 0x63f9b00063d0a0;
  param_1[0x18] = 0x63dc300063c860;
  param_1[0x19] = 0x3b2de00062f9f0;
  param_1[0x1a] = 0x1d4640001d38d0;
  param_1[0x1b] = 0x1d4120001d4530;
  param_1[0x1c] = 0x22d1f300046f9f0;
  param_1[0x1d] = 0x638340001da040;
  param_1[0x1e] = 0x1520d0001a47f40;
  param_1[0x1f] = 0x111fa18022d1d50;
  param_1[0x20] = 0x1b2853802136e90;
  param_1[0x21] = 0x26542c001102b70;
  param_1[0x22] = 0x21d278c0153d6c8;
  param_1[0x23] = 0x2647350000361cd;
  param_1[0x24] = 0x26680400265c080;
  param_1[0x25] = 0x266c00002668050;
  *(u32 *)(param_1 + 0x26) = 0x266c808;
  return;
}

/* ksdk_offsets_505 @ 0x10a64b size=615 */
void ksdk_offsets_505(u64 *param_1)

{
  *param_1 = 0x436040000001c0;
  param_1[1] = 0x10e5900010e250;
  param_1[2] = 0x1ea5300010e460;
  param_1[3] = 0x50ac0003205c0;
  param_1[4] = 0x3b71a0000fcc80;
  param_1[5] = 0x1be1f0003fb920;
  param_1[6] = 0xf5fd0000f5e10;
  param_1[7] = 0x19f1400010d390;
  param_1[8] = 0x19f1900019f760;
  param_1[9] = 0x1a3a50001a19d0;
  param_1[10] = 0x1a0280001a1f60;
  param_1[0xb] = 0x19f0600019eff0;
  param_1[0xc] = 0x1bff900030d150;
  param_1[0xd] = 0x1ec400001c0090;
  param_1[0xe] = 0x1eab400017dfb0;
  param_1[0xf] = 0x1b8fe0001ea630;
  param_1[0x10] = 0x4363500003c0b0;
  param_1[0x11] = 0x34187000436280;
  param_1[0x12] = 0x61efa0002d55b0;
  param_1[0x13] = 0x3a2bd0001fd7d0;
  param_1[0x14] = 0x62d780003a2e00;
  param_1[0x15] = 0x62e2a00062db10;
  param_1[0x16] = 0x623fc00061d7f0;
  param_1[0x17] = 0x642b400063cd40;
  param_1[0x18] = 0x6418e00063c4f0;
  param_1[0x19] = 0x117e000632540;
  param_1[0x1a] = 0x138b7000137df0;
  param_1[0x1b] = 0x13864000138a60;
  param_1[0x1c] = 0x1ac5158000ecac0;
  param_1[0x1d] = 0x6385f000428e50;
  param_1[0x1e] = 0x14b4110019eceb0;
  param_1[0x1f] = 0x10986a001ac60e0;
  param_1[0x20] = 0x2382ff8022c1a70;
  param_1[0x21] = 0x274c0400107c610;
  param_1[0x22] = 0x2381b8c014c9d48;
  param_1[0x23] = 0x271e20800013460;
  param_1[0x24] = 0x27445480271e5d8;
  param_1[0x25] = 0x274800002744558;
  *(u32 *)(param_1 + 0x26) = 0x2748800;
  return;
}

/* ksdk_offsets_671 @ 0x10ac4b size=615 */
void ksdk_offsets_671(u64 *param_1)

{
  *param_1 = 0x123280000001c0;
  param_1[1] = 0xdad00000d7a0;
  param_1[2] = 0x3c15b00000d9a0;
  param_1[3] = 0x207e40001687d0;
  param_1[4] = 0x2433e000250730;
  param_1[5] = 0x4a6fb00022a080;
  param_1[6] = 0x42880000426c0;
  param_1[7] = 0x44cd4000206d50;
  param_1[8] = 0x44cd900044d330;
  param_1[9] = 0x451bf00044f8a0;
  param_1[10] = 0x44def00044fe60;
  param_1[0xb] = 0x44cc600044cbf0;
  param_1[0xc] = 0x36b6e00010ee10;
  param_1[0xd] = 0x402e800036b7d0;
  param_1[0xe] = 0x3c1c50004817f0;
  param_1[0xf] = 0x39b6e0003c16b0;
  param_1[0x10] = 0x12359000329010;
  param_1[0x11] = 0x35410001234c0;
  param_1[0x12] = 0x64152000335b70;
  param_1[0x13] = 0x3c0320001d6050;
  param_1[0x14] = 0x649800003c0550;
  param_1[0x15] = 0x6493d000649b80;
  param_1[0x16] = 0x646e0000637ae0;
  param_1[0x17] = 0x6602600065e010;
  param_1[0x18] = 0x65e4900065d7a0;
  param_1[0x19] = 0x233c700064cc20;
  param_1[0x1a] = 0x8ae200008a0a0;
  param_1[0x1b] = 0x8a8f00008ad10;
  param_1[0x1c] = 0x22c0cd8003f8710;
  param_1[0x1d] = 0x654c4000469b40;
  param_1[0x1e] = 0x1540eb001a6eb18;
  param_1[0x1f] = 0x113e5180220dfc0;
  param_1[0x20] = 0x22bbe8002300320;
  param_1[0x21] = 0x2678cc00111e000;
  param_1[0x22] = 0x220c0cc0156a588;
  param_1[0x23] = 0x266ac680009d11d;
  param_1[0x24] = 0x269457002679040;
  param_1[0x25] = 0x269800002694580;
  *(u32 *)(param_1 + 0x26) = 0x2698808;
  return;
}

/* ksdk_offsets_672 @ 0x10b26b size=615 */
void ksdk_offsets_672(u64 *param_1)

{
  *param_1 = 0x123280000001c0;
  param_1[1] = 0xdad00000d7a0;
  param_1[2] = 0x3c15b00000d9a0;
  param_1[3] = 0x207e40001687d0;
  param_1[4] = 0x2433e000250730;
  param_1[5] = 0x4a6fb00022a080;
  param_1[6] = 0x42880000426c0;
  param_1[7] = 0x44cd4000206d50;
  param_1[8] = 0x44cd900044d330;
  param_1[9] = 0x451bf00044f8a0;
  param_1[10] = 0x44def00044fe60;
  param_1[0xb] = 0x44cc600044cbf0;
  param_1[0xc] = 0x36b6e00010ee10;
  param_1[0xd] = 0x402e800036b7d0;
  param_1[0xe] = 0x3c1c50004817f0;
  param_1[0xf] = 0x39b6e0003c16b0;
  param_1[0x10] = 0x12359000329010;
  param_1[0x11] = 0x35410001234c0;
  param_1[0x12] = 0x64152000335b70;
  param_1[0x13] = 0x3c0320001d6050;
  param_1[0x14] = 0x649800003c0550;
  param_1[0x15] = 0x6493d000649b80;
  param_1[0x16] = 0x646e0000637ae0;
  param_1[0x17] = 0x6602600065e010;
  param_1[0x18] = 0x65e4900065d7a0;
  param_1[0x19] = 0x233c700064cc20;
  param_1[0x1a] = 0x8ae200008a0a0;
  param_1[0x1b] = 0x8a8f00008ad10;
  param_1[0x1c] = 0x22c0cd8003f8710;
  param_1[0x1d] = 0x654c4000469b40;
  param_1[0x1e] = 0x1540eb001a6eb18;
  param_1[0x1f] = 0x113e5180220dfc0;
  param_1[0x20] = 0x22bbe8002300320;
  param_1[0x21] = 0x2678cc00111e000;
  param_1[0x22] = 0x220c0cc0156a588;
  param_1[0x23] = 0x266ac680009d11d;
  param_1[0x24] = 0x269457002679040;
  param_1[0x25] = 0x269800002694580;
  *(u32 *)(param_1 + 0x26) = 0x2698808;
  return;
}

/* ksdk_offsets_702 @ 0x10b88b size=615 */
void ksdk_offsets_702(u64 *param_1)

{
  *param_1 = 0xbc730000001c0;
  param_1[1] = 0x301b7000301840;
  param_1[2] = 0x2f04000301a40;
  param_1[3] = 0x207500002dfc20;
  param_1[4] = 0x93ff0001170f0;
  param_1[5] = 0x842e00016eee0;
  param_1[6] = 0x1ae1f0001ae030;
  param_1[7] = 0x25fb90002cd780;
  param_1[8] = 0x25fbe000260190;
  param_1[9] = 0x264a5000262700;
  param_1[10] = 0x260d6000262cc0;
  param_1[0xb] = 0x25fab00025fa50;
  param_1[0xc] = 0x2cebf000043e80;
  param_1[0xd] = 0x483810002cece0;
  param_1[0xe] = 0x2f6e000005740;
  param_1[0xf] = 0x3dabe00002f140;
  param_1[0x10] = 0xbca30000f9e40;
  param_1[0x11] = 0x10c900000bc970;
  param_1[0x12] = 0x64700000205f50;
  param_1[0x13] = 0x1da410001dd540;
  param_1[0x14] = 0x648650001da640;
  param_1[0x15] = 0x648220006489d0;
  param_1[0x16] = 0x63e230006376a0;
  param_1[0x17] = 0x65c34000660a90;
  param_1[0x18] = 0x65a56000660210;
  param_1[0x19] = 0x1cb9300064c110;
  param_1[0x1a] = 0xc4ee0000c4170;
  param_1[0x1b] = 0xc49c0000c4dd0;
  param_1[0x1c] = 0x21f07780021d3e0;
  param_1[0x1d] = 0x653ac000118660;
  param_1[0x1e] = 0x1a7ae5001a6eaa0;
  param_1[0x1f] = 0x113e398021c8ee0;
  param_1[0x20] = 0x1b48318022c5750;
  param_1[0x21] = 0x268840001125660;
  param_1[0x22] = 0x21f42ac01555bd8;
  param_1[0x23] = 0x2669e480006b192;
  param_1[0x24] = 0x2698848026945c0;
  param_1[0x25] = 0x269c00002698858;
  *(u32 *)(param_1 + 0x26) = 0x269c808;
  return;
}

/* ksdk_offsets_750 @ 0x10beb2 size=615 */
void ksdk_offsets_750(u64 *param_1)

{
  *param_1 = 0x26f740000001c0;
  param_1[1] = 0x1d69a0001d6680;
  param_1[2] = 0x28f800001d6870;
  param_1[3] = 0x31d2500008d6f0;
  param_1[4] = 0x2e8bc0001753e0;
  param_1[5] = 0x47ab6000086e80;
  param_1[6] = 0xd17c0000d1600;
  param_1[7] = 0x2fc430000d28e0;
  param_1[8] = 0x2fc480002fca70;
  param_1[9] = 0x3012f0002fefa0;
  param_1[10] = 0x2fd640002ff560;
  param_1[0xb] = 0x2fc350002fc2e0;
  param_1[0xc] = 0x4a526000361310;
  param_1[0xd] = 0xd3670004a5350;
  param_1[0xe] = 0x28fea0003b0250;
  param_1[0xf] = 0xbf6700028f900;
  param_1[0x10] = 0x26fa400021b800;
  param_1[0x11] = 0x459fb00026f980;
  param_1[0x12] = 0x63f10000274740;
  param_1[0x13] = 0x21f810001517f0;
  param_1[0x14] = 0x643b200021fa40;
  param_1[0x15] = 0x6436f000643e80;
  param_1[0x16] = 0x63e3e000634a40;
  param_1[0x17] = 0x657a300065c8e0;
  param_1[0x18] = 0x655c500065c090;
  param_1[0x19] = 0x364d800064a1a0;
  param_1[0x1a] = 0xe6700000d8f0;
  param_1[0x1b] = 0xe1400000e550;
  param_1[0x1c] = 0x213c7c00012d8d0;
  param_1[0x1d] = 0x651b20002a1530;
  param_1[0x1e] = 0x1556da001564910;
  param_1[0x1f] = 0x113b728021405b8;
  param_1[0x20] = 0x213c82801b463e0;
  param_1[0x21] = 0x268090001122340;
  param_1[0x22] = 0x216212c015a8fc8;
  param_1[0x23] = 0x266264800004fd4;
  param_1[0x24] = 0x26842380267c040;
  param_1[0x25] = 0x268800002684248;
  *(u32 *)(param_1 + 0x26) = 0x2688808;
  return;
}

/* ksdk_offsets_751 @ 0x10c4f6 size=615 */
void ksdk_offsets_751(u64 *param_1)

{
  *param_1 = 0x26f740000001c0;
  param_1[1] = 0x1d69a0001d6680;
  param_1[2] = 0x28f800001d6870;
  param_1[3] = 0x31d2500008d6f0;
  param_1[4] = 0x2e8bc0001753e0;
  param_1[5] = 0x47ab6000086e80;
  param_1[6] = 0xd17c0000d1600;
  param_1[7] = 0x2fc430000d28e0;
  param_1[8] = 0x2fc480002fca70;
  param_1[9] = 0x3012f0002fefa0;
  param_1[10] = 0x2fd640002ff560;
  param_1[0xb] = 0x2fc350002fc2e0;
  param_1[0xc] = 0x4a526000361310;
  param_1[0xd] = 0xd3670004a5350;
  param_1[0xe] = 0x28fea0003b0250;
  param_1[0xf] = 0xbf6700028f900;
  param_1[0x10] = 0x26fa400021b800;
  param_1[0x11] = 0x459fb00026f980;
  param_1[0x12] = 0x63f10000274740;
  param_1[0x13] = 0x21f810001517f0;
  param_1[0x14] = 0x643b200021fa40;
  param_1[0x15] = 0x6436f000643e80;
  param_1[0x16] = 0x63e3e000634a40;
  param_1[0x17] = 0x657a300065c8e0;
  param_1[0x18] = 0x655c500065c090;
  param_1[0x19] = 0x364d800064a1a0;
  param_1[0x1a] = 0xe6700000d8f0;
  param_1[0x1b] = 0xe1400000e550;
  param_1[0x1c] = 0x213c7c00012d8d0;
  param_1[0x1d] = 0x651b20002a1530;
  param_1[0x1e] = 0x1556da001564910;
  param_1[0x1f] = 0x113b728021405b8;
  param_1[0x20] = 0x213c82801b463e0;
  param_1[0x21] = 0x268090001122340;
  param_1[0x22] = 0x216212c015a8fc8;
  param_1[0x23] = 0x26626480001f842;
  param_1[0x24] = 0x26842380267c040;
  param_1[0x25] = 0x268800002684248;
  *(u32 *)(param_1 + 0x26) = 0x2688808;
  return;
}

/* ksdk_offsets_755 @ 0x10cb3a size=615 */
void ksdk_offsets_755(u64 *param_1)

{
  *param_1 = 0x26f740000001c0;
  param_1[1] = 0x1d69a0001d6680;
  param_1[2] = 0x28f800001d6870;
  param_1[3] = 0x31d2500008d6f0;
  param_1[4] = 0x2e8bc0001753e0;
  param_1[5] = 0x47ab6000086e80;
  param_1[6] = 0xd17c0000d1600;
  param_1[7] = 0x2fc430000d28e0;
  param_1[8] = 0x2fc480002fca70;
  param_1[9] = 0x3012f0002fefa0;
  param_1[10] = 0x2fd640002ff560;
  param_1[0xb] = 0x2fc350002fc2e0;
  param_1[0xc] = 0x4a526000361310;
  param_1[0xd] = 0xd3670004a5350;
  param_1[0xe] = 0x28fea0003b0250;
  param_1[0xf] = 0xbf6700028f900;
  param_1[0x10] = 0x26fa400021b800;
  param_1[0x11] = 0x459fb00026f980;
  param_1[0x12] = 0x63f10000274740;
  param_1[0x13] = 0x21f810001517f0;
  param_1[0x14] = 0x643b200021fa40;
  param_1[0x15] = 0x6436f000643e80;
  param_1[0x16] = 0x63e3e000634a40;
  param_1[0x17] = 0x657a300065c8e0;
  param_1[0x18] = 0x655c500065c090;
  param_1[0x19] = 0x364d800064a1a0;
  param_1[0x1a] = 0xe6700000d8f0;
  param_1[0x1b] = 0xe1400000e550;
  param_1[0x1c] = 0x213c7c00012d8d0;
  param_1[0x1d] = 0x651b20002a1530;
  param_1[0x1e] = 0x1556da001564910;
  param_1[0x1f] = 0x113b728021405b8;
  param_1[0x20] = 0x213c82801b463e0;
  param_1[0x21] = 0x268090001122340;
  param_1[0x22] = 0x216212c015a8fc8;
  param_1[0x23] = 0x26626480001f842;
  param_1[0x24] = 0x26842380267c040;
  param_1[0x25] = 0x268800002684248;
  *(u32 *)(param_1 + 0x26) = 0x2688808;
  return;
}

/* ksdk_offsets_800 @ 0x10d161 size=615 */
void ksdk_offsets_800(u64 *param_1)

{
  *param_1 = 0x430ae0000001c0;
  param_1[1] = 0x46fab00046f7f0;
  param_1[2] = 0x25e1c00046f9b0;
  param_1[3] = 0x195a90000f6c60;
  param_1[4] = 0x2f60900001b3f0;
  param_1[5] = 0x26fa50003381d0;
  param_1[6] = 0x43a5000043a340;
  param_1[7] = 0x3e768000155560;
  param_1[8] = 0x3e76d0003e7cc0;
  param_1[9] = 0x3ec4c0003ea180;
  param_1[10] = 0x3e8880003ea740;
  param_1[0xb] = 0x3e75a0003e7530;
  param_1[0xc] = 0x1714b000173770;
  param_1[0xd] = 0x26e27000171570;
  param_1[0xe] = 0x25e86000439c10;
  param_1[0xf] = 0x1846d00025e2c0;
  param_1[0x10] = 0x430de00014f8a0;
  param_1[0x11] = 0x1778c000430d20;
  param_1[0x12] = 0x61cba000126b90;
  param_1[0x13] = 0x1665b00038f5a0;
  param_1[0x14] = 0x61e250001667e0;
  param_1[0x15] = 0x61de200061e590;
  param_1[0x16] = 0x627fb000619be0;
  param_1[0x17] = 0x63eed000642780;
  param_1[0x18] = 0x63d14000641f40;
  param_1[0x19] = 0x1d57c00062f6e0;
  param_1[0x1a] = 0x46ed400046dfd0;
  param_1[0x1b] = 0x46e8200046ec30;
  param_1[0x1c] = 0x2221fd8001c7740;
  param_1[0x1d] = 0x636c2000459880;
  param_1[0x1e] = 0x1a77e100155d190;
  param_1[0x1f] = 0x111a7d001b243e0;
  param_1[0x20] = 0x1b244e001b8c730;
  param_1[0x21] = 0x266c500010fc4d0;
  param_1[0x22] = 0x2229cac01577f28;
  param_1[0x23] = 0x263fae8000e629c;
  param_1[0x24] = 0x264884802644008;
  param_1[0x25] = 0x264c00002648858;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* ksdk_offsets_801 @ 0x10d782 size=615 */
void ksdk_offsets_801(u64 *param_1)

{
  *param_1 = 0x430ae0000001c0;
  param_1[1] = 0x46fab00046f7f0;
  param_1[2] = 0x25e1c00046f9b0;
  param_1[3] = 0x195a90000f6c60;
  param_1[4] = 0x2f60900001b3f0;
  param_1[5] = 0x26fa50003381d0;
  param_1[6] = 0x43a5000043a340;
  param_1[7] = 0x3e768000155560;
  param_1[8] = 0x3e76d0003e7cc0;
  param_1[9] = 0x3ec4c0003ea180;
  param_1[10] = 0x3e8880003ea740;
  param_1[0xb] = 0x3e75a0003e7530;
  param_1[0xc] = 0x1714b000173770;
  param_1[0xd] = 0x26e27000171570;
  param_1[0xe] = 0x25e86000439c10;
  param_1[0xf] = 0x1846d00025e2c0;
  param_1[0x10] = 0x430de00014f8a0;
  param_1[0x11] = 0x1778c000430d20;
  param_1[0x12] = 0x61cba000126b90;
  param_1[0x13] = 0x1665b00038f5a0;
  param_1[0x14] = 0x61e250001667e0;
  param_1[0x15] = 0x61de200061e590;
  param_1[0x16] = 0x627fb000619be0;
  param_1[0x17] = 0x63eed000642780;
  param_1[0x18] = 0x63d14000641f40;
  param_1[0x19] = 0x1d57c00062f6e0;
  param_1[0x1a] = 0x46ed400046dfd0;
  param_1[0x1b] = 0x46e8200046ec30;
  param_1[0x1c] = 0x2221fd8001c7740;
  param_1[0x1d] = 0x636c2000459880;
  param_1[0x1e] = 0x1a77e100155d190;
  param_1[0x1f] = 0x111a7d001b243e0;
  param_1[0x20] = 0x1b244e001b8c730;
  param_1[0x21] = 0x266c500010fc4d0;
  param_1[0x22] = 0x2229cac01577f28;
  param_1[0x23] = 0x263fae8000e629c;
  param_1[0x24] = 0x264884802644008;
  param_1[0x25] = 0x264c00002648858;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* ksdk_offsets_803 @ 0x10ddc0 size=615 */
void ksdk_offsets_803(u64 *param_1)

{
  *param_1 = 0x430ae0000001c0;
  param_1[1] = 0x46fab00046f7f0;
  param_1[2] = 0x25e1c00046f9b0;
  param_1[3] = 0x195a90000f6c60;
  param_1[4] = 0x2f60900001b3f0;
  param_1[5] = 0x26fa50003381d0;
  param_1[6] = 0x43a5000043a340;
  param_1[7] = 0x3e768000155560;
  param_1[8] = 0x3e76d0003e7cc0;
  param_1[9] = 0x3ec4c0003ea180;
  param_1[10] = 0x3e8880003ea740;
  param_1[0xb] = 0x3e75a0003e7530;
  param_1[0xc] = 0x1714b000173770;
  param_1[0xd] = 0x26e27000171570;
  param_1[0xe] = 0x25e86000439c10;
  param_1[0xf] = 0x1846d00025e2c0;
  param_1[0x10] = 0x430de00014f8a0;
  param_1[0x11] = 0x1778c000430d20;
  param_1[0x12] = 0x61cba000126b90;
  param_1[0x13] = 0x1665b00038f5a0;
  param_1[0x14] = 0x61e250001667e0;
  param_1[0x15] = 0x61de200061e590;
  param_1[0x16] = 0x627fb000619be0;
  param_1[0x17] = 0x63eed000642780;
  param_1[0x18] = 0x63d14000641f40;
  param_1[0x19] = 0x1d57c00062f6e0;
  param_1[0x1a] = 0x46ed400046dfd0;
  param_1[0x1b] = 0x46e8200046ec30;
  param_1[0x1c] = 0x2221fd8001c7740;
  param_1[0x1d] = 0x636c2000459880;
  param_1[0x1e] = 0x1a77e100155d190;
  param_1[0x1f] = 0x111a7d001b243e0;
  param_1[0x20] = 0x1b244e001b8c730;
  param_1[0x21] = 0x266c500010fc4d0;
  param_1[0x22] = 0x2229cac01577f28;
  param_1[0x23] = 0x263fae8000e629c;
  param_1[0x24] = 0x264884802644008;
  param_1[0x25] = 0x264c00002648858;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* ksdk_offsets_850 @ 0x10e3fe size=615 */
void ksdk_offsets_850(u64 *param_1)

{
  *param_1 = 0x15d570000001c0;
  param_1[1] = 0xb5d00000b5a40;
  param_1[2] = 0x3a40f0000b5c00;
  param_1[3] = 0x20f280003d6710;
  param_1[4] = 0x270c40002199a0;
  param_1[5] = 0x3924400027c590;
  param_1[6] = 0x2bb0d0002baf10;
  param_1[7] = 0x1486d00040b420;
  param_1[8] = 0x14872000148d10;
  param_1[9] = 0x14d5100014b1d0;
  param_1[10] = 0x1498d00014b790;
  param_1[0xb] = 0x1485f000148580;
  param_1[0xc] = 0x81d2000131b50;
  param_1[0xd] = 0x1ed3d000081de0;
  param_1[0xe] = 0x3a479000456420;
  param_1[0xf] = 0x3cf6d0003a41f0;
  param_1[0x10] = 0x15d87000156e00;
  param_1[0x11] = 0x1bf100015d7b0;
  param_1[0x12] = 0x6295b000073d90;
  param_1[0x13] = 0x2639a000487240;
  param_1[0x14] = 0x620d0000263bd0;
  param_1[0x15] = 0x6208d000621040;
  param_1[0x16] = 0x62ee900061b030;
  param_1[0x17] = 0x640030006421d0;
  param_1[0x18] = 0x63e2b000641990;
  param_1[0x19] = 0x2936900062f8e0;
  param_1[0x1a] = 0x1138000010610;
  param_1[0x1b] = 0x10e6000011270;
  param_1[0x1c] = 0x1bd77b8000db870;
  param_1[0x1d] = 0x6380c0001cea20;
  param_1[0x1e] = 0x1528ff00153ae88;
  param_1[0x1f] = 0x111a8f001c64228;
  param_1[0x20] = 0x1bd72d801c66150;
  param_1[0x21] = 0x264c040010fc5c0;
  param_1[0x22] = 0x1c3d48c01583618;
  param_1[0x23] = 0x2646238000c810d;
  param_1[0x24] = 0x26500780266ca40;
  param_1[0x25] = 0x265400002650088;
  *(u32 *)(param_1 + 0x26) = 0x2654808;
  return;
}

/* ksdk_offsets_852 @ 0x10ea3c size=615 */
void ksdk_offsets_852(u64 *param_1)

{
  *param_1 = 0x15d570000001c0;
  param_1[1] = 0xb5d00000b5a40;
  param_1[2] = 0x3a40f0000b5c00;
  param_1[3] = 0x20f280003d6710;
  param_1[4] = 0x270c40002199a0;
  param_1[5] = 0x3924400027c590;
  param_1[6] = 0x2bb0d0002baf10;
  param_1[7] = 0x1486d00040b420;
  param_1[8] = 0x14872000148d10;
  param_1[9] = 0x14d5100014b1d0;
  param_1[10] = 0x1498d00014b790;
  param_1[0xb] = 0x1485f000148580;
  param_1[0xc] = 0x81d2000131b50;
  param_1[0xd] = 0x1ed3d000081de0;
  param_1[0xe] = 0x3a479000456420;
  param_1[0xf] = 0x3cf6d0003a41f0;
  param_1[0x10] = 0x15d87000156e00;
  param_1[0x11] = 0x1bf100015d7b0;
  param_1[0x12] = 0x6295b000073d90;
  param_1[0x13] = 0x2639a000487240;
  param_1[0x14] = 0x620d0000263bd0;
  param_1[0x15] = 0x6208d000621040;
  param_1[0x16] = 0x62ee900061b030;
  param_1[0x17] = 0x640030006421d0;
  param_1[0x18] = 0x63e2b000641990;
  param_1[0x19] = 0x2936900062f8e0;
  param_1[0x1a] = 0x1138000010610;
  param_1[0x1b] = 0x10e6000011270;
  param_1[0x1c] = 0x1bd77b8000db870;
  param_1[0x1d] = 0x6380c0001cea20;
  param_1[0x1e] = 0x1528ff00153ae88;
  param_1[0x1f] = 0x111a8f001c64228;
  param_1[0x20] = 0x1bd72d801c66150;
  param_1[0x21] = 0x264c040010fc5c0;
  param_1[0x22] = 0x1c3d48c01583618;
  param_1[0x23] = 0x2646238000c810d;
  param_1[0x24] = 0x26500780266ca40;
  param_1[0x25] = 0x265400002650088;
  *(u32 *)(param_1 + 0x26) = 0x2654808;
  return;
}

/* ksdk_offsets_900 @ 0x10f07a size=615 */
void ksdk_offsets_900(u64 *param_1)

{
  *param_1 = 0xb7a30000001c0;
  param_1[1] = 0x301de000301b20;
  param_1[2] = 0x2714b000301ce0;
  param_1[3] = 0x271e20001496c0;
  param_1[4] = 0x30f4500037be70;
  param_1[5] = 0x1ed67000453ea0;
  param_1[6] = 0x43e7d00043e610;
  param_1[7] = 0x7bb800029a380;
  param_1[8] = 0x7bbd00007c1c0;
  param_1[9] = 0x809c00007e680;
  param_1[10] = 0x7cd800007ec40;
  param_1[0xb] = 0x7baa00007ba30;
  param_1[0xc] = 0x2196d00041eb00;
  param_1[0xd] = 0xf837000219790;
  param_1[0xe] = 0x271b5000487ab0;
  param_1[0xf] = 0x124750002715b0;
  param_1[0x10] = 0xb7d300041e380;
  param_1[0x11] = 0x3a1b30000b7c70;
  param_1[0x12] = 0x6252d000445060;
  param_1[0x13] = 0x1ff2d0004628b0;
  param_1[0x14] = 0x61f690001ff500;
  param_1[0x15] = 0x61f2600061f9d0;
  param_1[0x16] = 0x6249700061ced0;
  param_1[0x17] = 0x641c60006441e0;
  param_1[0x18] = 0x63fee0006439a0;
  param_1[0x19] = 0x8bcd000630c40;
  param_1[0x1a] = 0x97750000969e0;
  param_1[0x1b] = 0x9723000097640;
  param_1[0x1c] = 0x21f1128002d6eb0;
  param_1[0x1d] = 0x6391600016cf90;
  param_1[0x1e] = 0x15621e00152bf60;
  param_1[0x1f] = 0x111f87002268d48;
  param_1[0x20] = 0x1b946e0021eff20;
  param_1[0x21] = 0x26541c001100310;
  param_1[0x22] = 0x1b50bec01579df8;
  param_1[0x23] = 0x2646ca80004c7ad;
  param_1[0x24] = 0x26482380264db40;
  param_1[0x25] = 0x264c00002648248;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* ksdk_offsets_903 @ 0x10f69b size=615 */
void ksdk_offsets_903(u64 *param_1)

{
  *param_1 = 0xb79e0000001c0;
  param_1[1] = 0x301a70003017b0;
  param_1[2] = 0x27113000301970;
  param_1[3] = 0x271aa000149670;
  param_1[4] = 0x30f0f00037a070;
  param_1[5] = 0x1ed62000451da0;
  param_1[6] = 0x43c6f00043c530;
  param_1[7] = 0x7bb800029a000;
  param_1[8] = 0x7bbd00007c1c0;
  param_1[9] = 0x809c00007e680;
  param_1[10] = 0x7cd800007ec40;
  param_1[0xb] = 0x7baa00007ba30;
  param_1[0xc] = 0x2193a00041ca70;
  param_1[0xd] = 0xf832000219460;
  param_1[0xe] = 0x2717d0004859b0;
  param_1[0xf] = 0x12470000271230;
  param_1[0x10] = 0xb7ce00041c2f0;
  param_1[0x11] = 0x39fd30000b7c20;
  param_1[0x12] = 0x62329000442f80;
  param_1[0x13] = 0x1ff000004607b0;
  param_1[0x14] = 0x61d650001ff230;
  param_1[0x15] = 0x61d2200061d990;
  param_1[0x16] = 0x6229300061ae90;
  param_1[0x17] = 0x63fc20006421a0;
  param_1[0x18] = 0x63dea000641960;
  param_1[0x19] = 0x8bcd00062ec00;
  param_1[0x1a] = 0x97750000969e0;
  param_1[0x1b] = 0x9723000097640;
  param_1[0x1c] = 0x21ed128002d6b30;
  param_1[0x1d] = 0x6371200016cf40;
  param_1[0x1e] = 0x155e1e001527f60;
  param_1[0x1f] = 0x111b84002264d48;
  param_1[0x20] = 0x1b906e0021ebf20;
  param_1[0x21] = 0x26501c0010fc310;
  param_1[0x22] = 0x1b4cbec01575df8;
  param_1[0x23] = 0x2642ca80005325b;
  param_1[0x24] = 0x264423802649b40;
  param_1[0x25] = 0x264800002644248;
  *(u32 *)(param_1 + 0x26) = 0x2648808;
  return;
}

/* ksdk_offsets_904 @ 0x10fcd9 size=615 */
void ksdk_offsets_904(u64 *param_1)

{
  *param_1 = 0xb79e0000001c0;
  param_1[1] = 0x301a70003017b0;
  param_1[2] = 0x27113000301970;
  param_1[3] = 0x271aa000149670;
  param_1[4] = 0x30f0f00037a070;
  param_1[5] = 0x1ed62000451da0;
  param_1[6] = 0x43c6f00043c530;
  param_1[7] = 0x7bb800029a000;
  param_1[8] = 0x7bbd00007c1c0;
  param_1[9] = 0x809c00007e680;
  param_1[10] = 0x7cd800007ec40;
  param_1[0xb] = 0x7baa00007ba30;
  param_1[0xc] = 0x2193a00041ca70;
  param_1[0xd] = 0xf832000219460;
  param_1[0xe] = 0x2717d0004859b0;
  param_1[0xf] = 0x12470000271230;
  param_1[0x10] = 0xb7ce00041c2f0;
  param_1[0x11] = 0x39fd30000b7c20;
  param_1[0x12] = 0x62329000442f80;
  param_1[0x13] = 0x1ff000004607b0;
  param_1[0x14] = 0x61d650001ff230;
  param_1[0x15] = 0x61d2200061d990;
  param_1[0x16] = 0x6229300061ae90;
  param_1[0x17] = 0x63fc20006421a0;
  param_1[0x18] = 0x63dea000641960;
  param_1[0x19] = 0x8bcd00062ec00;
  param_1[0x1a] = 0x97750000969e0;
  param_1[0x1b] = 0x9723000097640;
  param_1[0x1c] = 0x21ed128002d6b30;
  param_1[0x1d] = 0x6371200016cf40;
  param_1[0x1e] = 0x155e1e001527f60;
  param_1[0x1f] = 0x111b84002264d48;
  param_1[0x20] = 0x1b906e0021ebf20;
  param_1[0x21] = 0x26501c0010fc310;
  param_1[0x22] = 0x1b4cbec01575df8;
  param_1[0x23] = 0x2642ca80005325b;
  param_1[0x24] = 0x264423802649b40;
  param_1[0x25] = 0x264800002644248;
  *(u32 *)(param_1 + 0x26) = 0x2648808;
  return;
}

/* ksdk_offsets_950 @ 0x110317 size=615 */
void ksdk_offsets_950(u64 *param_1)

{
  *param_1 = 0x205470000001c0;
  param_1[1] = 0x29d5f00029d330;
  param_1[2] = 0x201cc00029d4f0;
  param_1[3] = 0x47cb80000c1720;
  param_1[4] = 0x3f1980001889d0;
  param_1[5] = 0x1ec43000062120;
  param_1[6] = 0x42bd000042bb40;
  param_1[7] = 0x191d3000331df0;
  param_1[8] = 0x191d8000192370;
  param_1[9] = 0x196b7000194830;
  param_1[10] = 0x192f3000194df0;
  param_1[0xb] = 0x191c5000191be0;
  param_1[0xc] = 0x2bdda000479620;
  param_1[0xd] = 0x285720002bde60;
  param_1[0xe] = 0x20236000248480;
  param_1[0xf] = 0x1360b000201dc0;
  param_1[0x10] = 0x205770000b1850;
  param_1[0x11] = 0x463060002056b0;
  param_1[0x12] = 0x61f6d00021b230;
  param_1[0x13] = 0x3681a00005f060;
  param_1[0x14] = 0x619df0003683d0;
  param_1[0x15] = 0x6199c00061a130;
  param_1[0x16] = 0x61f3f000613c30;
  param_1[0x17] = 0x635d200063b1b0;
  param_1[0x18] = 0x633fa00063a970;
  param_1[0x19] = 0x32640006276e0;
  param_1[0x1a] = 0x455ba000454e30;
  param_1[0x1b] = 0x45568000455a90;
  param_1[0x1c] = 0x21458800014e430;
  param_1[0x1d] = 0x62fec000331850;
  param_1[0x1e] = 0x1a4ecb001a50be0;
  param_1[0x1f] = 0x11137d002147830;
  param_1[0x20] = 0x221d2a0021a6c30;
  param_1[0x21] = 0x263aec0010f92f0;
  param_1[0x22] = 0x21baf4c01542948;
  param_1[0x23] = 0x263a6d000015a6d;
  param_1[0x24] = 0x2648b7802658650;
  param_1[0x25] = 0x264c00002648b88;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* ksdk_offsets_951 @ 0x11094f size=615 */
void ksdk_offsets_951(u64 *param_1)

{
  *param_1 = 0x205470000001c0;
  param_1[1] = 0x29d5f00029d330;
  param_1[2] = 0x201cc00029d4f0;
  param_1[3] = 0x47cb80000c1720;
  param_1[4] = 0x3f1980001889d0;
  param_1[5] = 0x1ec43000062120;
  param_1[6] = 0x42bd000042bb40;
  param_1[7] = 0x191d3000331df0;
  param_1[8] = 0x191d8000192370;
  param_1[9] = 0x196b7000194830;
  param_1[10] = 0x192f3000194df0;
  param_1[0xb] = 0x191c5000191be0;
  param_1[0xc] = 0x2bdda000479620;
  param_1[0xd] = 0x285720002bde60;
  param_1[0xe] = 0x20236000248480;
  param_1[0xf] = 0x1360b000201dc0;
  param_1[0x10] = 0x205770000b1850;
  param_1[0x11] = 0x463060002056b0;
  param_1[0x12] = 0x61f6d00021b230;
  param_1[0x13] = 0x3681a00005f060;
  param_1[0x14] = 0x619df0003683d0;
  param_1[0x15] = 0x6199c00061a130;
  param_1[0x16] = 0x61f3f000613c30;
  param_1[0x17] = 0x635d200063b1b0;
  param_1[0x18] = 0x633fa00063a970;
  param_1[0x19] = 0x32640006276e0;
  param_1[0x1a] = 0x455ba000454e30;
  param_1[0x1b] = 0x45568000455a90;
  param_1[0x1c] = 0x21458800014e430;
  param_1[0x1d] = 0x62fec000331850;
  param_1[0x1e] = 0x1a4ecb001a50be0;
  param_1[0x1f] = 0x11137d002147830;
  param_1[0x20] = 0x221d2a0021a6c30;
  param_1[0x21] = 0x263aec0010f92f0;
  param_1[0x22] = 0x21baf4c01542948;
  param_1[0x23] = 0x263a6d000015a6d;
  param_1[0x24] = 0x2648b7802658650;
  param_1[0x25] = 0x264c00002648b88;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* ksdk_offsets_960 @ 0x110f87 size=615 */
void ksdk_offsets_960(u64 *param_1)

{
  *param_1 = 0x205470000001c0;
  param_1[1] = 0x29d5f00029d330;
  param_1[2] = 0x201cc00029d4f0;
  param_1[3] = 0x47cb80000c1720;
  param_1[4] = 0x3f1980001889d0;
  param_1[5] = 0x1ec43000062120;
  param_1[6] = 0x42bd000042bb40;
  param_1[7] = 0x191d3000331df0;
  param_1[8] = 0x191d8000192370;
  param_1[9] = 0x196b7000194830;
  param_1[10] = 0x192f3000194df0;
  param_1[0xb] = 0x191c5000191be0;
  param_1[0xc] = 0x2bdda000479620;
  param_1[0xd] = 0x285720002bde60;
  param_1[0xe] = 0x20236000248480;
  param_1[0xf] = 0x1360b000201dc0;
  param_1[0x10] = 0x205770000b1850;
  param_1[0x11] = 0x463060002056b0;
  param_1[0x12] = 0x61f6d00021b230;
  param_1[0x13] = 0x3681a00005f060;
  param_1[0x14] = 0x619df0003683d0;
  param_1[0x15] = 0x6199c00061a130;
  param_1[0x16] = 0x61f3f000613c30;
  param_1[0x17] = 0x635d200063b1b0;
  param_1[0x18] = 0x633fa00063a970;
  param_1[0x19] = 0x32640006276e0;
  param_1[0x1a] = 0x455ba000454e30;
  param_1[0x1b] = 0x45568000455a90;
  param_1[0x1c] = 0x21458800014e430;
  param_1[0x1d] = 0x62fec000331850;
  param_1[0x1e] = 0x1a4ecb001a50be0;
  param_1[0x1f] = 0x11137d002147830;
  param_1[0x20] = 0x221d2a0021a6c30;
  param_1[0x21] = 0x263aec0010f92f0;
  param_1[0x22] = 0x21baf4c01542948;
  param_1[0x23] = 0x263a6d000015a6d;
  param_1[0x24] = 0x2648b7802658650;
  param_1[0x25] = 0x264c00002648b88;
  *(u32 *)(param_1 + 0x26) = 0x264c808;
  return;
}

/* proc_offsets_1000 @ 0x106ac8 size=25 */
u8  [16] proc_offsets_1000(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1001 @ 0x1070e3 size=25 */
u8  [16] proc_offsets_1001(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1050 @ 0x1076fe size=25 */
u8  [16] proc_offsets_1050(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1071 @ 0x107d30 size=25 */
u8  [16] proc_offsets_1071(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1100 @ 0x108362 size=25 */
u8  [16] proc_offsets_1100(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1102 @ 0x10899a size=25 */
u8  [16] proc_offsets_1102(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1152 @ 0x108fd2 size=25 */
u8  [16] proc_offsets_1152(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1202 @ 0x10960a size=25 */
u8  [16] proc_offsets_1202(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1252 @ 0x109c42 size=25 */
u8  [16] proc_offsets_1252(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_1300 @ 0x10a27a size=25 */
u8  [16] proc_offsets_1300(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_505 @ 0x10a8b2 size=25 */
u8  [16] proc_offsets_505(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x46c0000044c;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_671 @ 0x10aeb2 size=25 */
u8  [16] proc_offsets_671(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_672 @ 0x10b4d2 size=25 */
u8  [16] proc_offsets_672(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_702 @ 0x10baf2 size=25 */
u8  [16] proc_offsets_702(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_750 @ 0x10c119 size=25 */
u8  [16] proc_offsets_750(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_751 @ 0x10c75d size=25 */
u8  [16] proc_offsets_751(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_755 @ 0x10cda1 size=25 */
u8  [16] proc_offsets_755(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_800 @ 0x10d3c8 size=25 */
u8  [16] proc_offsets_800(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_801 @ 0x10d9e9 size=25 */
u8  [16] proc_offsets_801(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_803 @ 0x10e027 size=25 */
u8  [16] proc_offsets_803(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_850 @ 0x10e665 size=25 */
u8  [16] proc_offsets_850(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_852 @ 0x10eca3 size=25 */
u8  [16] proc_offsets_852(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_900 @ 0x10f2e1 size=25 */
u8  [16] proc_offsets_900(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_903 @ 0x10f902 size=25 */
u8  [16] proc_offsets_903(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_904 @ 0x10ff40 size=25 */
u8  [16] proc_offsets_904(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_950 @ 0x11057e size=25 */
u8  [16] proc_offsets_950(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_951 @ 0x110bb6 size=25 */
u8  [16] proc_offsets_951(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}

/* proc_offsets_960 @ 0x1111ee size=25 */
u8  [16] proc_offsets_960(void)

{
  u8 agg1 [16];
  
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0x47400000454;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 0x3d400000390;
  return agg1;
}
