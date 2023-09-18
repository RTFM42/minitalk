/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:31:32 by yushsato          #+#    #+#             */
/*   Updated: 2023/09/18 16:13:56 by yushsato         ###   ########.fr       */
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
	while (i < 8)
	{
		r |= bits[8 - i] << i;
		i++;
	}
	// while (p++ < sizeof(char) * 8)
	// 	r ^= *(bits++) << (sizeof(char) * 8 - p);
	return (r);
}

static void	sig_action(int sign)
{
	static unsigned short	array[8];
	static int				count = 0;

	if (sign == SIGUSR1)
		sign = 0;
	else if (sign == SIGUSR2)
		sign = 1;
	else
		return ;
	array[count++] = (unsigned short)sign;
	if (count == 8)
	{
		ft_printf("%c", btoc(array));
		count = 0;
	}
	return ;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = (int)(getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = sig_action;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", pid);
	while (1)
		usleep(100);
}
