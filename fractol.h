/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:11:58 by dbreton           #+#    #+#             */
/*   Updated: 2015/10/26 14:42:14 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <string.h>
# include <libft.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# define WIN_MAX_X 1080 
# define WIN_MAX_Y 600 
# define SCREEN_RATIO WIN_MAX_X/WIN_MAX_Y

typedef struct		s_mlxdata{
	void			*mlx;
	void			*win;
	void			*img;
	int				color;
	int				zoom;
	int				type;
	int				x_start;
	int				y_start;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	int				max_ite;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				xmax;
	int				ymax;
}					t_mlx;
void				win_init(t_mlx s, char *name);
void				win_draw(t_mlx s);
void				put_in_image(t_mlx *s, int x, int y, int color);
void				mandle_set(t_mlx *s);
#endif
