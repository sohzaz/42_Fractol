/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:27:23 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/21 13:38:49 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			main(int ac, char **av)
{
	t_mlx	s;

	s.max_ite = 30;
	if (ac == 2)
	{
		s.type = av[1][0] - 48;
		s.x_start = WIN_MAX_X / 2;
		s.y_start = WIN_MAX_Y / 2;

		win_init(s);
	}
	return (0);
}
