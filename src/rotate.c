/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:17:10 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/14 10:13:10 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bzero_mat(float mat[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	x_rotmatrix(float xmat[4][4], float ax)
{
	bzero_mat(xmat);
	xmat[0][0] = 1;
	xmat[1][1] = cos(ax);
	xmat[1][2] = sin(ax);
	xmat[2][1] = -sin(ax);
	xmat[2][2] = cos(ax);
	xmat[3][3] = 1;
}

void	y_rotmatrix(float ymat[4][4], float ay)
{
	bzero_mat(ymat);
	ymat[0][0] = cos(ay);
	ymat[0][2] = -sin(ay);
	ymat[1][1] = 1;
	ymat[2][0] = sin(ay);
	ymat[2][2] = cos(ay);
	ymat[3][3] = 1;
}

void	z_rotmatrix(float zmat[4][4], float az)
{
	bzero_mat(zmat);
	zmat[0][0] = cos(az);
	zmat[0][1] = sin(az);
	zmat[1][0] = -sin(az);
	zmat[1][1] = cos(az);
	zmat[2][2] = 1;
	zmat[3][3] = 1;
}
