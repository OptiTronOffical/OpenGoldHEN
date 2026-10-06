/*
 * patches.c - kernel and shell patches and their installers.
 */

#include <goldhen/types.h>

/* install_custom_syscalls @ 0x10256e size=197 */
u8  [16] install_custom_syscalls(void)

{
  u8 agg1 [16];
  u64 reg_rax;
  
  str_ntu1_22_04_2_11_4_0_shstrtab = 1;
  set_sysent_entry(0xb,kexec_rop,2);
  set_sysent_entry(0xc5,list_processes_handler,8);
  set_sysent_entry(0xc6,process_memory_rw_handler,8);
  set_sysent_entry(199,process_command_handler,8);
  set_sysent_entry(200,goldhen_util_command_handler,8);
  set_sysent_entry(0xc9,settings_syscall_handler,8);
  set_sysent_entry(500,process_control_syscall_handler,8);
  (*(u8_t *)((u8 *)&agg1 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg1 + 0)) = reg_rax;
  return agg1 << 0x40;
}

/* install_kernel_patches @ 0x1027b5 size=952 */
void install_kernel_patches(void)

{
  void (*pcVar1)(void);
  u16 uVar2;
  int iVar3;
  s64 lVar4;
  u8 *puVar5;
  u8 *puVar6;
  u64 uVar7;
  u8 local_200 [224];
  u32 local_120;
  u32 local_11c;
  u32 local_118;
  u32 local_114;
  u32 local_110;
  u32 local_10c;
  u64 local_108;
  u32 local_100;
  u32 local_f8;
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
  
  uVar2 = get_firmware();
  get_goldhen_offsets(local_200);
  lVar4 = get_kbase();
  uVar7 = (u64)local_10c;
  *(u32 *)((u64)local_120 + lVar4) = 0;
  *(u32 *)((u64)local_11c + lVar4) = 0;
  *(u32 *)((u64)local_118 + lVar4) = 0x90c3c031;
  *(u32 *)((u64)local_114 + lVar4) = 0x90c301b0;
  *(u32 *)((u64)local_110 + lVar4) = 0x90c301b0;
  if ((u16)(uVar2 - 0x1f9) < 0xfb) {
    *(u64 *)(uVar7 + lVar4) = local_108;
    if (local_100 == 0) goto l_0010299e;
l_001028ee:
    *(u32 *)((u64)local_100 + lVar4) = local_f8;
l_00102979:
    if (uVar2 < 800) goto l_0010299e;
  }
  else {
    if (0xc9 < (u16)(uVar2 - 800)) {
      if ((u16)(uVar2 - 0x41a) < 0xfb) {
        *(int *)(uVar7 + lVar4) = (int)local_108;
        puVar6 = (u8 *)((u64)local_f0 + lVar4);
        *puVar6 = 0x90;
        puVar6[1] = 0x90;
        puVar5 = (u8 *)((u64)local_ec + lVar4);
        puVar6[2] = 0x90;
        puVar6[3] = 0x90;
        puVar6[4] = 0x90;
        puVar6[5] = 0x90;
        *puVar5 = 0x90;
        puVar5[1] = 0x90;
        puVar5[2] = 0x90;
        puVar5[3] = 0x90;
        puVar5[4] = 0x90;
        puVar5[5] = 0x90;
        *(u8 *)((u64)local_e8 + lVar4) = 0x90;
        ((u8 *)((u64)local_e8 + lVar4))[1] = 0xe9;
        goto l_00102b5f;
      }
      if (local_100 != 0) goto l_001028ee;
      goto l_00102979;
    }
    *(short *)(uVar7 + lVar4) = (short)local_108;
l_00102b5f:
    if (local_100 != 0) goto l_001028ee;
  }
  puVar5 = (u8 *)((u64)local_e4 + lVar4);
  *puVar5 = 0x90;
  puVar5[1] = 0x90;
  puVar5[2] = 0x90;
  puVar5[3] = 0x90;
  puVar5[4] = 0x90;
  puVar5[5] = 0x90;
l_0010299e:
  *(u32 *)((u64)local_e0 + lVar4) = 0x90c301b0;
  *(u32 *)((u64)local_dc + lVar4) = 0x90c301b0;
  puVar5 = (u8 *)((u64)local_d8 + lVar4);
  *puVar5 = 0x31;
  puVar5[1] = 0xc0;
  puVar5[2] = 0xeb;
  puVar5[3] = 1;
  *(u16 *)((u64)local_d4 + lVar4) = 0x9090;
  if (0x29e < uVar2) {
    *(u16 *)((u64)local_d0 + lVar4) = 0x9090;
    *(u8 *)((u16 *)((u64)local_d0 + lVar4) + 1) = 0x90;
  }
  *(u16 *)((u64)local_cc + lVar4) = 0x9090;
  if (0x29e < uVar2) {
    *(u16 *)((u64)local_c8 + lVar4) = 0x9090;
    *(u8 *)((u16 *)((u64)local_c8 + lVar4) + 1) = 0x90;
  }
  *(u16 *)((u64)local_c4 + lVar4) = 0x9090;
  if (0x29e < uVar2) {
    *(u16 *)((u64)local_c0 + lVar4) = 0x9090;
    *(u8 *)((u16 *)((u64)local_c0 + lVar4) + 1) = 0x90;
  }
  if ((u16)(uVar2 - 0x29f) < 2) {
    *(u8 *)((u64)local_b0 + lVar4) = 0xeb;
  }
  else {
    *(u16 *)((u64)local_b0 + lVar4) = 0x9090;
  }
  *(u8 *)((u64)local_ac + lVar4) = 0xc3;
  *(u32 *)((u64)local_a8 + lVar4) = 0x90c301b0;
  *(u8 *)((u64)local_a4 + lVar4) = 0x40;
  write_abs_jump_stub((u64)local_8c + lVar4,return_zero_stub);
  write_abs_jump_stub((u64)local_88 + lVar4,return_zero_stub);
  pcVar1 = sceSblAIMgrIsTestKit;
  *(u16 *)((u64)local_a0 + lVar4) = 0x9090;
  *(u16 *)((u64)local_9c + lVar4) = 0x9090;
  *(u16 *)((u64)local_98 + lVar4) = 0x9090;
  if ((((pcVar1 != (void (*)(void))0x0) && (iVar3 = (*pcVar1)(), iVar3 != 0)) &&
      (sceSblDevActSetStatus != (void (*)(void))0x0 && local_94 != 0)) && (local_90 != 0)) {
    *(u8 *)((u64)local_94 + lVar4) = 0;
    *(u8 *)((u64)local_90 + lVar4) = 0x94;
    (*sceSblDevActSetStatus)(0);
    (*printf)("[GoldHEN] Testkit fake activation installed!\n");
  }
                    /* WARNING: Could not recover jumptable at 0x00102b59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*printf)("[GoldHEN] Kernel patches installed!\n");
  return;
}

/* install_remoteplay_patches @ 0x103198 size=311 */
int install_remoteplay_patches(void)

{
  u16 uVar1;
  int iVar2;
  s64 lVar3;
  s64 lVar4;
  u64 uVar5;
  s64 local_208;
  u64 local_200;
  u8 local_1f8 [8];
  u8 local_1f0 [104];
  u32 local_188;
  u32 local_184;
  
  uVar1 = get_firmware();
  get_goldhen_offsets(local_1f0,uVar1);
  local_208 = 0;
  lVar3 = find_process_by_name("SceRemotePlay");
  if (lVar3 != 0) {
    iVar2 = snapshot_vm_map_entries(lVar3,&local_208,&local_200);
    uVar5 = 0;
    if (iVar2 == 0) {
      for (; uVar5 < local_200; uVar5 = uVar5 + 1) {
        iVar2 = (*memcmp)(local_208 + uVar5 * 0x3a,"executable",10);
        if ((iVar2 == 0) && (lVar4 = uVar5 * 0x3a + local_208, *(short *)(lVar4 + 0x38) == 5)) {
          lVar4 = *(s64 *)(lVar4 + 0x20);
          if (lVar4 != 0) {
            iVar2 = proc_write_mem(lVar3,(u64)local_188 + lVar4,1,g_bytes_00196e05);
            if ((iVar2 == 0) &&
               (iVar2 = proc_write_mem(lVar3,lVar4 + (u64)local_184,2,g_bytes_00196e07,local_1f8),
               iVar2 == 0)) {
              (*printf)("[GoldHEN] SceRemotePlay patches installed!\n");
            }
            goto l_001032af;
          }
          break;
        }
      }
    }
  }
  iVar2 = 1;
l_001032af:
  if (local_208 != 0) {
    dealloc();
  }
  return iVar2;
}

/* install_shellcore_patches @ 0x102b6d size=1185 */
/* WARNING: Type propagation algorithm not settling */

int install_shellcore_patches(void)

{
  u16 uVar1;
  int iVar2;
  int iVar3;
  s64 lVar4;
  s64 lVar5;
  s64 lVar6;
  u32 local_245;
  u8 local_241;
  u8 local_240 [8];
  s64 local_238;
  s64 local_230 [2];
  u64 local_220;
  u64 local_218;
  u64 local_210;
  u64 local_208;
  u8 local_200 [112];
  u64 local_190;
  u64 local_188;
  u64 local_180;
  u64 local_178;
  u32 local_170;
  u32 local_16c;
  u32 local_154;
  u32 local_150;
  u32 local_14c;
  u32 local_148;
  u32 local_144;
  u32 local_140;
  u32 local_13c;
  u32 local_138;
  u32 local_134;
  u32 local_130;
  u32 local_12c;
  u32 local_128;
  u32 local_124;
  
  uVar1 = get_firmware();
  get_goldhen_offsets(local_200,uVar1);
  if ((sceSblAIMgrIsTestKit != (void (*)(void))0x0) && (iVar2 = (*sceSblAIMgrIsTestKit)(), iVar2 != 0)) {
    return 0;
  }
  local_238 = 0;
  local_230[0] = 0;
  local_245 = 0xc0ffc031;
  local_220 = local_190;
  local_241 = 0x90;
  local_218 = local_188;
  local_210 = local_180;
  local_208 = local_178;
  lVar4 = find_process_by_name("SceShellCore");
  if (lVar4 != 0) {
    iVar2 = snapshot_vm_map_entries(lVar4,&local_238,local_230);
    if (iVar2 != 0) goto l_00102fea;
    lVar5 = local_238;
    for (lVar6 = 0; local_230[0] != lVar6; lVar6 = lVar6 + 1) {
      if (*(short *)(lVar5 + 0x38) == 5) {
        lVar5 = *(s64 *)(lVar5 + 0x20);
        lVar6 = 0;
        if (lVar5 != 0) goto l_00102cfb;
        break;
      }
      lVar5 = lVar5 + 0x3a;
    }
  }
  iVar2 = -1;
  goto l_00102fea;
  while (lVar6 = lVar6 + 1, lVar6 != 8) {
l_00102cfb:
    iVar2 = proc_write_mem(lVar4,(u64)*(u32 *)((s64)&local_220 + lVar6 * 4) + lVar5,5,
                         g_bytes_00196d68,local_240);
    if (iVar2 != 0) goto l_00102fea;
  }
  iVar2 = proc_write_mem(lVar4,(u64)local_170 + lVar5,5,&local_245,local_240);
  if ((((((((iVar2 == 0) &&
           (iVar2 = proc_write_mem(lVar4,(u64)local_16c + lVar5,4,g_bytes_00196d6e,local_240),
           iVar2 == 0)) &&
          (iVar2 = proc_write_mem(lVar4,(u64)local_154 + lVar5,5,g_bytes_001969e0,local_240),
          iVar2 == 0)) &&
         ((iVar2 = proc_write_mem(lVar4,(u64)local_150 + lVar5,1,g_bytes_001969e6,local_240),
          iVar2 == 0 &&
          (iVar3 = proc_write_mem(lVar4,(u64)local_14c + lVar5,1,g_bytes_00196d73,local_240),
          iVar2 = iVar3, iVar3 == 0)))) &&
        ((local_148 == 0 ||
         (iVar2 = proc_write_mem(lVar4,(u64)local_148 + lVar5,5,g_bytes_00196d68,local_240), iVar2 == 0
         )))) && ((local_144 == 0 ||
                  (iVar2 = proc_write_mem(lVar4,(u64)local_144 + lVar5,5,g_bytes_00196d75,local_240),
                  iVar2 == 0)))) &&
      ((local_140 == 0 ||
       (iVar2 = proc_write_mem(lVar4,(u64)local_140 + lVar5,3,g_bytes_00196d7c,local_240), iVar2 == 0))
      )) && (((local_13c == 0 ||
              (iVar2 = proc_write_mem(lVar4,(u64)local_13c + lVar5,4,g_bytes_00196d7b,local_240),
              iVar2 == 0)) &&
             ((local_138 == 0 ||
              (iVar2 = proc_write_mem(lVar4,(u64)local_138 + lVar5,4,g_bytes_00196d7b,local_240),
              iVar2 == 0)))))) {
    if (local_134 != 0) {
      local_230[1] = 0xc3ffffffffc0c748;
      iVar2 = proc_write_mem(lVar4,(u64)local_134 + lVar5,8,local_230 + 1,local_240);
      if (iVar2 != 0) goto l_00102fea;
    }
    if (((((local_130 == 0) ||
          (iVar2 = proc_write_mem(lVar4,(u64)local_130 + lVar5,4,g_bytes_00196d7b,local_240),
          iVar2 == 0)) &&
         ((local_12c == 0 ||
          (iVar2 = proc_write_mem(lVar4,(u64)local_12c + lVar5,2,g_bytes_00196d70,local_240),
          iVar2 == 0)))) &&
        ((local_128 == 0 ||
         (iVar2 = proc_write_mem(lVar4,(u64)local_128 + lVar5,1,g_bytes_00196d73,local_240), iVar2 == 0
         )))) && ((local_124 == 0 ||
                  (iVar2 = proc_write_mem(lVar4,lVar5 + (u64)local_124,1,g_bytes_00196d73,local_240),
                  iVar2 == 0)))) {
      (*printf)("[GoldHEN] SceShellCore patches installed!\n");
      iVar2 = iVar3;
    }
  }
l_00102fea:
  if (local_238 != 0) {
    dealloc();
  }
  return iVar2;
}

/* install_shellui_patches @ 0x10300e size=394 */
int install_shellui_patches(void)

{
  u16 uVar1;
  int iVar2;
  s64 lVar3;
  s64 lVar4;
  u64 uVar5;
  u8 auStack_208 [8];
  s64 local_200;
  u64 local_1f8;
  u8 local_1f0 [64];
  s64 local_1b0;
  s64 local_1a8;
  u8 local_1a0 [16];
  u8 local_190;
  
  iVar2 = -1;
  uVar1 = get_firmware();
  get_goldhen_offsets(local_1f0,uVar1);
  local_200 = 0;
  local_1f8 = 0;
  lVar3 = find_process_by_name("SceShellUI");
  if (lVar3 != 0) {
    iVar2 = snapshot_vm_map_entries(lVar3,&local_200,&local_1f8);
    uVar5 = 0;
    if (iVar2 == 0) {
      for (; uVar5 < local_1f8; uVar5 = uVar5 + 1) {
        iVar2 = (*memcmp)(local_200 + uVar5 * 0x3a,"executable",10);
        if ((iVar2 == 0) && (lVar4 = uVar5 * 0x3a + local_200, 4 < *(u16 *)(lVar4 + 0x38))) {
          lVar4 = *(s64 *)(lVar4 + 0x20);
          if (lVar4 != 0) {
            uVar5 = 0;
            iVar2 = proc_write_mem(lVar3,lVar4 + local_1b0,4,g_bytes_00196d7b,auStack_208);
            if (iVar2 == 0) goto l_00103106;
            goto l_00103176;
          }
          break;
        }
      }
l_001030c6:
      iVar2 = 1;
    }
  }
l_00103176:
  if (local_200 != 0) {
    dealloc();
  }
  return iVar2;
l_00103106:
  if (local_1f8 <= uVar5) goto l_001030c6;
  iVar2 = (*memcmp)(local_200 + uVar5 * 0x3a,"app.exe.sprx",0xc);
  if ((iVar2 == 0) && (lVar4 = uVar5 * 0x3a + local_200, 4 < *(u16 *)(lVar4 + 0x38))) {
    lVar4 = *(s64 *)(lVar4 + 0x20);
    if (lVar4 != 0) {
      iVar2 = proc_write_mem(lVar3,lVar4 + local_1a8,local_190,local_1a0,auStack_208);
      (*printf)("[GoldHEN] SceShellUI patches installed!\n");
      goto l_00103176;
    }
    goto l_001030c6;
  }
  uVar5 = uVar5 + 1;
  goto l_00103106;
}

/* install_shellui_remoteplay_patches @ 0x103412 size=20 */
void install_shellui_remoteplay_patches(u64 param_1,u64 param_2)

{
  u64 reg_rax;
  
  install_shellui_patches();
  install_remoteplay_patches(param_1,param_2,reg_rax);
  return;
}
