/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 19:15:07 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/07 12:54:42 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_mlx *s)
{
	if (s->img != NULL)
		mlx_destroy_image(s->mlx, s->img);
	if ((s->img = mlx_new_image(s->mlx, WIN_MAX_X, WIN_MAX_Y)) != NULL)
	{
		//	s->max_ite = abs(s->zoom)/5;
		if (s->type == 1)
			mandle_set(s);

		mlx_clear_window(s->mlx, s->win);
		mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	}
	return (0);
}

int			mouse_hook(int btn, int x, int y, t_mlx *s)
{
	if (btn == 4)
	{	
		s->x_start += (s->x_start - x) / (s->zoom / 100) ;
		s->y_start += (s->y_start - y) / (s->zoom / 100) ;
		s->zoom += 50;

	}
	else if (btn == 5)
	{	
		s->x_start += ((s->x_start - x) * (x != s->x0)) / (s->zoom / 100) ;
		s->y_start += ((s->y_start - y) * (y != s->y0)) / (s->zoom / 100) ;
		s->zoom -= 50;
	}
	printf("%d||%d\n", s->x_start, s->y_start);
	mlx_clear_window(s->mlx, s->win);
	s->x0 = x;
	s->y0 = y;
	expose_hook(s);
	return (0);

}

int			key_hook(int key, t_mlx *s)
{
	printf("%d||%d||%d\n", key, s->zoom, s->max_ite);
	if (key == 53)
		exit(0);
	else if (key == 69)
		s->zoom += 100;
	else if (key == 78)
		s->zoom -= 100;
	else if (key == 67)
		s->max_ite += 10;
	else if (key == 75 && s->max_ite > 10)
		s->max_ite -= 10;
	else if (key == 123)
		s->x_start -= 20;
	else if (key == 124)
		s->x_start += 20;
	else if (key == 126)
		s->y_start -= 20;
	else if (key == 125)
		s->y_start += 20;
	expose_hook(s);
	return (0);
}

void		win_init(t_mlx s, char *name)
{
	if ((s.mlx = mlx_init()) != NULL)
	{
		s.win = mlx_new_window(s.mlx, WIN_MAX_X, WIN_MAX_Y, name);
		s.img = mlx_new_image(s.mlx, WIN_MAX_X, WIN_MAX_Y);
		if (s.win != NULL && s.img != NULL)
		{
			s.zoom = 100;
			s.color = 16777215;
			mlx_expose_hook(s.win, &expose_hook, &s);
			mlx_key_hook(s.win, &key_hook, &s);
			mlx_mouse_hook(s.win, &mouse_hook, &s);
			mlx_loop(s.mlx);
		}
	}
}
