/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:40:34 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/29 11:55:15 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			get_numbers(t_mlx *s, int x, int y)
{
    if (s->type == 1)
    {
        s->z_r = 0.0;
        s->z_i = 0.0;
        s->c_r = 1.5 * (x - s->x_start) /
            (0.25 * (s->zoom / 100) * WIN_MAX_X) * 10;
        s->c_i = (y - s->y_start) /
            (0.25 * (s->zoom / 100) * WIN_MAX_Y) * 10;
    }
    else if (s->type == 2)
    {
        s->z_r = 1.5 * (x - s->x_start) /
            (0.25 * (s->zoom / 100) * WIN_MAX_X) * 10;
        s->z_i = (y - s->y_start) /
            (0.25 * (s->zoom / 100) * WIN_MAX_Y) * 10;
    }
}
