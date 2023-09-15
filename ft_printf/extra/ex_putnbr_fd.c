/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:40:47 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/23 23:45:25 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ex_putnbr_fd(int n, int fd)
{
	unsigned int	unb;
	const char		number[] = "0123456789";
	int				len;

	unb = (unsigned int)n;
	len = 1;
	if (n < 0)
	{
		len = ex_uadd(len, 1);
		write(fd, "-", 1);
		unb = unb * -1;
	}
	if (unb / 10 > 0)
		len = ex_uadd(len, ex_putnbr_fd(unb / 10, fd));
	write(fd, &number[unb % 10], 1);
	return (len);
}
