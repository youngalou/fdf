# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 13:21:13 by lyoung            #+#    #+#              #
#    Updated: 2017/06/20 13:53:34 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAG = -Wall -Werror -Wextra
MLXFLAG = -framework OpenGL -framework AppKit
MLX = minilibx/libmlx.a
LIBFT = libft/libft.a

FILES = main.c \
	  set_map.c \
	  draw_line.c \
	  rotate.c \
	  key_command.c \

SRC = $(addprefix src/, $(FILES))

OBJ = *.o

all: $(NAME)

$(NAME): MLX LIBFT
	@gcc $(CFLAG) -o $(NAME) $(SRC) $(MLX) $(LIBFT) $(MLXFLAG)
	@echo "\033[32m- fdf executable compiled\033[0m"

MLX:
	@make -C minilibx re
	@echo "\033[32m- libmlx.a compiled\033[0m"

LIBFT:
	@make -C libft re
	@make -C libft clean

clean:

fclean: clean
	@rm -f fdf
	@make -C minilibx fclean
	@echo "\033[31m- libmlx.a removed\033[0m"
	@make -C libft fclean

re: fclean all
