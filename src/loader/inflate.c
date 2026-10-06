/*
 * inflate.c - the deflate (puff) decompressor and the adler32 checks.
 */

#include <goldhen/types.h>

/*
 * inflate_codes_case0
 *
 * inflate switch case 0 (jump table @0x46CF8[0])
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int inflate_codes_case0(void)

{
  u8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  s64 lVar7;
  u64 reg_rbx;
  s64 reg_rbp;
  u64 uVar8;
  u8 *puVar9;
  u64 in_stack_00000048;
  u8 in_stack_00000050 [16];
  u32 in_stack_000003ac;
  
code_r0x0009262007de:
  iVar3 = (int)reg_rbp;
  puff_bits(1);
  iVar2 = puff_bits(2);
  if (iVar2 == 1) {
    uVar8 = 2;
  }
  else if (iVar2 == 2) {
    uVar8 = 3;
  }
  else {
    if (iVar2 != 0) {
inflate_codes_exit_error:
      return iVar3 - __builtin_return_address(0);
    }
    uVar8 = 1;
  }
l_9262007af:
  do {
    iVar3 = (int)reg_rbp;
l_9262007bb:
    if ((reg_rbx <= in_stack_00000048) && (in_stack_000003ac == 0)) goto inflate_codes_exit_error;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar8) {
    case 0:
      goto code_r0x0009262007de;
    case 1:
      goto inflate_codes_case1_stored;
    case 2:
      lVar7 = 0;
      do {
  u8 stack0x000001a8 [0x400];
        (&stack0x000001a8)[lVar7] = 8;
        lVar7 = lVar7 + 1;
      } while (lVar7 != 0x90);
      do {
        (&stack0x000001a8)[lVar7] = 9;
        lVar7 = lVar7 + 1;
      } while (lVar7 != 0x100);
      do {
        (&stack0x000001a8)[lVar7] = 7;
        lVar7 = lVar7 + 1;
      } while (lVar7 != 0x118);
      lVar7 = 0;
      do {
  u8 stack0x000002c8 [0x400];
  u8 stack0x00000050 [0x400];
        (&stack0x000002c8)[lVar7] = 5;
        lVar7 = lVar7 + 1;
      } while (lVar7 != 0x20);
      puff_construct(0xf,10,0x120);
      iVar3 = 0x20;
      break;
    case 3:
      puVar9 = &stack0x00000050 + 0xd;
      for (lVar7 = 0xb; lVar7 != 0; lVar7 = lVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      ((*(u8_t *)((u8 *)&in_stack_00000050) >> 5)) = 0;
      iVar2 = puff_bits(5);
      iVar3 = puff_bits(5);
      iVar3 = iVar3 + 1;
      iVar4 = puff_bits(4);
      puVar9 = puff_order;
      for (lVar7 = 0; (int)lVar7 < iVar4 + 4; lVar7 = lVar7 + 1) {
        uVar1 = puff_bits(3);
        (&stack0x00000050)[(u64)(u8)puVar9[lVar7] + 5] = uVar1;
      }
      iVar4 = 0;
      puff_construct(7,7,0x13);
      while (iVar4 < iVar3 + iVar2 + 0x101) {
  u8 stack0x000003a8 [0x400];
        iVar5 = puff_decode(&stack0x000001a8,&stack0x000003a8,7);
        lVar7 = (s64)iVar4;
        if (iVar5 == 0x11) {
          iVar6 = puff_bits(3,&stack0x000003a8);
          iVar6 = iVar6 + 3;
          for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
  u8 stack0x00000068 [0x400];
            (&stack0x00000068)[lVar7] = 0;
            lVar7 = lVar7 + 1;
          }
l_926200ae6:
          iVar4 = iVar4 + iVar6;
        }
        else {
          if (iVar5 == 0x12) {
            iVar6 = puff_bits(7,&stack0x000003a8);
            iVar6 = iVar6 + 0xb;
            for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
              (&stack0x00000068)[lVar7] = 0;
              lVar7 = lVar7 + 1;
            }
            goto l_926200ae6;
          }
          if (iVar5 == 0x10) {
            iVar6 = puff_bits(2,&stack0x000003a8);
            iVar6 = iVar6 + 3;
            puVar9 = &stack0x00000068 + lVar7;
            for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = puVar9[-1];
              puVar9 = puVar9 + 1;
            }
            goto l_926200ae6;
          }
          (&stack0x00000068)[lVar7] = (char)iVar5;
          iVar4 = iVar4 + 1;
        }
      }
      puff_construct(0xf,10,iVar2 + 0x101);
      break;
    default:
      goto l_9262007bb;
    }
    puff_construct(0xf,8,iVar3);
    uVar8 = 4;
  } while( true );
inflate_codes_case1_stored:
  puff_bits(in_stack_000003ac & 7);
  iVar2 = puff_bits(0x10);
  lVar7 = (s64)iVar2;
  puff_bits(0x10);
  in_stack_000003ac = 0;
  if (((s64)(reg_rbx - (in_stack_00000048 - 2)) < lVar7) || (iVar2 == 0))
  goto inflate_codes_exit_error;
  reg_rbp = reg_rbp + lVar7;
  (*imp_memcpy)();
  in_stack_00000048 = (in_stack_00000048 - 2) + lVar7;
  uVar8 = 0;
  goto l_9262007af;
}

/*
 * inflate_codes_case1_stored
 *
 * inflate switch case 1: stored block copy (memcpy import)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 inflate_codes_case1_stored(u32 param_1)

{
  int iVar1;
  u64 uVar2;
  u64 reg_rbx;
  int reg_ebp;
  s64 in_stack_00000048;
  
  puff_bits(param_1 & 7);
  iVar1 = puff_bits(0x10);
  puff_bits(0x10);
  if (((s64)iVar1 <= (s64)(reg_rbx - (in_stack_00000048 + -2))) && (iVar1 != 0)) {
    reg_ebp = reg_ebp + iVar1;
    (*imp_memcpy)();
    if ((u64)(in_stack_00000048 + -2 + (s64)iVar1) < reg_rbx) {
                    /* WARNING: Could not recover jumptable at 0x0009262007db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(void (*)(void))((s64)&puff_code_offsets + (s64)puff_code_offsets))();
      return uVar2;
    }
  }
  return (u64)(u32)(reg_ebp - __builtin_return_address(0));
}

/*
 * inflate_codes_case2_fixed
 *
 * inflate switch case 2: build fixed Huffman tables
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 inflate_codes_case2_fixed(void)

{
  u64 uVar1;
  s64 lVar2;
  u64 reg_rbx;
  int reg_ebp;
  u64 in_stack_00000048;
  int in_stack_000003ac;
  
  lVar2 = 0;
  do {
    (&stack0x000001a8)[lVar2] = 8;
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x90);
  do {
    (&stack0x000001a8)[lVar2] = 9;
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x100);
  do {
    (&stack0x000001a8)[lVar2] = 7;
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x118);
  lVar2 = 0;
  do {
    (&stack0x000002c8)[lVar2] = 5;
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x20);
  puff_construct(0xf,10,0x120);
  puff_construct(0xf,8,0x20);
  if ((reg_rbx <= in_stack_00000048) && (in_stack_000003ac == 0)) {
    return (u64)(u32)(reg_ebp - __builtin_return_address(0));
  }
                    /* WARNING: Could not recover jumptable at 0x0009262007db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(void (*)(void))((s64)&puff_code_offsets + (s64)iRam0000000926246d08))();
  return uVar1;
}

/*
 * inflate_codes_case3_dynamic
 *
 * inflate switch case 3: read dynamic code lengths
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 inflate_codes_case3_dynamic(void)

{
  u8 stack0x0000005d [0x400];
  u8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u64 uVar7;
  s64 lVar8;
  u64 reg_rbx;
  int reg_ebp;
  u8 *puVar9;
  u64 in_stack_00000048;
  u64 uStack0000000000000055;
  int in_stack_000003ac;
  
  puVar9 = &stack0x0000005d;
  for (lVar8 = 0xb; lVar8 != 0; lVar8 = lVar8 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  uStack0000000000000055 = 0;
  iVar2 = puff_bits(5);
  iVar3 = puff_bits(5);
  iVar4 = puff_bits(4);
  puVar9 = puff_order;
  for (lVar8 = 0; (int)lVar8 < iVar4 + 4; lVar8 = lVar8 + 1) {
  u8 stack0x00000055 [0x400];
    uVar1 = puff_bits(3);
    *(u8 *)((s64)&stack0x00000055 + (u64)(u8)puVar9[lVar8]) = uVar1;
  }
  iVar4 = 0;
  puff_construct(7,7,0x13);
  do {
    while( true ) {
      if (iVar3 + 1 + iVar2 + 0x101 <= iVar4) {
        puff_construct(0xf,10,iVar2 + 0x101);
        puff_construct(0xf,8,iVar3 + 1);
        if ((reg_rbx <= in_stack_00000048) && (in_stack_000003ac == 0)) {
          return (u64)(u32)(reg_ebp - __builtin_return_address(0));
        }
                    /* WARNING: Could not recover jumptable at 0x0009262007db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar7 = (*(void (*)(void))((s64)&puff_code_offsets + (s64)iRam0000000926246d08))();
        return uVar7;
      }
      iVar5 = puff_decode(&stack0x000001a8,&stack0x000003a8,7);
      lVar8 = (s64)iVar4;
      if (iVar5 != 0x11) break;
      iVar6 = puff_bits(3,&stack0x000003a8);
      iVar6 = iVar6 + 3;
      for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        (&stack0x00000068)[lVar8] = 0;
        lVar8 = lVar8 + 1;
      }
l_926200ae6:
      iVar4 = iVar4 + iVar6;
    }
    if (iVar5 == 0x12) {
      iVar6 = puff_bits(7,&stack0x000003a8);
      iVar6 = iVar6 + 0xb;
      for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        (&stack0x00000068)[lVar8] = 0;
        lVar8 = lVar8 + 1;
      }
      goto l_926200ae6;
    }
    if (iVar5 == 0x10) {
      iVar6 = puff_bits(2,&stack0x000003a8);
      iVar6 = iVar6 + 3;
      puVar9 = &stack0x00000068 + lVar8;
      for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = puVar9[-1];
        puVar9 = puVar9 + 1;
      }
      goto l_926200ae6;
    }
    (&stack0x00000068)[lVar8] = (char)iVar5;
    iVar4 = iVar4 + 1;
  } while( true );
}

/*
 * inflate_codes_case4_loop
 *
 * inflate switch case 4: main decode loop (length/distance)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 inflate_codes_case4_loop(void)

{
  u8 stack0x000003b0 [0x400];
  u8 agg1 [16];
  u8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u64 uVar7;
  u32 uVar8;
  u64 reg_rbx;
  u8 *reg_rbp;
  u32 uVar9;
  u64 reg_r9;
  u8 *puVar10;
  s64 lVar11;
  u32 uVar12;
  int iVar13;
  u64 uVar14;
  u64 ret_xmm0_qa;
  u8 local_res10 [16];
  int local_res24;
  u64 in_stack_00000048;
  u8 in_stack_00000050 [16];
  s64 in_stack_000001a8;
  u32 in_stack_000003ac;
  
code_r0x000926200b3e:
  iVar6 = puff_decode(&stack0x000003b0,&stack0x000003a8,10);
  if (iVar6 < 0x101) {
    if (iVar6 == 0x100) {
  u8 stack0x00001888 [0x400];
      if (local_res24 == 0) goto l_9262007ac;
      uVar7 = inflate_codes_exit_error(ret_xmm0_qa,&stack0x000003a8);
      return uVar7;
    }
    *reg_rbp = (char)iVar6;
    reg_rbp = reg_rbp + 1;
    reg_r9 = reg_r9 & 0xffffffff;
    goto l_9262007bb;
  }
  lVar11 = (s64)(iVar6 + -0x101);
  iVar6 = puff_bits((puff_len_extra)[lVar11]);
  uVar12 = *(short *)(puff_len_base + lVar11 * 2) + iVar6;
  iVar6 = puff_decode(&stack0x00001888,&stack0x000003a8,8);
  lVar11 = (s64)iVar6;
  iVar6 = puff_bits((puff_dist_extra)[lVar11],&stack0x000003a8);
  iVar6 = iVar6 + *(short *)(puff_dist_base + lVar11 * 2);
  if ((int)((s64)reg_rbp - (u64)__builtin_return_address(0)) < iVar6) {
    return (s64)reg_rbp - (u64)__builtin_return_address(0) & 0xffffffff;
  }
  uVar9 = (int)uVar12 >> 2;
  if (iVar6 == 1) {
    uVar8 = (u32)(u8)reg_rbp[-1];
    in_stack_000001a8 =
         (s64)(int)(uVar8 << 0x18 | (u32)(u8)reg_rbp[-1] << 0x10 | uVar8 | uVar8 << 8);
    for (iVar13 = 0; iVar13 < (int)uVar9; iVar13 = iVar13 + 1) {
      (*imp_memcpy)();
    }
l_926200d50:
    local_res10 = (u64_t)(uVar9);
    agg1 = vpmaxsd_avx((u8  [16])0x0,local_res10);
    uVar12 = uVar12 & 3;
    reg_rbp = reg_rbp + (s64)(*(u4_t *)((u8 *)&agg1 + 0)) * 4;
  }
  else if (3 < iVar6) {
    for (iVar13 = 0; iVar13 < (int)uVar9; iVar13 = iVar13 + 1) {
      in_stack_000001a8 = 0;
      (*imp_memcpy)(iVar13,4);
      (*imp_memcpy)();
    }
    goto l_926200d50;
  }
  for (lVar11 = 0; (int)lVar11 < (int)uVar12; lVar11 = lVar11 + 1) {
    reg_rbp[lVar11] = reg_rbp[lVar11 - iVar6];
  }
  if ((int)uVar12 < 0) {
    uVar12 = 0;
  }
  reg_rbp = reg_rbp + (int)uVar12;
  reg_r9 = reg_r9 & 0xffffffff;
l_9262007bb:
  do {
    if ((reg_rbx <= in_stack_00000048) && (in_stack_000003ac == 0)) goto code_r0x000926200dd4;
  } while (4 < (u32)reg_r9);
  switch((s64)&puff_code_offsets + (s64)(int)(&puff_code_offsets)[reg_r9]) {
  case 0x9262007de:
    local_res24 = puff_bits(1);
    iVar6 = puff_bits(2);
    if (iVar6 == 1) {
      reg_r9 = 2;
      goto l_9262007bb;
    }
    if (iVar6 == 2) {
      reg_r9 = 3;
      goto l_9262007bb;
    }
    if (iVar6 == 0) {
      reg_r9 = 1;
      goto l_9262007bb;
    }
    break;
  case 0x92620082a:
    puff_bits(in_stack_000003ac & 7);
    iVar6 = puff_bits(0x10);
    lVar11 = (s64)iVar6;
    uVar14 = puff_bits(0x10);
    in_stack_000003ac = 0;
    if ((lVar11 <= (s64)(reg_rbx - (in_stack_00000048 - 2))) && (iVar6 != 0)) {
      reg_rbp = reg_rbp + lVar11;
      (*imp_memcpy)(uVar14,lVar11);
      in_stack_00000048 = (in_stack_00000048 - 2) + lVar11;
l_9262007ac:
      reg_r9 = 0;
      goto l_9262007bb;
    }
    break;
  case 0x9262008ae:
    lVar11 = 0;
    do {
      *(u8 *)((s64)&stack0x000001a8 + lVar11) = 8;
      lVar11 = lVar11 + 1;
    } while (lVar11 != 0x90);
    do {
      *(u8 *)((s64)&stack0x000001a8 + lVar11) = 9;
      lVar11 = lVar11 + 1;
    } while (lVar11 != 0x100);
    do {
      *(u8 *)((s64)&stack0x000001a8 + lVar11) = 7;
      lVar11 = lVar11 + 1;
    } while (lVar11 != 0x118);
    lVar11 = 0;
    do {
      (&stack0x000002c8)[lVar11] = 5;
      lVar11 = lVar11 + 1;
    } while (lVar11 != 0x20);
    puff_construct(0xf,10,0x120);
    iVar13 = 0x20;
    goto l_926200b2e;
  case 0x92620094c:
    puVar10 = &stack0x00000050 + 0xd;
    for (lVar11 = 0xb; lVar11 != 0; lVar11 = lVar11 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    ((*(u8_t *)((u8 *)&in_stack_00000050) >> 5)) = 0;
    iVar6 = puff_bits(5);
    iVar13 = puff_bits(5);
    iVar13 = iVar13 + 1;
    iVar3 = puff_bits(4);
    puVar10 = puff_order;
    for (lVar11 = 0; (int)lVar11 < iVar3 + 4; lVar11 = lVar11 + 1) {
      uVar2 = puff_bits(3);
      (&stack0x00000050)[(u64)(u8)puVar10[lVar11] + 5] = uVar2;
    }
    iVar3 = 0;
    puff_construct(7,7,0x13);
l_926200a18:
    do {
      if (iVar13 + iVar6 + 0x101 <= iVar3) goto l_926200aee;
      iVar4 = puff_decode(&stack0x000001a8,&stack0x000003a8,7);
      lVar11 = (s64)iVar3;
      if (iVar4 == 0x11) {
        iVar5 = puff_bits(3,&stack0x000003a8);
        iVar5 = iVar5 + 3;
        for (iVar4 = iVar5; iVar4 != 0; iVar4 = iVar4 + -1) {
          (&stack0x00000068)[lVar11] = 0;
          lVar11 = lVar11 + 1;
        }
      }
      else if (iVar4 == 0x12) {
        iVar5 = puff_bits(7,&stack0x000003a8);
        iVar5 = iVar5 + 0xb;
        for (iVar4 = iVar5; iVar4 != 0; iVar4 = iVar4 + -1) {
          (&stack0x00000068)[lVar11] = 0;
          lVar11 = lVar11 + 1;
        }
      }
      else {
        if (iVar4 != 0x10) {
          (&stack0x00000068)[lVar11] = (char)iVar4;
          iVar3 = iVar3 + 1;
          goto l_926200a18;
        }
        iVar5 = puff_bits(2,&stack0x000003a8);
        iVar5 = iVar5 + 3;
        puVar10 = &stack0x00000068 + lVar11;
        for (iVar4 = iVar5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = puVar10[-1];
          puVar10 = puVar10 + 1;
        }
      }
      iVar3 = iVar3 + iVar5;
    } while( true );
  case 0x926200b3e:
    goto code_r0x000926200b3e;
  }
code_r0x000926200dd4:
  return (u64)((int)reg_rbp - __builtin_return_address(0));
l_926200aee:
  puff_construct(0xf,10,iVar6 + 0x101);
l_926200b2e:
  puff_construct(0xf,8,iVar13);
  reg_r9 = 4;
  goto l_9262007bb;
}

/*
 * inflate_codes_exit_1
 *
 * Shared inflate return path 1 (part of codes switch)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 inflate_codes_exit_1(void)

{
  u64 uVar1;
  u64 reg_rbx;
  int reg_ebp;
  u64 in_stack_00000048;
  int in_stack_000003ac;
  
  if ((reg_rbx <= in_stack_00000048) && (in_stack_000003ac == 0)) {
    return (u64)(u32)(reg_ebp - __builtin_return_address(0));
  }
                    /* WARNING: Could not recover jumptable at 0x0009262007db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(void (*)(void))((s64)&puff_code_offsets + (s64)iRam0000000926246d00))();
  return uVar1;
}

/*
 * inflate_codes_exit_2
 *
 * Shared inflate return path 2 (part of codes switch)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u64 inflate_codes_exit_2(void)

{
  u64 uVar1;
  u64 reg_rbx;
  int reg_ebp;
  u64 in_stack_00000048;
  int in_stack_000003ac;
  
  if ((reg_rbx <= in_stack_00000048) && (in_stack_000003ac == 0)) {
    return (u64)(u32)(reg_ebp - __builtin_return_address(0));
  }
                    /* WARNING: Could not recover jumptable at 0x0009262007db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(void (*)(void))((s64)&puff_code_offsets + (s64)iRam0000000926246d04))();
  return uVar1;
}

/*
 * inflate_codes_exit_error
 *
 * Shared inflate error return (part of codes switch)
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int inflate_codes_exit_error(void)

{
  int reg_ebp;
  
  return reg_ebp - __builtin_return_address(0);
}

/*
 * puff_bits
 *
 * inflate: get `need` bits from input (puff.c bits())
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u32 puff_bits(int param_1,u32 *param_2)

{
  u8 bVar1;
  u32 uVar2;
  u32 uVar3;
  u8 *reg_rsi;
  u64 *reg_rdi;
  u8 *pbVar4;
  
  uVar2 = *param_2;
  pbVar4 = (u8 *)*reg_rdi;
  *param_2 = (int)uVar2 >> ((u8)param_1 & 0x1f);
  uVar3 = param_2[1] - param_1;
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  for (; (param_2[1] = uVar3, pbVar4 < reg_rsi && ((int)uVar3 < 0x10)); uVar3 = uVar3 + 8) {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    *param_2 = *param_2 | (u32)bVar1 << ((u8)uVar3 & 0x1f);
  }
  *reg_rdi = pbVar4;
  return (1 << ((u8)param_1 & 0x1f)) - 1U & uVar2;
}

/*
 * puff_codes
 *
 * inflate: decode literal/length/distance codes (puff.c codes())
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int puff_codes(u8 *out, const u8 *in, u32 in_size) {
  u64 uVar1;
  s64 lVar2;
  u64 reg_rsi;
  int *piVar3;
  int local_1b60 [1740];
  
  piVar3 = local_1b60;
  for (lVar2 = 0x6ca; lVar2 != 0; lVar2 = lVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  puff_bits(0,local_1b60);
  if (((s64)in + reg_rsi <= reg_rsi) && (local_1b60[1] == 0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0009262007db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(void (*)(void))((s64)&puff_code_offsets + (s64)puff_code_offsets))();
  return uVar1;
}

/*
 * puff_construct
 *
 * inflate: build canonical Huffman table (puff.c construct())
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
void puff_construct(int param_1,int param_2,int param_3)

{
  u8 bVar1;
  short sVar2;
  u8 bVar3;
  int iVar4;
  s64 lVar5;
  u64 uVar6;
  u32 uVar7;
  int iVar8;
  u32 uVar9;
  u64 uVar10;
  s64 reg_rsi;
  short *psVar11;
  u32 uVar12;
  s64 reg_rdi;
  int *piVar13;
  u32 uVar14;
  u32 uVar15;
  int iVar16;
  int iVar17;
  int local_2f8 [16];
  int local_2b8 [16];
  short asStack_278 [292];
  
  bVar3 = (u8)param_2;
  piVar13 = local_2f8;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *piVar13 = 0;
    piVar13 = piVar13 + 1;
  }
  piVar13 = local_2b8;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *piVar13 = 0;
    piVar13 = piVar13 + 1;
  }
  for (lVar5 = 0; (int)lVar5 < param_3; lVar5 = lVar5 + 1) {
    local_2f8[*(u8 *)(reg_rsi + lVar5)] = local_2f8[*(u8 *)(reg_rsi + lVar5)] + 1;
  }
  iVar4 = 0;
  local_2b8[1] = local_2f8[0];
  lVar5 = 1;
  do {
    iVar4 = local_2f8[lVar5] + iVar4 * 2;
    local_2b8[lVar5 + 1] = local_2b8[lVar5] + local_2f8[lVar5];
    lVar5 = lVar5 + 1;
  } while ((int)lVar5 < param_1);
  iVar16 = local_2f8[param_1];
  for (lVar5 = 0; (int)lVar5 < param_3; lVar5 = lVar5 + 1) {
    bVar1 = *(u8 *)(reg_rsi + lVar5);
    iVar8 = local_2b8[bVar1];
    asStack_278[iVar8] = (short)lVar5;
    local_2b8[bVar1] = iVar8 + 1;
  }
  if (iVar16 + iVar4 * 2 < 1 << ((u8)param_1 & 0x1f)) {
    lVar5 = 0;
    do {
      *(u32 *)(reg_rdi + lVar5 * 4) = 1;
      lVar5 = lVar5 + 1;
    } while ((int)lVar5 < 1 << (bVar3 & 0x1f));
  }
  else {
    uVar6 = 1;
    do {
      uVar10 = uVar6 & 0xffffffff;
      iVar4 = local_2f8[uVar6];
      uVar6 = uVar6 + 1;
    } while (iVar4 == 0);
    psVar11 = asStack_278 + local_2b8[0];
    iVar16 = 1 << ((u8)uVar10 & 0x1f);
    uVar7 = 0;
    while (uVar9 = (u32)uVar10, (int)uVar9 <= param_2) {
      do {
        sVar2 = *psVar11;
        psVar11 = psVar11 + 1;
        *(u32 *)(reg_rdi + (s64)(int)uVar7 * 4) = (int)sVar2 << 0x10 | uVar9;
        if (iVar16 - 1U == uVar7) {
          for (; (int)uVar10 < param_2; uVar10 = (u64)((int)uVar10 + 1)) {
            (*imp_memcpy)();
          }
          return;
        }
        uVar12 = 0x80000000 >> ((u8)__lzcount(iVar16 - 1U ^ uVar7) & 0x1f);
        uVar7 = uVar12 - 1 & uVar7 | uVar12;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar6 = (s64)(int)(uVar9 + 1);
      do {
        uVar10 = uVar6 & 0xffffffff;
        if ((int)uVar6 <= param_2) {
          (*imp_memcpy)(uVar6,(s64)iVar16 << 2);
          iVar16 = iVar16 * 2;
        }
        iVar4 = local_2f8[uVar6];
        uVar6 = uVar6 + 1;
      } while (iVar4 == 0);
    }
    iVar8 = 1 << (bVar3 & 0x1f);
    uVar9 = iVar8 - 1;
    uVar12 = 0xffffffff;
    iVar16 = 0;
    while( true ) {
      uVar14 = (int)uVar10 - param_2;
      uVar15 = uVar9 & uVar7;
      iVar17 = iVar8;
      if (uVar15 != uVar12) {
        lVar5 = (s64)(int)uVar14;
        iVar16 = iVar4;
        while( true ) {
          iVar17 = 1 << ((u8)lVar5 & 0x1f);
          if (iVar17 <= iVar16) break;
          iVar16 = local_2f8[(s64)param_2 + lVar5 + 1] + iVar16 * 2;
          lVar5 = lVar5 + 1;
        }
        *(u32 *)(reg_rdi + (s64)(int)uVar15 * 4) = iVar8 << 0x10 | (u32)lVar5 & 0xf | 0x10;
        iVar17 = iVar8 + iVar17;
        uVar12 = uVar15;
        iVar16 = iVar8;
      }
      iVar8 = iVar17;
      sVar2 = *psVar11;
      lVar5 = (s64)(((int)uVar7 >> (bVar3 & 0x1f)) + iVar16);
      do {
        *(u32 *)(reg_rdi + lVar5 * 4) = (int)sVar2 << 0x10 | uVar14 & 0xf;
        lVar5 = lVar5 + (1 << ((u8)uVar14 & 0x1f));
      } while ((int)lVar5 < iVar8);
      uVar14 = (1 << ((u8)uVar10 & 0x1f)) - 1;
      if (uVar14 == uVar7) break;
      iVar4 = iVar4 + -1;
      uVar14 = 0x80000000 >> ((u8)__lzcount(uVar14 ^ uVar7) & 0x1f);
      uVar7 = uVar14 - 1 & uVar7 | uVar14;
      uVar6 = (u64)(int)uVar10;
      while( true ) {
        uVar10 = uVar6 & 0xffffffff;
        uVar6 = uVar6 + 1;
        if (iVar4 != 0) break;
        iVar4 = local_2f8[uVar6];
      }
      psVar11 = psVar11 + 1;
    }
  }
  return;
}

/*
 * puff_decode
 *
 * inflate: decode symbol via Huffman table (puff.c decode())
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
u32 puff_decode(s64 param_1,u32 *param_2,u8 param_3)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = *(u32 *)(param_1 + (s64)(int)((1 << (param_3 & 0x1f)) - 1U & *param_2) * 4);
  if ((uVar1 & 0x10) != 0) {
    puff_bits();
    uVar1 = *(u32 *)(param_1 +
                     (u64)(((1 << ((u8)uVar1 & 0xf)) - 1U & *param_2) + (uVar1 >> 0x10)) * 4
                     );
  }
  uVar2 = uVar1 >> 0x10;
  puff_bits(uVar1 & 0xf);
  return uVar2 & 0xfff;
}

/*
 * verify_adler32
 *
 * Verify trailing Adler-32 checksum of decompressed data
 *
 * Decompiled from the loader image; see docs/FORMAT.md and src/index.md.
 */
int verify_adler32(u8 *out, const u8 *zlib_stream, u32 zlib_size) {
  u32 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  s64 lVar6;
  u64 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  u32 uVar12;
  u32 uVar13;
  s64 reg_rsi;
  u64 uVar14;
  u8 *reg_rdi;
  int iVar15;
  u8 *pbVar16;
  u32 uVar17;
  u32 uVar18;
  
  if (5 < zlib_stream) {
    uVar17 = 0;
    iVar2 = puff_codes();
    uVar18 = 1;
    uVar14 = (s64)iVar2 % 0x15b0 & 0xffffffff;
    for (iVar15 = iVar2; iVar15 != 0; iVar15 = iVar15 - uVar13) {
      for (pbVar16 = reg_rdi; uVar13 = (u32)uVar14,
          (u32)((7 - (int)reg_rdi) + (int)pbVar16) < uVar13; pbVar16 = pbVar16 + 8) {
        iVar8 = *pbVar16 + uVar18;
        iVar9 = (u32)pbVar16[1] + iVar8;
        iVar3 = (u32)pbVar16[2] + iVar9;
        iVar10 = (u32)pbVar16[3] + iVar3;
        iVar4 = (u32)pbVar16[4] + iVar10;
        iVar11 = (u32)pbVar16[5] + iVar4;
        iVar5 = (u32)pbVar16[6] + iVar11;
        uVar18 = (u32)pbVar16[7] + iVar5;
        uVar17 = iVar8 + iVar9 + uVar17 + iVar3 + iVar10 + iVar4 + iVar11 + iVar5 + uVar18;
      }
      uVar12 = uVar13 & 0xfffffff8;
      for (lVar6 = 0; uVar12 + (int)lVar6 < uVar13; lVar6 = lVar6 + 1) {
        uVar18 = uVar18 + reg_rdi[lVar6 + (uVar14 & 0xfffffffffffffff8)];
        uVar17 = uVar17 + uVar18;
      }
      uVar7 = (u64)(uVar13 - uVar12);
      if (uVar13 < uVar12) {
        uVar7 = 0;
      }
      reg_rdi = reg_rdi + uVar7 + (uVar14 & 0xfffffffffffffff8);
      uVar18 = uVar18 % 0xfff1;
      uVar14 = 0x15b0;
      uVar17 = uVar17 % 0xfff1;
    }
    uVar1 = *(u32 *)(reg_rsi + -4 + (s64)zlib_stream);
    if (((u32_t)((char)uVar1) << 24 | (u32_t)(((u24_t)((char)((u32)uVar1 >> 8)) << 16 | (u24_t)(((u16_t)((char)((u32)uVar1 >> 0x10)) << 8 | (u16_t)((char)((u32)uVar1 >> 0x18))))))) !=
        uVar17 * 0x10000 + uVar18) {
      iVar2 = -1;
    }
    return iVar2;
  }
  return -1;
}
