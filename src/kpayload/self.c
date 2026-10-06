/*
 * self.c - SELF/payload format handling and HMAC helpers.
 */

#include <goldhen/types.h>

/* compute_hmac_sha256 @ 0x10040b size=153 */
void compute_hmac_sha256(u64 param_1,u64 param_2,u32 param_3,u64 param_4)

{
  u64 uVar1;
  u64 *reg_gs_offset;
  u32 local_4c;
  u8 local_48 [24];
  
  uVar1 = *reg_gs_offset;
  (*memset)(&local_4c,0,0x14);
  local_4c = param_3;
  (*memcpy)(local_48,param_2,0x10);
  (*fpu_kern_enter)(uVar1,FPU_CTX,0);
  (*Sha256Hmac)(param_4,&local_4c,0x14,param_1,0x20);
  (*fpu_kern_leave)(uVar1,FPU_CTX);
  return;
}

/* decrypt_self_header @ 0x100910 size=115 */
u64 decrypt_self_header(s64 param_1)

{
  u64 uVar1;
  int iVar2;
  u64 uVar3;
  u64 *reg_gs_offset;
  
  uVar3 = 0x800f0a25;
  uVar1 = *reg_gs_offset;
  (*fpu_kern_enter)(uVar1,FPU_CTX,0);
  iVar2 = (*AesCbcCfb128Decrypt)(param_1 + 0x10,param_1 + 0x10,0x90,g_bytes_00196800,0x80);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  (*fpu_kern_leave)(uVar1,FPU_CTX);
  return uVar3;
}

/* identify_payload_format @ 0x104b43 size=58 */
int identify_payload_format(int *param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 < 5)) {
    iVar1 = -1;
  }
  else {
    iVar1 = 1;
    if (*param_1 != 0x464c457f) {
      iVar1 = -1;
      if (((char)*param_1 == -0x17) &&
         (iVar2 = *(int *)((s64)param_1 + 1) + 5, iVar1 = -1, -1 < iVar2)) {
        return -(u32)((int)param_2 < iVar2);
      }
    }
  }
  return iVar1;
}

/* is_fself @ 0x100c46 size=61 */
bool is_fself(int *param_1)

{
  int iVar1;
  bool bVar2;
  s64 local_10;
  
  bVar2 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 2)) {
    iVar1 = (*sceSblAuthMgrGetSelfInfo)(param_1,&local_10);
    if (iVar1 == 0) {
      bVar2 = *(s64 *)(local_10 + 8) == 1;
    }
  }
  return bVar2;
}
