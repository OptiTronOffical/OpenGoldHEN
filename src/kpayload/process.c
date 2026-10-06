/*
 * process.c - process memory, ELF loading and kexec helpers.
 */

#include <goldhen/types.h>

/* apply_elf_relocations @ 0x104f5a size=203 */
u64 apply_elf_relocations(u64 param_1,s64 param_2,s64 param_3)

{
  void (*pcVar1)(void);
  s64 lVar2;
  s64 *plVar3;
  u64 uVar4;
  int iVar5;
  s64 local_40 [2];
  
  iVar5 = 0;
  while( true ) {
    if ((int)(u32)*(u16 *)(param_2 + 0x3c) <= iVar5) {
      return 0;
    }
    if ((*(s64 *)(param_2 + 0x28) == 0) ||
       (lVar2 = *(s64 *)(param_2 + 0x28) + param_2, lVar2 == 0)) break;
    lVar2 = (int)((u32)*(u16 *)(param_2 + 0x3a) * iVar5) + lVar2;
    if (*(int *)(lVar2 + 4) == 4) {
      for (uVar4 = 0; uVar4 < *(u64 *)(lVar2 + 0x20) / *(u64 *)(lVar2 + 0x38); uVar4 = uVar4 + 1
          ) {
        plVar3 = (s64 *)(*(s64 *)(lVar2 + 0x18) + param_2 + uVar4 * 0x18);
        if ((int)plVar3[1] == 8) {
          local_40[0] = plVar3[2] + param_3;
          proc_write_mem(param_1,*plVar3 + param_3,8,local_40,0);
        }
      }
    }
    iVar5 = iVar5 + 1;
  }
                    /* WARNING: Does not return */
  *(volatile u64 *)0x10;
  __builtin_trap();
  (*pcVar1)();
}

/* copy_elf_segments @ 0x104e5f size=251 */
u8  [16] copy_elf_segments(u64 param_1,s64 param_2,s64 param_3,u64 param_4)

{
  void (*pcVar1)(void);
  u8 agg2 [16];
  s64 lVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = iVar4;
  if ((*(s64 *)(param_2 + 0x20) == 0) || (iVar5 = 0, *(s64 *)(param_2 + 0x20) + param_2 == 0)) {
    for (; iVar5 < (int)(u32)*(u16 *)(param_2 + 0x3c); iVar5 = iVar5 + 1) {
      if ((*(s64 *)(param_2 + 0x28) == 0) ||
         (lVar3 = *(s64 *)(param_2 + 0x28) + param_2, lVar3 == 0)) goto l_00104f4e;
      lVar3 = (int)((u32)*(u16 *)(param_2 + 0x3a) * iVar5) + lVar3;
      if (((*(u8 *)(lVar3 + 8) & 2) != 0) && (*(s64 *)(lVar3 + 0x20) != 0)) {
        proc_write_mem(param_1,*(s64 *)(lVar3 + 0x10) + param_3,*(s64 *)(lVar3 + 0x20),
                     *(s64 *)(lVar3 + 0x18) + param_2,0);
      }
    }
  }
  else {
    for (; iVar4 < (int)(u32)*(u16 *)(param_2 + 0x38); iVar4 = iVar4 + 1) {
      if ((*(s64 *)(param_2 + 0x20) == 0) ||
         (lVar3 = *(s64 *)(param_2 + 0x20) + param_2, lVar3 == 0)) {
l_00104f4e:
                    /* WARNING: Does not return */
        *(volatile u64 *)0x10;
        __builtin_trap();
        (*pcVar1)();
      }
      lVar3 = (int)((u32)*(u16 *)(param_2 + 0x36) * iVar4) + lVar3;
      if (*(s64 *)(lVar3 + 0x20) != 0) {
        proc_write_mem(param_1,*(s64 *)(lVar3 + 0x18) + param_3,*(s64 *)(lVar3 + 0x20),
                     *(s64 *)(lVar3 + 8) + param_2,0);
      }
    }
  }
  (*(u8_t *)((u8 *)&agg2 + 1)) = 0;
  (*(u8_t *)((u8 *)&agg2 + 0)) = param_4;
  return agg2 << 0x40;
}

/* find_process_by_pid @ 0x103af0 size=31 */
void find_process_by_pid(int param_1)

{
  s64 *plVar1;
  
  plVar1 = (s64 *)*allproc;
  do {
    if ((int)plVar1[0x16] == param_1) {
      return;
    }
    plVar1 = (s64 *)*plVar1;
  } while (plVar1 != (s64 *)0x0);
  return;
}

/* get_elf_load_size @ 0x10033f size=204 */
u8  [16] get_elf_load_size(s64 param_1,u64 *param_2,u64 param_3,u64 param_4)

{
  void (*pcVar1)(void);
  int iVar2;
  s64 lVar3;
  u64 uVar4;
  s64 lVar5;
  u64 uVar6;
  u64 uVar7;
  u8 agg8 [16];
  
  iVar2 = (*memcmp)(param_1,g_bytes_00111e80,4);
  if (iVar2 == 0) {
    uVar7 = 0;
    if ((*(s64 *)(param_1 + 0x20) == 0) ||
       (lVar3 = *(s64 *)(param_1 + 0x20) + param_1, lVar3 == 0)) {
      uVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(u32)*(u16 *)(param_1 + 0x3c); iVar2 = iVar2 + 1) {
        if ((*(s64 *)(param_1 + 0x28) == 0) ||
           (lVar3 = *(s64 *)(param_1 + 0x28) + param_1, lVar3 == 0)) {
                    /* WARNING: Does not return */
          *(volatile u64 *)0x10;
          __builtin_trap();
          (*pcVar1)();
        }
        lVar5 = (s64)(int)((u32)*(u16 *)(param_1 + 0x3a) * iVar2);
        uVar6 = *(s64 *)(lVar3 + 0x10 + lVar5) + *(s64 *)(lVar3 + 0x20 + lVar5);
        if (uVar4 < uVar6) {
          uVar4 = uVar6;
        }
      }
    }
    else {
      uVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(u32)*(u16 *)(param_1 + 0x38); iVar2 = iVar2 + 1) {
        lVar5 = (s64)(int)((u32)*(u16 *)(param_1 + 0x36) * iVar2);
        uVar6 = *(s64 *)(lVar3 + 0x18 + lVar5) + *(s64 *)(lVar3 + 0x28 + lVar5);
        if (uVar4 < uVar6) {
          uVar4 = uVar6;
        }
      }
    }
    if (param_2 != (u64 *)0x0) {
      *param_2 = uVar4;
    }
  }
  else {
    uVar7 = 1;
  }
  (*(u8_t *)((u8 *)&agg8 + 1)) = param_4;
  (*(u8_t *)((u8 *)&agg8 + 0)) = uVar7;
  return agg8;
}

/* kexec_payload_file @ 0x1051a5 size=347 */
u32 kexec_payload_file(s64 param_1,s64 param_2)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u64 uVar5;
  s64 lVar6;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0xb0) == 0)) &&
     (param_1 = find_process_by_name("SceSpZeroConf"), param_1 == 0)) {
    return 1;
  }
  if (*(int *)(param_1 + 0xb0) == 0) {
    return 1;
  }
  if (param_2 == 0) {
    return 1;
  }
  lVar1 = *(s64 *)(param_1 + 0x10);
  if (lVar1 == 0) {
    return 1;
  }
  jailbreak_thread(lVar1,0);
  iVar2 = sys_open(param_2,0,0,lVar1);
  if (iVar2 < 0) {
    return 1;
  }
  uVar5 = sys_lseek(iVar2,0,2,lVar1);
  if (uVar5 != 0) {
    sys_lseek(iVar2,0,0,lVar1);
    lVar6 = alloc(uVar5 & 0xffffffff);
    if (lVar6 != 0) {
      iVar3 = sys_read(iVar2,lVar6,uVar5 & 0xffffffff,lVar1);
      if (-1 < iVar3) {
        sys_close(iVar2,lVar1);
        iVar2 = identify_payload_format(lVar6,uVar5);
        if (iVar2 == 0) {
          uVar4 = run_payload_blob_default(param_1,lVar6,uVar5);
        }
        else {
          uVar4 = 1;
          if (iVar2 == 1) {
            uVar4 = load_and_exec_elf_in_process(param_1,lVar6,0);
          }
        }
        dealloc(lVar6);
        return uVar4;
      }
      goto l_001052d5;
    }
  }
  lVar6 = 0;
l_001052d5:
  sys_close(iVar2,lVar1);
  if (lVar6 != 0) {
    dealloc(lVar6);
  }
  return 1;
}

/*
 * kexec_payload_file_alias - second jump thunk for kexec_payload_file().
 *
 *
 *     f3 0f 1e fa      endbr64
 *     e9 79 34 00 00   jmp kexec_payload_file_thunk
 *
 * Nothing calls this thunk and nothing stores its address, so it is unreachable
 * as shipped.  It is real code in the image, though - an alias entry next to
 * the handler's own code, i.e. the shape a patch site would point at.
 */
void kexec_payload_file_thunk(void *process, u64 arg);

void kexec_payload_file_alias(void *process, u64 arg)
{
    kexec_payload_file_thunk(process, arg);
}

/* kexec_payload_file_thunk @ 0x105300 size=9 */
void kexec_payload_file_thunk(void)

{
  kexec_payload_file();
  return;
}

/* load_and_exec_elf_in_process @ 0x1050d7 size=192 */
bool load_and_exec_elf_in_process(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  s64 local_40;
  u64 local_38;
  u64 local_30 [2];
  
  iVar1 = load_elf_in_process(param_1,param_2,0,local_30,param_3);
  if (((iVar1 != 0) || (iVar1 = snapshot_vm_map_entries(param_1,&local_40,&local_38), iVar1 != 0)) ||
     (uVar3 = 0, lVar2 = local_40, local_40 == 0)) {
    return true;
  }
  do {
    if (local_38 <= uVar3) {
l_00105175:
      iVar1 = run_goldhen_loader_stub(param_1,local_30[0],0);
      return iVar1 != 0;
    }
    if ((*(short *)(lVar2 + 0x38) == 5) && (iVar1 = (*memcmp)(lVar2,"executable",10), iVar1 == 0)) {
      proc_vm_map_protect(param_1,*(s64 *)(lVar2 + 0x20),*(s64 *)(lVar2 + 0x28) - *(s64 *)(lVar2 + 0x20)
                   ,7);
      goto l_00105175;
    }
    uVar3 = uVar3 + 1;
    lVar2 = lVar2 + 0x3a;
  } while( true );
}

/* load_elf_in_process @ 0x105025 size=178 */
void load_elf_in_process(u64 param_1,s64 param_2,s64 *param_3,s64 *param_4,s64 param_5)

{
  s64 lVar1;
  int iVar2;
  s64 local_40 [2];
  u64 local_30;
  
  local_30 = 0;
  local_40[0] = param_5;
  iVar2 = get_elf_load_size(param_2,&local_30);
  if (iVar2 == 0) {
    local_30 = (local_30 & 0xffffffffffffc000) + 0x4000;
    iVar2 = proc_vm_map_alloc(param_1,local_40,local_30,0);
    lVar1 = local_40[0];
    if (iVar2 == 0) {
      iVar2 = copy_elf_segments(param_1,param_2,local_40[0]);
      if (iVar2 == 0) {
        iVar2 = apply_elf_relocations(param_1,param_2,lVar1);
        if (iVar2 == 0) {
          if (param_3 != (s64 *)0x0) {
            *param_3 = lVar1;
          }
          if (param_4 != (s64 *)0x0) {
            *param_4 = lVar1 + *(s64 *)(param_2 + 0x18);
          }
        }
      }
    }
  }
  return;
}

/* load_plugin_in_process @ 0x104545 size=688 */
u64 load_plugin_in_process(s64 param_1,u64 param_2,char param_3)

{
  s64 lVar1;
  u16 uVar2;
  int iVar3;
  u64 uVar4;
  u64 uVar5;
  s64 lVar6;
  u64 *puVar7;
  char local_23c [19];
  char local_229;
  s64 local_228;
  s64 local_220;
  u64 local_218;
  s64 local_210;
  u64 local_208;
  u8 local_200 [392];
  u32 local_78;
  u32 local_74;
  u32 local_70;
  
  local_228 = 0;
  local_220 = 0;
  local_218 = 0;
  lVar6 = (s64)(int)(g_bytes_00187c4c + 0x83fffU & 0xffffc000);
  local_210 = 0;
  local_229 = '\0';
  local_208 = 0;
  local_23c[0] = param_3;
  iVar3 = proc_vm_map_alloc(param_1,&local_228,lVar6,0);
  if ((iVar3 == 0) &&
     (iVar3 = proc_vm_map_alloc(param_1,&local_220,0x80000,0), lVar1 = local_228, iVar3 == 0)) {
    iVar3 = proc_write_mem(param_1,local_228,(s64)g_bytes_00187c4c,g_bytes_001879cc,&local_218);
    if (iVar3 == 0) {
      puVar7 = (u64 *)**(u64 **)(param_1 + 0x340);
      uVar2 = get_firmware();
      get_goldhen_offsets(local_200,uVar2);
      for (; puVar7 != (u64 *)0x0; puVar7 = (u64 *)*puVar7) {
        uVar4 = get_path_basename(puVar7[1]);
        iVar3 = (*memcmp)(uVar4,"libkernel_sys.sprx",0x12);
        if (iVar3 == 0) {
          uVar5 = (u64)local_70;
l_0010468d:
          local_210 = uVar5 + puVar7[6];
          break;
        }
        iVar3 = (*memcmp)(uVar4,"libkernel_web.sprx",0x12);
        if (iVar3 == 0) {
          uVar5 = (u64)local_74;
          goto l_0010468d;
        }
        iVar3 = (*memcmp)(uVar4,"libkernel.sprx",0xe);
        if (iVar3 == 0) {
          uVar5 = (u64)local_78;
          goto l_0010468d;
        }
      }
      if (local_210 != 0) {
        uVar4 = (*strlen)(param_2);
        iVar3 = proc_write_mem(param_1,lVar1 + 0x15,uVar4,param_2,&local_218);
        if (((iVar3 == 0) &&
            (uVar4 = proc_write_mem(param_1,lVar1 + 0xc,8,&local_210,&local_218), (int)uVar4 == 0)) &&
           ((local_23c[0] != '\x01' ||
            (uVar4 = proc_write_mem(param_1,lVar1 + 0x81,1,local_23c,&local_218), (int)uVar4 == 0))))
        {
          iVar3 = (*create_thread)(*(u64 *)(param_1 + 0x10),0,g_bytes_001879d0 + lVar1,0,
                                   local_220,0x80000,0,0,0,0,0,uVar4);
          while (iVar3 == 0) {
            if (local_229 != '\0') {
              read_process_memory(param_1,lVar1 + 0x79,8,&local_208,&local_218);
              break;
            }
            iVar3 = read_process_memory(param_1,lVar1 + 0x14,1,&local_229,&local_218);
          }
        }
      }
    }
  }
  if (local_228 != 0) {
    proc_vm_map_free(param_1,local_228,lVar6);
  }
  if (local_220 != 0) {
    proc_vm_map_free(param_1,local_220,0x80000);
  }
  return local_208 & 0xffffffff;
}

/* load_prx_into_named_process @ 0x1023f8 size=87 */
u8  [16] load_prx_into_named_process(s64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  u8 agg4 [16];
  
  lVar2 = (*strlen)();
  if (lVar2 != 0) {
    lVar2 = (*strlen)(param_1 + 0x20);
    if (lVar2 != 0) {
      lVar2 = find_process_by_name(param_1);
      if (lVar2 != 0) {
        iVar1 = load_plugin_in_process(lVar2,param_1 + 0x20,0);
        *(s64 *)(param_1 + 0x84) = (s64)iVar1;
        uVar3 = 0;
        goto l_0010244b;
      }
    }
  }
  uVar3 = 1;
l_0010244b:
  (*(u8_t *)((u8 *)&agg4 + 1)) = param_4;
  (*(u8_t *)((u8 *)&agg4 + 0)) = uVar3;
  return agg4;
}

/* proc_write_mem @ 0x103e56 size=15 */
void proc_write_mem(void)

{
  rw_process_memory();
  return;
}

/* read_process_memory @ 0x103e4a size=12 */
void read_process_memory(void)

{
  rw_process_memory();
  return;
}

/* run_blob_at_fixed_address_in_process @ 0x104b7d size=738 */
u64 run_blob_at_fixed_address_in_process(s64 param_1,u64 param_2,s64 param_3,u64 param_4,s64 param_5)

{
  s64 lVar1;
  s64 lVar2;
  u16 uVar3;
  u32 uVar4;
  int iVar5;
  s64 lVar6;
  u64 uVar7;
  u64 uVar8;
  u64 uVar9;
  u64 *puVar10;
  u64 local_230;
  char local_221;
  s64 local_220;
  s64 local_218;
  u64 local_210;
  s64 local_208;
  u8 local_200 [392];
  u32 local_78;
  u32 local_74;
  u32 local_70;
  
  uVar8 = param_3 + 0x83fffU & 0xffffffffffffc000;
  lVar6 = (s64)(int)(g_bytes_001881c8 + 0x3fffU & 0xffffc000);
  local_220 = 0;
  local_218 = 0;
  local_210 = 0;
  local_208 = 0;
  local_221 = '\0';
  local_230 = param_4;
  uVar4 = proc_vm_map_alloc(param_1,&local_230,uVar8,0);
  uVar9 = (u64)uVar4;
  if (uVar4 == 0) {
    if (param_5 != 0) {
      set_vm_map_entry_name(param_1,local_230,uVar8,7);
    }
    uVar4 = proc_write_mem(param_1,local_230,param_3,param_2,0);
    uVar9 = (u64)uVar4;
    if (uVar4 == 0) {
      uVar4 = proc_vm_map_alloc(param_1,&local_220,lVar6,0);
      uVar9 = (u64)uVar4;
      if (uVar4 == 0) {
        uVar4 = proc_vm_map_alloc(param_1,&local_218,0x80000,0);
        lVar1 = local_220;
        uVar9 = (u64)uVar4;
        if (uVar4 == 0) {
          uVar4 = proc_write_mem(param_1,local_220,(s64)g_bytes_001881c8,g_bytes_00188140,&local_210);
          uVar9 = (u64)uVar4;
          if (uVar4 == 0) {
            puVar10 = (u64 *)**(u64 **)(param_1 + 0x340);
            uVar3 = get_firmware();
            get_goldhen_offsets(local_200,uVar3);
            for (; puVar10 != (u64 *)0x0; puVar10 = (u64 *)*puVar10) {
              uVar7 = get_path_basename(puVar10[1]);
              iVar5 = (*memcmp)(uVar7,"libkernel_sys.sprx",0x12);
              if (iVar5 == 0) {
                uVar8 = (u64)local_70;
l_00104d44:
                local_208 = uVar8 + puVar10[6];
                break;
              }
              iVar5 = (*memcmp)(uVar7,"libkernel_web.sprx",0x12);
              if (iVar5 == 0) {
                uVar8 = (u64)local_74;
                goto l_00104d44;
              }
              iVar5 = (*memcmp)(uVar7,"libkernel.sprx",0xe);
              if (iVar5 == 0) {
                uVar8 = (u64)local_78;
                goto l_00104d44;
              }
            }
            lVar2 = local_218;
            if (local_208 != 0) {
              uVar8 = proc_write_mem(param_1,lVar1 + 0xd,8,&local_230,&local_210);
              if (((int)uVar8 == 0) &&
                 (uVar8 = proc_write_mem(param_1,lVar1 + 0x15,8,&local_208,&local_210),
                 (int)uVar8 == 0)) {
                uVar8 = (*create_thread)(*(u64 *)(param_1 + 0x10),0,g_bytes_00188144 + lVar1,0,
                                         lVar2,0x80000,0,0,0,0,0,uVar8);
                iVar5 = (int)uVar8;
                while (iVar5 == 0) {
                  if (local_221 != '\0') goto l_00104e1d;
                  uVar8 = read_process_memory(param_1,lVar1 + 0xc,1,&local_221,&local_210);
                  iVar5 = (int)uVar8;
                }
              }
              uVar9 = uVar8 & 0xffffffff;
            }
          }
        }
      }
    }
  }
l_00104e1d:
  if (local_220 != 0) {
    proc_vm_map_free(param_1,local_220,lVar6);
  }
  if (local_218 != 0) {
    proc_vm_map_free(param_1,local_218,0x80000);
  }
  return uVar9;
}

/* run_goldhen_loader_stub @ 0x104000 size=1130 */
/* WARNING: Type propagation algorithm not settling */

u64 run_goldhen_loader_stub(s64 param_1,u64 param_2,char param_3)

{
  u64 uVar1;
  u64 *puVar2;
  s64 lVar3;
  u16 uVar4;
  u32 uVar5;
  int iVar6;
  u64 uVar7;
  u64 uVar8;
  s64 lVar9;
  s64 lVar10;
  u64 local_278;
  char local_264 [4];
  u64 local_260;
  char local_251;
  s64 local_250;
  s64 local_248;
  s64 local_240;
  u64 local_238 [7];
  u8 local_200 [392];
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
  
  local_250 = 0;
  local_248 = 0;
  local_240 = 0;
  lVar9 = (s64)(int)(g_bytes_00187f9c + 0x3fffU & 0xffffc000);
  local_238[0] = 0;
  local_238[1] = 0;
  local_264[0] = param_3;
  local_260 = param_2;
  uVar5 = proc_vm_map_alloc(param_1,&local_250,lVar9,param_2);
  uVar8 = (u64)uVar5;
  if (uVar5 == 0) {
    uVar5 = proc_vm_map_alloc(param_1,&local_248,0x80000,local_260);
    lVar3 = local_250;
    uVar8 = (u64)uVar5;
    if (uVar5 == 0) {
      puVar2 = local_238 + 1;
      uVar5 = proc_write_mem(param_1,local_250,(s64)g_bytes_00187f9c,g_bytes_00187e6c,puVar2);
      uVar8 = (u64)uVar5;
      if (uVar5 == 0) {
        uVar1 = *(u64 *)(param_1 + 0x10);
        uVar5 = snapshot_vm_map_entries(param_1,&local_240,local_238);
        lVar10 = local_240;
        uVar8 = (u64)uVar5;
        if (uVar5 == 0) {
          if (local_240 == 0) {
            uVar8 = 1;
          }
          else {
            local_238[2] = 0;
            local_238[3] = 0;
            local_238[4] = 0;
            local_238[5] = 0;
            local_238[6] = 0;
            uVar4 = get_firmware();
            get_goldhen_offsets(local_200,uVar4);
            for (local_278 = 0; local_278 < local_238[0]; local_278 = local_278 + 1) {
              if (*(short *)(lVar10 + 0x38) == 5) {
                iVar6 = (*memcmp)(lVar10,"libkernel_sys.sprx",0x12);
                if (iVar6 == 0) {
                  lVar10 = *(s64 *)(lVar10 + 0x20);
                  local_238[2] = (u64)local_64 + lVar10;
                  local_238[3] = (u64)local_58 + lVar10;
                  local_238[4] = (u64)local_4c + lVar10;
                  local_238[5] = (u64)local_40 + lVar10;
                  local_238[6] = (u64)local_70;
                }
                else {
                  iVar6 = (*memcmp)(lVar10,"libkernel_web.sprx",0x12);
                  if (iVar6 == 0) {
                    lVar10 = *(s64 *)(lVar10 + 0x20);
                    local_238[2] = (u64)local_68 + lVar10;
                    local_238[3] = (u64)local_5c + lVar10;
                    local_238[4] = (u64)local_50 + lVar10;
                    local_238[5] = (u64)local_44 + lVar10;
                    local_238[6] = (u64)local_74;
                  }
                  else {
                    iVar6 = (*memcmp)(lVar10,"libkernel.sprx",0xe);
                    if (iVar6 != 0) goto l_00104299;
                    lVar10 = *(s64 *)(lVar10 + 0x20);
                    local_238[2] = (u64)local_6c + lVar10;
                    local_238[3] = (u64)local_60 + lVar10;
                    local_238[4] = (u64)local_54 + lVar10;
                    local_238[5] = (u64)local_48 + lVar10;
                    local_238[6] = (u64)local_78;
                  }
                }
                local_238[6] = lVar10 + local_238[6];
                break;
              }
l_00104299:
              lVar10 = lVar10 + 0x3a;
            }
            if (local_238[2] != 0) {
              uVar7 = proc_write_mem(param_1,lVar3 + 0xe,8,&local_260,puVar2);
              if (((((int)uVar7 == 0) &&
                   ((((local_264[0] != '\x01' ||
                      (uVar7 = proc_write_mem(param_1,lVar3 + 0xd,1,local_264,puVar2), (int)uVar7 == 0
                      )) && (uVar7 = proc_write_mem(param_1,lVar3 + 0x16,8,local_238 + 2,puVar2),
                            lVar10 = local_248, (int)uVar7 == 0)) &&
                    ((uVar7 = proc_write_mem(param_1,lVar3 + 0x1e,8,local_238 + 3,puVar2),
                     (int)uVar7 == 0 &&
                     (uVar7 = proc_write_mem(param_1,lVar3 + 0x26,8,local_238 + 4,puVar2),
                     (int)uVar7 == 0)))))) &&
                  (uVar7 = proc_write_mem(param_1,lVar3 + 0x2e,8,local_238 + 5,puVar2),
                  (int)uVar7 == 0)) &&
                 ((uVar7 = proc_write_mem(param_1,lVar3 + 0x36,8,local_238 + 6,puVar2),
                  (int)uVar7 == 0 &&
                  (uVar7 = (*create_thread)(uVar1,0,g_bytes_00187e70 + lVar3,0,lVar10,0x80000,0,0,0,0,0,
                                            uVar7), (int)uVar7 == 0)))) {
                local_251 = '\0';
                do {
                  uVar7 = read_process_memory(param_1,lVar3 + 0xc,1,&local_251,puVar2);
                  if ((int)uVar7 != 0) goto l_0010440f;
                } while (local_251 == '\0');
              }
              else {
l_0010440f:
                uVar8 = uVar7 & 0xffffffff;
              }
            }
          }
        }
      }
    }
  }
  if (local_240 != 0) {
    (*free)(local_240,M_TEMP);
  }
  if (local_250 != 0) {
    proc_vm_map_free(param_1,local_250,lVar9);
  }
  if (local_248 != 0) {
    proc_vm_map_free(param_1,local_248,0x80000);
  }
  return uVar8;
}

/* run_payload_blob_default @ 0x105197 size=14 */
void run_payload_blob_default(void)

{
  run_payload_blob_in_process();
  return;
}

/* run_payload_blob_in_process @ 0x104a9c size=167 */
bool run_payload_blob_in_process(u64 param_1,u64 param_2,s64 param_3,u64 param_4,s64 param_5
                 )

{
  u64 uVar1;
  int iVar2;
  u64 uVar3;
  u64 local_30;
  
  uVar3 = param_3 + 0x83fffU & 0xffffffffffffc000;
  local_30 = param_4;
  iVar2 = proc_vm_map_alloc(param_1,&local_30,uVar3,0);
  uVar1 = local_30;
  if (iVar2 == 0) {
    if (param_5 != 0) {
      set_vm_map_entry_name(param_1,local_30,uVar3,7);
    }
    iVar2 = proc_write_mem(param_1,uVar1,param_3,param_2,0);
    if (iVar2 == 0) {
      iVar2 = run_goldhen_loader_stub(param_1,uVar1,0);
      return iVar2 != 0;
    }
  }
  return true;
}

/* rw_process_memory @ 0x103d53 size=247 */
u64
rw_process_memory(s64 param_1,u64 param_2,s64 param_3,u64 param_4,s64 *param_5,
            int param_6)

{
  u64 uVar1;
  u64 uVar2;
  u64 *reg_gs_offset;
  u64 local_78;
  s64 local_70;
  u64 *local_68;
  u32 local_60;
  u64 local_58;
  s64 local_50;
  u32 local_48;
  u32 local_44;
  u64 local_40;
  
  uVar1 = *reg_gs_offset;
  uVar2 = 1;
  if (param_1 != 0) {
    if (param_3 == 0) {
      uVar2 = 0;
      if (param_5 != (s64 *)0x0) {
        *param_5 = 0;
      }
    }
    else {
      (*memset)(&local_78,0,0x10);
      local_78 = param_4;
      local_70 = param_3;
      (*memset)(&local_68,0,0x30);
      local_60 = 1;
      local_48 = 1;
      local_44 = (u32)(param_6 != 0);
      local_68 = &local_78;
      local_58 = param_2;
      local_50 = param_3;
      local_40 = uVar1;
      uVar2 = (*proc_rwmem)(param_1,&local_68);
      if (param_5 != (s64 *)0x0) {
        *param_5 = param_3 - local_50;
      }
    }
  }
  return uVar2;
}

/* syscall_rw_process_memory @ 0x1023d5 size=35 */
u64 syscall_rw_process_memory(s64 param_1,u64 *param_2)

{
  u64 uVar1;
  
  if (param_1 != 0) {
    uVar1 = rw_process_memory(param_1,*param_2,param_2[2],param_2[1],0,*(u32 *)(param_2 + 3));
    return uVar1;
  }
  return 0;
}

/* unload_plugin_in_process @ 0x1047f5 size=679 */
u64 unload_plugin_in_process(s64 param_1,u64 param_2,char param_3)

{
  s64 lVar1;
  u16 uVar2;
  int iVar3;
  u64 uVar4;
  u64 uVar5;
  s64 lVar6;
  u64 *puVar7;
  char local_244 [4];
  u64 local_240 [2];
  char local_229;
  s64 local_228;
  s64 local_220;
  u64 local_218;
  s64 local_210;
  u64 local_208;
  u8 local_200 [392];
  u32 local_78;
  u32 local_74;
  u32 local_70;
  
  local_228 = 0;
  local_220 = 0;
  local_218 = 0;
  lVar6 = (s64)(int)(g_bytes_00187e68 + 0x3fffU & 0xffffc000);
  local_210 = 0;
  local_229 = '\0';
  local_208 = 0;
  local_244[0] = param_3;
  local_240[0] = param_2;
  iVar3 = proc_vm_map_alloc(param_1,&local_228,lVar6,0);
  if ((iVar3 == 0) &&
     (iVar3 = proc_vm_map_alloc(param_1,&local_220,0x80000,0), lVar1 = local_228, iVar3 == 0)) {
    iVar3 = proc_write_mem(param_1,local_228,(s64)g_bytes_00187e68,g_bytes_00187c50,&local_218);
    if (iVar3 == 0) {
      puVar7 = (u64 *)**(u64 **)(param_1 + 0x340);
      uVar2 = get_firmware();
      get_goldhen_offsets(local_200,uVar2);
      for (; puVar7 != (u64 *)0x0; puVar7 = (u64 *)*puVar7) {
        uVar4 = get_path_basename(puVar7[1]);
        iVar3 = (*memcmp)(uVar4,"libkernel_sys.sprx",0x12);
        if (iVar3 == 0) {
          uVar5 = (u64)local_70;
l_00104935:
          local_210 = uVar5 + puVar7[6];
          break;
        }
        iVar3 = (*memcmp)(uVar4,"libkernel_web.sprx",0x12);
        if (iVar3 == 0) {
          uVar5 = (u64)local_74;
          goto l_00104935;
        }
        iVar3 = (*memcmp)(uVar4,"libkernel.sprx",0xe);
        if (iVar3 == 0) {
          uVar5 = (u64)local_78;
          goto l_00104935;
        }
      }
      if ((((local_210 != 0) &&
           (iVar3 = proc_write_mem(param_1,lVar1 + 0x15,8,local_240,&local_218), iVar3 == 0)) &&
          (uVar4 = proc_write_mem(param_1,lVar1 + 0xc,8,&local_210,&local_218), (int)uVar4 == 0)) &&
         ((local_244[0] != '\x01' ||
          (uVar4 = proc_write_mem(param_1,lVar1 + 0x81,1,local_244,&local_218), (int)uVar4 == 0)))) {
        iVar3 = (*create_thread)(*(u64 *)(param_1 + 0x10),0,g_bytes_00187c54 + lVar1,0,local_220,
                                 0x80000,0,0,0,0,0,uVar4);
        while (iVar3 == 0) {
          if (local_229 != '\0') {
            read_process_memory(param_1,lVar1 + 0x1d,8,&local_208,&local_218);
            break;
          }
          iVar3 = read_process_memory(param_1,lVar1 + 0x14,1,&local_229,&local_218);
        }
      }
    }
  }
  if (local_228 != 0) {
    proc_vm_map_free(param_1,local_228,lVar6);
  }
  if (local_220 != 0) {
    proc_vm_map_free(param_1,local_220,0x80000);
  }
  return local_208 & 0xffffffff;
}

/* unload_prx_from_named_process @ 0x10244f size=70 */
u64 unload_prx_from_named_process(s64 param_1)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = (*strlen)();
  if (((lVar2 != 0) && (*(s64 *)(param_1 + 0x20) != 0)) &&
     (lVar2 = find_process_by_name(param_1), lVar2 != 0)) {
    iVar1 = unload_plugin_in_process(lVar2,*(u64 *)(param_1 + 0x20),0);
    *(s64 *)(param_1 + 0x28) = (s64)iVar1;
    return 0;
  }
  return 1;
}
