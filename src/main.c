/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:30:05 by lyoung            #+#    #+#             */
/*   Updated: 2017/09/15 11:44:05 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->bpp = 4;
	env->sl = 0;
	env->endian = 0;
	env->length = 0;
	env->width = 0;
	env->win_x = 1200;
	env->win_y = 1200;
	env->scale = 1;
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
	env->color0 = 16777215;
	env->drawn = 0;
	return (env);
}

void	clear_pixels(t_env *env)
{
	int		i;

	i = 0;
	while (i < (env->win_x * env->win_y))
	{
		env->pixels[i] = 0;
		i++;
	}
}

void	wireframe(t_env *env)
{
	int		y;
	int		x;

	if (env->drawn)
	{
		mlx_clear_window(env->mlx, env->win);
		clear_pixels(env);
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
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->drawn = 1;
}

void	open_mlx(t_env *env, char *filename)
{
	env->mlx = mlx_init();
	set_scale(env);
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, filename);
	env->img = mlx_new_image(env->mlx, env->win_x, env->win_y);
	env->pixels = (int*)mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
	wireframe(env);
	mlx_hook(env->win, 2, 0, key_command, env);
	mlx_loop(env->mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_env	*env;

	if (argc != 2)
	{
		ft_printf("%{red}Invalid # of arguments.%{eoc}\nUsage:\t./fdf <map>\n");
		return (0);
	}
	env = init_env();
	fd = open(argv[1], O_RDONLY);
	set_map(env, fd);
	open_mlx(env, argv[1]);
	return (0);
}
