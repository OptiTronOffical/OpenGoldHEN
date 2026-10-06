/*
 * syscalls.c - syscall wrappers and the saved sysent slots.
 */

#include <goldhen/types.h>

/* init_syscall_wrappers @ 0x105cf3 size=180 */
void init_syscall_wrappers(void)

{
  g_orig_sys_read = *(u64 *)(sysents + 0x98);
  g_orig_sys_write = *(u64 *)(sysents + 200);
  g_orig_sys_open = *(u64 *)(sysents + 0xf8);
  g_orig_sys_close = *(u64 *)(sysents + 0x128);
  g_orig_sys_socket = *(u64 *)(sysents + 0x1238);
  g_orig_sys_listen = *(u64 *)(sysents + 0x13e8);
  g_orig_sys_bind = *(u64 *)(sysents + 5000);
  g_orig_sys_accept = *(u64 *)(sysents + 0x5a8);
  g_orig_sys_setsockopt = *(u64 *)(sysents + 0x13b8);
  g_orig_sys_getsockopt = *(u64 *)(sysents + 0x1628);
  g_orig_sys_lseek = *(u64 *)(sysents + 0x59a8);
  g_orig_sys_getdirentries = *(u64 *)(sysents + 0x24c8);
  return;
}

/* sys_accept @ 0x105b08 size=89 */
int sys_accept(int param_1,u64 param_2,u64 param_3,s64 param_4)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_20;
  u64 local_18;
  u64 local_10;
  
  local_20 = (s64)param_1;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  local_18 = param_2;
  local_10 = param_3;
  iVar1 = (*g_orig_sys_accept)(param_4,&local_20);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_4 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_bind @ 0x105aad size=91 */
int sys_bind(int param_1,u64 param_2,u32 param_3,s64 param_4)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_20;
  u64 local_18;
  u64 local_10;
  
  local_20 = (s64)param_1;
  local_10 = (u64)param_3;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  local_18 = param_2;
  iVar1 = (*g_orig_sys_bind)(param_4,&local_20);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_4 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_close @ 0x1059ab size=79 */
int sys_close(int param_1,s64 param_2)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_10;
  
  local_10 = (s64)param_1;
  if (param_2 == 0) {
    param_2 = *reg_gs_offset;
  }
  *(u64 *)(param_2 + 0x398) = 0;
  iVar1 = (*g_orig_sys_close)(param_2,&local_10);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_2 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_getdirentries @ 0x105c95 size=94 */
s64 sys_getdirentries(int param_1,u64 param_2,u64 param_3,u64 param_4,s64 param_5)

{
  int iVar1;
  s64 lVar2;
  s64 *reg_gs_offset;
  s64 local_28;
  u64 local_20;
  u64 local_18;
  u64 local_10;
  
  local_28 = (s64)param_1;
  if (param_5 == 0) {
    param_5 = *reg_gs_offset;
  }
  *(u64 *)(param_5 + 0x398) = 0;
  local_20 = param_2;
  local_18 = param_3;
  local_10 = param_4;
  iVar1 = (*g_orig_sys_getdirentries)(param_5,&local_28);
  if (iVar1 == 0) {
    lVar2 = *(s64 *)(param_5 + 0x398);
  }
  else {
    lVar2 = (s64)-iVar1;
  }
  return lVar2;
}

/* sys_getsockopt @ 0x105bcd size=105 */
int sys_getsockopt(int param_1,int param_2,int param_3,u64 param_4,u64 param_5,
                s64 param_6)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_30;
  s64 local_28;
  s64 local_20;
  u64 local_18;
  u64 local_10;
  
  local_30 = (s64)param_1;
  local_28 = (s64)param_2;
  local_20 = (s64)param_3;
  if (param_6 == 0) {
    param_6 = *reg_gs_offset;
  }
  *(u64 *)(param_6 + 0x398) = 0;
  local_18 = param_4;
  local_10 = param_5;
  iVar1 = (*g_orig_sys_getsockopt)(param_6,&local_30);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_6 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_listen @ 0x105a59 size=84 */
int sys_listen(int param_1,int param_2,s64 param_3)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_18;
  s64 local_10;
  
  local_18 = (s64)param_1;
  local_10 = (s64)param_2;
  if (param_3 == 0) {
    param_3 = *reg_gs_offset;
  }
  *(u64 *)(param_3 + 0x398) = 0;
  iVar1 = (*g_orig_sys_listen)(param_3,&local_18);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_lseek @ 0x105c36 size=95 */
s64 sys_lseek(int param_1,u64 param_2,int param_3,s64 param_4)

{
  int iVar1;
  s64 lVar2;
  s64 *reg_gs_offset;
  s64 local_20;
  u64 local_18;
  s64 local_10;
  
  local_20 = (s64)param_1;
  local_10 = (s64)param_3;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  local_18 = param_2;
  iVar1 = (*g_orig_sys_lseek)(param_4,&local_20);
  if (iVar1 == 0) {
    lVar2 = *(s64 *)(param_4 + 0x398);
  }
  else {
    lVar2 = (s64)-iVar1;
  }
  return lVar2;
}

/* sys_open @ 0x10594f size=92 */
int sys_open(u64 param_1,int param_2,int param_3,s64 param_4)

{
  int iVar1;
  s64 *reg_gs_offset;
  u64 local_20;
  s64 local_18;
  s64 local_10;
  
  local_18 = (s64)param_2;
  local_10 = (s64)param_3;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  local_20 = param_1;
  iVar1 = (*g_orig_sys_open)(param_4,&local_20);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_4 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_read @ 0x105897 size=92 */
int sys_read(int param_1,u64 param_2,int param_3,s64 param_4)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_20;
  u64 local_18;
  s64 local_10;
  
  local_20 = (s64)param_1;
  local_10 = (s64)param_3;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  local_18 = param_2;
  iVar1 = (*g_orig_sys_read)(param_4,&local_20);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_4 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_setsockopt @ 0x105b61 size=108 */
int sys_setsockopt(int param_1,int param_2,int param_3,u64 param_4,u32 param_5,s64 param_6)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_30;
  s64 local_28;
  s64 local_20;
  u64 local_18;
  u64 local_10;
  
  local_30 = (s64)param_1;
  local_28 = (s64)param_2;
  local_20 = (s64)param_3;
  local_10 = (u64)param_5;
  if (param_6 == 0) {
    param_6 = *reg_gs_offset;
  }
  *(u64 *)(param_6 + 0x398) = 0;
  local_18 = param_4;
  iVar1 = (*g_orig_sys_setsockopt)(param_6,&local_30);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_6 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_socket @ 0x1059fa size=95 */
int sys_socket(int param_1,int param_2,int param_3,s64 param_4)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_20;
  s64 local_18;
  s64 local_10;
  
  local_20 = (s64)param_1;
  local_18 = (s64)param_2;
  local_10 = (s64)param_3;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  iVar1 = (*g_orig_sys_socket)(param_4,&local_20);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_4 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* sys_write @ 0x1058f3 size=92 */
int sys_write(int param_1,u64 param_2,int param_3,s64 param_4)

{
  int iVar1;
  s64 *reg_gs_offset;
  s64 local_20;
  u64 local_18;
  s64 local_10;
  
  local_20 = (s64)param_1;
  local_10 = (s64)param_3;
  if (param_4 == 0) {
    param_4 = *reg_gs_offset;
  }
  *(u64 *)(param_4 + 0x398) = 0;
  local_18 = param_2;
  iVar1 = (*g_orig_sys_write)(param_4,&local_20);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_4 + 0x398);
  }
  else {
    iVar1 = -iVar1;
  }
  return iVar1;
}
