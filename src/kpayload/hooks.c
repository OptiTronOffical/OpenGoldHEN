/*
 * hooks.c - kernel hooks and their installers.
 */

#include <goldhen/types.h>

/* acmgr_get_path_id_hook @ 0x100bfa size=76 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void acmgr_get_path_id_hook(s64 param_1)

{
  s64 lVar1;
  
  if ((param_1 != 0) && (lVar1 = (*strstr)(param_1,"/data/self/"), lVar1 != 0)) {
    param_1 = (*strlen)("/data/self/");
    param_1 = lVar1 + param_1;
  }
                    /* WARNING: Could not recover jumptable at 0x00100c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_sceSblACMgrGetPathId)(param_1);
  return;
}

/* authmgr_sm_is_loadable2_hook @ 0x100dcc size=412 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

u64 authmgr_sm_is_loadable2_hook(int *param_1,s64 param_2,u32 param_3,s64 param_4)

{
  u16 uVar1;
  int iVar2;
  u32 uVar3;
  s64 lVar4;
  u64 uVar5;
  s64 *plVar6;
  u8 *puVar7;
  u64 *local_a8;
  u64 local_a0 [17];
  
  if ((*param_1 != 1) && (iVar2 = is_fself(), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x00100e1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*_sceSblAuthMgrSmIsLoadable2)(param_1,param_2,param_3,param_4);
    return uVar5;
  }
  if (((param_2 == 0) || (param_4 == 0)) || (iVar2 = is_fself(param_1), iVar2 == 0)) {
    return 0x16;
  }
  uVar3 = (*sceSblAuthMgrGetSelfInfo)(param_1,&local_a8);
  if (uVar3 != 0) {
    return (u64)uVar3;
  }
  if (*param_1 == 1) {
    lVar4 = *(s64 *)(param_1 + 0xe);
    if (lVar4 == 0) {
      return 3;
    }
  }
  else {
    if (*param_1 != 2) {
      return 0xffffffdd;
    }
    lVar4 = *(s64 *)(param_1 + 0xe);
    uVar5 = ((u64)*(u16 *)(lVar4 + 0xc) - 0x20) + (u64)*(u16 *)(lVar4 + 0x18) * -0x20;
    if ((uVar5 < 0x40) || ((uVar5 & 0xf) != 0)) {
      return 0xffffffdb;
    }
    plVar6 = (s64 *)(((u64)*(u16 *)(lVar4 + 0xc) - 0x100) + (u64)*(u16 *)(lVar4 + 0xe) +
                     lVar4);
    lVar4 = lVar4 + 0x20 + (u64)*(u16 *)(lVar4 + 0x18) * 0x20;
    if (*plVar6 == 0x88) {
      (*memcpy)(local_a0,plVar6 + 1,0x88);
      goto l_00100f25;
    }
  }
  uVar1 = (u16)*(u32 *)(lVar4 + 0x10);
  if (uVar1 == 0xfe18) {
    puVar7 = g_bytes_00196820;
  }
  else {
    if ((0xfe18 < uVar1) || (((uVar1 & 0xffef) != 0xfe00 && (uVar1 != 2)))) {
      return 0x2d;
    }
    puVar7 = g_bytes_001968c0;
  }
  (*memcpy)(local_a0,puVar7,0x88);
  local_a0[0] = *local_a8;
l_00100f25:
  (*memcpy)(param_4,local_a0,0x88);
  return 0;
}

/* authmgr_verify_header_hook @ 0x100c83 size=241 */
u32 authmgr_verify_header_hook(int *param_1)

{
  int iVar1;
  s64 lVar2;
  u32 uVar3;
  int iVar4;
  s64 lVar5;
  int iVar6;
  u8 local_40 [16];
  
  (*sceSblAuthMgrSmStart)(local_40);
  if ((*param_1 != 1) && (iVar4 = is_fself(param_1), iVar4 == 0)) {
    uVar3 = (*sceSblAuthMgrVerifyHeader)(param_1);
    return uVar3;
  }
  lVar2 = MINI_SYSCORE_SELF_BINARY;
  iVar4 = *param_1;
  uVar3 = 0xc;
  iVar1 = param_1[2];
  iVar6 = (u32)*(u16 *)(MINI_SYSCORE_SELF_BINARY + 0xc) +
          (u32)*(u16 *)(MINI_SYSCORE_SELF_BINARY + 0xe);
  lVar5 = alloc(iVar6);
  if (lVar5 != 0) {
    (*memcpy)(lVar5,*(u64 *)(param_1 + 0xe),iVar6);
    (*memcpy)(*(u64 *)(param_1 + 0xe),lVar2,iVar6);
    *param_1 = 2;
    param_1[2] = iVar6;
    uVar3 = (*sceSblAuthMgrVerifyHeader)(param_1);
    (*memcpy)(*(u64 *)(param_1 + 0xe),lVar5,iVar6);
    *param_1 = iVar4;
    param_1[2] = iVar1;
    dealloc(lVar5);
  }
  return uVar3;
}

/* fself_mailbox_copy_hook @ 0x100f8f size=291 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

u64 fself_mailbox_copy_hook(u64 param_1,s64 param_2,u64 param_3)

{
  int iVar1;
  u32 uVar2;
  s64 lVar3;
  s64 lVar4;
  int iVar5;
  s64 lVar6;
  s64 lVar7;
  s64 lVar8;
  u64 uVar9;
  s64 reg_rbp;
  
  uVar9 = *(u64 *)(param_2 + 8);
  lVar3 = *(s64 *)(param_2 + 0x50);
  lVar4 = *(s64 *)(param_2 + 0x58);
  iVar1 = *(int *)(param_2 + 0x48);
  uVar2 = *(u32 *)(param_2 + 0x44);
  if (*(int **)(reg_rbp + -8) != (int *)0x0) {
    if (**(int **)(reg_rbp + -8) != 1) {
      iVar5 = is_fself();
      if (iVar5 == 0) goto l_00101015;
    }
    lVar8 = 0;
    lVar6 = get_sbl_mapped_page_addr(uVar9);
    lVar7 = get_sbl_mapped_page_addr(lVar3);
    if (lVar4 != 0) {
      lVar8 = get_sbl_mapped_page_addr(lVar4);
    }
    if ((lVar6 != 0) && (lVar7 != 0)) {
      if ((lVar4 == 0 || lVar3 == lVar4) || (uVar2 == 0)) {
        (*memcpy)(lVar6,(u64)uVar2 + lVar7,iVar1);
      }
      else {
        (*memcpy)(lVar6,(u64)uVar2 + lVar7,(u64)(0x4000 - uVar2));
        if (lVar8 != 0) {
          (*memcpy)((u64)(0x4000 - uVar2) + lVar6,lVar8,(uVar2 - 0x4000) + iVar1);
        }
      }
    }
    *(u32 *)(param_2 + 4) = 0;
    return 0;
  }
l_00101015:
                    /* WARNING: Could not recover jumptable at 0x00101029. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar9 = (*_sceSblServiceMailbox)(param_1,param_2,param_3);
  return uVar9;
}

/* fself_mailbox_hook @ 0x100d74 size=88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

u64 fself_mailbox_hook(u64 param_1,u64 param_2,s64 param_3)

{
  int iVar1;
  u64 uVar2;
  s64 reg_rbp;
  
  if (*(s64 *)(reg_rbp + -8) != 0) {
    iVar1 = is_fself();
    if (iVar1 != 0) {
      *(u32 *)(param_3 + 4) = 0;
      return 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00100db5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*_sceSblServiceMailbox)(param_1,param_2);
  return uVar2;
}

/* install_fakepkg_hooks @ 0x100a65 size=405 */
void install_fakepkg_hooks(void)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  u16 uVar6;
  s64 lVar7;
  int iVar8;
  u8 local_200 [32];
  u32 local_1e0;
  u32 local_1dc;
  u32 local_1d8;
  u32 local_1d4;
  u32 local_1d0;
  
  uVar6 = get_firmware();
  get_goldhen_offsets(local_200,uVar6);
  lVar7 = get_kbase();
  uVar1 = *(u64 *)(sysents + 0x48c8);
  uVar2 = *(u64 *)(sysents + 0x48f8);
  uVar3 = *(u64 *)(sysents + 0x49e8);
  uVar4 = *(u64 *)(sysents + 0x4ce8);
  uVar5 = *(u64 *)(sysents + 0x4d18);
  write_abs_jump_stub(uVar1,keymgr_sm_callfunc_hook);
  *(u8 *)((u64)local_1d8 + lVar7) = 0xe8;
  iVar8 = (int)lVar7;
  *(u32 *)((u8 *)((u64)local_1d8 + lVar7) + 1) = ((-5 - local_1d8) + (int)uVar1) - iVar8;
  write_abs_jump_stub(uVar2,keymgr_ms_callfunc_hook);
  *(u8 *)((u64)local_1d4 + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1d4 + lVar7) + 1) = ((-5 - local_1d4) + (int)uVar2) - iVar8;
  write_abs_jump_stub(uVar3,sbl_driver_send_msg_hook);
  *(u8 *)((u64)local_1e0 + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1e0 + lVar7) + 1) = ((-5 - local_1e0) + (int)uVar3) - iVar8;
  write_abs_jump_stub(uVar4,keymgr_restore_key_storage_hook);
  *(u8 *)((u64)local_1dc + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1dc + lVar7) + 1) = ((-5 - local_1dc) + (int)uVar4) - iVar8;
  write_abs_jump_stub(uVar5,pfs_set_keys_hook);
  *(u8 *)((u64)local_1d0 + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1d0 + lVar7) + 1) = ((-5 - local_1d0) + (int)uVar5) - iVar8;
                    /* WARNING: Could not recover jumptable at 0x00100bf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*printf)("[GoldHEN] FakePKG hooks installed!\n");
  return;
}

/* install_fakeself_hooks @ 0x1010b2 size=441 */
void install_fakeself_hooks(void)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  u16 uVar6;
  s64 lVar7;
  int iVar8;
  int iVar9;
  u8 local_200 [8];
  u32 local_1f8;
  u32 local_1f4;
  u32 local_1f0;
  u32 local_1ec;
  u32 local_1e8;
  u32 local_1e4;
  
  uVar6 = get_firmware();
  get_goldhen_offsets(local_200,uVar6);
  lVar7 = get_kbase();
  uVar1 = *(u64 *)(sysents + 0x4cb8);
  uVar2 = *(u64 *)(sysents + 0x4808);
  uVar3 = *(u64 *)(sysents + 0x4838);
  uVar4 = *(u64 *)(sysents + 0x4898);
  uVar5 = *(u64 *)(sysents + 0x4868);
  write_abs_jump_stub(uVar1,authmgr_sm_is_loadable2_hook);
  *(u8 *)((u64)local_1f4 + lVar7) = 0xe8;
  iVar8 = (int)lVar7;
  *(u32 *)((u8 *)((u64)local_1f4 + lVar7) + 1) = ((-5 - local_1f4) + (int)uVar1) - iVar8;
  write_abs_jump_stub(uVar2,authmgr_verify_header_hook);
  *(u8 *)((u64)local_1f0 + lVar7) = 0xe8;
  iVar9 = (int)uVar2;
  *(u32 *)((u8 *)((u64)local_1f0 + lVar7) + 1) = ((-5 - local_1f0) + iVar9) - iVar8;
  *(u8 *)((u64)local_1ec + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1ec + lVar7) + 1) = ((-5 - local_1ec) + iVar9) - iVar8;
  write_abs_jump_stub(uVar3,fself_mailbox_hook);
  *(u8 *)((u64)local_1e8 + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1e8 + lVar7) + 1) = ((-5 - local_1e8) + (int)uVar3) - iVar8;
  write_abs_jump_stub(uVar4,fself_mailbox_copy_hook);
  *(u8 *)((u64)local_1e4 + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1e4 + lVar7) + 1) = ((-5 - local_1e4) + (int)uVar4) - iVar8;
  write_abs_jump_stub(uVar5,acmgr_get_path_id_hook);
  *(u8 *)((u64)local_1f8 + lVar7) = 0xe8;
  *(u32 *)((u8 *)((u64)local_1f8 + lVar7) + 1) = ((-5 - local_1f8) + (int)uVar5) - iVar8;
                    /* WARNING: Could not recover jumptable at 0x00101265. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*printf)("[GoldHEN] FakeSelf hooks installed!\n");
  return;
}

/* install_function_hook @ 0x105dc7 size=239 */
s64 * install_function_hook(s64 *param_1,s64 param_2,s64 param_3,s64 param_4,s64 param_5)

{
  int iVar1;
  u32 uVar2;
  u64 uVar3;
  u64 reg_r13;
  s64 reg_r15;
  u8 local_5d [34];
  u8 local_3b;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    reg_r15 = 0;
  }
  else {
    uVar3 = 0;
    do {
      iVar1 = decode_x86_instruction(uVar3 + param_2,local_5d);
      if ((local_3b & 0x10) != 0) goto l_00105e95;
      uVar2 = (int)uVar3 + iVar1;
      uVar3 = (u64)uVar2;
    } while (uVar2 < 0xe);
    reg_r13 = (u64)(uVar2 + 0xe);
    reg_r15 = rwx_alloc(reg_r13);
    param_4 = param_3;
    param_5 = param_2;
    if (reg_r15 != 0) {
      (*memcpy)(reg_r15,param_2,uVar3);
      write_abs_jump_stub(reg_r15 + uVar3,param_2 + uVar3);
      write_abs_jump_stub(param_2,param_3);
    }
  }
l_00105e95:
  param_1[2] = reg_r15;
  param_1[3] = reg_r13;
  *param_1 = param_5;
  param_1[1] = param_4;
  return param_1;
}

/* install_sysmodule_preload_hook @ 0x1002fd size=66 */
u64 install_sysmodule_preload_hook(void)

{
  g_saved_sysent_00198420 = *(u64 *)(sysents + 0x6ed8);
  *(void (**)(void))(sysents + 0x6ed8) = sysmodule_preload_module_hook;
  return 0;
}

/* keymgr_ms_callfunc_hook @ 0x100983 size=145 */
int keymgr_ms_callfunc_hook(s64 param_1)

{
  int iVar1;
  int iVar2;
  s64 lVar3;
  s64 lVar4;
  
  lVar4 = 0;
  lVar3 = find_sbl_mapped_page(*(u64 *)(param_1 + 8));
  if (lVar3 != 0) {
    lVar4 = *(s64 *)(lVar3 + 0x10);
  }
  iVar1 = (*sceSblKeymgrSmCallfunc)(param_1);
  if ((((iVar1 != 0) || (*(int *)(param_1 + 4) != 0)) && (lVar4 != 0)) &&
     (*(short *)(lVar4 + 0x50) == 2)) {
    iVar2 = decrypt_self_header(lVar4 + 0x260);
    if (iVar2 == 0) {
      iVar1 = 0;
      (*memcpy)(lVar4,lVar4 + 0x260,0xa0);
      (*memset)(lVar4 + 0xa0,0,0x360);
      *(u32 *)(param_1 + 4) = 0;
    }
  }
  return iVar1;
}

/* keymgr_restore_key_storage_hook @ 0x100869 size=167 */
u32 keymgr_restore_key_storage_hook(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  uVar3 = (*sx_xlock)();
  puVar5 = (u32 *)*SBL_KEYMGR_KEY_SLOTS;
  do {
    if (puVar5 == (u32 *)0x0) {
      return uVar3;
    }
    uVar2 = puVar5[2];
    if (uVar2 != 0xffffffff) {
      puVar4 = (u32 *)*SBL_KEYMGR_KEY_RBTREE;
      do {
        while( true ) {
          while( true ) {
            if (puVar4 == (u32 *)0x0) goto l_001008c8;
            uVar1 = *puVar4;
            if (uVar2 <= uVar1) break;
            puVar4 = *(u32 **)(puVar4 + 0x24);
          }
          if (uVar1 <= uVar2) break;
          puVar4 = *(u32 **)(puVar4 + 0x22);
        }
      } while (uVar2 != uVar1);
      if (((puVar4[1] != 0) && ((short)puVar4[2] == 0x1337)) &&
         (*(short *)((s64)puVar4 + 10) == 0x20)) {
        (*memcpy)(SBL_KEYMGR_BUF_VA,puVar4 + 3,0x20);
        (*sceSblKeymgrSetKeyStorage)
                  (*SBL_KEYMGR_BUF_GVA,*(u16 *)((s64)puVar4 + 10),(short)puVar4[2],*puVar5);
      }
    }
l_001008c8:
    puVar5 = *(u32 **)(puVar5 + 4);
  } while( true );
}

/* keymgr_sm_callfunc_hook @ 0x100a14 size=81 */
u8  [16] keymgr_sm_callfunc_hook(s64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u32 uVar1;
  s64 lVar2;
  u64 uVar3;
  int *piVar4;
  u8 agg5 [16];
  
  piVar4 = (int *)0x0;
  lVar2 = find_sbl_mapped_page(*(u64 *)(param_1 + 8));
  if (lVar2 != 0) {
    piVar4 = *(int **)(lVar2 + 0x10);
  }
  uVar3 = (*sceSblKeymgrSmCallfunc)(param_1);
  if (((((int)uVar3 != 0) || (*(int *)(param_1 + 4) != 0)) && (piVar4 != (int *)0x0)) &&
     (*piVar4 == 0x200)) {
    uVar1 = decrypt_self_header(piVar4 + 9);
    *(u32 *)(param_1 + 4) = uVar1;
    uVar3 = 0;
  }
  (*(u8_t *)((u8 *)&agg5 + 1)) = param_4;
  (*(u8_t *)((u8 *)&agg5 + 0)) = uVar3;
  return agg5;
}

/* pfs_set_keys_hook @ 0x1004c1 size=847 */
int pfs_set_keys_hook(int *param_1,int *param_2,u64 param_3)

{
  u64 uVar1;
  int iVar2;
  int iVar3;
  u64 *reg_gs_offset;
  s64 in_stack_00000008;
  int in_stack_00000020;
  u64 local_1c8;
  u64 local_1c0;
  u8 *local_1b8;
  u64 local_1b0;
  u8 local_1a8 [16];
  u8 local_198 [32];
  u8 local_178 [32];
  u8 *local_158;
  u8 *local_150;
  u8 *local_148;
  u8 *local_140;
  u8 *local_138;
  u32 local_130;
  u8 local_12c [120];
  u32 local_b4;
  u8 local_b0 [128];
  
  iVar2 = (*sceSblPfsSetKeys)();
  if ((iVar2 != 0) && (in_stack_00000020 == 0)) {
    (*memset)(&local_1c8,0,0x10);
    local_1c0 = 0x100;
    local_1c8 = param_3;
    (*memset)(&local_1b8,0,0x10);
    local_1b0 = 0x20;
    local_1b8 = local_198;
    (*memset)(local_178,0,0x48);
    local_158 = g_bytes_00196780;
    local_150 = g_bytes_00196700;
    local_148 = g_bytes_00196680;
    local_140 = g_bytes_00196600;
    local_138 = g_bytes_00196580;
    uVar1 = *reg_gs_offset;
    (*fpu_kern_enter)(uVar1,FPU_CTX,0);
    iVar3 = (*RsaesPkcs1v15Dec2048CRT)(&local_1b8,&local_1c8,local_178);
    (*fpu_kern_leave)(uVar1,FPU_CTX);
    if (iVar3 == 0) {
      (*sx_xlock)(SBL_PFS_SX,0,0,0);
      (*memset)(&local_130,0,0x7c);
      local_130 = 0x201337;
      compute_hmac_sha256(local_198,in_stack_00000008 + 0x370,1,local_12c);
      (*fpu_kern_enter)(uVar1,FPU_CTX,0);
      (*memset)(local_1a8,0,0x10);
      iVar3 = (*AesCbcCfb128Encrypt)(local_12c,local_12c,0x20,"FAKEFAKEFAKEFAKE",0x80,local_1a8);
      (*fpu_kern_leave)(uVar1,FPU_CTX);
      if (iVar3 == 0) {
        (*memset)(&local_b4,0,0x7c);
        local_b4 = 0x201337;
        compute_hmac_sha256(local_198,in_stack_00000008 + 0x370,2,local_b0);
        (*fpu_kern_enter)(uVar1,FPU_CTX,0);
        (*memset)(local_1a8,0,0x10);
        iVar3 = (*AesCbcCfb128Encrypt)(local_b0,local_b0,0x20,"FAKEFAKEFAKEFAKE",0x80,local_1a8);
        (*fpu_kern_leave)(uVar1,FPU_CTX);
        if (iVar3 == 0) {
          iVar3 = (*sceSblKeymgrSetKeyForPfs)(&local_130,param_1);
          if (iVar3 == 0) {
            iVar3 = (*sceSblKeymgrSetKeyForPfs)(&local_b4,param_2);
            if (iVar3 == 0) {
              (*sx_xunlock)(SBL_PFS_SX);
              return 0;
            }
            iVar3 = *param_2;
          }
          else {
            iVar3 = *param_1;
          }
          if (iVar3 != -1) {
            (*sceSblKeymgrClearKey)();
          }
        }
      }
      (*sx_xunlock)(SBL_PFS_SX);
    }
  }
  return iVar2;
}

/* remove_function_hook @ 0x105eb6 size=78 */
u64 remove_function_hook(u64 param_1,u64 param_2,u64 param_3)

{
  s64 in_stack_00000008;
  s64 in_stack_00000018;
  u64 in_stack_00000020;
  
  if ((in_stack_00000008 != 0 && in_stack_00000018 != 0) && (0xe < in_stack_00000020)) {
    (*memcpy)(in_stack_00000008,in_stack_00000018,in_stack_00000020 - 0xe);
  }
  return param_3;
}

/* sbl_driver_send_msg_hook @ 0x100810 size=89 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sbl_driver_send_msg_hook(int *param_1)

{
  u32 uVar1;
  s64 lVar2;
  
  if (*param_1 == 8) {
    uVar1 = param_1[6];
    if (((uVar1 >> 0x18 == 0) && ((uVar1 & 0xc0000) == 0xc0000)) && (param_1[0xe] == 0x1337)) {
      param_1[6] = uVar1 & 0xfffbffff;
      lVar2 = 0;
      do {
        *(char *)((s64)param_1 + lVar2 + 0x38) = "FAKEFAKEFAKEFAKE"[0xf - lVar2];
        lVar2 = lVar2 + 1;
      } while (lVar2 != 0x10);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00100863. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_sceSblDriverSendMsg_0)();
  return;
}

/* sysmodule_preload_module_hook @ 0x100125 size=472 */
u32 sysmodule_preload_module_hook(s64 param_1,s64 param_2)

{
  u32 uVar1;
  int iVar2;
  s64 lVar3;
  u64 local_438;
  s64 local_430;
  u8 local_428 [1032];
  
  uVar1 = (*g_saved_sysent_00198420)();
  local_438 = 0;
  if (*(s64 *)(param_2 + 8) != 0) {
    (*memset)(local_428,0,0x400);
    (*copyinstr)(*(u64 *)(param_2 + 8),local_428,0x400,&local_438);
    lVar3 = (*strlen)(*(s64 *)(param_1 + 8) + 0x390);
    if (lVar3 != 0) {
      iVar2 = (*memcmp)(*(s64 *)(param_1 + 8) + 0x390,g_bytes_00196b8c,4);
      if (iVar2 != 0) {
        iVar2 = (*memcmp)(local_428,"sceSysmodulePreloadModuleForLibkernel",0x25);
        if (iVar2 == 0) {
          local_430 = 0;
          inject_fake_symbol_stub(*(u64 *)(param_1 + 8),**(u64 **)(param_2 + 0x10),&local_430);
          if (local_430 != 0) {
            (*copyout)(&local_430,*(u64 *)(param_2 + 0x10),8);
          }
        }
        else {
          iVar2 = (*memcmp)(local_428,"GoldHENFakeSymbol",0x11);
          if (iVar2 == 0) {
            load_plugin_in_process(*(u64 *)(param_1 + 8),"/data/GoldHEN/plugins/goldhen_private.prx",1)
            ;
            if (g_patch_update_module_flag != 0) {
              run_blob_at_fixed_address_in_process(*(u64 *)(param_1 + 8),g_bytes_0019115c,(s64)g_bytes_00192af8,0xfeb000000
                           ,"ScePatchUpdate");
            }
            if (g_game_update_module_flag != 0) {
              run_blob_at_fixed_address_in_process(*(u64 *)(param_1 + 8),g_bytes_0018feb0,(s64)g_bytes_00191158,0xfea000000
                           ,"SceGameUpdate");
            }
            if (g_game_patch_plugin_flag != 0) {
              load_plugin_in_process(*(u64 *)(param_1 + 8),"/data/GoldHEN/plugins/game_patch.prx",1);
            }
            if (g_aio_fix_plugin_flag != 0) {
              load_plugin_in_process(*(u64 *)(param_1 + 8),"/data/GoldHEN/plugins/aio_fix_505.prx",1);
            }
          }
        }
      }
    }
  }
  return uVar1;
}

/* toggle_noop_kernel_hook @ 0x1039c4 size=193 */
void toggle_noop_kernel_hook(int param_1)

{
  u8 stack0x00000008 [0x400];
  u16 uVar1;
  s64 lVar2;
  u32 *puVar3;
  u32 *puVar4;
  u8 bVar5;
  u32 auStack_240 [6];
  u64 uStack_228;
  u32 local_220 [14];
  u8 local_1e8 [384];
  s64 local_68;
  u8 *local_20;
  
  bVar5 = 0;
  local_20 = &stack0x00000008;
  if (param_1 == 0) {
    if (str_ext_get_installer_offsets_te != 0) {
      puVar3 = g_saved_sysent_00198400;
      puVar4 = auStack_240;
      for (lVar2 = 8; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      remove_function_hook();
      str_ext_get_installer_offsets_te = 0;
    }
  }
  else if (str_ext_get_installer_offsets_te == 0) {
    uStack_228 = 0x1039fb;
    uVar1 = get_firmware();
    uStack_228 = 0x103a11;
    get_goldhen_offsets(local_1e8,uVar1);
    uStack_228 = 0x103a18;
    lVar2 = get_kbase();
    uStack_228 = 0x103a2e;
    install_function_hook(local_220,lVar2 + local_68,noop_stub);
    puVar3 = local_220;
    puVar4 = g_saved_sysent_00198400;
    for (lVar2 = 8; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + (u64)bVar5 * -2 + 1;
      puVar4 = puVar4 + (u64)bVar5 * -2 + 1;
    }
    str_ext_get_installer_offsets_te = 1;
  }
  return;
}

/* toggle_tty_redirect_hook @ 0x102654 size=196 */
void toggle_tty_redirect_hook(int param_1)

{
  u16 uVar1;
  s64 lVar2;
  u32 *puVar3;
  u32 *puVar4;
  u8 bVar5;
  u32 auStack_240 [6];
  u64 uStack_228;
  u32 local_220 [14];
  u8 local_1e8 [328];
  s64 local_a0;
  u8 *local_20;
  
  bVar5 = 0;
  local_20 = &stack0x00000008;
  if (param_1 == 0) {
    if (g_bytes_001983a0 != 0) {
      puVar3 = g_bytes_001983c0;
      puVar4 = auStack_240;
      for (lVar2 = 8; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      remove_function_hook();
      g_bytes_001983a0 = 0;
    }
  }
  else if (g_bytes_001983a0 == 0) {
    uStack_228 = 0x10268b;
    uVar1 = get_firmware();
    uStack_228 = 0x1026a1;
    get_goldhen_offsets(local_1e8,uVar1);
    uStack_228 = 0x1026a8;
    lVar2 = get_kbase();
    uStack_228 = 0x1026c1;
    install_function_hook(local_220,lVar2 + local_a0,tty_console_write_hook);
    puVar3 = local_220;
    puVar4 = g_bytes_001983c0;
    for (lVar2 = 8; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + (u64)bVar5 * -2 + 1;
      puVar4 = puVar4 + (u64)bVar5 * -2 + 1;
    }
    g_bytes_001983a0 = 1;
  }
  return;
}

/* tty_console_write_hook @ 0x102633 size=33 */
u8  [16] tty_console_write_hook(u64 param_1,u64 param_2,u64 param_3)

{
  u8 agg1 [16];
  u8 agg2 [16];
  s64 *plVar3;
  
  plVar3 = dev_console;
  if (*dev_console != 0) {
    (*ttyconsdev_write)();
    (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
    (*(u8_t *)((u8 *)&agg1 + 0)) = plVar3;
    return agg1 << 0x40;
  }
  (*(u8_t *)((u8 *)&agg2 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg2 + 0)) = param_3;
  return agg2 << 0x40;
}

/* write_abs_jump_stub @ 0x105da7 size=32 */
void write_abs_jump_stub(u8 *param_1,u64 param_2)

{
  *param_1 = 0xff;
  param_1[1] = 0x25;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(u64 *)(param_1 + 6) = param_2;
  return;
}
