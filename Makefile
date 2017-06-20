# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 13:21:13 by lyoung            #+#    #+#              #
#    Updated: 2017/06/20 13:38:54 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Werror -Wextra

FILES = main.c \
	  set_map.c \
	  draw_line.c \
	  rotate.c \
	  key_command.c \

SRC = $(addprefix src/, $(FILES))

OBJ = *.o

all: $(NAME)

$(NAME): MLX LIBFT
	gcc $(CFLAGS) -o $(NAME) $(SRC)

MLX:
	make -C minilibx re
	make -C minilibx clean

LIBFT:
	make -C libft re
	make -C libft clean

clean:

fclean: clean
	rm -f fdf
	make -C minilibx fclean
	make -C libft fclean

re: fclean all
