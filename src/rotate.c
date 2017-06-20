/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:51:57 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/20 11:13:18 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
