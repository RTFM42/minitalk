/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:31:32 by yushsato          #+#    #+#             */
/*   Updated: 2023/09/15 19:54:07 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

unsigned char	btoc(unsigned short *bits)
{
	unsigned short	p;
	unsigned char	r;

	p = 0;
	r = 0;
	while (p++ <= sizeof(char) * 8UL)
		r ^= *(bits++) << (sizeof(char) * 8UL - p);
	return (r);
}

static void	sig_action(int sign)
{
	static unsigned short	array[8];
	static int				count = 0;

	if (sign == 30)
		sign = 0;
	else
		sign = 1;
	array[count] = (unsigned short)sign;
	if (++count == 8)
	{
		ft_printf("%c", btoc(array));
		count = 0;
	}
	return ;
}

int	main(void)
{
	int	pid;

	pid = (int)(getpid());
	ft_printf("%d\n", pid);
	signal(SIGUSR1, sig_action);
	signal(SIGUSR2, sig_action);
	while (1)
		usleep(100);
}
