/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:41:26 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/23 23:47:37 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ex_putunbr_fd(size_t n, int fd)
{
	const char	number[] = "0123456789";
	int			len;

	len = 1;
	if (n / 10 > 0)
		len = ex_uadd(len, ex_putunbr_fd(n / 10, fd));
	write(fd, &number[n % 10], 1);
	return (len);
}
