# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 16:03:37 by efarhat           #+#    #+#              #
#    Updated: 2023/02/10 19:04:51 by efarhat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB_LIBFT = libft/libft.a
LIB_PRINTF = ft_printf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = utils/get_next_line.c utils/get_next_line_utils.c error.c utils/map_utils.c so_long.c check_map.c valid_path.c parse_map.c\
playing.c moving.c animation.c

OBJ = $(SRC:.c=.o)

all : $(LIB_LIBFT) $(LIB_PRINTF) $(NAME)

$(LIB_LIBFT) :
	$(MAKE) -C utils/libft/

$(LIB_PRINTF) :
	$(MAKE) -C utils/ft_printf/

$(NAME) : $(OBJ) so_long.h
	$(CC) $(CFLAGS) $(LIB_PRINTF) $(LIB_LIBFT) $(OBJ) -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(MAKE) clean -C ft_printf/
	$(MAKE) clean -C libft/
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ft_printf/
	$(MAKE) fclean -C libft/
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re
