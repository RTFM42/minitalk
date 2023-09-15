/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:41:00 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/24 18:21:55 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ex_putptr_fd(void *ptr, int fd)
{
	int	len;

	write(fd, "0x", 2);
	len = ex_putunbr_base_fd((size_t)ptr, "0123456789abcdef", fd);
	return (len + 2);
}
