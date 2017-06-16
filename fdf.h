/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:33:44 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/16 12:37:08 by lyoung           ###   ########.fr       */
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
	double		x_scale;
	double		y_scale;
	double		z_scale;
	int			x0;
	int			y0;
	double		zoom;
	double		ax;
	double		ay;
	double		az;
	int			x_place;
	int			y_place;
	int			hprev_x;
	int			hprev_y;
	int			vprev_x;
	int			vprev_y;
	int			color;
	int			drawn;
}				t_env;

void	open_mlx(t_env *env, char *filename);
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
void	set_scale(t_env *env);
void	rotate(t_env *env, int z);
void	rotate_hprev(t_env *env, int z);
void	rotate_vprev(t_env *env, int z);

#endif
