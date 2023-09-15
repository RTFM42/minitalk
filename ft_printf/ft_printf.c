/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:46:20 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/24 23:11:33 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

static int	is_include(char c, char *s)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

int	ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		flag;
	int		len;

	va_start(ap, fmt);
	len = 0;
	while (*fmt != '\0')
	{
		if (fmt[0] == '%' && fmt[1] != '\0')
		{
			flag = is_include(fmt[1], "cspdiuxX%");
			if (flag)
			{
				len = ex_uadd(len, ex_putva_fd((const char)fmt[1], &ap, 1));
				fmt += 2;
			}
			else
				len = ex_uadd(len, ex_putchar_fd(*fmt++, 1));
		}
		else
			len = ex_uadd(len, ex_putchar_fd(*fmt++, 1));
	}
	va_end(ap);
	return (len);
}
