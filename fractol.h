/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:11:58 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/29 11:55:17 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# define WIN_MAX_X 640
# define WIN_MAX_Y 480
# define PTR_MOTION_MASK (1L << 6)
# define MOTION_NOTIFY 6

typedef struct		s_mlxdata{
	void			*mlx;
	void			*win;
	void			*img;
	double			color;
	long long		zoom;
	int				type;
	long long		x_start;
	long long		y_start;
	int				max_ite;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				f_lock;
}					t_mlx;
void				win_init(t_mlx s);
void				win_draw(t_mlx s);
void				put_in_image(t_mlx *s, int x, int y, int color);
void				mandle_set(t_mlx *s);
void				sierp_carp_set(t_mlx *s);
int					mouse_zoom_handler(int btn, int x, int y, t_mlx *s);
int					key_win_handler(int key, t_mlx *s);
int					frac_select(int key, t_mlx *s);
int					ptr_motion_hook(int x, int y, t_mlx *s);
int					expose_hook(t_mlx *s);
void				julia_set(t_mlx *s);
int					mandle_color(const t_mlx *s, const int i);
void				win_reset(t_mlx *s);
#endif
