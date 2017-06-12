/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:10:38 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/07 13:48:47 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "New Window");
	color = 0xffffff;
	y = 200;
	while (y < 800)
	{
		x = 200;
		while (x < 800)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
			color -= 50;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
