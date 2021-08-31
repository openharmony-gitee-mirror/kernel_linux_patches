/*
 * This header was generated from the Linux kernel headers by update_headers.py,
 * to provide necessary information from kernel to userspace, such as constants,
 * structures, and macros, and thus, contains no copyrightable information.
 */
#ifndef _UAPI_LINUX_TIME_TYPES_H
#define _UAPI_LINUX_TIME_TYPES_H
#include <linux/types.h>
struct __kernel_timespec {
	__kernel_time64_t       tv_sec;
	long long               tv_nsec;
};
struct __kernel_itimerspec {
	struct __kernel_timespec it_interval;
	struct __kernel_timespec it_value;
};
#ifndef __kernel_old_timeval
struct __kernel_old_timeval {
	__kernel_long_t tv_sec;
	__kernel_long_t tv_usec;
};
#endif
struct __kernel_old_timespec {
	__kernel_old_time_t	tv_sec;
	long			tv_nsec;
};
struct __kernel_old_itimerval {
	struct __kernel_old_timeval it_interval;
	struct __kernel_old_timeval it_value;
};
struct __kernel_sock_timeval {
	__s64 tv_sec;
	__s64 tv_usec;
};
#endif
