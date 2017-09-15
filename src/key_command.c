/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:21:20 by lyoung            #+#    #+#             */
/*   Updated: 2017/09/15 11:55:35 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		key_command(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
	{
		(key == 126) ? env->ay += .05 : 0;
		(key == 125) ? env->ay -= .05 : 0;
		(key == 123) ? env->ax += .05 : 0;
		(key == 124) ? env->ax -= .05 : 0;
		wireframe(env);
	}
	key_zoom(env, key);
	key_translate(env, key);
	key_color(env, key);
	if (key == 48)
	{
		set_scale(env);
		wireframe(env);
	}
	return (0);
}

void	key_zoom(t_env *env, int key)
{
	if (key == 24 || key == 27)
	{
		if (key == 24)
		{
			env->zoom *= 1.1;
			env->x_scale *= 1.1;
			env->y_scale *= 1.1;
			env->z_scale *= 1.1;
		}
		if (key == 27)
		{
			env->zoom /= 1.1;
			env->x_scale /= 1.1;
			env->y_scale /= 1.1;
			env->z_scale /= 1.1;
		}
		wireframe(env);
	}
}

void	key_translate(t_env *env, int key)
{
	if (key == 13 || (key >= 0 && key <= 2))
	{
		(key == 13) ? env->y0 -= env->y_scale / 2 : 0;
		(key == 1) ? env->y0 += env->y_scale / 2 : 0;
		(key == 0) ? env->x0 -= env->x_scale / 2 : 0;
		(key == 2) ? env->x0 += env->x_scale / 2 : 0;
		wireframe(env);
	}
	if (key == 34 || (key >= 37 && key <= 40))
	{
		(key == 34) ? env->y0 -= env->y_scale * 10 : 0;
		(key == 40) ? env->y0 += env->y_scale * 10 : 0;
		(key == 38) ? env->x0 -= env->x_scale * 10 : 0;
		(key == 37) ? env->x0 += env->x_scale * 10 : 0;
		wireframe(env);
	}
}

void	key_color(t_env *env, int key)
{
	if (key >= 82 && key <= 92)
	{
		(key == 82) ? env->color0 = 16777215 : 0;
		(key == 83) ? env->color0 = 1283748 : 0;
		(key == 84) ? env->color0 = 14554898 : 0;
		(key == 85) ? env->color0 = 15524880 : 0;
		(key == 86) ? env->color0 = 12345678 : 0;
		(key == 87) ? env->color0 = 1111111 : 0;
		(key == 88) ? env->color0 = 14988716 : 0;
		(key == 89) ? env->color0 = 21701798 : 0;
		(key == 91) ? env->color0 = 8978117 : 0;
		(key == 92) ? env->color0 = 6737033 : 0;
		wireframe(env);
	}
}
