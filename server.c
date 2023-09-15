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

static void	print2char(int two)
{
	int	value;
	int	base;

	value = 0;
	base = 1;
	while (two > 0)
	{
		value = value + (two % 10) * base;
		two = two / 10;
		base = base * 2;
	}
	write(1, &value, 1);
	return ;
}

static void	sig_action(int sign)
{
	static int	value = 0;
	static int	count = 0;

	if (sign == 30)
		sign = 0;
	else
		sign = 1;
	value = value * 10 + sign;
	if (++count == 8)
	{
		print2char(value);
		count = 0;
		value = 0;
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
