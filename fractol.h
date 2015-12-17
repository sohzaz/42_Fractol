/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:11:58 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/17 14:48:43 by dbreton          ###   ########.fr       */
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
# define WIN_MAX_X 1960 
# define WIN_MAX_Y 1080  
# define SCREEN_RATIO WIN_MAX_X/WIN_MAX_Y
# define PTR_MOTION_MASK (1L << 6)
# define MOTION_NOTIFY 7 

typedef struct		s_mlxdata{
	void			*mlx;
	void			*win;
	void			*img;
	double			color;
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
	int				max_step;
}					t_mlx;
void				win_init(t_mlx s, char *name);
void				win_draw(t_mlx s);
void				put_in_image(t_mlx *s, int x, int y, int color);
void				mandle_set(t_mlx *s);
void				sierp_carp_set(t_mlx *s);
int					mouse_zoom_handler(int btn, int x, int y, t_mlx *s);
int			        key_win_handler(int key, t_mlx *s);
int					frac_select(int key, t_mlx *s);
int					ptr_motion_hook(int x, int y, t_mlx *s);
int					expose_hook(t_mlx *s);
#endif
