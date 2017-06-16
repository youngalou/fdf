/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:30:05 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/16 12:27:18 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = 0;
	env->win = 0;
	env->length = 0;
	env->width = 0;
	env->map = 0;
	env->win_x = 1200;
	env->win_y = 1200;
	env->scale = 1;
	env->x_scale = 20;
	env->y_scale = 20;
	env->z_scale = 1;
	env->x0 = 600;
	env->y0 = 600;
	env->zoom = .25;
	env->ax = .7854;
	env->ay = .6982;
	env->az = .0524;
	env->x_place = 0;
	env->y_place = 0;
	env->hprev_x = 0;
	env->hprev_y = 0;
	env->vprev_x = 0;
	env->vprev_y = 0;
	env->color = 0;
	env->drawn = 0;
	return (env);
}

void	populate_row(t_env *env, char *line, int y)
{
	char	*tmp;
	int		x;

	tmp = line;
	env->map[y] = (int*)malloc(sizeof(int*) * env->width);
	x = 0;
	while (x < env->width)
	{
		env->map[y][x] = ft_atoi(line);
		while (*line >= '0' && *line <= '9')
			line++;
		if (*line == ',')
			env->color = ft_atoi_base(++line, 16);
		while ((*line >= '0' && *line <= '9') || *line == 'x')
			line++;
		while (*line == ' ' || *line == '\t')
			line++;
		x++;
	}
	ft_strdel(&tmp);
}

void	set_map(t_env *env, int fd)
{
	char	**line;
	int		y;

	line = (char**)malloc(sizeof(char**) * UINT_MAX);
	y = 0;
	while (get_next_line(fd, &line[y]))
		y++;
	env->length = y;
	env->width = count_words(*line, ' ');
	env->map = (int**)malloc(sizeof(int**) * env->length);
	y = 0;
	while (y < env->length)
	{
		populate_row(env, line[y], y);
		y++;
	}
}

void	print_array(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < env->length)
	{
		x = 0;
		while (x < env->width)
		{
			ft_printf("%d ", env->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		key_command(int key, t_env *env)
{
	//ft_printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
	{
		(key == 126) ? env->ay += .25 : 0;
		(key == 125) ? env->ay -= .25 : 0;
		(key == 123) ? env->ax += .25 : 0;
		(key == 124) ? env->ax -= .25 : 0;
		wireframe(env);
	}
	if (key == 13 || (key >= 0 && key <= 2))
	{
		(key == 13) ? env->y0 -= env->y_scale : 0;
		(key == 1) ? env->y0 += env->y_scale : 0;
		(key == 0) ? env->x0 -= env->x_scale : 0;
		(key == 2) ? env->x0 += env->x_scale : 0;
		wireframe(env);
	}
	if (key == 34 || (key >= 37 && key <= 40))
	{
		(key == 34) ? env->y0 -= env->y_scale * 10 : 0;
		(key == 40) ? env->y0 += env->y_scale * 10 : 0;
		(key == 38) ? env->x0 -= env->x_scale * 10 : 0;
		(key == 37) ? env->x0 += env->x_scale * 10 : 0;;
		wireframe(env);
	}
	if (key == 24 || key == 27)
	{
		if (key == 24)
		{
			env->zoom *= 2;
			env->x_scale = env->x_scale * 2;
			env->y_scale = env->y_scale * 2;
			env->z_scale = env->z_scale * 2;
		}
		if (key == 27)
		{
			env->zoom /= 2;
			env->x_scale = env->x_scale / 2;
			env->y_scale = env->y_scale / 2;
			env->z_scale = env->z_scale / 2;
		}
		wireframe(env);
	}
	if (key == 48)
	{
		set_scale(env);
		wireframe(env);
	}
	return (0);
}

void	set_scale(t_env *env)
{
	env->scale = env->width / env->length;
	if (env->scale > 1)
		env->win_y = env->win_x / env->scale;
	else
		env->win_x = env->win_y * env->scale;
	env->x_scale = (env->win_x / env->width) / 2;
	env->y_scale = (env->win_y / env->length) / 2;
	env->z_scale = 1;
	env->x0 = (env->win_x / 2);
	env->y0 = (env->win_y / 2);
	env->zoom = .25;
	env->ax = .7854;
	env->ay = .6982;
	env->az = .0524;
}

void	wireframe(t_env *env)
{
	int		y;
	int		x;

	if (env->drawn)
	{
		mlx_clear_window(env->mlx, env->win);
		env->drawn = 0;
	}
	y = 0;
	while (y < env->length)
	{
		x = 0;
		while (x < env->width)
		{
			draw_segment(env, y, x);
			x++;
		}
		y++;
	}
	env->drawn = 1;
}

void	open_mlx(t_env *env, char *filename)
{
	env->mlx = mlx_init();
	set_scale(env);
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, filename);
	wireframe(env);
	mlx_key_hook(env->win, key_command, env);
	mlx_loop(env->mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_env	*env;

	if (argc != 2)
	{
		ft_printf("%{red}Invalid # of arguments.%{eoc}\nusage:\t./fdf [map]\n");
		return (0);
	}
	env = init_env();
	fd = open(argv[1], O_RDONLY);
	set_map(env, fd);
	//print_array(env);
	open_mlx(env, argv[1]);
	return (0);
}
