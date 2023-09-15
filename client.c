/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:31:39 by yushsato          #+#    #+#             */
/*   Updated: 2023/09/15 19:55:01 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	uctobit(unsigned char c, char *res)
{
	unsigned char	bit;

	bit = 1 << 7;
	while (bit != 0)
	{
		if (c & bit)
			*res++ = '1';
		else
			*res++ = '0';
		bit >>= 1;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	char	res[9];
	int		n;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		message = av[2];
		while (*message)
		{
			uctobit(*message++, res);
			n = 0;
			while (res[n])
			{
				if (res[n++] == '0')
					kill(pid, SIGUSR1);			
				else
					kill(pid, SIGUSR2);			
				usleep(100);
			}
		}
	}
}
