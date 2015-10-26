/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 19:15:07 by dbreton           #+#    #+#             */
/*   Updated: 2015/10/26 15:09:05 by dbreton          ###   ########.fr       */
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
		mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	}
	return (0);
}

int			mouse_hook(int btn, int x, int y, t_mlx *s)
{
	printf("%d|%d|%d\n", btn, x,y);
	if (btn == 4)
	{	
		s->x_start = x / 3;
		s->y_start = y / 3;
		s->zoom += 50;

	}
	else if (btn == 5)
	{	
		s->x_start = x / 3;
		s->y_start = y / 3;
		s->zoom -= 50;

	}
	mlx_clear_window(s->mlx, s->win);
	expose_hook(s);
	return (0);

}

int			key_hook(int key, t_mlx *s)
{
	printf("%d||%d\n", key, s->zoom);
	if (key == 53)
		exit(0);
	else if (key == 69)
		s->zoom += 100;
	else if (key == 78)
		s->zoom -= 100;
	mlx_clear_window(s->mlx, s->win);
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
			s.x_start = WIN_MAX_X / 8;
			s.y_start = WIN_MAX_Y / 4;
			mlx_expose_hook(s.win, &expose_hook, &s);
			mlx_key_hook(s.win, &key_hook, &s);
			mlx_mouse_hook(s.win, &mouse_hook, &s);
			mlx_loop(s.mlx);
		}
	}
}
