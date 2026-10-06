/*
 * misc.c - the x86 instruction decoder used by the hook installer.
 */

#include <goldhen/types.h>

/* decode_x86_instruction @ 0x10126b size=1562 */
u8 decode_x86_instruction(u8 *param_1,u8 *param_2)

{
  char cVar1;
  u16 uVar2;
  u32 uVar3;
  u8 bVar4;
  u8 *pbVar5;
  u8 bVar6;
  u64 uVar7;
  u8 *pbVar8;
  char *pcVar9;
  u8 bVar10;
  u8 bVar11;
  u32 uVar12;
  u32 uVar13;
  u16 uVar14;
  u8 *pbVar15;
  u8 bVar16;
  u8 *puVar17;
  u8 bVar18;
  u32 uVar19;
  char *pcVar20;
  u8 bVar21;
  u32 uVar22;
  bool bVar23;
  
  (*memset)(param_2,0,0x25);
  uVar12 = 0;
  pbVar15 = param_1;
l_001012ac:
  pbVar5 = pbVar15;
  bVar4 = *pbVar5;
  uVar7 = (u64)bVar4;
  pbVar15 = pbVar5 + 1;
  if (bVar4 == 0xf0) {
    param_2[2] = 0xf0;
    uVar12 = uVar12 | 0x20;
  }
  else if (bVar4 < 0xf1) {
    if (bVar4 != 0x26) {
      bVar6 = bVar4 - 0x2e;
      if (0x39 < bVar6) goto l_0010131f;
      if ((1L << (bVar6 & 0x3f) & 0xc0000000010101U) == 0) {
        if (bVar6 != 0x39) {
          if (bVar6 == 0x38) {
            param_2[4] = 0x66;
            uVar12 = uVar12 | 8;
            goto l_0010131a;
          }
          goto l_0010131f;
        }
        param_2[5] = 0x67;
        uVar12 = uVar12 | 0x10;
        goto l_0010131a;
      }
    }
    param_2[3] = bVar4;
    uVar12 = uVar12 | 0x40;
  }
  else if (bVar4 == 0xf2) {
    param_2[1] = 0xf2;
    uVar12 = uVar12 | 2;
  }
  else {
    if (bVar4 != 0xf3) goto l_0010131f;
    param_2[1] = 0xf3;
    uVar12 = uVar12 | 4;
  }
l_0010131a:
  if (pbVar15 == param_1 + 0x10) goto l_0010131f;
  goto l_001012ac;
l_0010131f:
  uVar13 = uVar12;
  if ((char)uVar12 == '\0') {
    uVar13 = 1;
  }
  if ((bVar4 & 0xf0) == 0x40) {
    *(u32 *)(param_2 + 0x21) = uVar12 << 0x17 | 0x40000000;
    uVar12 = (int)(u32)bVar4 >> 3;
    bVar6 = (u8)uVar12 & 1;
    param_2[7] = bVar6;
    if ((uVar12 & 1) != 0) {
      bVar6 = (*pbVar15 & 0xf8) == 0xb8;
    }
    param_2[9] = (u8)((int)(u32)bVar4 >> 1) & 1;
    pbVar5 = pbVar5 + 2;
    param_2[8] = (u8)((int)(u32)bVar4 >> 2) & 1;
    param_2[10] = bVar4 & 1;
    uVar7 = (u64)*pbVar15;
    if ((*pbVar15 & 0xf0) != 0x40) goto l_001013a3;
l_001013fd:
    *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x3000;
    uVar14 = (u16)(((u32)uVar7 & 0xfd) == 0x24);
    uVar12 = 0;
  }
  else {
    *(u32 *)(param_2 + 0x21) = uVar12 << 0x17;
    bVar6 = false;
    pbVar5 = pbVar15;
l_001013a3:
    bVar4 = (u8)uVar7;
    param_2[0xb] = bVar4;
    if (bVar4 == 0xf) {
      bVar4 = *pbVar5;
      uVar7 = (u64)bVar4;
      puVar17 = g_bytes_001980ca;
      pbVar5 = pbVar5 + 1;
      param_2[0xc] = bVar4;
    }
    else {
      puVar17 = g_bytes_00198080;
      if ((u8)(bVar4 + 0x60) < 4) {
        bVar6 = bVar6 + 1;
        if ((uVar13 & 0x10) == 0) {
          uVar13 = uVar13 & 0xfffffff7;
        }
        else {
          uVar13 = uVar13 | 8;
        }
      }
    }
    bVar4 = puVar17[(int)((u32)(u8)puVar17[uVar7 >> 2] + ((u32)uVar7 & 3))];
    uVar14 = (u16)bVar4;
    if (bVar4 == 0xff) goto l_001013fd;
    uVar12 = 0;
    if ((char)bVar4 < '\0') {
      uVar14 = *(u16 *)(puVar17 + (bVar4 & 0x7f));
      uVar12 = (u32)(u8)(uVar14 >> 8);
    }
  }
  bVar4 = param_2[0xc];
  uVar22 = (u32)uVar7;
  if ((bVar4 != 0) &&
     ((u8)((u8)uVar13 &
            s_____AI____LB________ODS___DWC____001981bc
            [(int)((u32)(u8)s_____AI____LB________ODS___DWC____001981bc[uVar7 >> 2] +
                  (uVar22 & 3))]) != 0)) {
    *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x3000;
  }
  if ((uVar14 & 1) == 0) {
    if ((uVar13 & 0x20) != 0) {
      *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x9000;
    }
  }
  else {
    uVar3 = *(u32 *)(param_2 + 0x21);
    *(u32 *)(param_2 + 0x21) = uVar3 | 1;
    bVar11 = *pbVar5;
    param_2[0xd] = bVar11;
    bVar16 = bVar11 >> 6;
    param_2[0xe] = bVar16;
    bVar21 = (u8)(bVar11 & 7);
    param_2[0x10] = bVar21;
    uVar19 = (int)(u32)bVar11 >> 3 & 7;
    bVar18 = (u8)uVar19;
    param_2[0xf] = bVar18;
    if (((char)uVar12 != '\0') && ((uVar12 << bVar18 & 0x80) != 0)) {
      *(u32 *)(param_2 + 0x21) = uVar3 | 0x3001;
    }
    bVar10 = (u8)uVar7;
    if (bVar4 == 0) {
      if ((u8)(uVar22 + 0x27) < 7) {
        uVar7 = (u64)(uVar22 + 0x27 & 0xff);
        if (bVar16 == 3) {
          cVar1 = *(char *)(uVar7 * 8 + 0x198184 + (u64)uVar19);
          uVar19 = bVar11 & 7;
        }
        else {
          cVar1 = (g_bytes_0019817d)[uVar7];
        }
        if ((char)(cVar1 << (sbyte)uVar19) < '\0') {
          *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x3000;
        }
      }
      if ((uVar13 & 0x20) != 0) {
        if (bVar16 != 3) {
          pcVar20 = g_bytes_00198246;
          uVar22 = uVar22 & 0xfffffffe;
          pcVar9 = g_bytes_0019822e;
l_00101686:
          for (; pcVar9 != pcVar20; pcVar9 = pcVar9 + 2) {
            if (*pcVar9 == (char)uVar22) {
              if ((pcVar9[1] << bVar18 & 0x80U) == 0) goto l_001016ac;
              break;
            }
          }
        }
l_001016a5:
        *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x9000;
l_001016ac:
        if (bVar4 != 0) goto l_00101623;
      }
      if (bVar10 == 0x8c) {
l_0010183e:
        if (5 < bVar18) goto l_0010173e;
      }
      else {
        if (bVar10 == 0x8e) {
          if (bVar18 == 1) goto l_0010173e;
          goto l_0010183e;
        }
l_001016c7:
        if (bVar16 == 3) {
          pbVar15 = (u8 *)0x198291;
          pbVar8 = g_bytes_00198267;
          if (bVar4 == 0) {
            pbVar15 = g_bytes_00198267;
            pbVar8 = g_bytes_00198258;
          }
          for (; pbVar8 != pbVar15; pbVar8 = pbVar8 + 3) {
            if (*pbVar8 == bVar10) {
              if (((u8)uVar13 & pbVar8[1]) != 0) {
                bVar23 = (pbVar8[2] << bVar18 & 0x80) == 0;
                goto l_00101724;
              }
              break;
            }
          }
        }
        else if (bVar4 != 0) {
          if (bVar10 == 0xd6) {
            uVar12 = uVar13 & 6;
          }
          else {
            if (bVar10 < 0xd7) {
              if (bVar10 != 0x50) {
                bVar23 = bVar10 == 0xc5;
                goto l_00101724;
              }
            }
            else if ((bVar10 & 0xdf) != 0xd7) goto l_00101745;
            uVar12 = uVar13 & 9;
          }
          if (uVar12 != 0) goto l_0010173e;
        }
      }
    }
    else {
      if ((uVar13 & 0x20) != 0) {
        if (bVar16 != 3) {
          pcVar20 = g_bytes_00198258;
          pcVar9 = g_bytes_00198246;
          goto l_00101686;
        }
        goto l_001016a5;
      }
l_00101623:
      if (bVar10 == 0x22) {
l_0010163e:
        bVar16 = 3;
        if (bVar18 < 5) {
          bVar23 = bVar18 == 1;
l_00101724:
          if (!bVar23) goto l_00101745;
        }
      }
      else {
        if (bVar10 < 0x23) {
          if (bVar10 == 0x20) goto l_0010163e;
          bVar23 = bVar10 == 0x21;
        }
        else {
          bVar23 = bVar10 == 0x23;
        }
        if (!bVar23) goto l_001016c7;
        bVar16 = 3;
        if (1 < (u8)(bVar18 - 4)) goto l_00101745;
      }
l_0010173e:
      *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x11000;
    }
l_00101745:
    bVar4 = pbVar5[1];
    if (((int)(u32)bVar11 >> 3 & 6U) == 0) {
      if (bVar10 == 0xf6) {
        uVar14 = uVar14 | 2;
      }
      else if (bVar10 == 0xf7) {
        uVar14 = uVar14 | 0x10;
      }
    }
    bVar11 = 1;
    if (bVar16 != 1) {
      if (bVar16 == 2) {
        bVar11 = (-((uVar13 & 0x10) == 0) & 2U) + 2;
      }
      else {
        bVar11 = 0;
        if (bVar16 == 0) {
          if ((uVar13 & 0x10) == 0) {
            bVar11 = (bVar21 == 5) << 2;
          }
          else {
            bVar11 = (bVar21 == 6) * '\x02';
          }
        }
      }
    }
    if ((bVar16 == 3) || (bVar21 != 4)) {
      pbVar5 = pbVar5 + 2;
l_001017ec:
      if (bVar11 == 2) {
        uVar2 = *(u16 *)(pbVar5 + -1);
        *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x80;
        *(u16 *)(param_2 + 0x1d) = uVar2;
      }
      else {
        if (bVar11 == 4) goto l_00101818;
        if (bVar11 == 1) {
          *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x40;
          param_2[0x1d] = pbVar5[-1];
        }
      }
    }
    else {
      param_2[0x11] = bVar4;
      *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 2;
      pbVar5 = pbVar5 + 3;
      param_2[0x12] = bVar4 >> 6;
      param_2[0x13] = bVar4 >> 3 & 7;
      param_2[0x14] = bVar4 & 7;
      if (((bVar4 & 7) != 5) || ((bVar16 & 1) != 0)) goto l_001017ec;
l_00101818:
      *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x100;
      *(u32 *)(param_2 + 0x1d) = *(u32 *)(pbVar5 + -1);
      bVar11 = 4;
    }
    pbVar5 = pbVar5 + ((u64)bVar11 - 1);
  }
  pbVar15 = pbVar5;
  if ((uVar14 & 0x10) == 0) goto l_001015a9;
  uVar12 = *(u32 *)(param_2 + 0x21);
  if ((uVar14 & 0x40) == 0) {
    if (bVar6 == 0) {
      if ((uVar13 & 8) == 0) {
        pbVar15 = pbVar5 + 4;
        *(u32 *)(param_2 + 0x21) = uVar12 | 0x10;
        *(u32 *)(param_2 + 0x15) = *(u32 *)pbVar5;
        goto l_001015a9;
      }
l_001015af:
      uVar2 = *(u16 *)pbVar5;
      pbVar15 = pbVar5 + 2;
      *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 8;
      *(u16 *)(param_2 + 0x15) = uVar2;
    }
    else {
      pbVar15 = pbVar5 + 8;
      *(u32 *)(param_2 + 0x21) = uVar12 | 0x20;
      *(u64 *)(param_2 + 0x15) = *(u64 *)pbVar5;
l_001015a9:
      pbVar5 = pbVar15;
      if ((uVar14 & 4) != 0) goto l_001015af;
    }
    pbVar5 = pbVar15;
    if ((uVar14 & 2) != 0) {
      *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 4;
      pbVar5 = pbVar15 + 1;
      param_2[0x15] = *pbVar15;
    }
    if ((uVar14 & 0x40) == 0) {
      pbVar15 = pbVar5;
      if ((uVar14 & 0x20) != 0) {
        *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x204;
        pbVar15 = pbVar5 + 1;
        param_2[0x15] = *pbVar5;
      }
      goto l_001015fe;
    }
  }
  else if ((uVar13 & 8) != 0) {
    *(u32 *)(param_2 + 0x21) = uVar12 | 0x208;
    *(u16 *)(param_2 + 0x15) = *(u16 *)pbVar5;
    pbVar15 = pbVar5 + 2;
    goto l_001015fe;
  }
  *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x210;
  *(u32 *)(param_2 + 0x15) = *(u32 *)pbVar5;
  pbVar15 = pbVar5 + 4;
l_001015fe:
  bVar4 = (char)pbVar15 - (char)param_1;
  *param_2 = bVar4;
  if (0xf < bVar4) {
    *(u32 *)(param_2 + 0x21) = *(u32 *)(param_2 + 0x21) | 0x5000;
    *param_2 = 0xf;
  }
  return *param_2;
}
