/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:20:16 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/17 13:21:49 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			mandle_color(const t_mlx *s, const int i)
{
	int				col;
	int				v;

	if (s->color == 1)
		col = (255 * (3 * i) * 255 * 255) * (i < s->max_ite);
	else
	{
		v = round(i + 1 - (log2(log(hypot(s->z_r, s->z_i))/log(2))));
		col = (255 * (2 * v) * 255 * 255) * (i < s->max_ite);
	}
	return (col);

}
static void			mandle_ite(t_mlx *s, int x, int y)
{
	int i;
	int max_color;
	double tmp;

	i = 0;
	max_color = 16711680;
	while ((pow(s->z_r, 2) + pow(s->z_i, 2) < 4) && (i < s->max_ite))
	{

		tmp = s->z_r;
		s->z_r = pow(s->z_r, 2) - pow(s->z_i, 2) + s->c_r;
		s->z_i = 2 * s->z_i * tmp + s->c_i;
		i += 1;
	}
	put_in_image(s, x, y, mandle_color(s, i));

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

int					sierp_carp_draw(t_mlx *s,int x, int y)
{
	(void)s;
	x %= s->zoom;
	y %= s->zoom;
	while (x > 0 || y > 0)
	{
		if (x% 3 == 1 && y% 3 == 1)
			return (0);
		y /= 3;
		x /= 3;
	}
	return (16777215);
}

void				sierp_carp_set(t_mlx *s)
{
	int				x;
	int				y;

	y = 0;
	while (y < WIN_MAX_Y)
	{
		x = 0;
		while (x < WIN_MAX_X)
		{
			put_in_image(s, x, y,sierp_carp_draw(s,
						x + s->x_start,y + s->y_start));
			x++;
		}
		y++;
	}
}
