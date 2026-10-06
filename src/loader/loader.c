/*
 * loader.c - loader core: entry, kernel setup, kpayload loading and install.
 */

#include <goldhen/types.h>
#include <goldhen/loader.h>

/*
 * call_import_4600
 *
 * jmp qword ptr [0x47600]
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

kaddr_t call_import_4600(u64 size) {
                    /* WARNING: Could not recover jumptable at 0x000926201823. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*IMP_KMEM_ALLOC)();
  return;
}

/*
 * call_import_4630
 *
 * call qword ptr [0x47630] with (arg,2)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void call_import_4630(u64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00092620183b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*IMP_MALLOC)(param_1,2);
  return;
}

/*
 * entry_stub - the payload's entry point.
 *
 *
 * The exploit copies the loader image into kernel memory and jumps to its base.
 * The whole function is a single near jump:
 *
 *     e9 d2 11 00 00     jmp payload_entry_check
 *
 * 0x0 + 5 (the length of the jump) + 0x11d2 = 0x11d7, which is exactly where
 * payload_entry_check lives.
 *
 * This file previously held a copy of payload_entry_check's body instead.  That
 * was an artefact: the jump target's body had been attributed to the thunk.  The two files were byte-identical apart from their
 * comments, which is what gave it away.  The real content is the jump above,
 * and nothing else executes here.
 *
 * The jump is emitted as assembly rather than as a C call so that the emitted
 * code stays a tail jump and not a call/return pair, which is what the original
 * binary does.
 */
void entry_stub(void) __attribute__((naked, used, section(".text.entry_stub")));

void entry_stub(void)
{
    __asm__ volatile("jmp payload_entry_check");
}

/*
 * get_firmware_version
 *
 * Find "s/release_" in kernel rodata, decode version BCD
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 get_firmware_version(u64 param_1,u64 param_2,u64 param_3)

{
  s64 lVar1;
  s64 lVar2;
  s64 lVar3;
  int iVar4;
  u32 uVar5;
  u64 uVar6;
  char local_a [10];
  
  uVar6 = ((u64_t)((s64)((u64)param_3 >> 0x10)) << 16 | (u64_t)(firmware_version));
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
        goto l_9262012b8;
      }
    }
    lVar3 = lVar3 + 1;
  } while (lVar1 + 0x2200000 != lVar3);
l_9262012b8:
  firmware_version = (short)uVar5;
  return (u64)uVar5;
}

/*
 * get_kbase
 *
 * rdmsr(0xC0000082) - 0x1C0
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
s64 get_kbase(void)

{
  s64 lVar1;
  
  lVar1 = rdmsr(0xc0000082);
  return lVar1 + -0x1c0;
}

/*
 * goldhen_is_loaded
 *
 * Compare kernel_global->f2588 vs ->f25b8
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
bool goldhen_is_loaded(void)

{
  return *(s64 *)(g_kernel_got_base + 0x2588) != *(s64 *)(g_kernel_got_base + 0x25b8);
}

/*
 * goldhen_main
 *
 * Main install flow
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 goldhen_main(void)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = loader_init();
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = goldhen_is_loaded();
  if ((iVar1 != 0) && (iVar1 = kcall_2588(), iVar1 == 1)) {
    kcall_2588();
    kcall_2588();
    return 0;
  }
  uVar2 = install_goldhen();
  return uVar2;
}

/*
 * install_goldhen
 *
 * Patch kernel, print banner, load kpayload
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
bool install_goldhen(void)

{
  int iVar1;
  
  patch_kernel_installer();
  print_banner();
  (*imp_printf)();
  iVar1 = load_and_start_kpayload();
  return iVar1 != 0;
}

/*
 * is_kernel_pointer
 *
 * True if (~rdi & 0xFFFF800000000000)==0
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int is_kernel_pointer(kaddr_t p) {
  u64 reg_rdi;
  
  return (~reg_rdi & 0xffff800000000000) == 0;
}

/*
 * kcall_2588
 *
 * Call kernel function pointer at kernel_global+0x2588, return td_retval[0]
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int kcall_2588(u64 code, u64 arg) {
  void (*pcVar1)(void);
  s64 lVar2;
  int iVar3;
  s64 *reg_gs_offset;
  
  pcVar1 = *(void (**)(void))(g_kernel_got_base + 0x2588);
  lVar2 = *reg_gs_offset;
  *(u64 *)(lVar2 + 0x398) = 0;
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    iVar3 = *(int *)(lVar2 + 0x398);
  }
  else {
    iVar3 = -iVar3;
  }
  return iVar3;
}

/*
 * load_and_start_kpayload
 *
 * Adler verify + load ELF + call entry (starts GoldHEN)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
bool load_and_start_kpayload(void)

{
  int iVar1;
  s64 lVar2;
  bool bVar3;
  u64 local_28;
  void (*local_20)(void) [2];
  
  if (kpayload_zlib_size * 3 != 0) {
    lVar2 = call_import_4630();
    bVar3 = false;
    if (lVar2 != 0) {
      verify_adler32(0,kpayload_zlib_size);
      iVar1 = elf_check_and_measure();
      if (((iVar1 == 0) && (lVar2 = call_import_4600(), lVar2 != 0)) &&
         (iVar1 = elf_load(local_28,lVar2,local_20), iVar1 == 0)) {
        iVar1 = (*local_20[0])();
        bVar3 = iVar1 != 0;
      }
      else {
        (*imp_printf)();
        bVar3 = true;
      }
    }
    return bVar3;
  }
  return false;
}

/*
 * loader_init
 *
 * firmware_version=0; get_firmware(); resolve_imports()
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void loader_init(u64 param_1)

{
  u64 reg_rax;
  
  firmware_version = 0;
  get_firmware_version();
  resolve_imports(param_1,reg_rax);
  return;
}

/*
 * patch_kernel_installer
 *
 * CR0.WP off, write jmp patch at installer offsets, WP on
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 patch_kernel_installer(void)

{
  s64 lVar1;
  u64 reg_cr0;
  u32 local_1c;
  u16 local_18;
  u32 local_14;
  u32 local_10;
  u32 local_c;
  
  get_firmware_version();
  get_installer_offsets();
  reg_cr0 = reg_cr0 & 0xfffffffffffeffff;
  lVar1 = get_kbase();
  *(u8 *)((u64)local_c + lVar1) = 0xeb;
  *(u16 *)((u64)local_1c + lVar1) = local_18;
  *IMP_DISABLE_CONSOLE_OUTPUT = 0;
  *(u8 *)((u64)local_14 + lVar1) = 7;
  *(u8 *)((u64)local_10 + lVar1) = 7;
  return reg_cr0 | 0x10000;
}

/*
 * payload_entry_check
 *
 * Check rdi is kernel pointer: install() or print error
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void payload_entry_check(void)

{
  int iVar1;
  u64 reg_rsi;
  
  iVar1 = is_kernel_pointer();
  if (iVar1 == 1) {
    goldhen_main(reg_rsi);
    return;
  }
  syscall0();
  return;
}

/*
 * print_banner
 *
 * Print ASCII-art banner + status lines via printf import
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void print_banner(u64 param_1)

{
  u64 reg_rax;
  
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
  (*imp_printf)();
                    /* WARNING: Could not recover jumptable at 0x00092620101f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*imp_printf)(param_1,reg_rax);
  return;
}

/*
 * resolve_imports
 *
 * Build import table: kernel_base + per-firmware offsets
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int resolve_imports(u16 firmware) {
  s64 lVar1;
  u64 uVar2;
  u16 reg_di;
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
  
  get_ksdk_offsets();
  uVar2 = 1;
  if (local_13c != 0) {
    kernel_base = get_kbase();
    IMP_XFAST_SYSCALL = (u64)local_13c + kernel_base;
    imp_printf = (u64)local_138 + kernel_base;
    IMP_MALLOC = (u64)local_134 + kernel_base;
    IMP_REALLOC = (u64)local_130 + kernel_base;
    IMP_FREE = (u64)local_12c + kernel_base;
    imp_memcpy = (u64)local_128 + kernel_base;
    imp_memset = (u64)local_124 + kernel_base;
    imp_memcmp = (u64)local_120 + kernel_base;
    IMP_KMEM_ALLOC = (u64)local_11c + kernel_base;
    IMP_STRLEN = (u64)local_118 + kernel_base;
    IMP_PAUSE = (u64)local_114 + kernel_base;
    IMP_CREATE_THREAD = (u64)local_110 + kernel_base;
    IMP_SX_XLOCK = (u64)local_10c + kernel_base;
    IMP_SX_XUNLOCK = (u64)local_108 + kernel_base;
    IMP_KERN_REBOOT = (u64)local_104 + kernel_base;
    IMP_VM_MAP_LOCK_READ = (u64)local_100 + kernel_base;
    IMP_VM_MAP_LOOKUP_ENTRY = (u64)local_fc + kernel_base;
    IMP_VM_MAP_UNLOCK_READ = (u64)local_f8 + kernel_base;
    IMP_VM_MAP_DELETE = (u64)local_f4 + kernel_base;
    IMP_VM_MAP_PROTECT = (u64)local_f0 + kernel_base;
    IMP_VM_MAP_FINDSPACE = (u64)local_ec + kernel_base;
    IMP_VM_MAP_INSERT = (u64)local_e8 + kernel_base;
    IMP_VM_MAP_LOCK = (u64)local_e4 + kernel_base;
    IMP_VM_MAP_UNLOCK = (u64)local_e0 + kernel_base;
    IMP_PROC_RWMEM = (u64)local_dc + kernel_base;
    IMP_FPU_KERN_ENTER = (u64)local_d8 + kernel_base;
    IMP_FPU_KERN_LEAVE = (u64)local_d4 + kernel_base;
    lVar1 = (u64)local_d0 + kernel_base;
    if ((reg_di & 0xfffd) == 0x1f9) {
      lVar1 = IMP_EVENTHANDLER_REGISTER1;
      IMP_EVENTHANDLER_REGISTER2 = (u64)local_d0 + kernel_base;
    }
    IMP_EVENTHANDLER_REGISTER1 = lVar1;
    IMP_STRSTR = (u64)local_cc + kernel_base;
    IMP_COPYINSTR = (u64)local_c8 + kernel_base;
    IMP_COPYOUT = (u64)local_c4 + kernel_base;
    IMP_STRNCMP = (u64)local_c0 + kernel_base;
    IMP_STRNCPY = (u64)local_bc + kernel_base;
    IMP_SNPRINTF = (u64)local_b8 + kernel_base;
    IMP_SPRINTF = (u64)local_b4 + kernel_base;
    IMP_SCE_KERNEL_SEND_NOTIFICATION_REQUEST = (u64)local_b0 + kernel_base;
    IMP_SHA256_HMAC = (u64)local_ac + kernel_base;
    IMP_SCE_SBL_PFS_SET_KEYS = (u64)local_a8 + kernel_base;
    IMP_RSAES_PKCS1V15_DEC2048_CRT = (u64)local_a4 + kernel_base;
    IMP_AES_CBC_CFB128_ENCRYPT = (u64)local_a0 + kernel_base;
    IMP_AES_CBC_CFB128_DECRYPT = (u64)local_9c + kernel_base;
    IMP_SCE_SBL_KEYMGR_SET_KEY_FOR_PFS = (u64)local_98 + kernel_base;
    IMP_SCE_SBL_KEYMGR_CLEAR_KEY = (u64)local_94 + kernel_base;
    IMP_SCE_SBL_KEYMGR_SM_CALLFUNC = (u64)local_90 + kernel_base;
    IMP_SCE_SBL_DRIVER_SEND_MSG_0 = (u64)local_8c + kernel_base;
    IMP_SCE_SBL_KEYMGR_SET_KEY_STORAGE = (u64)local_88 + kernel_base;
    IMP_SCE_SBL_AUTH_MGR_GET_SELF_INFO = (u64)local_84 + kernel_base;
    IMP_SCE_SBL_AUTH_MGR_VERIFY_HEADER = (u64)local_80 + kernel_base;
    IMP_SCE_SBL_AUTH_MGR_SM_IS_LOADABLE2 = (u64)local_7c + kernel_base;
    IMP_SCE_SBL_AUTH_MGR_SM_START = (u64)local_78 + kernel_base;
    IMP_SCE_SBL_SERVICE_MAILBOX = (u64)local_74 + kernel_base;
    IMP_SCE_SBL_ACMGR_GET_PATH_ID = (u64)local_70 + kernel_base;
    IMP_KPROC_CREATE = (u64)local_6c + kernel_base;
    IMP_KPROC_KTHREAD_ADD = (u64)local_68 + kernel_base;
    IMP_KTHREAD_SUSPEND_CHECK = (u64)local_64 + kernel_base;
    IMP_KTHREAD_EXIT = (u64)local_60 + kernel_base;
    IMP_TTYCONSDEV_WRITE = (u64)local_5c + kernel_base;
    IMP_DEV_CONSOLE = (u64)local_58 + kernel_base;
    IMP_SCE_SBL_AIMGR_IS_TEST_KIT = (u64)local_54 + kernel_base;
    IMP_SCE_SBL_DEV_ACT_SET_STATUS = (u64)local_50 + kernel_base;
    IMP_DISABLE_CONSOLE_OUTPUT = (u64)local_4c + kernel_base;
    IMP_M_TEMP = (u64)local_48 + kernel_base;
    IMP_KERNEL_MAP = (u64)local_44 + kernel_base;
    IMP_PRISON0 = (u64)local_40 + kernel_base;
    IMP_ROOTVNODE = (u64)local_3c + kernel_base;
    IMP_ALLPROC = (u64)local_38 + kernel_base;
    g_kernel_got_base = (u64)local_34 + kernel_base;
    IMP_FPU_CTX = (u64)local_30 + kernel_base;
    IMP_MINI_SYSCORE_SELF_BINARY = (u64)local_2c + kernel_base;
    IMP_SOUTHBRIDGE = (u64)local_28 + kernel_base;
    IMP_KEXEC_ROP = (u64)local_24 + kernel_base;
    IMP_SBL_DRIVER_MAPPED_PAGES = (u64)local_20 + kernel_base;
    IMP_SBL_PFS_SX = (u64)local_1c + kernel_base;
    IMP_SBL_KEYMGR_KEY_SLOTS = (u64)local_18 + kernel_base;
    IMP_SBL_KEYMGR_KEY_RBTREE = (u64)local_14 + kernel_base;
    IMP_SBL_KEYMGR_BUF_VA = (u64)local_10 + kernel_base;
    kernel_base = kernel_base + (u64)local_c;
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * syscall0
 *
 * FreeBSD syscall(0,...) wrapper
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
long syscall0(long nr, ...) {
  syscall();
  return 0;
}
