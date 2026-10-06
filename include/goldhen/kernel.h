/*
 * kernel.h - the kernel symbols GoldHEN imports.
 *
 * Neither half of the payload links against the kernel.  Both resolve the
 * same set of symbols at run time by adding a per-firmware offset (from the
 * ksdk table, see offsets.h) to the kernel base:
 *
 *   loader    resolve_imports() fills the GOT in place
 *   kpayload  map_functions() stores each resolved address in a named pointer
 *
 * The index -> symbol mapping below is the ksdk table order; both the enum
 * and the GOT table are fixed by the original image.
 */
#ifndef GOLDHEN_KERNEL_H
#define GOLDHEN_KERNEL_H

#include <goldhen/types.h>

/* The kernel symbols, in import-table order.  Index 27 is a pair and
 * index 76 is not a GOT slot: its offset is added to the kernel base
 * itself, which is what get_kbase() undoes with its -0x1c0. */
enum kernel_import {
    IMP_XFAST_SYSCALL = 0,
    IMP_PRINTF = 1,
    IMP_MALLOC = 2,
    IMP_REALLOC = 3,
    IMP_FREE = 4,
    IMP_MEMCPY = 5,
    IMP_MEMSET = 6,
    IMP_MEMCMP = 7,
    IMP_KMEM_ALLOC = 8,
    IMP_STRLEN = 9,
    IMP_PAUSE = 10,
    IMP_CREATE_THREAD = 11,
    IMP_SX_XLOCK = 12,
    IMP_SX_XUNLOCK = 13,
    IMP_KERN_REBOOT = 14,
    IMP_VM_MAP_LOCK_READ = 15,
    IMP_VM_MAP_LOOKUP_ENTRY = 16,
    IMP_VM_MAP_UNLOCK_READ = 17,
    IMP_VM_MAP_DELETE = 18,
    IMP_VM_MAP_PROTECT = 19,
    IMP_VM_MAP_FINDSPACE = 20,
    IMP_VM_MAP_INSERT = 21,
    IMP_VM_MAP_LOCK = 22,
    IMP_VM_MAP_UNLOCK = 23,
    IMP_PROC_RWMEM = 24,
    IMP_FPU_KERN_ENTER = 25,
    IMP_FPU_KERN_LEAVE = 26,
    IMP_EVENTHANDLER_REGISTER1 = 27,
    IMP_EVENTHANDLER_REGISTER2 = 27,  /* same table entry */
    IMP_STRSTR = 28,
    IMP_COPYINSTR = 29,
    IMP_COPYOUT = 30,
    IMP_STRNCMP = 31,
    IMP_STRNCPY = 32,
    IMP_SNPRINTF = 33,
    IMP_SPRINTF = 34,
    IMP_SCE_KERNEL_SEND_NOTIFICATION_REQUEST = 35,
    IMP_SHA256_HMAC = 36,
    IMP_SCE_SBL_PFS_SET_KEYS = 37,
    IMP_RSAES_PKCS1V15_DEC2048_CRT = 38,
    IMP_AES_CBC_CFB128_ENCRYPT = 39,
    IMP_AES_CBC_CFB128_DECRYPT = 40,
    IMP_SCE_SBL_KEYMGR_SET_KEY_FOR_PFS = 41,
    IMP_SCE_SBL_KEYMGR_CLEAR_KEY = 42,
    IMP_SCE_SBL_KEYMGR_SM_CALLFUNC = 43,
    IMP_SCE_SBL_DRIVER_SEND_MSG_0 = 44,
    IMP_SCE_SBL_KEYMGR_SET_KEY_STORAGE = 45,
    IMP_SCE_SBL_AUTH_MGR_GET_SELF_INFO = 46,
    IMP_SCE_SBL_AUTH_MGR_VERIFY_HEADER = 47,
    IMP_SCE_SBL_AUTH_MGR_SM_IS_LOADABLE2 = 48,
    IMP_SCE_SBL_AUTH_MGR_SM_START = 49,
    IMP_SCE_SBL_SERVICE_MAILBOX = 50,
    IMP_SCE_SBL_ACMGR_GET_PATH_ID = 51,
    IMP_KPROC_CREATE = 52,
    IMP_KPROC_KTHREAD_ADD = 53,
    IMP_KTHREAD_SUSPEND_CHECK = 54,
    IMP_KTHREAD_EXIT = 55,
    IMP_TTYCONSDEV_WRITE = 56,
    IMP_DEV_CONSOLE = 57,
    IMP_SCE_SBL_AIMGR_IS_TEST_KIT = 58,
    IMP_SCE_SBL_DEV_ACT_SET_STATUS = 59,
    IMP_DISABLE_CONSOLE_OUTPUT = 60,
    IMP_M_TEMP = 61,
    IMP_KERNEL_MAP = 62,
    IMP_PRISON0 = 63,
    IMP_ROOTVNODE = 64,
    IMP_ALLPROC = 65,
    IMP_SYSENTS = 66,
    IMP_FPU_CTX = 67,
    IMP_MINI_SYSCORE_SELF_BINARY = 68,
    IMP_SOUTHBRIDGE = 69,
    IMP_KEXEC_ROP = 70,
    IMP_SBL_DRIVER_MAPPED_PAGES = 71,
    IMP_SBL_PFS_SX = 72,
    IMP_SBL_KEYMGR_KEY_SLOTS = 73,
    IMP_SBL_KEYMGR_KEY_RBTREE = 74,
    IMP_SBL_KEYMGR_BUF_VA = 75,
    IMP_SBL_KEYMGR_BUF_GVA = 76,
    KERNEL_IMPORT_COUNT = 77,
};

/* ---- kpayload: one named pointer per resolved symbol ----------------
 * map_functions() writes these; the rest of the payload calls through
 * them.  They live in .bss and start out NULL.
 */
extern void *_Xfast_syscall;
extern void *printf;
extern void *_malloc;
extern void *realloc;
extern void *free;
extern void *memcpy;
extern void *memset;
extern void *memcmp;
extern void *_kmem_alloc;
extern void *strlen;
extern void *pause;
extern void *create_thread;
extern void *sx_xlock;
extern void *sx_xunlock;
extern void *kern_reboot;
extern void *vm_map_lock_read;
extern void *vm_map_lookup_entry;
extern void *vm_map_unlock_read;
extern void *vm_map_delete;
extern void *vm_map_protect;
extern void *vm_map_findspace;
extern void *vm_map_insert;
extern void *vm_map_lock;
extern void *vm_map_unlock;
extern void *proc_rwmem;
extern void *fpu_kern_enter;
extern void *fpu_kern_leave;
extern void *_eventhandler_register1;
extern void *_eventhandler_register2;
extern void *strstr;
extern void *copyinstr;
extern void *copyout;
extern void *strncmp;
extern void *strncpy;
extern void *snprintf;
extern void *sprintf;
extern void *sceKernelSendNotificationRequest;
extern void *Sha256Hmac;
extern void *sceSblPfsSetKeys;
extern void *RsaesPkcs1v15Dec2048CRT;
extern void *AesCbcCfb128Encrypt;
extern void *AesCbcCfb128Decrypt;
extern void *sceSblKeymgrSetKeyForPfs;
extern void *sceSblKeymgrClearKey;
extern void *sceSblKeymgrSmCallfunc;
extern void *_sceSblDriverSendMsg_0;
extern void *sceSblKeymgrSetKeyStorage;
extern void *sceSblAuthMgrGetSelfInfo;
extern void *sceSblAuthMgrVerifyHeader;
extern void *_sceSblAuthMgrSmIsLoadable2;
extern void *sceSblAuthMgrSmStart;
extern void *_sceSblServiceMailbox;
extern void *_sceSblACMgrGetPathId;
extern void *_kproc_create;
extern void *_kproc_kthread_add;
extern void *_kthread_suspend_check;
extern void *_kthread_exit;
extern void *ttyconsdev_write;
extern void *dev_console;
extern void *sceSblAIMgrIsTestKit;
extern void *sceSblDevActSetStatus;
extern void *_disable_console_output;   /* kernel global, not a function */
extern void *M_TEMP;   /* kernel global, not a function */
extern void *kernel_map;   /* kernel global, not a function */
extern void *prison0;   /* kernel global, not a function */
extern void *rootvnode;   /* kernel global, not a function */
extern void *allproc;   /* kernel global, not a function */
extern void *sysents;   /* kernel global, not a function */
extern void *FPU_CTX;   /* kernel global, not a function */
extern void *MINI_SYSCORE_SELF_BINARY;   /* kernel global, not a function */
extern void *southbridge;   /* kernel global, not a function */
extern void *kexec_rop;   /* kernel global, not a function */
extern void *SBL_DRIVER_MAPPED_PAGES;   /* kernel global, not a function */
extern void *SBL_PFS_SX;   /* kernel global, not a function */
extern void *SBL_KEYMGR_KEY_SLOTS;   /* kernel global, not a function */
extern void *SBL_KEYMGR_KEY_RBTREE;   /* kernel global, not a function */
extern void *SBL_KEYMGR_BUF_VA;   /* kernel global, not a function */
extern void *SBL_KEYMGR_BUF_GVA;   /* kernel global, not a function */

/* ---- loader: the GOT, addressed absolutely ---------------------------
 * The loader is a flat image based at 0x926200000 and reaches its imports
 * through absolute slots in [0x9262473E0, 0x926247648).  resolve_imports()
 * fills them in DESCENDING address order, so import index n lives at
 *
 *   0x926247640 - 8n        for n <= 26
 *   0x926247640 - 8(n + 1)  for n >= 28
 *
 * Index 27 needs two slots: 0x926247560 normally, and 0x926247568 on
 * firmware 5.05, where the kernel exposes a different registration pair.
 * Index 76 has no slot at all.
 */
#define IMP_XFAST_SYSCALL (*(void **)0x926247640u)  /* index 0 */
#define IMP_PRINTF (*(void **)0x926247638u)  /* index 1 */
#define IMP_MALLOC (*(void **)0x926247630u)  /* index 2 */
#define IMP_REALLOC (*(void **)0x926247628u)  /* index 3 */
#define IMP_FREE (*(void **)0x926247620u)  /* index 4 */
#define IMP_MEMCPY (*(void **)0x926247618u)  /* index 5 */
#define IMP_MEMSET (*(void **)0x926247610u)  /* index 6 */
#define IMP_MEMCMP (*(void **)0x926247608u)  /* index 7 */
#define IMP_KMEM_ALLOC (*(void **)0x926247600u)  /* index 8 */
#define IMP_STRLEN (*(void **)0x9262475f8u)  /* index 9 */
#define IMP_PAUSE (*(void **)0x9262475f0u)  /* index 10 */
#define IMP_CREATE_THREAD (*(void **)0x9262475e8u)  /* index 11 */
#define IMP_SX_XLOCK (*(void **)0x9262475e0u)  /* index 12 */
#define IMP_SX_XUNLOCK (*(void **)0x9262475d8u)  /* index 13 */
#define IMP_KERN_REBOOT (*(void **)0x9262475d0u)  /* index 14 */
#define IMP_VM_MAP_LOCK_READ (*(void **)0x9262475c8u)  /* index 15 */
#define IMP_VM_MAP_LOOKUP_ENTRY (*(void **)0x9262475c0u)  /* index 16 */
#define IMP_VM_MAP_UNLOCK_READ (*(void **)0x9262475b8u)  /* index 17 */
#define IMP_VM_MAP_DELETE (*(void **)0x9262475b0u)  /* index 18 */
#define IMP_VM_MAP_PROTECT (*(void **)0x9262475a8u)  /* index 19 */
#define IMP_VM_MAP_FINDSPACE (*(void **)0x9262475a0u)  /* index 20 */
#define IMP_VM_MAP_INSERT (*(void **)0x926247598u)  /* index 21 */
#define IMP_VM_MAP_LOCK (*(void **)0x926247590u)  /* index 22 */
#define IMP_VM_MAP_UNLOCK (*(void **)0x926247588u)  /* index 23 */
#define IMP_PROC_RWMEM (*(void **)0x926247580u)  /* index 24 */
#define IMP_FPU_KERN_ENTER (*(void **)0x926247578u)  /* index 25 */
#define IMP_FPU_KERN_LEAVE (*(void **)0x926247570u)  /* index 26 */
#define IMP_EVENTHANDLER_REGISTER1 (*(void **)0x926247560u)  /* fw!=5.05 */
#define IMP_EVENTHANDLER_REGISTER2 (*(void **)0x926247568u)  /* fw==5.05 */
#define IMP_STRSTR (*(void **)0x926247558u)  /* index 28 */
#define IMP_COPYINSTR (*(void **)0x926247550u)  /* index 29 */
#define IMP_COPYOUT (*(void **)0x926247548u)  /* index 30 */
#define IMP_STRNCMP (*(void **)0x926247540u)  /* index 31 */
#define IMP_STRNCPY (*(void **)0x926247538u)  /* index 32 */
#define IMP_SNPRINTF (*(void **)0x926247530u)  /* index 33 */
#define IMP_SPRINTF (*(void **)0x926247528u)  /* index 34 */
#define IMP_SCE_KERNEL_SEND_NOTIFICATION_REQUEST (*(void **)0x926247520u)  /* index 35 */
#define IMP_SHA256_HMAC (*(void **)0x926247518u)  /* index 36 */
#define IMP_SCE_SBL_PFS_SET_KEYS (*(void **)0x926247510u)  /* index 37 */
#define IMP_RSAES_PKCS1V15_DEC2048_CRT (*(void **)0x926247508u)  /* index 38 */
#define IMP_AES_CBC_CFB128_ENCRYPT (*(void **)0x926247500u)  /* index 39 */
#define IMP_AES_CBC_CFB128_DECRYPT (*(void **)0x9262474f8u)  /* index 40 */
#define IMP_SCE_SBL_KEYMGR_SET_KEY_FOR_PFS (*(void **)0x9262474f0u)  /* index 41 */
#define IMP_SCE_SBL_KEYMGR_CLEAR_KEY (*(void **)0x9262474e8u)  /* index 42 */
#define IMP_SCE_SBL_KEYMGR_SM_CALLFUNC (*(void **)0x9262474e0u)  /* index 43 */
#define IMP_SCE_SBL_DRIVER_SEND_MSG_0 (*(void **)0x9262474d8u)  /* index 44 */
#define IMP_SCE_SBL_KEYMGR_SET_KEY_STORAGE (*(void **)0x9262474d0u)  /* index 45 */
#define IMP_SCE_SBL_AUTH_MGR_GET_SELF_INFO (*(void **)0x9262474c8u)  /* index 46 */
#define IMP_SCE_SBL_AUTH_MGR_VERIFY_HEADER (*(void **)0x9262474c0u)  /* index 47 */
#define IMP_SCE_SBL_AUTH_MGR_SM_IS_LOADABLE2 (*(void **)0x9262474b8u)  /* index 48 */
#define IMP_SCE_SBL_AUTH_MGR_SM_START (*(void **)0x9262474b0u)  /* index 49 */
#define IMP_SCE_SBL_SERVICE_MAILBOX (*(void **)0x9262474a8u)  /* index 50 */
#define IMP_SCE_SBL_ACMGR_GET_PATH_ID (*(void **)0x9262474a0u)  /* index 51 */
#define IMP_KPROC_CREATE (*(void **)0x926247498u)  /* index 52 */
#define IMP_KPROC_KTHREAD_ADD (*(void **)0x926247490u)  /* index 53 */
#define IMP_KTHREAD_SUSPEND_CHECK (*(void **)0x926247488u)  /* index 54 */
#define IMP_KTHREAD_EXIT (*(void **)0x926247480u)  /* index 55 */
#define IMP_TTYCONSDEV_WRITE (*(void **)0x926247478u)  /* index 56 */
#define IMP_DEV_CONSOLE (*(void **)0x926247470u)  /* index 57 */
#define IMP_SCE_SBL_AIMGR_IS_TEST_KIT (*(void **)0x926247468u)  /* index 58 */
#define IMP_SCE_SBL_DEV_ACT_SET_STATUS (*(void **)0x926247460u)  /* index 59 */
#define IMP_DISABLE_CONSOLE_OUTPUT (*(void **)0x926247458u)  /* index 60 */
#define IMP_M_TEMP (*(void **)0x926247450u)  /* index 61 */
#define IMP_KERNEL_MAP (*(void **)0x926247448u)  /* index 62 */
#define IMP_PRISON0 (*(void **)0x926247440u)  /* index 63 */
#define IMP_ROOTVNODE (*(void **)0x926247438u)  /* index 64 */
#define IMP_ALLPROC (*(void **)0x926247430u)  /* index 65 */
#define IMP_SYSENTS (*(void **)0x926247428u)  /* index 66 */
#define IMP_FPU_CTX (*(void **)0x926247420u)  /* index 67 */
#define IMP_MINI_SYSCORE_SELF_BINARY (*(void **)0x926247418u)  /* index 68 */
#define IMP_SOUTHBRIDGE (*(void **)0x926247410u)  /* index 69 */
#define IMP_KEXEC_ROP (*(void **)0x926247408u)  /* index 70 */
#define IMP_SBL_DRIVER_MAPPED_PAGES (*(void **)0x926247400u)  /* index 71 */
#define IMP_SBL_PFS_SX (*(void **)0x9262473f8u)  /* index 72 */
#define IMP_SBL_KEYMGR_KEY_SLOTS (*(void **)0x9262473f0u)  /* index 73 */
#define IMP_SBL_KEYMGR_KEY_RBTREE (*(void **)0x9262473e8u)  /* index 74 */
#define IMP_SBL_KEYMGR_BUF_VA (*(void **)0x9262473e0u)  /* index 75 */
/* index 76: no GOT slot - the loader stores it in the kernel_base global at 0x9262473d8, which it then never uses as a base again */
#define IMP_SBL_KEYMGR_BUF_GVA (*(void **)0x9262473d8u)

#endif /* GOLDHEN_KERNEL_H */
