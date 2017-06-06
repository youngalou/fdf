/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:30:05 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 14:05:16 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_printf("%{red}Invalid # of arguments.%{eoc}\nusage:\t./fdf [map]\n");
	fd = open(argv[1], O_RDONLY);
	return (0);
}
