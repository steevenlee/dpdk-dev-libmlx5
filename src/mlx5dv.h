/*
 * Copyright (c) 2017 Mellanox Technologies, Inc.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _MLX5DV_H_
#define _MLX5DV_H_

#include <stddef.h>
#include <stdio.h>

/* Verbs header. */
/* ISO C doesn't support unnamed structs/unions, disabling -pedantic. */
#ifdef PEDANTIC
#pragma GCC diagnostic ignored "-Wpedantic"
#endif
#include <infiniband/verbs.h>
#ifdef PEDANTIC
#pragma GCC diagnostic error "-Wpedantic"
#endif

enum mlx5dv_ctx_attr_type {
	MLX5DV_CTX_ATTR_BUF_ALLOCATORS = 1,
	MLX5DV_CTX_ATTR_UAR_INFO,
};

struct mlx5dv_ctx_attr_allocators {
	void *(*alloc_buf)(size_t size, int alignment);
	void (*free_buf)(void *ptr);
};

struct mlx5dv_ctx_uar_attr {
	void *addr; /* IN: address of db or uar base */
	void *uar_base_addr; /* OUT: uar page aligned address used in mmap */
	off_t uar_offset; /* OUT: offset used in mmap to request UAR mapping */
};

/*
 * Generic context attributes set API
 *
 * Return: 0 in case of success.
 */
int mlx5dv_context_attr_set(struct ibv_context *context,
		enum mlx5dv_ctx_attr_type type, void *attr);

/*
 * Generic context attributes get API
 *
 * Return: 0 in case of success.
 */
int mlx5dv_context_attr_get(struct ibv_context *context,
		enum mlx5dv_ctx_attr_type type, void *attr);

#endif /* _MLX5DV_H_ */
