/*
 * libc.c - freestanding string, memory and print helpers.
 */

#include <goldhen/types.h>

/* _memcpy @ 0x106014 size=23 */
void * _memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  for (pvVar1 = (void *)0x0; pvVar1 != (void *)__n; pvVar1 = (void *)((s64)pvVar1 + 1)) {
    *(u8 *)((s64)__dest + (s64)pvVar1) = *(u8 *)((s64)__src + (s64)pvVar1);
  }
  return pvVar1;
}

/* get_path_basename @ 0x105f39 size=30 */
s64 get_path_basename(s64 param_1)

{
  s64 lVar1;
  
  lVar1 = strrchr(param_1,0x2f);
  if (lVar1 != 0) {
    param_1 = lVar1 + 1;
  }
  return param_1;
}

/* print_hex_dump @ 0x105fb2 size=98 */
void print_hex_dump(s64 param_1,u64 param_2)

{
  u64 uVar1;
  
  for (uVar1 = 0; uVar1 != param_2; uVar1 = uVar1 + 1) {
    (*printf)("%02X ",*(u8 *)(param_1 + uVar1));
    if (((uVar1 & 0xf) == 0) && ((int)uVar1 != 0)) {
      (*printf)("\n");
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00106012. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*printf)("\n");
  return;
}

/* strchr @ 0x105f21 size=24 */
char * strchr(char *param_1,int param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_1;
    if (cVar1 == param_2) {
      return param_1;
    }
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (char *)0x0;
}

/* strrchr @ 0x105f04 size=29 */
char * strrchr(char *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if (*param_1 == param_2) {
      pcVar1 = param_1;
    }
  }
  return pcVar1;
}

/* version_string_to_float @ 0x105f57 size=91 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

u64 version_string_to_float(s64 param_1)

{
  double dVar1;
  int iVar2;
  s64 lVar3;
  bool bVar4;
  u8 agg5 [64];
  
  lVar3 = 0;
  iVar2 = 0;
  agg5 = (u64_t)((u64_t)(0));
  do {
    if (*(char *)(param_1 + lVar3) == '.') {
      iVar2 = 7 - (int)lVar3;
    }
    else {
      dVar1 = (double)(*(char *)(param_1 + lVar3) + -0x30) + (double)(*(u4_t *)((u8 *)&agg5 + 0)) * g_bytes_00196fa8;
      agg5 = (u64_t)(((u64_t)((int)((u64)dVar1 >> 0x20)) << 32 | (u64_t)((float)dVar1)));
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 8);
  while (bVar4 = iVar2 != 0, iVar2 = iVar2 + -1, bVar4) {
    agg5 = (u64_t)((((u64_t)(((*(u12_t *)((u8 *)&agg5) >> 4))) << 32) | (u64_t)((*(u4_t *)((u8 *)&agg5 + 0)) / g_bytes_00196fb0)));
  }
  return (*(u8_t *)((u8 *)&agg5 + 0));
}
