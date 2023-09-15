/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:41:15 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/23 23:46:51 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ex_putunbr_base_fd(size_t n, const char *base, int fd)
{
	int	len;
	int	res;

	len = ft_strlen(base);
	res = 1;
	if (n / len > 0)
		res = ex_uadd(res, ex_putunbr_base_fd(n / len, base, fd));
	write(fd, &base[n % len], 1);
	return (res);
}
