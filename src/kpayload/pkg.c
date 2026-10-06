/*
 * pkg.c - pkg and appmeta reading, title-version helpers.
 */

#include <goldhen/types.h>

/* collect_all_title_versions @ 0x105782 size=277 */
void collect_all_title_versions(s64 param_1,s64 *param_2,s64 *param_3)

{
  s64 lVar1;
  s64 lVar2;
  s64 lVar3;
  s64 lVar4;
  s64 lVar5;
  u64 *puVar6;
  s64 lVar7;
  u64 *puVar8;
  s64 local_48;
  s64 local_40;
  s64 local_38;
  s64 local_30;
  
  if (param_1 == 0) {
    param_1 = find_process_by_name("ScePartyDaemon");
  }
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  scan_appmeta_title_versions("/system_data/priv/appmeta",param_1,&local_48,&local_38);
  scan_appmeta_title_versions("/system_data/priv/appmeta/external",param_1,&local_40);
  lVar3 = local_30;
  lVar2 = local_38;
  lVar1 = local_38 + local_30;
  lVar4 = alloc((int)lVar1 << 4);
  lVar5 = 0;
  for (lVar7 = 0; lVar2 != lVar7; lVar7 = lVar7 + 1) {
    *(u64 *)(lVar4 + lVar5) = *(u64 *)(local_48 + lVar5);
    *(u64 *)(lVar4 + 8 + lVar5) = *(u64 *)(local_48 + 8 + lVar5);
    lVar5 = lVar5 + 0x10;
  }
  puVar6 = (u64 *)(lVar4 + lVar2 * 0x10);
  for (lVar5 = 0; lVar3 != lVar5; lVar5 = lVar5 + 1) {
    puVar8 = (u64 *)(lVar5 * 0x10 + local_40);
    *puVar6 = *puVar8;
    puVar6[1] = puVar8[1];
    puVar6 = puVar6 + 2;
  }
  if (param_3 != (s64 *)0x0) {
    *param_3 = lVar1;
  }
  if (param_2 != (s64 *)0x0) {
    *param_2 = lVar4;
  }
  return;
}

/* copy_appmeta_entries @ 0x1021ee size=173 */
u64 copy_appmeta_entries(s64 *param_1)

{
  s64 lVar1;
  u64 uVar2;
  s64 local_28;
  u64 local_20;
  
  local_28 = 0;
  local_20 = 0;
  if (param_1 != (s64 *)0x0) {
    collect_all_title_versions(0,&local_28,&local_20);
    if (*param_1 == 0) {
      param_1[1] = local_20;
    }
    else {
      uVar2 = 0;
      if (local_20 < (u64)param_1[1]) {
        return 1;
      }
      for (; uVar2 < local_20; uVar2 = uVar2 + 1) {
        lVar1 = uVar2 * 0x10;
        (*memcpy)(*param_1 + lVar1,local_28 + lVar1,10);
        (*memcpy)(lVar1 + *param_1 + 10,local_28 + lVar1 + 10,6);
      }
    }
  }
  return 0;
}

/* extract_app_info_from_pkg @ 0x103724 size=667 */
int extract_app_info_from_pkg(u64 param_1,s64 param_2,s64 param_3,s64 param_4)

{
  u64 uVar1;
  u8 uVar2;
  u8 uVar4;
  u8 uVar6;
  u8 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  s64 lVar11;
  int *piVar12;
  u32 *puVar13;
  int iVar14;
  u64 uVar15;
  int iVar16;
  int iVar17;
  u8 bVar18;
  u64 local_c0;
  int local_b4 [7];
  u32 local_98 [8];
  u8 local_78 [72];
  u8 uVar3;
  u8 uVar5;
  
  bVar18 = 0;
  if (param_4 == 0) {
    param_4 = find_process_by_name("ScePartyDaemon");
  }
  uVar1 = *(u64 *)(param_4 + 0x10);
  piVar12 = local_b4;
  for (lVar11 = 7; lVar11 != 0; lVar11 = lVar11 + -1) {
    *piVar12 = 0;
    piVar12 = piVar12 + (u64)bVar18 * -2 + 1;
  }
  puVar13 = local_98;
  for (lVar11 = 8; lVar11 != 0; lVar11 = lVar11 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + (u64)bVar18 * -2 + 1;
  }
  local_c0 = 0;
  jailbreak_thread(uVar1,0);
  iVar9 = sys_open(param_1,0,0,uVar1);
  if (iVar9 < 0) {
    if (iVar9 == -1) {
      return -1;
    }
  }
  else {
    sys_read(iVar9,local_b4,0x1c,uVar1);
    if (local_b4[0] == 0x544e437f) {
      iVar17 = 0;
      iVar16 = 0;
      sys_lseek(iVar9,((u32_t)((char)local_b4[6]) << 24 | (u32_t)(((u24_t)((char)((u32)local_b4[6] >> 8)) << 16 | (u24_t)(((u16_t)((char)((u32)local_b4[6] >> 0x10)) << 8 | (u16_t)((char)((u32)local_b4[6] >> 0x18))))))),0,uVar1);
      iVar14 = 0;
      iVar10 = 0;
      for (uVar15 = 0;
          uVar15 < ((u32_t)((char)local_b4[4]) << 24 | (u32_t)(((u24_t)((char)((u32)local_b4[4] >> 8)) << 16 | (u24_t)(((u16_t)((char)((u32)local_b4[4] >> 0x10)) << 8 | (u16_t)((char)((u32)local_b4[4] >> 0x18)))))));
          uVar15 = uVar15 + 1) {
        sys_read(iVar9,local_98,0x20,uVar1);
        iVar8 = ((u32_t)((char)local_98[0]) << 24 | (u32_t)(((u24_t)((char)((u32)local_98[0] >> 8)) << 16 | (u24_t)(((u16_t)((char)((u32)local_98[0] >> 0x10)) << 8 | (u16_t)((char)((u32)local_98[0] >> 0x18)))))));
        uVar4 = (u8)((u32)local_98[4] >> 8);
        uVar2 = (u8)((u32)local_98[4] >> 0x10);
        uVar6 = (u8)((u32)local_98[4] >> 0x18);
        uVar5 = (u8)((u32)local_98[5] >> 8);
        uVar3 = (u8)((u32)local_98[5] >> 0x10);
        uVar7 = (u8)((u32)local_98[5] >> 0x18);
        if (iVar8 == 0x1000) {
          iVar10 = ((u32_t)((char)local_98[4]) << 24 | (u32_t)(((u24_t)(uVar4) << 16 | (u24_t)(((u16_t)(uVar2) << 8 | (u16_t)(uVar6))))));
          iVar14 = ((u32_t)((char)local_98[5]) << 24 | (u32_t)(((u24_t)(uVar5) << 16 | (u24_t)(((u16_t)(uVar3) << 8 | (u16_t)(uVar7))))));
        }
        else if (iVar8 == 0x1200) {
          iVar16 = ((u32_t)((char)local_98[4]) << 24 | (u32_t)(((u24_t)(uVar4) << 16 | (u24_t)(((u16_t)(uVar2) << 8 | (u16_t)(uVar6))))));
          iVar17 = ((u32_t)((char)local_98[5]) << 24 | (u32_t)(((u24_t)(uVar5) << 16 | (u24_t)(((u16_t)(uVar3) << 8 | (u16_t)(uVar7))))));
        }
      }
      if ((iVar10 != 0) && (iVar14 != 0)) {
        iVar10 = read_pkg_entry_to_buffer(uVar1,iVar9,&local_c0,iVar10);
        if (iVar10 == 0) {
          iVar10 = parse_param_sfo(local_c0,iVar14,param_3);
        }
        dealloc(local_c0);
        if (iVar10 != 0) goto l_0010399c;
      }
      if ((((param_2 == 0) || (lVar11 = (*strlen)(param_2), param_3 == 0)) || (lVar11 == 0)) ||
         (((lVar11 = (*strlen)(param_3), lVar11 == 0 || (iVar16 == 0)) || (iVar17 == 0)))) {
        iVar10 = 0;
      }
      else {
        (*snprintf)(local_78,0x40,"%s/%s.png",param_2,param_3);
        iVar10 = extract_pkg_entry_to_file(uVar1,iVar9,local_78,iVar16,iVar17);
        (*printf)("[+] icon0_png_path: %s - offset: 0x%lx - size: 0x%lx - ret: %d\n",local_78,iVar16
                  ,iVar17,iVar10);
        if (iVar10 == 0) {
          (*strncpy)(param_3 + 0xd4,local_78,0x40);
        }
      }
      goto l_0010399c;
    }
  }
  iVar10 = -1;
l_0010399c:
  sys_close(iVar9,uVar1);
  return iVar10;
}

/* extract_pkg_entry_to_file @ 0x10345b size=183 */
u64
extract_pkg_entry_to_file(u64 param_1,u32 param_2,u64 param_3,u64 param_4,
            u32 param_5)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  
  iVar1 = sys_open(param_3,0x601,0x180,param_1);
  if (iVar1 == -1) {
    uVar3 = 0xffffffff;
    lVar2 = 0;
  }
  else {
    uVar3 = 0xffffffff;
    lVar2 = alloc(param_5);
    if (lVar2 != 0) {
      uVar3 = 0;
      sys_lseek(param_2,param_4,0,param_1);
      sys_read(param_2,lVar2,param_5,param_1);
      sys_write(iVar1,lVar2,param_5,param_1);
    }
  }
  dealloc(lVar2);
  if (iVar1 != -1) {
    sys_close(iVar1,param_1);
  }
  return uVar3;
}

/* fill_app_info_from_pkg @ 0x10229b size=124 */
bool fill_app_info_from_pkg(s64 param_1)

{
  int iVar1;
  s64 lVar2;
  bool bVar3;
  
  if (((param_1 == 0) || (*(s64 *)(param_1 + 0x440) == 0)) || (lVar2 = alloc(0x114), lVar2 == 0)) {
    bVar3 = true;
  }
  else {
    iVar1 = extract_app_info_from_pkg(param_1,param_1 + 0x400,lVar2,0);
    bVar3 = iVar1 != 0;
    if (!bVar3) {
      (*memcpy)(*(u64 *)(param_1 + 0x440),lVar2,0x114);
    }
    dealloc(lVar2);
  }
  return bVar3;
}

/* fill_app_version_field @ 0x10219b size=83 */
u64 fill_app_version_field(s64 *param_1)

{
  u64 uVar1;
  s64 lVar2;
  
  uVar1 = 1;
  if (param_1 != (s64 *)0x0) {
    if (*param_1 != 0) {
      lVar2 = get_appmeta_version_for_title(*param_1,0);
      if (lVar2 == 0) {
        (*memset)(*param_1 + 10,0,6);
      }
      else {
        (*memcpy)(*param_1 + 10,lVar2,6);
      }
      uVar1 = 0;
    }
    return uVar1;
  }
  return uVar1;
}

/* get_appmeta_version_for_title @ 0x10553f size=85 */
void get_appmeta_version_for_title(u64 param_1,s64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  s64 lVar1;
  
  if (param_2 == 0) {
    param_2 = find_process_by_name("ScePartyDaemon");
  }
  lVar1 = get_title_version_from_appmeta("/system_data/priv/appmeta",param_1,param_2);
  if (lVar1 == 0) {
    get_title_version_from_appmeta("/system_data/priv/appmeta/external",param_1,param_2,param_5);
    return;
  }
  return;
}

/* get_title_version_from_appmeta @ 0x105390 size=431 */
s64 get_title_version_from_appmeta(u64 param_1,u64 param_2,s64 param_3)

{
  u64 uVar1;
  int iVar2;
  int iVar3;
  s64 lVar4;
  u64 uVar5;
  int *piVar6;
  u32 *puVar7;
  s64 lVar8;
  s64 lVar9;
  u64 local_88;
  u8 local_6a [58];
  
  if ((param_3 == 0) || (lVar4 = (*strlen)(param_2), lVar4 != 9)) {
    return 0;
  }
  iVar2 = (*sprintf)(local_6a,"%s/%s/param.sfo",param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  uVar1 = *(u64 *)(param_3 + 0x10);
  jailbreak_thread(uVar1,0);
  iVar2 = sys_open(local_6a,0,0,uVar1);
  if (iVar2 < 0) {
    return 0;
  }
  uVar5 = sys_lseek(iVar2,0,2,uVar1);
  if (uVar5 < 8) {
    lVar4 = 0;
    piVar6 = (int *)0x0;
    if (iVar2 == 0) {
      return 0;
    }
l_001054ff:
    sys_close(iVar2,uVar1);
  }
  else {
    sys_lseek(iVar2,0,0,uVar1);
    piVar6 = (int *)alloc(uVar5 & 0xffffffff);
    lVar4 = 0;
    iVar3 = sys_read(iVar2,piVar6,uVar5 & 0xffffffff,uVar1);
    if (-1 < iVar3) {
      if (*piVar6 == 0x46535000) {
        puVar7 = (u32 *)(piVar6 + 8);
        lVar9 = 0;
        for (local_88 = 0; local_88 < (u32)piVar6[4]; local_88 = local_88 + 1) {
          lVar8 = (u64)(u32)piVar6[2] + (u64)(u16)puVar7[-3] + (s64)piVar6;
          iVar3 = (*memcmp)(lVar8,"APP_VER",7);
          if (iVar3 == 0) {
            lVar4 = (u64)(u32)piVar6[3] + (u64)*puVar7 + (s64)piVar6;
          }
          else {
            iVar3 = (*memcmp)(lVar8,"VERSION",7);
            if (iVar3 == 0) {
              lVar9 = (u64)(u32)piVar6[3] + (u64)*puVar7 + (s64)piVar6;
            }
          }
          puVar7 = puVar7 + 4;
        }
        lVar4 = pick_highest_version_string(lVar4,lVar9);
      }
      if (iVar2 == 0) goto l_0010550e;
      goto l_001054ff;
    }
    if (iVar2 != 0) goto l_001054ff;
  }
  if (piVar6 == (int *)0x0) {
    return lVar4;
  }
l_0010550e:
  dealloc(piVar6);
  return lVar4;
}

/* parse_param_sfo @ 0x103580 size=420 */
u64 parse_param_sfo(int *param_1,u64 param_2,s64 param_3)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  s64 lVar4;
  u64 uVar5;
  s64 lVar6;
  u16 *puVar7;
  u32 uVar8;
  
  uVar5 = 0xffffffff;
  if (param_2 < 0x14) {
    return 0xffffffff;
  }
  if (*param_1 == 0x46535000) {
    puVar7 = (u16 *)(param_1 + 5);
    uVar8 = 0;
    while( true ) {
      lVar4 = param_3 + 0xbe;
      if ((u32)param_1[4] <= uVar8) break;
      uVar1 = param_1[3];
      uVar2 = *(u32 *)(puVar7 + 6);
      lVar6 = (u64)(u32)param_1[2] + (u64)*puVar7 + (s64)param_1;
      iVar3 = (*strncmp)("TITLE_ID",lVar6,10);
      if (iVar3 == 0) {
        uVar5 = 10;
        lVar4 = param_3;
l_001036d8:
        (*strncpy)(lVar4,(u64)uVar1 + (u64)uVar2 + (s64)param_1,uVar5);
      }
      else {
        iVar3 = (*strncmp)("CONTENT_ID",lVar6,0x30);
        if (iVar3 == 0) {
          lVar4 = param_3 + 10;
          uVar5 = 0x30;
          goto l_001036d8;
        }
        iVar3 = (*strncmp)("TITLE",lVar6,0x80);
        if (iVar3 == 0) {
          lVar4 = param_3 + 0x3a;
          uVar5 = 0x80;
          goto l_001036d8;
        }
        iVar3 = (*strncmp)("CATEGORY",lVar6,4);
        if (iVar3 == 0) {
          lVar4 = param_3 + 0xba;
          uVar5 = 4;
          goto l_001036d8;
        }
        iVar3 = (*strncmp)("APP_VER",lVar6,8);
        uVar5 = 8;
        if (iVar3 == 0) goto l_001036d8;
        iVar3 = (*strncmp)("VERSION",lVar6,8);
        if (iVar3 == 0) {
          uVar5 = 8;
          lVar4 = param_3 + 0xc6;
          goto l_001036d8;
        }
      }
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 8;
    }
    lVar4 = pick_highest_version_string(lVar4,param_3 + 0xc6);
    uVar5 = 0;
    if (lVar4 != 0) {
      (*strncpy)(param_3 + 0xce,lVar4,6);
      uVar5 = 0;
    }
  }
  return uVar5;
}

/* pick_highest_version_string @ 0x105309 size=135 */
u64 pick_highest_version_string(s64 param_1,s64 param_2)

{
  void (*pcVar1)(void);
  u64 uVar2;
  float fVar3;
  float fVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = alloc(6);
    (*memset)(uVar2,0,6);
    pcVar1 = memcpy;
    fVar3 = (float)version_string_to_float(param_1);
    fVar4 = (float)version_string_to_float(param_2);
    if (fVar3 <= fVar4) {
      param_1 = param_2;
    }
    (*pcVar1)(uVar2,param_1,5);
  }
  return uVar2;
}

/* read_pkg_entry_to_buffer @ 0x103512 size=110 */
u8  [16]
read_pkg_entry_to_buffer(u64 param_1,u32 param_2,s64 *param_3,u64 param_4,
            u32 param_5,u64 param_6)

{
  s64 lVar1;
  u64 uVar2;
  u8 agg3 [16];
  
  if (param_3 != (s64 *)0x0) {
    lVar1 = alloc(param_5);
    uVar2 = 0xffffffff;
    if (lVar1 != 0) {
      sys_lseek(param_2,param_4,0,param_1);
      sys_read(param_2,lVar1,param_5,param_1);
      *param_3 = lVar1;
      uVar2 = 0;
    }
    (*(u8_t *)((u8 *)&agg3 + 1)) = param_6;
    (*(u8_t *)((u8 *)&agg3 + 0)) = uVar2;
    return agg3;
  }
  return (u64_t)(0xffffffff);
}

/* scan_appmeta_title_versions @ 0x105594 size=494 */
u64 scan_appmeta_title_versions(u64 param_1,s64 param_2,s64 *param_3,s64 *param_4)

{
  u8 *puVar1;
  u64 uVar2;
  int iVar3;
  int iVar4;
  s64 lVar5;
  s64 lVar6;
  s64 lVar7;
  int iVar8;
  int iVar9;
  int local_480;
  u64 local_440;
  u8 local_438 [4];
  u16 local_434 [2];
  u8 local_430 [1024];
  
  local_440 = 0;
  if (param_2 != 0) {
    uVar2 = *(u64 *)(param_2 + 0x10);
    jailbreak_thread(uVar2,0);
    iVar3 = sys_open(param_1,0,0,uVar2);
    if (-1 < iVar3) {
      iVar4 = sys_getdirentries(iVar3,local_438,0x400,&local_440,uVar2);
      if (iVar4 < 0) {
l_00105618:
        lVar5 = 0;
        iVar9 = 0;
      }
      else {
        iVar9 = 0;
        for (iVar8 = 0; iVar8 < iVar4;
            iVar8 = iVar8 + (u32)*(u16 *)((s64)local_434 + (s64)iVar8)) {
          lVar5 = (*strlen)(local_430 + iVar8);
          if (lVar5 == 9) {
            iVar9 = iVar9 + 1;
          }
        }
        if (iVar9 == 0) goto l_00105618;
        lVar5 = alloc(iVar9 << 4);
        if (lVar5 != 0) {
          local_480 = 0;
          for (iVar8 = 0; iVar8 < iVar4;
              iVar8 = iVar8 + (u32)*(u16 *)((s64)local_434 + (s64)iVar8)) {
            puVar1 = local_430 + iVar8;
            lVar6 = (*strlen)(puVar1);
            if ((local_480 < iVar9) && (lVar6 == 9)) {
              lVar7 = (s64)local_480 * 0x10 + lVar5;
              (*memcpy)(lVar7,puVar1,10);
              lVar6 = get_title_version_from_appmeta(param_1,puVar1,param_2);
              if (lVar6 == 0) {
                (*memset)(lVar7 + 10,0,6);
              }
              else {
                (*memcpy)();
              }
              local_480 = local_480 + 1;
            }
          }
        }
      }
      if (iVar3 != 0) {
        sys_close(iVar3,uVar2);
      }
      goto l_0010574b;
    }
  }
  lVar5 = 0;
  iVar9 = 0;
l_0010574b:
  if (param_3 != (s64 *)0x0) {
    *param_3 = lVar5;
  }
  if (param_4 != (s64 *)0x0) {
    *param_4 = (s64)iVar9;
  }
  return 0;
}
