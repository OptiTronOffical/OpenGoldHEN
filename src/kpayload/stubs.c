/*
 * stubs.c - tiny return and trap stubs used as patch targets.
 */

#include <goldhen/types.h>

/* inject_fake_symbol_stub @ 0x10446a size=219 */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int inject_fake_symbol_stub(u64 param_1,u64 param_2,s64 *param_3)

{
  s64 lVar1;
  int iVar2;
  s64 lVar3;
  u64 local_40;
  s64 local_38 [2];
  
  local_38[0] = 0;
  local_38[1] = 0;
  lVar3 = (s64)(int)(g_bytes_001879c8 + 0x83fffU & 0xffffc000);
  local_40 = param_2;
  iVar2 = proc_vm_map_alloc(param_1,local_38,lVar3,param_2);
  lVar1 = local_38[0];
  if (iVar2 == 0) {
    iVar2 = proc_write_mem(param_1,local_38[0],(s64)g_bytes_001879c8,g_bytes_0018795c);
    if ((iVar2 == 0) &&
       (iVar2 = proc_write_mem(param_1,lVar1 + 0xc,8,&local_40,local_38 + 1), iVar2 == 0)) {
      *param_3 = lVar1 + g_bytes_00187960;
      return 0;
    }
  }
  if (local_38[0] != 0) {
    proc_vm_map_free(param_1,local_38[0],lVar3);
  }
  return iVar2;
}

/* noop_stub @ 0x1039bf size=5 */
void noop_stub(void)

{
  return;
}

/* return_one_stub @ 0x1027ab size=10 */
u64 return_one_stub(void)

{
  return 1;
}

/* return_zero_stub @ 0x1027a4 size=7 */
u64 return_zero_stub(void)

{
  return 0;
}
