/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 10:21:55 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/16 12:53:19 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	horizontal_line(t_env *env, int x0, int y0, int x1, int y1)
{
	int		dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int		dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
	int		err = (dx > dy ? dx : -dy) / 2, e2;

	while (x0 != x1)
	{
		mlx_pixel_put(env->mlx, env->win, x0, y0, env->color);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	vertical_line(t_env *env, int x0, int y0, int x1, int y1)
{
	int		dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int		dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
	int		err = (dx > dy ? dx : -dy) / 2, e2;

	while (y0 != y1)
	{
		mlx_pixel_put(env->mlx, env->win, x0, y0, env->color);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	determine_prev(t_env *env, int y, int x)
{
   	env->hprev_x = (((x - 1) * env->x_scale) + (env->x0 - (env->zoom * env->x0))) - env->x0;
   	env->vprev_x = ((x * env->x_scale) + (env->x0 - (env->zoom * env->x0))) - env->x0;
   	env->vprev_y = (((y - 1) * env->y_scale) + (env->y0 - (env->zoom * env->y0))) - env->y0;
   	env->hprev_y = ((y * env->y_scale) + (env->y0 - (env->zoom * env->y0))) - env->y0;
	rotate_hprev(env, env->map[y][(x > 0) ? x - 1 : x] * env->z_scale);
	rotate_vprev(env, env->map[(y > 0) ? y - 1 : y][x] * env->z_scale);
}

void	color_select(t_env *env, int y, int x, int hv)
{
	env->color = 0xffffff - (env->map[y][x] * 5000);
	if (env->map[(y > 0) ? y - 1 : y][x] && hv == 2)
		env->color = 0xffffff - (env->map[(y > 0) ? y - 1 : y][x] * 5000);
	else if (env->map[y][(x > 0) ? x - 1 : x] && hv == 1)
		env->color = 0xffffff - (env->map[y][(x > 0) ? x - 1 : x] * 5000);
}

void	draw_segment(t_env *env, int y, int x)
{
	env->x_place = (x * env->x_scale + (env->x0 - (env->zoom * env->x0))) - env->x0;
	env->y_place = (y * env->y_scale + (env->y0 - (env->zoom * env->y0))) - env->y0;
	rotate(env, env->map[y][x] * env->z_scale);
	determine_prev(env, y, x);
	env->x_place = (env->x_place + env->x0);
	env->y_place = (env->y_place + env->y0);
	env->hprev_x = env->hprev_x + env->x0;
	env->hprev_y = env->hprev_y + env->y0;
	env->vprev_x = env->vprev_x + env->x0;
	env->vprev_y = env->vprev_y + env->y0;
	color_select(env, y, x, 1);
	if (x > 0)
		horizontal_line(env, env->x_place, env->y_place, env->hprev_x, env->hprev_y);
	color_select(env, y, x, 2);
	if (y > 0)
		vertical_line(env, env->x_place, env->y_place, env->vprev_x, env->vprev_y);
}

void	rotate(t_env *env, int z)
{
	int		x_tmp;

	x_tmp = env->x_place;
	env->x_place = env->x_place * cos(env->ax) - env->y_place * sin(env->ax);
	env->y_place = x_tmp * sin(env->ax) + env->y_place * cos(env->ax);
	env->y_place = (env->y_place * cos(env->ay) - z * sin(env->ay));
	env->x_place = env->x_place * cos(env->az) + z * sin(env->az);
}

void	rotate_hprev(t_env *env, int z)
{
	int		x_tmp;

	x_tmp = env->hprev_x;
	env->hprev_x = env->hprev_x * cos(env->ax) - env->hprev_y * sin(env->ax);
	env->hprev_y = x_tmp * sin(env->ax) + env->hprev_y * cos(env->ax);
	env->hprev_y = (env->hprev_y * cos(env->ay) - z * sin(env->ay));
	env->hprev_x = env->hprev_x * cos(env->az) + z * sin(env->az);
}

void	rotate_vprev(t_env *env, int z)
{
	int		x_tmp;

	x_tmp = env->vprev_x;
	env->vprev_x = env->vprev_x * cos(env->ax) - env->vprev_y * sin(env->ax);
	env->vprev_y = x_tmp * sin(env->ax) + env->vprev_y * cos(env->ax);
	env->vprev_y = (env->vprev_y * cos(env->ay) - z * sin(env->ay));
	env->vprev_x = env->vprev_x * cos(env->az) + z * sin(env->az);
}
