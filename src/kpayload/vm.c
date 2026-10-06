/*
 * vm.c - vm_map helpers, SBL mapping and allocation.
 */

#include <goldhen/types.h>

/* find_sbl_mapped_page @ 0x1004a4 size=29 */
s64 * find_sbl_mapped_page(s64 param_1)

{
  s64 *plVar1;
  s64 *plVar2;
  
  plVar1 = (s64 *)0x0;
  plVar2 = SBL_DRIVER_MAPPED_PAGES;
  if (param_1 != 0) {
    do {
      plVar1 = (s64 *)*plVar2;
      if (plVar1 == (s64 *)0x0) {
        return (s64 *)0;
      }
      plVar2 = plVar1;
    } while (plVar1[4] != param_1);
  }
  return plVar1;
}

/* get_sbl_mapped_page_addr @ 0x100f68 size=39 */
u64 get_sbl_mapped_page_addr(s64 param_1)

{
  u64 uVar1;
  s64 *plVar2;
  
  uVar1 = 0;
  plVar2 = SBL_DRIVER_MAPPED_PAGES;
  if (param_1 != 0) {
    do {
      plVar2 = (s64 *)*plVar2;
      if (plVar2 == (s64 *)0x0) {
        return 0;
      }
    } while (param_1 != plVar2[4]);
    uVar1 = plVar2[2];
  }
  return uVar1;
}

/* proc_vm_map_alloc @ 0x103e65 size=209 */
int proc_vm_map_alloc(s64 param_1,s64 *param_2,s64 param_3,u64 param_4)

{
  u64 uVar1;
  s64 lVar2;
  int iVar3;
  s64 local_30;
  
  iVar3 = 1;
  local_30 = 0;
  if (param_2 != (s64 *)0x0) {
    uVar1 = *(u64 *)(param_1 + 0x168);
    (*vm_map_lock)(uVar1);
    lVar2 = *param_2;
    if ((*param_2 == 0) &&
       (iVar3 = (*vm_map_findspace)(uVar1,param_4,param_3,&local_30), lVar2 = local_30, iVar3 != 0))
    {
      (*vm_map_unlock)(uVar1);
    }
    else {
      local_30 = lVar2;
      iVar3 = (*vm_map_insert)(uVar1,0,0,local_30,
                               (param_3 + 0x3fffU & 0xffffffffffffc000) + local_30,7,7,0);
      (*vm_map_unlock)(uVar1);
      if (iVar3 == 0) {
        *param_2 = local_30;
      }
    }
  }
  return iVar3;
}

/* proc_vm_map_free @ 0x103f36 size=95 */
u32 proc_vm_map_free(s64 param_1,s64 param_2,s64 param_3)

{
  u64 uVar1;
  u32 uVar2;
  
  uVar1 = *(u64 *)(param_1 + 0x168);
  (*vm_map_lock)(uVar1);
  uVar2 = (*vm_map_delete)(uVar1,param_2,(param_3 + 0x3fffU & 0xffffffffffffc000) + param_2);
  (*vm_map_unlock)(uVar1);
  return uVar2;
}

/* proc_vm_map_protect @ 0x103f95 size=107 */
void proc_vm_map_protect(s64 param_1,s64 param_2,s64 param_3,u64 param_4)

{
  s64 lVar1;
  u64 uVar2;
  int iVar3;
  
  uVar2 = *(u64 *)(param_1 + 0x168);
  lVar1 = (param_3 + 0x3fffU & 0xffffffffffffc000) + param_2;
  iVar3 = (*vm_map_protect)(uVar2,param_2,lVar1,param_4,1);
  if (iVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00103ff1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*vm_map_protect)(uVar2,param_2,lVar1,param_4 & 0xffffffff,0);
    return;
  }
  return;
}

/* set_vm_map_entry_name @ 0x103c33 size=288 */
u64 set_vm_map_entry_name(s64 param_1,s64 param_2,s64 param_3,u64 param_4,s64 param_5)

{
  int iVar1;
  s64 lVar2;
  bool bVar3;
  int iVar4;
  s64 lVar5;
  u64 uVar6;
  s64 local_40 [2];
  
  local_40[0] = 0;
  if (param_2 == 0 || param_5 == 0) {
    uVar6 = 1;
  }
  else {
    lVar2 = *(s64 *)(param_1 + 0x168);
    (*vm_map_lock_read)(lVar2);
    iVar1 = *(int *)(lVar2 + 0x100);
    if (iVar1 != 0) {
      iVar4 = (*vm_map_lookup_entry)(lVar2,0,local_40);
      if (iVar4 == 0) {
        bVar3 = false;
        lVar5 = local_40[0];
        for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
          if (((*(s64 *)(lVar5 + 0x20) == param_2) &&
              (*(s64 *)(lVar5 + 0x28) == (param_3 + 0x3fffU & 0xffffffffffffc000) + param_2)) &&
             ((*(u32 *)(lVar5 + 0x5c) >> 8 & 0xff & *(u32 *)(lVar5 + 0x5c)) == param_4)) {
            if (bVar3) {
              local_40[0] = lVar5;
            }
            (*memcpy)(lVar5 + 0x8d,param_5,0x20);
            goto l_00103d2d;
          }
          lVar5 = *(s64 *)(lVar5 + 8);
          if (lVar5 == 0) {
            local_40[0] = 0;
            goto l_00103d2d;
          }
          bVar3 = true;
        }
        if (bVar3) {
          local_40[0] = lVar5;
        }
      }
    }
l_00103d2d:
    (*vm_map_unlock_read)(lVar2);
    uVar6 = 0;
  }
  return uVar6;
}

/* snapshot_vm_map_entries @ 0x103b0f size=292 */
int snapshot_vm_map_entries(s64 param_1,s64 *param_2,s64 *param_3)

{
  int iVar1;
  s64 lVar2;
  int iVar3;
  s64 lVar4;
  s64 lVar5;
  int iVar6;
  s64 local_40 [2];
  
  lVar2 = *(s64 *)(param_1 + 0x168);
  local_40[0] = 0;
  (*vm_map_lock_read)(lVar2);
  iVar1 = *(int *)(lVar2 + 0x100);
  if (iVar1 == 0) {
    iVar3 = 0;
    lVar4 = 0;
  }
  else {
    lVar4 = 0;
    iVar3 = (*vm_map_lookup_entry)(lVar2,0,local_40);
    if (iVar3 == 0) {
      lVar4 = alloc(iVar1 * 0x3a);
      if (lVar4 == 0) {
        iVar3 = 1;
      }
      else {
        lVar5 = lVar4;
        for (iVar6 = 0; iVar6 < iVar1; iVar6 = iVar6 + 1) {
          *(u64 *)(lVar5 + 0x20) = *(u64 *)(local_40[0] + 0x20);
          *(u64 *)(lVar5 + 0x28) = *(u64 *)(local_40[0] + 0x28);
          *(u64 *)(lVar5 + 0x30) = *(u64 *)(local_40[0] + 0x50);
          *(u16 *)(lVar5 + 0x38) =
               (u16)((u32)*(u32 *)(local_40[0] + 0x5c) >> 8) & 0xff &
               (u16)*(u32 *)(local_40[0] + 0x5c);
          (*memcpy)(lVar5,local_40[0] + 0x8d,0x20);
          local_40[0] = *(s64 *)(local_40[0] + 8);
          lVar5 = lVar5 + 0x3a;
          if (local_40[0] == 0) break;
        }
      }
    }
  }
  (*vm_map_unlock_read)(lVar2);
  if (param_2 != (s64 *)0x0) {
    *param_2 = lVar4;
  }
  if (param_3 != (s64 *)0x0) {
    *param_3 = (s64)iVar1;
  }
  return iVar3;
}
