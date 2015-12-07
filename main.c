/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:27:23 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/07 14:04:16 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char	*name_assign(char const *str)
{
	int		i;
	char	*name;

	i = 0;
	name = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strcpy(name, str);
	return (name);
}

int			main(int ac, char **av)
{
	char	*name = NULL;
	t_mlx	s;

	s.x_start = WIN_MAX_X / 2;
	s.y_start = WIN_MAX_Y / 2;
	s.max_ite = 30;
	if (ac == 2)
	{
		if (av[1][0] == '1')
			name = name_assign("Mandelbrot set");
		else if (av[1][0] == '2')
			name = name_assign("Julia set");
		else if (av[1][0] == '3')
			name = name_assign("Sierpinski Carpet");
		s.type = ft_atoi(av[1]);
		win_init(s, name);
	}
	return (0);
}
