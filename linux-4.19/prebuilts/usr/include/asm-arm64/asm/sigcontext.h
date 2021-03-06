/*
 * This header was generated from the Linux kernel headers by update_headers.py,
 * to provide necessary information from kernel to userspace, such as constants,
 * structures, and macros, and thus, contains no copyrightable information.
 */
#ifndef __ASM_SIGCONTEXT_H
#define __ASM_SIGCONTEXT_H
#ifndef __ASSEMBLY__
#include <linux/types.h>
struct sigcontext {
	__u64 fault_address;

	__u64 regs[31];
	__u64 sp;
	__u64 pc;
	__u64 pstate;

	__u8 __reserved[4096] __attribute__((__aligned__(16)));
};
struct _aarch64_ctx {
	__u32 magic;
	__u32 size;
};
#define FPSIMD_MAGIC	0x46508001
struct fpsimd_context {
	struct _aarch64_ctx head;
	__u32 fpsr;
	__u32 fpcr;
	__uint128_t vregs[32];
};
#define ESR_MAGIC	0x45535201
struct esr_context {
	struct _aarch64_ctx head;
	__u64 esr;
};
#define EXTRA_MAGIC	0x45585401
struct extra_context {
	struct _aarch64_ctx head;
	__u64 datap;
	__u32 size;
	__u32 __reserved[3];
};
#define SVE_MAGIC	0x53564501
struct sve_context {
	struct _aarch64_ctx head;
	__u16 vl;
	__u16 __reserved[3];
};
#endif
#define SVE_VQ_BYTES		16
#define SVE_VQ_MIN		1
#define SVE_VQ_MAX		512
#define SVE_VL_MIN		(SVE_VQ_MIN * SVE_VQ_BYTES)
#define SVE_VL_MAX		(SVE_VQ_MAX * SVE_VQ_BYTES)
#define SVE_NUM_ZREGS		32
#define SVE_NUM_PREGS		16
#define sve_vl_valid(vl) \
	((vl) % SVE_VQ_BYTES == 0 && (vl) >= SVE_VL_MIN && (vl) <= SVE_VL_MAX)
#define sve_vq_from_vl(vl)	((vl) / SVE_VQ_BYTES)
#define sve_vl_from_vq(vq)	((vq) * SVE_VQ_BYTES)
#define SVE_SIG_ZREG_SIZE(vq)	((__u32)(vq) * SVE_VQ_BYTES)
#define SVE_SIG_PREG_SIZE(vq)	((__u32)(vq) * (SVE_VQ_BYTES / 8))
#define SVE_SIG_FFR_SIZE(vq)	SVE_SIG_PREG_SIZE(vq)
#define SVE_SIG_REGS_OFFSET					\
	((sizeof(struct sve_context) + (SVE_VQ_BYTES - 1))	\
		/ SVE_VQ_BYTES * SVE_VQ_BYTES)
#define SVE_SIG_ZREGS_OFFSET	SVE_SIG_REGS_OFFSET
#define SVE_SIG_ZREG_OFFSET(vq, n) \
	(SVE_SIG_ZREGS_OFFSET + SVE_SIG_ZREG_SIZE(vq) * (n))
#define SVE_SIG_ZREGS_SIZE(vq) \
	(SVE_SIG_ZREG_OFFSET(vq, SVE_NUM_ZREGS) - SVE_SIG_ZREGS_OFFSET)
#define SVE_SIG_PREGS_OFFSET(vq) \
	(SVE_SIG_ZREGS_OFFSET + SVE_SIG_ZREGS_SIZE(vq))
#define SVE_SIG_PREG_OFFSET(vq, n) \
	(SVE_SIG_PREGS_OFFSET(vq) + SVE_SIG_PREG_SIZE(vq) * (n))
#define SVE_SIG_PREGS_SIZE(vq) \
	(SVE_SIG_PREG_OFFSET(vq, SVE_NUM_PREGS) - SVE_SIG_PREGS_OFFSET(vq))
#define SVE_SIG_FFR_OFFSET(vq) \
	(SVE_SIG_PREGS_OFFSET(vq) + SVE_SIG_PREGS_SIZE(vq))
#define SVE_SIG_REGS_SIZE(vq) \
	(SVE_SIG_FFR_OFFSET(vq) + SVE_SIG_FFR_SIZE(vq) - SVE_SIG_REGS_OFFSET)
#define SVE_SIG_CONTEXT_SIZE(vq) (SVE_SIG_REGS_OFFSET + SVE_SIG_REGS_SIZE(vq))
#endif
