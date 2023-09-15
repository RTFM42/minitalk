/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:04:47 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/24 18:45:34 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ex_putstr_fd(const char *str, int fd)
{
	int	len;

	if (str == NULL)
	{
		len = ft_strlen("(null)");
		ft_putstr_fd("(null)", fd);
		return (len);
	}
	len = ft_strlen(str);
	ft_putstr_fd((char *)str, fd);
	return (len);
}
