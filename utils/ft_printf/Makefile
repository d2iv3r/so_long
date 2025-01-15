# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 20:17:38 by efarhat           #+#    #+#              #
#    Updated: 2023/02/10 19:04:15 by efarhat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_prtchar.c ft_prtstr.c ft_prtnbr.c ft_prthexa.c ft_prtuni.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony : all clean fclean re
