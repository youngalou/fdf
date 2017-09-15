/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 10:21:55 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/20 11:52:17 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	horizontal_line(t_env *env, int x0, int y0)
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;

	dx = abs(env->hprev_x - x0);
	sx = x0 < env->hprev_x ? 1 : -1;
	dy = abs(env->hprev_y - y0);
	sy = y0 < env->hprev_y ? 1 : -1;
	env->err = (dx > dy ? dx : -dy) / 2;
	while (x0 != env->hprev_x)
	{
		if (x0 >= 0 && x0 < 1200 && y0 >= 0 && y0 < 1200)
			env->pixels[x0 + (y0 * env->win_x)] = env->color;
		env->e2 = env->err;
		if (env->e2 > -dx)
		{
			env->err -= dy;
			x0 += sx;
		}
		if (env->e2 < dy)
		{
			env->err += dx;
			y0 += sy;
		}
	}
}

void	vertical_line(t_env *env, int x0, int y0)
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;

	dx = abs(env->vprev_x - x0);
	sx = x0 < env->vprev_x ? 1 : -1;
	dy = abs(env->vprev_y - y0);
	sy = y0 < env->vprev_y ? 1 : -1;
	env->err = (dx > dy ? dx : -dy) / 2;
	while (y0 != env->vprev_y)
	{
		if (x0 >= 0 && x0 < 1200 && y0 >= 0 && y0 < 1200)
			env->pixels[x0 + (y0 * env->win_x)] = env->color;
		env->e2 = env->err;
		if (env->e2 > -dx)
		{
			env->err -= dy;
			x0 += sx;
		}
		if (env->e2 < dy)
		{
			env->err += dx;
			y0 += sy;
		}
	}
}

void	determine_prev(t_env *env, int y, int x)
{
	env->hprev_x = (((x - 1) * env->x_scale) +
					(env->x0 - (env->zoom * env->x0))) - env->x0;
	env->vprev_x = ((x * env->x_scale) +
					(env->x0 - (env->zoom * env->x0))) - env->x0;
	env->vprev_y = (((y - 1) * env->y_scale) +
					(env->y0 - (env->zoom * env->y0))) - env->y0;
	env->hprev_y = ((y * env->y_scale) +
					(env->y0 - (env->zoom * env->y0))) - env->y0;
	rotate_hprev(env, env->map[y][(x > 0) ? x - 1 : x] * env->z_scale);
	rotate_vprev(env, env->map[(y > 0) ? y - 1 : y][x] * env->z_scale);
}

void	color_select(t_env *env, int y, int x, int hv)
{
	env->color = env->color0 - (env->map[y][x] * 5000);
	if (env->map[(y > 0) ? y - 1 : y][x] && hv == 2)
		env->color = env->color0 - (env->map[(y > 0) ? y - 1 : y][x] * 5000);
	else if (env->map[y][(x > 0) ? x - 1 : x] && hv == 1)
		env->color = env->color0 - (env->map[y][(x > 0) ? x - 1 : x] * 5000);
}

void	draw_segment(t_env *env, int y, int x)
{
	env->x_place = (x * env->x_scale +
					(env->x0 - (env->zoom * env->x0))) - env->x0;
	env->y_place = (y * env->y_scale +
					(env->y0 - (env->zoom * env->y0))) - env->y0;
	rotate(env, env->map[y][x] * env->z_scale);
	determine_prev(env, y, x);
	env->x_place += env->x0;
	env->y_place += env->y0;
	env->hprev_x += env->x0;
	env->hprev_y += env->y0;
	env->vprev_x += env->x0;
	env->vprev_y += env->y0;
	color_select(env, y, x, 1);
	if (x > 0)
		horizontal_line(env, env->x_place, env->y_place);
	color_select(env, y, x, 2);
	if (y > 0)
		vertical_line(env, env->x_place, env->y_place);
}
