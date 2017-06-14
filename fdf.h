/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:33:44 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/14 12:42:18 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/superlibft.h"
# include "minilibx/mlx.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			length;
	int			width;
	int			**map;
	int			win_x;
	int			win_y;
	double		scale;
	int			x_scale;
	int			y_scale;
	int			x0;
	int			y0;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	int			hprev_x;
	int			hprev_y;
	int			vprev_x;
	int			vprev_y;
	int			color;
	int			drawn;
}				t_env;

void	open_mlx(t_env *env);
void	draw_segment(t_env *env, int y, int x);
void	determine_prev(t_env *env, int y, int x);
void	vertical_line(t_env *env, int x0, int y0, int x1, int y1);
void	horizontal_line(t_env *env, int x0, int y0, int x1, int y1);
void	print_array(t_env *env);
void	set_map(t_env *env, int fd);
void	populate_row(t_env *env, char *line, int y);
t_env	*init_env(void);
void	wireframe(t_env *env);
int		key_command(int key, t_env *env);
void	reset_wireframe(t_env *env);

#endif
