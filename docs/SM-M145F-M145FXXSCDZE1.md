# Galaxy M14 4G (SM-M145F) - M145FXXSCDZE1 Port

## Device Information
- **Model:** SM-M145F
- **Build ID:** M145FXXSCDZE1
- **Codename:** m14
- **Platform:** Qualcomm Snapdragon
- **Kernel:** 5.15.180-android13-8-31192385-abM145FXXSCDZE1
- **Android:** 13
- **SDK:** 33
- **Build Date:** May 28, 2026

## Firmware Identity
- **Display Build:** TP1A.220624.014.M145FXXSCDZE1
- **Build Fingerprint:** samsung/m14/m14:13/TP1A.220624.014/M145FXXSCDZE1:user/release-keys
- **Kernel Release:** 5.15.180-android13-8-31192385-abM145FXXSCDZE1

## Kernel Details
- **Architecture:** ARM64 (AArch64)
- **Kernel Size:** 46 MB (0x2dd2a00 bytes)
- **Kernel SHA-256:** [Compute with: sha256sum kernel]
- **ELF Base:** 0xffffffc000000000
- **Compiler:** clang 14.0.7 (LLVM 14)
- **CFI:** Enabled
- **BTF:** Compiled in, no embedded data

## Symbol Offsets (19 Primary + 11 CFI)

### Exploit Entry
- `CALL_USERMODEHELPER_EXEC_WORK_OFF`: 0xffffffc00816ec08

### File Operations
- `NOOP_LLSEEK_OFF`: 0xffffffc008556884
- `COPY_SPLICE_READ_OFF`: 0xffffffc0085ca2dc
- `CONFIGFS_READ_ITER_OFF`: 0xffffffc00867f0cc
- `CONFIGFS_BIN_WRITE_ITER_OFF`: 0xffffffc00867fbf0

### ashmem Interface
- `ASHMEM_IOCTL_OFF`: 0xffffffc00918e290
- `ASHMEM_COMPAT_IOCTL_OFF`: 0xffffffc00918e940
- `ASHMEM_MMAP_OFF`: 0xffffffc00918e9a0
- `ASHMEM_OPEN_OFF`: 0xffffffc00918ec90
- `ASHMEM_RELEASE_OFF`: 0xffffffc00918ed30
- `ASHMEM_SHOW_FDINFO_OFF`: 0xffffffc00918ee54
- `ASHMEM_FOPS_OFF`: 0xffffffc00a16b0f8

### Memory Management
- `KMALLOC_CACHES_OFF`: 0xffffffc00a1d5250
- `ANON_PIPE_BUF_OPS_OFF`: 0xffffffc009fe61b0

### Workqueue & Logging
- `SYSTEM_UNBOUND_WQ_OFF`: 0xffffffc00ab807d8
- `LOGGERS_OFF`: 0xffffffc00ab81d50
- `SLIDE_LOGGERS_0_1_OFF`: 0xffffffc00ab81d50

### Process & Scheduling
- `INIT_TASK_OFF`: 0xffffffc00acc5e80
- `ROOT_TASK_GROUP_OFF`: 0xffffffc00addbac0

### Security & Boot
- `SELINUX_ENFORCING_OFF`: 0x0 (optimized away)
- `SYSCTL_BOOTID_OFF`: 0xffffffc00af4c3a1

## P0 Fingerprints
- **Count:** 32 entries
- **Slide Range:** 0x000000 to 0x1f0000 (0x10000 step)
- **File:** src/targets/m14-M145FXXSCDZE1/p0_fingerprint.h

## Physical Load Addresses
- `P0_PHYS_OFFSET`: 0x80000000
- `P0_KERNEL_PHYS_LOAD`: 0x80000000

## Trace Configuration
- `SLIDE_TRACEFS_EVENT_ID`: 106
- `SLIDE_TRACEFS_WORKER_CALLER_OFF`: 0x000dbd9c
- `SLIDE_PSELECT_WORD_SHIFT`: 0

## Build Configuration
- `CONFIG_HAVE_ARCH_KGDB`: Yes
- `CONFIG_STACKTRACE`: Yes
- `CONFIG_SECURITY_SELINUX`: Yes
- `CONFIG_DEBUG_INFO_BTF`: Yes (compiled in)
- `CONFIG_HAVE_FUNCTION_TRACER`: Yes
- `CONFIG_HAVE_DYNAMIC_FTRACE`: Yes

## Exploit Artifacts
- **Payload:** cve-2026-43499-app.so
- **KernelSU KMI:** android13-5.15
- **KernelSU Binary:** ksud-m14-M145FXXSCDZE1-kdp

## Status
- ✅ **Target Headers:** Complete (target.h, p0_fingerprint.h)
- ✅ **Support Feed:** Added to targets-v2.json
- ✅ **GitHub Actions:** Configured for automated builds
- ⏳ **Payload Build:** Pending (GitHub Actions)
- ⏳ **KernelSU Module:** Pending (manual build required)
- ⏳ **Device Testing:** Not yet performed

## Notes
- M14 4G is a Snapdragon-based device (not Exynos)
- No embedded BTF in kernel (standard for 5.15)
- SELinux enforcing symbol optimized away
- CFI protection present - use jump table offsets for protected functions
- Device testing has not been completed on hardware

## References
- Porting Guide: https://github.com/BuSung-dev/Root-My-Galaxy-Payloads/blob/main/docs/PORTING.md
- Target Headers: `src/targets/m14-M145FXXSCDZE1/`
- Support Profile: `support/targets-v2.json`
