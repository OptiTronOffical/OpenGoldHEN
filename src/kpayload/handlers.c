/*
 * handlers.c - the syscall and command handlers exposed to the exploit.
 */

#include <goldhen/types.h>

/* alloc_process_memory_handler @ 0x101b1c size=126 */
u64 alloc_process_memory_handler(u64 param_1,u64 *param_2)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  u64 local_20;
  
  local_20 = 0;
  uVar3 = 1;
  iVar1 = proc_vm_map_alloc(param_1,&local_20,param_2[1],param_2[2]);
  if (iVar1 == 0) {
    uVar3 = 0;
    *param_2 = local_20;
    lVar2 = (*strlen)(param_2 + 3);
    if (lVar2 != 0) {
      set_vm_map_entry_name(param_1,*param_2,param_2[1],7,param_2 + 3);
    }
  }
  return uVar3;
}

/* copy_memory_handler @ 0x1020e5 size=94 */
u64 copy_memory_handler(s64 param_1,u64 *param_2)

{
  if (param_2[3] == 0) {
    (*memcpy)(param_2[1],*param_2,param_2[2]);
  }
  else {
    (*memcpy)(*param_2,param_2[1],param_2[2]);
  }
  *(u64 *)(param_1 + 0x398) = 0;
  return 0;
}

/* find_thread_by_id_handler @ 0x101f6b size=94 */
bool find_thread_by_id_handler(s64 param_1,int *param_2)

{
  s64 lVar1;
  
  lVar1 = *(s64 *)(param_1 + 0x10);
  while( true ) {
    if (lVar1 == 0) {
      return true;
    }
    if (*(int *)(lVar1 + 0x88) == *param_2) break;
    lVar1 = *(s64 *)(lVar1 + 0x10);
  }
  param_2[1] = (u32)*(u16 *)(lVar1 + 0x380);
  (*memcpy)(param_2 + 2,lVar1 + 0x284,0x20);
  return *(int *)(lVar1 + 0x88) != *param_2;
}

/* free_process_memory_handler @ 0x101b9a size=16 */
void free_process_memory_handler(u64 param_1,u64 *param_2)

{
  proc_vm_map_free(param_1,*param_2,param_2[1]);
  return;
}

/* get_kernel_base_handler @ 0x1020bc size=41 */
u8  [16] get_kernel_base_handler(s64 param_1,u64 *param_2)

{
  u8 agg1 [16];
  u64 reg_rax;
  u64 uVar2;
  
  param_2 = (u64 *)*param_2;
  uVar2 = get_kbase();
  *param_2 = uVar2;
  *(u64 *)(param_1 + 0x398) = 0;
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg1 + 0)) = reg_rax;
  return agg1 << 0x40;
}

/* get_process_info_handler @ 0x101e87 size=228 */
u8  [16] get_process_info_handler(s64 param_1,u32 *param_2,u64 param_3,u64 param_4)

{
  u16 uVar1;
  s64 lVar2;
  u8 agg3 [16];
  
  uVar1 = get_firmware();
  agg3 = get_proc_offsets(uVar1);
  (*memset)(param_2,0,0xca);
  *param_2 = *(u32 *)(param_1 + 0xb0);
  (*memcpy)(param_2 + 1,((*(u8_t *)((u8 *)&agg3 + 1)) & 0xffffffff) + param_1,0x28);
  (*memcpy)(param_2 + 0xb,param_1 + ((*(u8_t *)((u8 *)&agg3 + 1)) >> 0x20),0x40);
  (*memcpy)(param_2 + 0x1b,((*(u8_t *)((u8 *)&agg3 + 0)) & 0xffffffff) + param_1,0x10);
  (*memcpy)(param_2 + 0x1f,param_1 + ((*(u8_t *)((u8 *)&agg3 + 0)) >> 0x20),0x40);
  lVar2 = get_appmeta_version_for_title(param_1 + 0x390,0);
  if (lVar2 != 0) {
    (*memcpy)(param_2 + 0x2f,lVar2,6);
  }
  if (**(s64 **)(param_1 + 0x340) != 0) {
    *(u64 *)((s64)param_2 + 0xc2) = *(u64 *)(**(s64 **)(param_1 + 0x340) + 0x30);
  }
  (*(u8_t *)((u8 *)&agg3 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg3 + 0)) = param_4;
  return agg3 << 0x40;
}

/* goldhen_util_command_handler @ 0x101a76 size=166 */
u64 goldhen_util_command_handler(s64 param_1,u64 *param_2)

{
  s64 lVar1;
  char *pcVar2;
  
  switch(*param_2) {
  case 1:
    (*kern_reboot)(0);
    break;
  case 2:
    pcVar2 = "[GoldHEN] %s\n";
    if (param_2[1] != 0) {
l_00101acb:
      (*printf)(pcVar2);
    }
    break;
  case 3:
    jailbreak_thread(param_1,param_2[1]);
    break;
  case 4:
    if (param_2[1] != 0) {
      notify(param_2[1],0);
    }
    break;
  case 5:
    if (param_2[1] != 0) {
      pcVar2 = "%s";
      goto l_00101acb;
    }
    break;
  case 6:
    lVar1 = (s64)str_ntu1_22_04_2_11_4_0_shstrtab;
    goto l_00101b11;
  case 7:
    list_processes_ex_handler(param_1,param_2[1]);
    break;
  case 8:
    unjailbreak_thread(param_1,param_2[1]);
  }
  lVar1 = 0;
l_00101b11:
  *(s64 *)(param_1 + 0x398) = lVar1;
  return 0;
}

/* install_patches_and_exec_handler @ 0x103426 size=53 */
void install_patches_and_exec_handler(void)

{
  install_kernel_patches();
  install_shellui_remoteplay_patches();
  eventhandler_register(0,"process_exec_end",process_exec_end_handler,0,0,20000);
  return;
}

/* jailbreak_process_handler @ 0x1020a9 size=19 */
u8  [16] jailbreak_process_handler(u64 param_1)

{
  u64 reg_rax;
  u8 agg1 [16];
  
  jailbreak_process(param_1,0);
  (*(u8_t *)((u8 *)&agg1 + 1)) = reg_rax;
  (*(u8_t *)((u8 *)&agg1 + 0)) = 1;
  return agg1;
}

/* list_process_memory_maps_handler @ 0x101bbd size=260 */
u64 list_process_memory_maps_handler(s64 param_1,s64 *param_2)

{
  u32 uVar1;
  s64 lVar2;
  int iVar3;
  s64 lVar4;
  s64 lVar5;
  s64 local_20;
  
  lVar2 = *(s64 *)(param_1 + 0x168);
  (*vm_map_lock_read)(lVar2);
  if (*param_2 == 0) {
    param_2[1] = (s64)*(int *)(lVar2 + 0x100);
  }
  else {
    iVar3 = (*vm_map_lookup_entry)(lVar2,0,&local_20);
    if (iVar3 != 0) {
      (*vm_map_unlock_read)(lVar2);
      return 1;
    }
    if (param_2[1] != (s64)*(int *)(lVar2 + 0x100)) {
      lVar4 = (*realloc)(*param_2,(s64)*(int *)(lVar2 + 0x100) << 4);
      *param_2 = lVar4;
      param_2[1] = (s64)*(int *)(lVar2 + 0x100);
    }
    lVar4 = 0;
    do {
      if ((*(int *)(lVar2 + 0x100) <= (int)lVar4) || (local_20 == 0)) break;
      uVar1 = *(u32 *)(local_20 + 0x5c);
      lVar5 = lVar4 * 0x3a + *param_2;
      lVar4 = lVar4 + 1;
      *(u64 *)(lVar5 + 0x20) = *(u64 *)(local_20 + 0x20);
      *(u64 *)(lVar5 + 0x28) = *(u64 *)(local_20 + 0x28);
      *(u64 *)(lVar5 + 0x30) = *(u64 *)(local_20 + 0x50);
      *(u16 *)(lVar5 + 0x38) = (u16)((u32)uVar1 >> 8) & 0xff & (u16)uVar1;
      (*memcpy)(lVar5,local_20 + 0x8d,0x20);
      local_20 = *(s64 *)(local_20 + 8);
    } while (local_20 != 0);
  }
  (*vm_map_unlock_read)(lVar2);
  return 0;
}

/* list_processes_ex_handler @ 0x101993 size=227 */
void list_processes_ex_handler(s64 param_1,s64 *param_2)

{
  s64 *plVar1;
  u16 uVar2;
  int iVar3;
  u32 ret_edx;
  s64 *plVar4;
  s64 lVar5;
  s64 lVar6;
  
  iVar3 = 1;
  if (param_2[1] != 0) {
    uVar2 = get_firmware();
    get_proc_offsets(uVar2);
    if (*param_2 == 0) {
      plVar4 = (s64 *)*allproc;
      iVar3 = 0;
      do {
        plVar4 = (s64 *)*plVar4;
        iVar3 = iVar3 + 1;
      } while (plVar4 != (s64 *)0x0);
      *(s64 *)param_2[1] = (s64)iVar3;
    }
    else {
      lVar6 = 0;
      plVar4 = (s64 *)*allproc;
      iVar3 = *(int *)param_2[1];
      do {
        if (iVar3 <= (int)lVar6) break;
        lVar5 = lVar6 * 0x34;
        lVar6 = lVar6 + 1;
        (*memcpy)(*param_2 + lVar5,(s64)plVar4 + (u64)ret_edx,0x20);
        (*memcpy)(*param_2 + lVar5 + 0x24,plVar4 + 0x72,0x10);
        plVar1 = plVar4 + 0x16;
        plVar4 = (s64 *)*plVar4;
        *(int *)(*param_2 + 0x20 + lVar5) = (int)*plVar1;
      } while (plVar4 != (s64 *)0x0);
    }
    iVar3 = 0;
  }
  *(s64 *)(param_1 + 0x398) = (s64)iVar3;
  return;
}

/* list_processes_handler @ 0x101885 size=199 */
void list_processes_handler(s64 param_1,s64 *param_2)

{
  s64 *plVar1;
  u16 uVar2;
  int iVar3;
  u32 ret_edx;
  s64 *plVar4;
  s64 lVar5;
  s64 lVar6;
  
  iVar3 = 1;
  if (param_2[1] != 0) {
    uVar2 = get_firmware();
    get_proc_offsets(uVar2);
    if (*param_2 == 0) {
      plVar4 = (s64 *)*allproc;
      iVar3 = 0;
      do {
        plVar4 = (s64 *)*plVar4;
        iVar3 = iVar3 + 1;
      } while (plVar4 != (s64 *)0x0);
      *(s64 *)param_2[1] = (s64)iVar3;
    }
    else {
      lVar6 = 0;
      plVar4 = (s64 *)*allproc;
      iVar3 = *(int *)param_2[1];
      do {
        if (iVar3 <= (int)lVar6) break;
        lVar5 = lVar6 * 0x24;
        lVar6 = lVar6 + 1;
        (*memcpy)(*param_2 + lVar5,(s64)plVar4 + (u64)ret_edx,0x20);
        plVar1 = plVar4 + 0x16;
        plVar4 = (s64 *)*plVar4;
        *(int *)(*param_2 + 0x20 + lVar5) = (int)*plVar1;
      } while (plVar4 != (s64 *)0x0);
    }
    iVar3 = 0;
  }
  *(s64 *)(param_1 + 0x398) = (s64)iVar3;
  return;
}

/* process_command_handler @ 0x101fc9 size=224 */
void process_command_handler(s64 param_1,u32 *param_2)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = find_process_by_pid(*param_2);
  iVar1 = 1;
  if (lVar2 != 0) {
    iVar1 = 1;
    switch(*(u64 *)(param_2 + 2)) {
    case 1:
      iVar1 = alloc_process_memory_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 2:
      iVar1 = free_process_memory_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 3:
      iVar1 = protect_process_memory_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 4:
      iVar1 = list_process_memory_maps_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 5:
      iVar1 = run_embedded_payload_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 6:
      iVar1 = process_payload_handshake_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 7:
      iVar1 = run_elf_payload_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 8:
      iVar1 = get_process_info_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 9:
      iVar1 = find_thread_by_id_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 10:
      jailbreak_process(lVar2,0);
      iVar1 = 1;
      break;
    case 0xb:
      iVar1 = run_raw_payload_handler(lVar2,*(u64 *)(param_2 + 4));
      break;
    case 0xc:
      iVar1 = kexec_payload_file_thunk(lVar2,*(u64 *)(param_2 + 4));
    }
  }
  *(s64 *)(param_1 + 0x398) = (s64)iVar1;
  return;
}

/* process_control_syscall_handler @ 0x102495 size=155 */
void process_control_syscall_handler(s64 param_1,u64 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  switch(*param_2) {
  case 0:
    iVar1 = 0x100;
    break;
  case 1:
    iVar1 = 0;
    if (param_2[1] == 0) break;
    (*printf)(g_bytes_00196cbe);
    goto l_001024e3;
  case 2:
    jailbreak_thread(param_1,param_2[1]);
    goto l_001024e3;
  case 3:
    unjailbreak_thread(param_1,param_2[1]);
l_001024e3:
    iVar1 = 0;
    break;
  case 4:
    iVar1 = get_process_info_handler(*(u64 *)(param_1 + 8),param_2[1]);
    break;
  case 5:
    iVar1 = syscall_rw_process_memory(*(u64 *)(param_1 + 8),param_2[1]);
    break;
  case 6:
    iVar1 = load_prx_into_named_process(param_2[1]);
    break;
  case 7:
    iVar1 = unload_prx_from_named_process(param_2[1]);
  }
  *(s64 *)(param_1 + 0x398) = (s64)iVar1;
  return;
}

/* process_exec_end_handler @ 0x1032f9 size=129 */
void process_exec_end_handler(u64 param_1,s64 param_2)

{
  u16 uVar1;
  int iVar2;
  u32 ret_edx;
  
  if (param_2 == 0) {
    return;
  }
  uVar1 = get_firmware();
  get_proc_offsets(uVar1);
  iVar2 = (*memcmp)((u64)ret_edx + param_2,"orbis-jsc-compiler.self",0x17);
  if (iVar2 == 0) {
    iVar2 = (*memcmp)(param_2 + 0x390,"NPXS20001",9);
    if (iVar2 == 0) {
      (*pause)("injector",2000);
      install_remoteplay_patches();
      iVar2 = load_goldhen_menu_module();
      if (iVar2 == 0) {
        install_shellui_patches();
        return;
      }
    }
  }
  return;
}

/* process_memory_rw_handler @ 0x10194c size=71 */
void process_memory_rw_handler(s64 param_1,u32 *param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = find_process_by_pid(*param_2);
  iVar1 = 1;
  if (lVar2 != 0) {
    iVar1 = rw_process_memory(lVar2,*(u64 *)(param_2 + 2),*(u64 *)(param_2 + 6),
                         *(u64 *)(param_2 + 4),0,param_2[8],param_4);
  }
  *(s64 *)(param_1 + 0x398) = (s64)iVar1;
  return;
}

/* process_payload_handshake_handler @ 0x101d56 size=264 */
u64 process_payload_handshake_handler(u64 param_1,s64 param_2)

{
  s64 lVar1;
  int iVar2;
  u64 uVar3;
  u8 local_32;
  char local_31;
  u64 local_30;
  
  lVar1 = *(s64 *)(param_2 + 4);
  iVar2 = proc_write_mem(param_1,lVar1 + 0xc,0x38,param_2 + 0x14,0);
  if (iVar2 == 0) {
    local_32 = 1;
    uVar3 = proc_write_mem(param_1,lVar1 + 0x4c,1,&local_32,0);
    if ((int)uVar3 == 0) {
      if (*(char *)(param_2 + 0x4c) != '\0') {
        *(u64 *)(param_2 + 0xc) = 0;
        return uVar3;
      }
      local_31 = '\0';
      do {
        iVar2 = read_process_memory(param_1,lVar1 + 0x4d,1,&local_31,0);
        if (iVar2 != 0) {
          return 1;
        }
      } while (local_31 == '\0');
      local_31 = '\0';
      iVar2 = proc_write_mem(param_1,lVar1 + 0x4d,1,&local_31,0);
      if (iVar2 == 0) {
        local_30 = 0;
        uVar3 = read_process_memory(param_1,lVar1 + 0x44,8,&local_30,0);
        if ((int)uVar3 == 0) {
          *(u64 *)(param_2 + 0xc) = local_30;
          return uVar3;
        }
      }
    }
  }
  return 1;
}

/* protect_process_memory_handler @ 0x101baa size=19 */
void protect_process_memory_handler(u64 param_1,u64 *param_2)

{
  proc_vm_map_protect(param_1,*param_2,param_2[1],*(u32 *)(param_2 + 2));
  return;
}

/* run_elf_payload_handler @ 0x101e5e size=16 */
void run_elf_payload_handler(u64 param_1,u64 *param_2)

{
  load_and_exec_elf_in_process(param_1,*param_2,param_2[1]);
  return;
}

/* run_embedded_payload_handler @ 0x101cc1 size=149 */
u64 run_embedded_payload_handler(u64 param_1,s64 *param_2)

{
  int iVar1;
  u64 uVar2;
  s64 lVar3;
  s64 local_20;
  
  local_20 = 0;
  lVar3 = (s64)(int)(g_bytes_0018813c + 0x3fffU & 0xffffc000);
  iVar1 = proc_vm_map_alloc(param_1,&local_20,lVar3,0);
  if (((iVar1 == 0) && (iVar1 = proc_write_mem(param_1,local_20,lVar3,g_bytes_00187fa0,0), iVar1 == 0))
     && (uVar2 = run_goldhen_loader_stub(param_1,g_bytes_00187fa4 + local_20,0), (int)uVar2 == 0)) {
    *param_2 = local_20;
    return uVar2;
  }
  return 1;
}

/* run_raw_payload_handler @ 0x101e6e size=16 */
void run_raw_payload_handler(u64 param_1,u64 *param_2)

{
  run_payload_blob_default(param_1,*param_2,param_2[1]);
  return;
}

/* set_console_output_handler @ 0x102143 size=16 */
u8  [16] set_console_output_handler(u32 *param_1)

{
  u8 agg1 [16];
  u64 reg_rax;
  
  toggle_tty_redirect_hook(*param_1);
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg1 + 0)) = reg_rax;
  return agg1 << 0x40;
}

/* settings_syscall_handler @ 0x102317 size=190 */
void settings_syscall_handler(s64 param_1,u64 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  switch(*param_2) {
  case 1:
    set_console_output_handler(param_2[1]);
    goto l_001023b6;
  case 2:
    iVar1 = *southbridge;
    break;
  case 3:
    iVar1 = (int)*(u64 *)param_2[1];
    g_game_update_module_flag = iVar1;
    break;
  case 4:
    iVar1 = fill_app_version_field(param_2[1]);
    break;
  case 5:
    iVar1 = copy_appmeta_entries(param_2[1]);
    break;
  case 6:
    iVar1 = (int)*(u64 *)param_2[1];
    g_patch_update_module_flag = iVar1;
    break;
  case 7:
    iVar1 = fill_app_info_from_pkg(param_2[1]);
    break;
  case 8:
    iVar1 = (int)*(u64 *)param_2[1];
    g_game_patch_plugin_flag = iVar1;
    break;
  case 9:
    toggle_kernel_noop_patch_handler(param_2[1]);
l_001023b6:
    iVar1 = 0;
    break;
  case 10:
    iVar1 = (int)*(u64 *)param_2[1];
    g_aio_fix_plugin_flag = iVar1;
  }
  *(s64 *)(param_1 + 0x398) = (s64)iVar1;
  return;
}

/* toggle_kernel_noop_patch_handler @ 0x102153 size=16 */
u8  [16] toggle_kernel_noop_patch_handler(u32 *param_1)

{
  u8 agg1 [16];
  u64 reg_rax;
  
  toggle_noop_kernel_hook(*param_1);
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg1 + 0)) = reg_rax;
  return agg1 << 0x40;
}
