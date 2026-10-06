/*
 * init.c - payload entry, early init and sysent helpers.
 */

#include <goldhen/types.h>

/* entry @ 0x100120 size=5 */
u8  [16] entry(void)

{
  u8 agg1 [16];
  u64 reg_rax;
  
  init_ksdk();
  (*pause)("GoldHEN",500);
  init_syscall_wrappers();
  install_fakepkg_hooks();
  install_fakeself_hooks();
  install_shellcore_patches();
  install_custom_syscalls();
  install_patches_and_exec_handler();
  notify("GoldHEN v2.4b18.9 loaded!\nCoded by Zer0day",0);
  load_klog_server_module();
  load_ftp_server_module();
  load_payloader_server_module();
  load_goldhen_menu_module();
  install_sysmodule_preload_hook();
  (*printf)("[GoldHEN] All done!\n");
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg1 + 0)) = reg_rax;
  return agg1 << 0x40;
}

/* goldhen_init @ 0x102718 size=140 */
u8  [16] goldhen_init(void)

{
  u8 agg1 [16];
  u64 reg_rax;
  
  init_ksdk();
  (*pause)("GoldHEN",500);
  init_syscall_wrappers();
  install_fakepkg_hooks();
  install_fakeself_hooks();
  install_shellcore_patches();
  install_custom_syscalls();
  install_patches_and_exec_handler();
  notify("GoldHEN v2.4b18.9 loaded!\nCoded by Zer0day",0);
  load_klog_server_module();
  load_ftp_server_module();
  load_payloader_server_module();
  load_goldhen_menu_module();
  install_sysmodule_preload_hook();
  (*printf)("[GoldHEN] All done!\n");
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg1 + 0)) = reg_rax;
  return agg1 << 0x40;
}

/* set_sysent_entry @ 0x102530 size=62 */
void set_sysent_entry(u64 param_1,u64 param_2,u32 param_3)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)((param_1 & 0xffffffff) * 0x30 + sysents);
  (*memset)(puVar1,0,0x30);
  *puVar1 = param_3;
  *(u64 *)(puVar1 + 2) = param_2;
  puVar1[0xb] = 1;
  return;
}
