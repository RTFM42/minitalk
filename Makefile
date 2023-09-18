# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 20:23:39 by yushsato          #+#    #+#              #
#    Updated: 2023/09/18 16:18:29 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
CLIENT	= client

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS_S	= server.c
SRCS_C	= client.c

OBJS_S	= $(SRCS_S:.c=.o)
OBJS_C	= $(SRCS_C:.c=.o)

INCL_PF	= -Ift_printf/ft_printf.h \
		  -Ift_printf/libft/libft.h \
		  -Ift_printf/extra/extra.h

SRCS_PF	= ft_printf/ft_printf.c \
		  ft_printf/libft/ft_memcmp.c \
		  ft_printf/libft/ft_atoi.c \
		  ft_printf/libft/ft_putstr_fd.c \
		  ft_printf/libft/ft_putnbr_fd.c \
		  ft_printf/libft/ft_putchar_fd.c \
		  ft_printf/libft/ft_strlen.c \
		  ft_printf/extra/ex_putchar_fd.c \
		  ft_printf/extra/ex_putnbr_fd.c \
		  ft_printf/extra/ex_putptr_fd.c \
		  ft_printf/extra/ex_putstr_fd.c \
		  ft_printf/extra/ex_putunbr_base_fd.c \
		  ft_printf/extra/ex_putunbr_fd.c \
		  ft_printf/extra/ex_putva_fd.c \
		  ft_printf/extra/ex_uadd.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRCS_S)
	$(CC) $(CFLAGS) -o $@ $< $(SRCS_PF) $(INCL_PF)

$(CLIENT): $(SRCS_C)
	$(CC) $(CFLAGS) -o $@ $< $(SRCS_PF) $(INCL_PF)

clean:
	rm -f

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
