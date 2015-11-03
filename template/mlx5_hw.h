/**
 * Copyright (C) Mellanox Technologies Ltd. 2001-2014.  ALL RIGHTS RESERVED.
 * This software product is a proprietary product of Mellanox Technologies Ltd.
 * (the "Company") and all right, title, and interest and to the software product,
 * including all associated intellectual property rights, are and shall
 * remain exclusively with the Company.
 *
 * This software product is governed by the End User License Agreement
 * provided with the software product.
 */

#ifndef MLX_HW_H_
#define MLX_HW_H_

#include <linux/types.h>
#include <stdint.h>
#include <pthread.h>
#include <infiniband/driver.h>
#include <infiniband/verbs.h>
#include <infiniband/list.h>

#define MLX5_GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#if MLX5_GCC_VERSION >= 403
#	define __MLX5_ALGN_F__ __attribute__((noinline, aligned(64)))
#	define __MLX5_ALGN_D__ __attribute__((aligned(64)))
#else
#	define __MLX5_ALGN_F__
#	define __MLX5_ALGN_D__
#endif


