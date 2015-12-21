/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:40:34 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/21 13:29:57 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandle_color(const t_mlx *s , const int i);
int			julia_color(const t_mlx *s, const int i)
{
	//return (16777215 * (i < s->max_ite));
	
	return (mandle_color(s, i));
}

void			julia_ite(t_mlx *s, int x, int y)
{
	int			i;
	double		tmp;

	i = 0;
	while ((pow(s->z_r, 2) + pow(s->z_i, 2) < 4) && (i < s->max_ite))
	{

		tmp = s->z_r;
		s->z_r = pow(s->z_r, 2) - pow(s->z_i, 2) + s->c_r;
		s->z_i = 2 * s->z_i * tmp + s->c_i;
		i += 1;
	}
	put_in_image(s, x, y, julia_color(s, i));
}

void			julia_set(t_mlx *s)
{
	int			x;
	int			y;

	y = 0;
	while (y < WIN_MAX_Y + 1)
	{
		x = 0;
		while (x < WIN_MAX_X + 1)
		{
			s->z_r = 1.5 * (x - s->x_start) / 
				(0.5 *(s->zoom / 100)* WIN_MAX_X) * 100;
			s->z_i =(y - s->y_start) / 
				(0.5 *(s->zoom / 100)* WIN_MAX_Y) * 100;
			julia_ite(s, x, y);
			x++;
		}
		y++;
	}
}
