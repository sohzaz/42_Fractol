/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 19:15:07 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/22 14:08:57 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_mlx *s)
{
	if (s->img != NULL)
		mlx_destroy_image(s->mlx, s->img);
	if ((s->img = mlx_new_image(s->mlx, WIN_MAX_X, WIN_MAX_Y)) != NULL)
	{
		s->max_ite = (s->max_ite <= 70000) ? round(sqrt(s->zoom)) : s->max_ite;
		printf("%lld|%d\n", s->zoom, s->max_ite);
		if (s->type == 1)
			mandle_set(s);
		else if (s->type == 2)
			julia_set(s);
		else if (s->type == 3)
			sierp_carp_set(s);

		mlx_clear_window(s->mlx, s->win);
		mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	}
	return (0);
}

int			mouse_hook(int btn, int x, int y, t_mlx *s)
{
	mouse_zoom_handler(btn, x, y, s);
	expose_hook(s);
	return (0);

}

int			key_hook(int key, t_mlx *s)
{
	key_win_handler(key, s);
	frac_select(key, s);
	expose_hook(s);
	return (0);
}

void		win_init(t_mlx s)
{
	if ((s.mlx = mlx_init()) != NULL)
	{
		s.win = mlx_new_window(s.mlx, WIN_MAX_X, WIN_MAX_Y, "42 Fractol");
		s.img = mlx_new_image(s.mlx, WIN_MAX_X, WIN_MAX_Y);
		if (s.win != NULL && s.img != NULL)
		{
			s.zoom = 500;
			s.color = 1;
			s.f_lock = 1;
			s.c_r = -0.5;
			s.c_i = 0.5;
			mlx_expose_hook(s.win, &expose_hook, &s);
			mlx_key_hook(s.win, &key_hook, &s);
			mlx_mouse_hook(s.win, &mouse_hook, &s);
			mlx_hook(s.win, MOTION_NOTIFY, PTR_MOTION_MASK,
					&ptr_motion_hook, &s);
			mlx_loop(s.mlx);
		}
	}
}
