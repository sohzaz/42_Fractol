/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:20:16 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/07 14:34:48 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			mandle_ite(t_mlx *s, int x, int y)
{
	int i;
	double tmp;

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
		put_in_image(s, x,y , (int)s->z_r * 1000000);

}

void				mandle_set(t_mlx *s)
{
	int				x;
	int				y;

	y = WIN_MAX_Y + 1;
	while (y  >= 0)
	{
		x = WIN_MAX_X + 1;
		while (x >= 0)
		{
			s->z_r = 0.0;
			s->z_i = 0.0;
			s->c_r = (float)(x - s->x_start) / s->zoom;
			s->c_i = (float)(y - s->y_start) / s->zoom;
			mandle_ite(s, x, y);
			x -= 1;
		}
		y--;
	}

}

void				sierp_set(t_mlx *s)
{
	int				x;
	int				y;
	int				step;

	y = 0;
	while (y < WIN_MAX_Y)
	{
		x = 0;
		while (x < WIN_MAX_X)
		{
			step = 0;
			while (step < s->max_step)
			{
				if (((((x*s->zoom)/(long)(pow(3, step))) % 3) != 1)
						&& ((((s->zoom * y)/(long)(pow(3, step))) % 3) != 1))
					step++;
				else
					break;
			}
			put_in_image(s, x, y, s->color * !(step == s->max_step));
			x++;
		}
		y++;
	}
}
