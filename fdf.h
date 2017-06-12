/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:33:44 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/12 15:08:19 by lyoung           ###   ########.fr       */
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
	int			length;
	int			width;
	int			**map;
	int			x_scale;
	int			y_scale;
	void		*mlx;
	void		*win;
	int			color;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	int			hprev_x;
	int			hprev_y;
	int			vprev_x;
	int			vprev_y;
}				t_env;

#endif
