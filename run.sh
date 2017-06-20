gcc -o fdf src/main.c src/draw_line.c src/rotate.c src/key_command.c src/set_map.c libft/libft.a minilibx/libmlx.a -framework OpenGL -framework AppKit -g
./fdf $1
