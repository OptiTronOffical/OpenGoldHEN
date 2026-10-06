/*
 * modules.c - embedded module loaders (ftp, klog, payloader, goldhen menu).
 */

#include <goldhen/types.h>

/* load_ftp_server_module @ 0x10337a size=53 */
void load_ftp_server_module(void)

{
  u64 reg_rax;
  u64 uVar1;
  
  uVar1 = find_process_by_name("SceCloudClientDaemo");
  run_blob_at_fixed_address_in_process(uVar1,g_bytes_001881cc,(s64)g_bytes_0018feac,0x9a0000000,0,reg_rax);
  return;
}

/* load_goldhen_menu_module @ 0x1032cf size=42 */
void load_goldhen_menu_module(void)

{
  u64 reg_rax;
  u64 uVar1;
  
  uVar1 = find_process_by_name("SceShellUI");
  load_and_exec_elf_in_process(uVar1,g_bytes_00111e88,0x9a0000000,reg_rax);
  return;
}

/* load_klog_server_module @ 0x1033e4 size=46 */
void load_klog_server_module(void)

{
  u64 reg_rax;
  u64 uVar1;
  
  uVar1 = find_process_by_name("SceCloudClientDaemo");
  run_blob_at_fixed_address_in_process(uVar1,g_bytes_00195344,(s64)g_bytes_00196554,0,0,reg_rax);
  return;
}

/* load_payloader_server_module @ 0x1033af size=53 */
void load_payloader_server_module(void)

{
  u64 reg_rax;
  u64 uVar1;
  
  uVar1 = find_process_by_name("SceCloudClientDaemo");
  run_blob_at_fixed_address_in_process(uVar1,g_bytes_00192afc,(s64)g_bytes_00195340,0x9b0000000,0,reg_rax);
  return;
}
