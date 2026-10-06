/*
 * elf.c - the loader's minimal ELF reader: check, measure, map, relocate, load.
 */

#include <goldhen/types.h>

/*
 * elf_apply_relocations
 *
 * Apply SHT_REL-style relocations (r_type==R_X86_64_RELATIVE=8)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int elf_apply_relocations(Elf64_Ehdr *ehdr, u8 *load_base) {
  u16 uVar1;
  u64 uVar2;
  u64 uVar3;
  void (*pcVar4)(void);
  s64 lVar5;
  s64 *plVar6;
  int iVar7;
  s64 reg_rsi;
  s64 reg_rdi;
  s64 lVar8;
  
  uVar1 = *(u16 *)(reg_rdi + 0x3c);
  iVar7 = 0;
  if (uVar1 == 0) {
    return 0;
  }
  if ((*(s64 *)(reg_rdi + 0x28) != 0) &&
     (lVar5 = *(s64 *)(reg_rdi + 0x28) + reg_rdi, lVar5 != 0)) {
    while( true ) {
      lVar5 = (int)((u32)*(u16 *)(reg_rdi + 0x3a) * iVar7) + lVar5;
      if (*(int *)(lVar5 + 4) == 9) {
        uVar2 = *(u64 *)(lVar5 + 0x20);
        uVar3 = *(u64 *)(lVar5 + 0x38);
        for (lVar8 = 0; (uVar2 / uVar3) * 0x18 - lVar8 != 0; lVar8 = lVar8 + 0x18) {
          plVar6 = (s64 *)(*(s64 *)(lVar5 + 0x18) + reg_rdi + lVar8);
          if ((int)plVar6[1] == 8) {
            *(s64 *)(reg_rsi + *plVar6) = plVar6[2] + reg_rsi;
          }
        }
      }
      iVar7 = iVar7 + 1;
      if ((int)(u32)uVar1 <= iVar7) break;
      if ((*(s64 *)(reg_rdi + 0x28) == 0) ||
         (lVar5 = *(s64 *)(reg_rdi + 0x28) + reg_rdi, lVar5 == 0)) {
                    /* WARNING: Does not return */
        *(volatile u64 *)0x10;
        __builtin_trap();
        (*pcVar4)();
      }
    }
    return 0;
  }
                    /* WARNING: Does not return */
  *(volatile u64 *)0x10;
  __builtin_trap();
  (*pcVar4)();
}

/*
 * elf_check_and_measure
 *
 * memcmp(elf, "\x7fELF",4) + compute image size from phdrs/shdrs
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int elf_check_and_measure(Elf64_Ehdr *ehdr, u64 *out_size) {
  void (*pcVar1)(void);
  int iVar2;
  s64 lVar3;
  u64 uVar4;
  s64 lVar5;
  u64 *reg_rsi;
  s64 reg_rdi;
  u64 uVar6;
  u64 uVar7;
  
  iVar2 = (*imp_memcmp)(ehdr,4);
  if (iVar2 == 0) {
    uVar7 = 0;
    if ((*(s64 *)(reg_rdi + 0x20) == 0) ||
       (lVar3 = *(s64 *)(reg_rdi + 0x20) + reg_rdi, lVar3 == 0)) {
      uVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(u32)*(u16 *)(reg_rdi + 0x3c); iVar2 = iVar2 + 1) {
        if ((*(s64 *)(reg_rdi + 0x28) == 0) ||
           (lVar3 = *(s64 *)(reg_rdi + 0x28) + reg_rdi, lVar3 == 0)) {
                    /* WARNING: Does not return */
          *(volatile u64 *)0x10;
          __builtin_trap();
          (*pcVar1)();
        }
        lVar5 = (s64)(int)((u32)*(u16 *)(reg_rdi + 0x3a) * iVar2);
        uVar6 = *(s64 *)(lVar3 + 0x10 + lVar5) + *(s64 *)(lVar3 + 0x20 + lVar5);
        if (uVar4 < uVar6) {
          uVar4 = uVar6;
        }
      }
    }
    else {
      uVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(u32)*(u16 *)(reg_rdi + 0x38); iVar2 = iVar2 + 1) {
        lVar5 = (s64)(int)((u32)*(u16 *)(reg_rdi + 0x36) * iVar2);
        uVar6 = *(s64 *)(lVar3 + 0x18 + lVar5) + *(s64 *)(lVar3 + 0x28 + lVar5);
        if (uVar4 < uVar6) {
          uVar4 = uVar6;
        }
      }
    }
    if (reg_rsi != (u64 *)0x0) {
      *reg_rsi = uVar4;
    }
  }
  else {
    uVar7 = 1;
  }
  return uVar7;
}

/*
 * elf_load
 *
 * Validate + load + relocate embedded ELF; returns entry point
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int elf_load(Elf64_Ehdr *elf, u64 elf_size, kaddr_t load_base, u64 alloc_size,
             kaddr_t *entry_out) {
  int iVar1;
  u64 uVar2;
  s64 reg_rsi;
  s64 reg_rdi;
  
  if (reg_rdi != 0) {
    if ((((elf_size == 0) || (reg_rsi == 0)) || (elf == 0)) ||
       ((iVar1 = (*imp_memcmp)(elf,4), iVar1 != 0 ||
        (((u16)*(u32 *)(reg_rdi + 0x10) & 0xfffd) != 1)))) {
      uVar2 = 1;
    }
    else {
      iVar1 = elf_check_and_measure();
      uVar2 = 2;
      if (iVar1 == 0) {
        iVar1 = elf_map_segments();
        uVar2 = 3;
        if (iVar1 == 0) {
          uVar2 = elf_apply_relocations();
          if ((int)uVar2 == 0) {
            if (load_base != (s64 *)0x0) {
              *load_base = elf_size + *(s64 *)(reg_rdi + 0x18);
            }
          }
          else {
            uVar2 = 4;
          }
        }
      }
    }
    return uVar2;
  }
  return 1;
}

/*
 * elf_map_segments
 *
 * Map PT_LOAD segments: memcpy/memset through runtime import table
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int elf_map_segments(Elf64_Ehdr *ehdr, u8 *load_base) {
  void (*pcVar1)(void);
  s64 lVar2;
  s64 reg_rdi;
  int iVar3;
  
  if ((*(s64 *)(reg_rdi + 0x20) == 0) ||
     (iVar3 = 0, *(s64 *)(reg_rdi + 0x20) + reg_rdi == 0)) {
    for (iVar3 = 0; iVar3 < (int)(u32)*(u16 *)(reg_rdi + 0x3c); iVar3 = iVar3 + 1) {
      if ((*(s64 *)(reg_rdi + 0x28) == 0) ||
         (lVar2 = *(s64 *)(reg_rdi + 0x28) + reg_rdi, lVar2 == 0)) goto l_9262001c5;
      lVar2 = (int)((u32)*(u16 *)(reg_rdi + 0x3a) * iVar3) + lVar2;
      if (((*(u8 *)(lVar2 + 8) & 2) != 0) && (*(s64 *)(lVar2 + 0x20) != 0)) {
        (*imp_memcpy)();
      }
    }
  }
  else {
    for (; iVar3 < (int)(u32)*(u16 *)(reg_rdi + 0x38); iVar3 = iVar3 + 1) {
      if ((*(s64 *)(reg_rdi + 0x20) == 0) ||
         (lVar2 = *(s64 *)(reg_rdi + 0x20) + reg_rdi, lVar2 == 0)) {
l_9262001c5:
                    /* WARNING: Does not return */
        *(volatile u64 *)0x10;
        __builtin_trap();
        (*pcVar1)();
      }
      lVar2 = (int)((u32)*(u16 *)(reg_rdi + 0x36) * iVar3) + lVar2;
      if (*(s64 *)(lVar2 + 0x20) != 0) {
        (*imp_memcpy)();
      }
      if (*(s64 *)(lVar2 + 0x28) != *(s64 *)(lVar2 + 0x20)) {
        (*imp_memset)();
      }
    }
  }
  return 0;
}
