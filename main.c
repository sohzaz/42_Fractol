/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:27:23 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/22 17:17:54 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		get_usage(void)
{
	write(2, "Usage: ./fractol [123]\n", 23);
	write(2, "1\tMandelbrot Set\n", 17);
	write(2, "2\tJulia Set\n", 12);
	write(2, "3\tSierpinski carpet\n", 20);
}

int			main(int ac, char **av)
{
	t_mlx	s;

	s.max_ite = 30;
	if (ac == 2)
	{
		s.type = av[1][0] - 48;
		if (s.type <= 3 && s.type >= 1)
		{
			s.x_start = WIN_MAX_X / 2;
			s.y_start = WIN_MAX_Y / 2;
			win_init(s);
		}
	}
	get_usage();
	return (0);
}
