/*
 * jailbreak.c - jailbreak/unjailbreak primitives and kernel helpers.
 */

/* jailbreak @ 0x111d68 size=21 */

#include <goldhen/types.h>

void jailbreak(u64 param_1)

{
  u64 *reg_gs_offset;
  
  jailbreak_thread(*reg_gs_offset,param_1);
  return;
}

/* alloc @ 0x111e37 size=24 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void alloc(u32 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00111e49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_malloc)(param_1,M_TEMP,2);
  return;
}
/* check_kernel_address @ 0x111e60 size=25 */
bool check_kernel_address(u64 param_1)

{
  return (~param_1 & 0xffff800000000000) == 0;
}
/* dealloc @ 0x111e4f size=17 */
void dealloc(u64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00111e5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*free)(param_1,M_TEMP);
  return;
}
/* eventhandler_register @ 0x111668 size=86 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void eventhandler_register
               (u64 param_1,u64 param_2,u64 param_3,u64 param_4,
               u64 param_5)

{
  u16 uVar1;
  
  uVar1 = get_firmware();
  if ((uVar1 & 0xfffd) == 0x1f9) {
                    /* WARNING: Could not recover jumptable at 0x001116ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_eventhandler_register1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x001116b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_eventhandler_register2)(param_1,param_2,param_3,param_4,param_5);
  return;
}
/* find_process_by_name @ 0x103a85 size=107 */
s64 * find_process_by_name(s64 param_1)

{
  void (*pcVar1)(void);
  u16 uVar2;
  int iVar3;
  u64 uVar4;
  u64 ret_rdx;
  s64 *plVar5;
  
  if (param_1 != 0) {
    uVar2 = get_firmware();
    get_proc_offsets(uVar2);
    plVar5 = (s64 *)*allproc;
    do {
      pcVar1 = memcmp;
      uVar4 = (*strlen)(param_1);
      iVar3 = (*pcVar1)((s64)plVar5 + (ret_rdx & 0xffffffff),param_1,uVar4);
      if (iVar3 == 0) {
        return plVar5;
      }
      plVar5 = (s64 *)*plVar5;
    } while (plVar5 != (s64 *)0x0);
  }
  return (s64 *)0x0;
}
/* get_firmware @ 0x1115be size=170 */
u64 get_firmware(void)

{
  s64 lVar1;
  s64 lVar2;
  s64 lVar3;
  int iVar4;
  u32 uVar5;
  u64 reg_r8;
  u64 uVar6;
  char local_a [10];
  
  uVar6 = ((u64_t)((s64)((u64)reg_r8 >> 0x10)) << 16 | (u64_t)(firmware_version));
  uVar5 = (u32)uVar6;
  if (firmware_version != 0) {
    return uVar6 & 0xffffffff;
  }
  builtin_strncpy(local_a,"s/release_",10);
  lVar1 = get_kbase();
  lVar3 = lVar1 + 0x1300000;
  do {
    lVar2 = 0;
    while (local_a[lVar2] == *(char *)(lVar2 + lVar3)) {
      lVar2 = lVar2 + 1;
      if (lVar2 == 10) {
        iVar4 = *(u8 *)(lVar3 + 10) - 0x30;
        uVar5 = ((u32_t)((short)((u32)iVar4 >> 0x10)) << 16 | (u32_t)((short)iVar4 * 1000)) + -0x30 +
                (u32)*(u8 *)(lVar3 + 0xe) + (*(u8 *)(lVar3 + 0xb) - 0x30) * 100 +
                (*(u8 *)(lVar3 + 0xd) - 0x30) * 10;
        goto l_0011164a;
      }
    }
    lVar3 = lVar3 + 1;
  } while (lVar1 + 0x2200000 != lVar3);
l_0011164a:
  firmware_version = (short)uVar5;
  return (u64)uVar5;
}
/* get_kbase @ 0x1115a2 size=28 */
s64 get_kbase(void)

{
  s64 lVar1;
  
  lVar1 = rdmsr(0xc0000082);
  return lVar1 + -0x1c0;
}
/* init_ksdk @ 0x111bd1 size=30 */
void init_ksdk(u64 param_1,u64 param_2)

{
  u16 uVar1;
  u64 reg_rax;
  
  firmware_version = 0;
  uVar1 = get_firmware();
  map_functions(uVar1,param_2,reg_rax);
  return;
}
/* jailbreak_process @ 0x111c7f size=220 */
void jailbreak_process(s64 param_1,u32 *param_2)

{
  s64 lVar1;
  s64 lVar2;
  u32 *puVar3;
  u64 uVar4;
  u64 *puVar5;
  
  if (param_1 != 0) {
    lVar1 = *(s64 *)(param_1 + 0x40);
    lVar2 = *(s64 *)(param_1 + 0x48);
    if ((lVar1 != 0) && (lVar2 != 0)) {
      puVar3 = *(u32 **)(lVar1 + 0x118);
      if (param_2 != (u32 *)0x0) {
        *param_2 = *(u32 *)(lVar1 + 4);
        param_2[1] = *(u32 *)(lVar1 + 8);
        param_2[2] = *(u32 *)(lVar1 + 0x14);
        param_2[3] = *puVar3;
        *(u64 *)(param_2 + 4) = *(u64 *)(lVar1 + 0x58);
        *(u64 *)(param_2 + 10) = *(u64 *)(lVar1 + 0x30);
        *(u64 *)(param_2 + 6) = *(u64 *)(lVar1 + 0x60);
        *(u64 *)(param_2 + 8) = *(u64 *)(lVar1 + 0x68);
        *(u64 *)(param_2 + 0xc) = *(u64 *)(lVar2 + 0x10);
        *(u64 *)(param_2 + 0xe) = *(u64 *)(lVar2 + 0x20);
        *(u64 *)(param_2 + 0x10) = *(u64 *)(lVar2 + 0x18);
      }
      puVar5 = prison0;
      *(u64 *)(lVar1 + 4) = 0;
      *(u32 *)(lVar1 + 0x14) = 0;
      *puVar3 = 0;
      *(u64 *)(lVar1 + 0x58) = 0x3801000000000013;
      uVar4 = *puVar5;
      *(u64 *)(lVar1 + 0x60) = 0xffffffffffffffff;
      *(u64 *)(lVar1 + 0x68) = 0xffffffffffffffff;
      *(u64 *)(lVar1 + 0x30) = uVar4;
      uVar4 = *rootvnode;
      *(u64 *)(lVar2 + 0x20) = uVar4;
      *(u64 *)(lVar2 + 0x18) = uVar4;
      *(u64 *)(lVar2 + 0x10) = uVar4;
    }
  }
  return;
}
/* jailbreak_thread @ 0x111d5b size=13 */
void jailbreak_thread(s64 param_1)

{
  jailbreak_process(*(u64 *)(param_1 + 8));
  return;
}
/* map_functions @ 0x1116be size=1299 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

u64 map_functions(u16 param_1)

{
  s64 lVar1;
  u64 uVar2;
  s64 lVar3;
  u64 uVar4;
  u32 local_13c;
  u32 local_138;
  u32 local_134;
  u32 local_130;
  u32 local_12c;
  u32 local_128;
  u32 local_124;
  u32 local_120;
  u32 local_11c;
  u32 local_118;
  u32 local_114;
  u32 local_110;
  u32 local_10c;
  u32 local_108;
  u32 local_104;
  u32 local_100;
  u32 local_fc;
  u32 local_f8;
  u32 local_f4;
  u32 local_f0;
  u32 local_ec;
  u32 local_e8;
  u32 local_e4;
  u32 local_e0;
  u32 local_dc;
  u32 local_d8;
  u32 local_d4;
  u32 local_d0;
  u32 local_cc;
  u32 local_c8;
  u32 local_c4;
  u32 local_c0;
  u32 local_bc;
  u32 local_b8;
  u32 local_b4;
  u32 local_b0;
  u32 local_ac;
  u32 local_a8;
  u32 local_a4;
  u32 local_a0;
  u32 local_9c;
  u32 local_98;
  u32 local_94;
  u32 local_90;
  u32 local_8c;
  u32 local_88;
  u32 local_84;
  u32 local_80;
  u32 local_7c;
  u32 local_78;
  u32 local_74;
  u32 local_70;
  u32 local_6c;
  u32 local_68;
  u32 local_64;
  u32 local_60;
  u32 local_5c;
  u32 local_58;
  u32 local_54;
  u32 local_50;
  u32 local_4c;
  u32 local_48;
  u32 local_44;
  u32 local_40;
  u32 local_3c;
  u32 local_38;
  u32 local_34;
  u32 local_30;
  u32 local_2c;
  u32 local_28;
  u32 local_24;
  u32 local_20;
  u32 local_1c;
  u32 local_18;
  u32 local_14;
  u32 local_10;
  u32 local_c;
  
  get_ksdk_offsets(&local_13c,param_1);
  uVar4 = (u64)local_13c;
  uVar2 = 1;
  if (local_13c != 0) {
    lVar3 = get_kbase();
    _Xfast_syscall = uVar4 + lVar3;
    printf = (u64)local_138 + lVar3;
    _malloc = (u64)local_134 + lVar3;
    realloc = (u64)local_130 + lVar3;
    free = (u64)local_12c + lVar3;
    memcpy = (u64)local_128 + lVar3;
    memset = (u64)local_124 + lVar3;
    memcmp = (u64)local_120 + lVar3;
    _kmem_alloc = (u64)local_11c + lVar3;
    strlen = (u64)local_118 + lVar3;
    pause = (u64)local_114 + lVar3;
    create_thread = (u64)local_110 + lVar3;
    sx_xlock = (u64)local_10c + lVar3;
    sx_xunlock = (u64)local_108 + lVar3;
    kern_reboot = (u64)local_104 + lVar3;
    vm_map_lock_read = (u64)local_100 + lVar3;
    vm_map_lookup_entry = (u64)local_fc + lVar3;
    vm_map_unlock_read = (u64)local_f8 + lVar3;
    vm_map_delete = (u64)local_f4 + lVar3;
    vm_map_protect = (u64)local_f0 + lVar3;
    vm_map_findspace = (u64)local_ec + lVar3;
    vm_map_insert = (u64)local_e8 + lVar3;
    vm_map_lock = (u64)local_e4 + lVar3;
    vm_map_unlock = (u64)local_e0 + lVar3;
    proc_rwmem = (u64)local_dc + lVar3;
    fpu_kern_enter = (u64)local_d8 + lVar3;
    fpu_kern_leave = (u64)local_d4 + lVar3;
    lVar1 = (u64)local_d0 + lVar3;
    if ((param_1 & 0xfffd) == 0x1f9) {
      lVar1 = _eventhandler_register2;
      _eventhandler_register1 = (u64)local_d0 + lVar3;
    }
    _eventhandler_register2 = lVar1;
    strstr = (u64)local_cc + lVar3;
    copyinstr = (u64)local_c8 + lVar3;
    copyout = (u64)local_c4 + lVar3;
    strncmp = (u64)local_c0 + lVar3;
    strncpy = (u64)local_bc + lVar3;
    snprintf = (u64)local_b8 + lVar3;
    sprintf = (u64)local_b4 + lVar3;
    sceKernelSendNotificationRequest = (u64)local_b0 + lVar3;
    Sha256Hmac = (u64)local_ac + lVar3;
    sceSblPfsSetKeys = (u64)local_a8 + lVar3;
    RsaesPkcs1v15Dec2048CRT = (u64)local_a4 + lVar3;
    AesCbcCfb128Encrypt = (u64)local_a0 + lVar3;
    AesCbcCfb128Decrypt = (u64)local_9c + lVar3;
    sceSblKeymgrSetKeyForPfs = (u64)local_98 + lVar3;
    sceSblKeymgrClearKey = (u64)local_94 + lVar3;
    sceSblKeymgrSmCallfunc = (u64)local_90 + lVar3;
    _sceSblDriverSendMsg_0 = (u64)local_8c + lVar3;
    sceSblKeymgrSetKeyStorage = (u64)local_88 + lVar3;
    sceSblAuthMgrGetSelfInfo = (u64)local_84 + lVar3;
    sceSblAuthMgrVerifyHeader = (u64)local_80 + lVar3;
    _sceSblAuthMgrSmIsLoadable2 = (u64)local_7c + lVar3;
    sceSblAuthMgrSmStart = (u64)local_78 + lVar3;
    _sceSblServiceMailbox = (u64)local_74 + lVar3;
    _sceSblACMgrGetPathId = (u64)local_70 + lVar3;
    _kproc_create = (u64)local_6c + lVar3;
    _kproc_kthread_add = (u64)local_68 + lVar3;
    _kthread_suspend_check = (u64)local_64 + lVar3;
    _kthread_exit = (u64)local_60 + lVar3;
    ttyconsdev_write = (u64)local_5c + lVar3;
    dev_console = (u64)local_58 + lVar3;
    sceSblAIMgrIsTestKit = (u64)local_54 + lVar3;
    sceSblDevActSetStatus = (u64)local_50 + lVar3;
    _disable_console_output = (u64)local_4c + lVar3;
    M_TEMP = (u64)local_48 + lVar3;
    kernel_map = (u64)local_44 + lVar3;
    prison0 = (u64)local_40 + lVar3;
    rootvnode = (u64)local_3c + lVar3;
    allproc = (u64)local_38 + lVar3;
    sysents = (u64)local_34 + lVar3;
    FPU_CTX = (u64)local_30 + lVar3;
    MINI_SYSCORE_SELF_BINARY = (u64)local_2c + lVar3;
    southbridge = (u64)local_28 + lVar3;
    kexec_rop = (u64)local_24 + lVar3;
    SBL_DRIVER_MAPPED_PAGES = (u64)local_20 + lVar3;
    SBL_PFS_SX = (u64)local_1c + lVar3;
    SBL_KEYMGR_KEY_SLOTS = (u64)local_18 + lVar3;
    SBL_KEYMGR_KEY_RBTREE = (u64)local_14 + lVar3;
    SBL_KEYMGR_BUF_VA = (u64)local_10 + lVar3;
    SBL_KEYMGR_BUF_GVA = lVar3 + (u64)local_c;
    uVar2 = 0;
  }
  return uVar2;
}
/* notify @ 0x111bef size=144 */
void notify(u64 param_1,char *param_2)

{
  u32 local_c48 [4];
  u32 local_c38;
  u32 local_c20;
  u8 local_c1c;
  u8 local_c1b [1024];
  u8 local_81b [2051];
  
  (*sprintf)(local_c1b,g_bytes_00196cbe,param_1);
  local_c48[0] = 0;
  local_c20 = 0;
  local_c1c = 1;
  local_c38 = 0xffffffff;
  if (param_2 == (char *)0x0) {
    param_2 = "/user/data/profile.dat";
  }
  (*sprintf)(local_81b,g_bytes_00196cbe,param_2);
  (*sceKernelSendNotificationRequest)(0,local_c48,0xc30,0);
  return;
}
/* rwx_alloc @ 0x111e15 size=34 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rwx_alloc(s64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00111e31. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_kmem_alloc)(*kernel_map,param_1 + 0x3fffU & 0xffffffffffffc000);
  return;
}
/* unjailbreak @ 0x111e00 size=21 */
void unjailbreak(u64 param_1)

{
  u64 *reg_gs_offset;
  
  unjailbreak_thread(*reg_gs_offset,param_1);
  return;
}
/* unjailbreak_process @ 0x111d7d size=118 */
void unjailbreak_process(s64 param_1,u32 *param_2)

{
  u32 uVar1;
  s64 lVar2;
  s64 lVar3;
  
  if ((param_1 != 0) && (param_2 != (u32 *)0x0)) {
    lVar2 = *(s64 *)(param_1 + 0x40);
    lVar3 = *(s64 *)(param_1 + 0x48);
    if ((lVar2 != 0) && (lVar3 != 0)) {
      uVar1 = param_2[3];
      *(u32 *)(lVar2 + 4) = *param_2;
      *(u32 *)(lVar2 + 8) = param_2[1];
      *(u32 *)(lVar2 + 0x14) = param_2[2];
      **(u32 **)(lVar2 + 0x118) = uVar1;
      *(u64 *)(lVar2 + 0x58) = *(u64 *)(param_2 + 4);
      *(u64 *)(lVar2 + 0x60) = *(u64 *)(param_2 + 6);
      *(u64 *)(lVar2 + 0x68) = *(u64 *)(param_2 + 8);
      *(u64 *)(lVar2 + 0x30) = *(u64 *)(param_2 + 10);
      *(u64 *)(lVar3 + 0x10) = *(u64 *)(param_2 + 0xc);
      *(u64 *)(lVar3 + 0x20) = *(u64 *)(param_2 + 0xe);
      *(u64 *)(lVar3 + 0x18) = *(u64 *)(param_2 + 0x10);
    }
  }
  return;
}
/* unjailbreak_thread @ 0x111df3 size=13 */
void unjailbreak_thread(s64 param_1)

{
  unjailbreak_process(*(u64 *)(param_1 + 8));
  return;
}
