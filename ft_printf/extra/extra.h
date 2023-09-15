/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:01:42 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/24 23:10:10 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

int	ex_putchar_fd(const char c, int fd);
int	ex_putnbr_fd(int n, int fd);
int	ex_putptr_fd(void *ptr, int fd);
int	ex_putstr_fd(const char *str, int fd);
int	ex_putunbr_base_fd(size_t n, const char *base, int fd);
int	ex_putunbr_fd(size_t n, int fd);
int	ex_putva_fd(const char type, va_list *ap, int fd);
int	ex_uadd(int i1, int i2);

#endif
