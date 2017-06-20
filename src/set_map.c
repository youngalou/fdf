/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:35:37 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/20 15:12:57 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		while ((*line >= '0' && *line <= '9') || (*line >= 'a' && *line <= 'z')
				|| (*line >= 'A' && *line <= 'Z'))
			line++;
		while (*line == ' ' || *line == '\t')
			line++;
		x++;
	}
	ft_strdel(&tmp);
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
	env->z_scale = 2;
	env->x0 = (env->win_x / 2);
	env->y0 = (env->win_y / 2);
	env->zoom = .5;
	env->ax = .7854;
	env->ay = .6982;
	env->az = .0524;
}
