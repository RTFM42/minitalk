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

unsigned short *ctob(unsigned char c, unsigned short *res)
{
	unsigned char bit;

	if (res == NULL)
		return (NULL);
	bit = 0b10000000;
	while (bit != 0)
	{
		if (c & bit)
			*res = 1;
		else
			*res = 0;
		res++;
		bit >>= 1;
	}
	return (res - 8);
}

int main(int ac, char **av)
{
	int pid;
	char *message;
	unsigned short res[8];
	int n;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			return (1);
		message = av[2];
		while (*message)
		{
			ctob(*message++, res);
			n = 0;
			while (n < 8)
			{
				if (res[n++] == 0)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(1000);
			}
		}
	}
}
