/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 10:21:55 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/14 12:31:04 by lyoung           ###   ########.fr       */
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

/*void	draw_2D_segment(t_env *env, int y, int x)
{
	int		y_place;
	int		x_place;
	
	y_place = (y * env->y_scale) + env->y_scale;
	x_place = (x * env->x_scale) + env->x_scale;
	env->color = ((env->map[y][x] == 0 || env->map[y][x - 1] == 0) ? 0xffffff : 0x7fff00);
	if (x > 0)
		horizontal_line(env, x_place, y_place, ((x - 1) * env->x_scale) + env->x_scale, (y * env->y_scale) + env->y_scale);
	env->color = ((env->map[y][x] == 0 || env->map[y - 1][x] == 0) ? 0xffffff : 0x7fff00);
	if (y > 0)
		vertical_line(env, x_place, y_place, (x * env->x_scale) + env->x_scale, ((y - 1) * env->y_scale) + env->y_scale);
}*/

void	determine_prev(t_env *env, int y, int x)
{
   	env->hprev_x = ((x - 1) * env->x_scale) - env->x0;
   	env->vprev_x = (x * env->x_scale) - env->x0;
	env->vprev_y = ((y - 1) * env->y_scale) - env->y0;
	env->hprev_y = ((y) * env->y_scale) - env->y0;
	env->vprev_y = env->vprev_x + (2 * env->vprev_y) + env->map[(y > 0) ? y - 1 : y][x];
	env->hprev_y = env->hprev_x + (2 * env->hprev_y) + env->map[y][(x > 0) ? x - 1 : x];
	env->hprev_x = (sqrt(3) * env->hprev_x) - (sqrt(3) * env->map[y][(x > 0) ? x - 1 : x]);
	env->vprev_x = (sqrt(3) * env->vprev_x) - (sqrt(3) * env->map[(y > 0) ? y - 1 : y][x]);
}

/*void	determine_prev(t_env *env, int y, int x)
{
	int		hprev_x;
	int		hprev_y;
	int		vprev_x;
	int		vprev_y;

   	hprev_x = ((x - 1) * env->x_scale) + env->x_scale;
   	vprev_x = (x * env->x_scale) + env->x_scale;

	vprev_y = ((y - 1) * env->y_scale) + env->y_scale;
	hprev_y = ((y) * env->y_scale) + env->y_scale;
	env->hprev_x = (hprev_x * (cos(env->y_angle) * cos(env->z_angle))) - (hprev_y * (cos(env->y_angle) * sin(env->z_angle))) + (env->map[y][(x > 0) ? x - 1 : x] * sin(env->y_angle));
	env->hprev_y = (hprev_x * (sin(env->x_angle) * cos(env->y_angle) * cos(env->z_angle)) + (cos(env->x_angle) * sin(env->z_angle))) + (hprev_y * (sin(env->x_angle) * sin(env->y_angle) * sin(env->z_angle)) + (cos(env->x_angle) * cos(env->z_angle))) - (env->map[y][(x > 0) ? x - 1 : x] * (cos(env->y_angle) * sin(env->x_angle)));
	env->vprev_y = (vprev_x * (sin(env->x_angle) * cos(env->y_angle) * cos(env->z_angle)) + (cos(env->x_angle) * sin(env->z_angle))) + (vprev_y * (sin(env->x_angle) * sin(env->y_angle) * sin(env->z_angle)) + (cos(env->x_angle) * cos(env->z_angle))) - (env->map[(y > 0) ? y - 1: y][x] * (cos(env->y_angle) * sin(env->x_angle)));
	env->vprev_x = (vprev_x * (cos(env->y_angle) * cos(env->z_angle))) - (vprev_y * (cos(env->y_angle) * sin(env->z_angle))) + (env->map[(y > 0) ? y - 1 : y][x] * sin(env->y_angle));
}*/

void	draw_segment(t_env *env, int y, int x)
{
	int		y_place;
	int		x_place;

	x_place = (x * env->x_scale) - env->x0;
	y_place = (y * env->y_scale) - env->y0;
	y_place = x_place + (2 * y_place) + env->map[y][x];
	x_place = (sqrt(3) * x_place) - (sqrt(3) * env->map[y][x]);
	determine_prev(env, y, x);
	x_place = (x_place + env->x0 * 3);
	y_place = (y_place + env->y0 * 3);
	env->hprev_x = env->hprev_x + env->x0 * 3;
	env->hprev_y = env->hprev_y + env->y0 * 3;
	env->vprev_x = env->vprev_x + env->x0 * 3;
	env->vprev_y = env->vprev_y + env->y0 * 3;
	env->color = ((env->map[y][x] == 0 || env->map[y][x - 1] == 0) ? 0xffffff : 0x7fff00);
	if (x > 0)
		horizontal_line(env, x_place, y_place, env->hprev_x, env->hprev_y);
	env->color = ((env->map[y][x] == 0 || env->map[y - 1][x] == 0) ? 0xffffff : 0x7fff00);
	if (y > 0)
		vertical_line(env, x_place, y_place, env->vprev_x, env->vprev_y);
}

/*void	draw_segment(t_env *env, int y, int x)
{
	int		y_place;
	int		x_place;
	int		y_new;
	int		x_new;
	
	x_place = (x * env->x_scale) + env->x_scale;
	y_place = (y * env->y_scale) + env->y_scale;
	x_new = (x_place * (cos(env->y_angle) * cos(env->z_angle))) - (y_place * (cos(env->y_angle) * sin(env->z_angle))) + (env->map[y][x] * sin(env->y_angle));
	y_new = (x_place * (sin(env->x_angle) * sin(env->y_angle) * cos(env->z_angle)) + (cos(env->x_angle) * sin(env->z_angle))) + (y_place * (sin(env->x_angle) * sin(env->y_angle) * sin(env->z_angle)) + (cos(env->x_angle) * cos(env->z_angle))) - (env->map[y][x] * (cos(env->y_angle) * sin(env->x_angle)));
	determine_prev(env, y, x);
	env->color = ((env->map[y][x] == 0 || env->map[y][x - 1] == 0) ? 0xffffff : 0x7fff00);
	if (x > 0)
		//mlx_pixel_put(env->mlx, env->win, x_new, y_new, env->color);
		horizontal_line(env, x_new, y_new, env->hprev_x, env->hprev_y);
	env->color = ((env->map[y][x] == 0 || env->map[y - 1][x] == 0) ? 0xffffff : 0x7fff00);
	if (y > 0)
		//mlx_pixel_put(env->mlx, env->win, x_new, y_new, env->color);
		vertical_line(env, x_new, y_new, env->vprev_x, env->vprev_y);
}*/
