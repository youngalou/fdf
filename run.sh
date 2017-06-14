gcc -o fdf src/main.c src/draw_line.c libft/libft.a minilibx/libmlx.a -framework OpenGL -framework AppKit -g
./fdf $1
