/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:39:09 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/21 13:28:07 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_zoom_handler(int btn, int x, int y, t_mlx *s)
{
	s->zoom = (s->zoom <= 50) ? 50 : s->zoom;
	if (btn == 4)
	{	
		s->x_start += (s->x_start - x) / (s->zoom / 50) ;
		s->y_start += (s->y_start - y) / (s->zoom / 50) ;
		s->zoom += 50;

	}
	else if (btn == 5)
	{	
		s->x_start += (s->x_start - x) / (s->zoom / 50) ;
		s->y_start += (s->y_start - y) / (s->zoom / 50) ;
		s->zoom -= 50;
	}
	s->zoom = (s->zoom <= 1) ? 1 : s->zoom;
	return (0);

}
int			frac_select(int key, t_mlx *s)
{
	printf("%d\n", key);
	if (key == 18)
		s->type = 1;
	else if (key == 20)
		s->type = 3;
	else if (key == 83)
		s->color = 2;
	else if (key == 84)
		s->color = 1;
	return (0);
}
int				ptr_motion_hook(int x, int y, t_mlx *s)
{
	if (x >= 0 && y >= 0 && x <= WIN_MAX_X && y <= WIN_MAX_Y)
	{
		s->c_r = (double)x / (double)WIN_MAX_X * 4 - 2;
		s->c_i = (double)y / (double)WIN_MAX_Y * 4 - 2;
	}
	expose_hook(s);
	return (0);
}
void		key_zoom_handler(int key, t_mlx *s)
{
	int		x;
	int		y;

	x = WIN_MAX_X / 2;
	y = WIN_MAX_Y / 2;
	if (key == 69)
	{
		s->x_start += (s->x_start - x) / (s->zoom / 100);
		s->y_start += (s->y_start - y) / (s->zoom / 100);

		s->zoom += 100;
	}
	else if (key == 78)
	{
		s->x_start += (s->x_start - x) / (s->zoom / 100) ;
		s->y_start += (s->y_start - y) / (s->zoom / 100) ;
		s->zoom -= 100;
	}

}
int			key_win_handler(int key, t_mlx *s)
{
	key_zoom_handler(key, s);
	if (key == 53)
		exit(0);
	else if (key == 67)
		s->max_ite += 5;
	else if (key == 75 && s->max_ite > 10)
		s->max_ite -= 5;
	else if (key == 123)
		s->x_start -= 20;
	else if (key == 124)
		s->x_start += 20;
	else if (key == 126)
		s->y_start -= 20;
	else if (key == 125)
		s->y_start += 20;
	s->zoom = (s->zoom <= 1) ? 1 : s->zoom;
	return (0);
}

