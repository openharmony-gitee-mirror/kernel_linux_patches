/*
 * This header was generated from the Linux kernel headers by update_headers.py,
 * to provide necessary information from kernel to userspace, such as constants,
 * structures, and macros, and thus, contains no copyrightable information.
 */
#ifndef _NF_SYNPROXY_H
#define _NF_SYNPROXY_H
#include <linux/types.h>
#define NF_SYNPROXY_OPT_MSS		0x01
#define NF_SYNPROXY_OPT_WSCALE		0x02
#define NF_SYNPROXY_OPT_SACK_PERM	0x04
#define NF_SYNPROXY_OPT_TIMESTAMP	0x08
#define NF_SYNPROXY_OPT_ECN		0x10
#define NF_SYNPROXY_OPT_MASK		(NF_SYNPROXY_OPT_MSS | \
					 NF_SYNPROXY_OPT_WSCALE | \
					 NF_SYNPROXY_OPT_SACK_PERM | \
					 NF_SYNPROXY_OPT_TIMESTAMP)
struct nf_synproxy_info {
	__u8	options;
	__u8	wscale;
	__u16	mss;
};
#endif
