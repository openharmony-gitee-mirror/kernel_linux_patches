/*
 * This header was generated from the Linux kernel headers by update_headers.py,
 * to provide necessary information from kernel to userspace, such as constants,
 * structures, and macros, and thus, contains no copyrightable information.
 */
#ifndef _UAPI_LINUX_SCHED_TYPES_H
#define _UAPI_LINUX_SCHED_TYPES_H
#include <linux/types.h>
struct sched_param {
	int sched_priority;
};
#define SCHED_ATTR_SIZE_VER0	48
#define SCHED_ATTR_SIZE_VER1	56
struct sched_attr {
	__u32 size;
	__u32 sched_policy;
	__u64 sched_flags;

	__s32 sched_nice;

	__u32 sched_priority;

	__u64 sched_runtime;
	__u64 sched_deadline;
	__u64 sched_period;

	__u32 sched_util_min;
	__u32 sched_util_max;
};
#endif
