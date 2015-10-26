/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:20:16 by dbreton           #+#    #+#             */
/*   Updated: 2015/10/26 14:04:42 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandle_set(t_mlx *s)
{
	int				i;
	int				x;
	int				y;
	double 			tmp;

	y = WIN_MAX_Y;
	while (y  > 0)
	{
		x = WIN_MAX_X;
		while (x > 0)
		{
			s->z_r = 0.0;
			s->z_i = 0.0;
			s->c_r = (float)(x - s->x_start) / s->zoom;
			s->c_i = (float)(y - s->y_start) / s->zoom;
			i = 0;
			while ((pow(s->z_r, 2) + pow(s->z_i, 2) < 4) && (i < s->max_ite))
			{
				tmp = s->z_r;
				s->z_r = pow(s->z_r, 2) - pow(s->z_i, 2) + s->c_r;
				s->z_i = 2 * s->z_i * tmp + s->c_i;
				i += 1;
			}
			if (i == s->max_ite)
				put_in_image(s, x, y, 0);
			else
				put_in_image(s, x,y , 16777215);
			x -= 1;
		}
		y--;
	}

}