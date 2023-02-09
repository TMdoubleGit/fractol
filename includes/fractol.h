/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:54 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/09 11:25:01 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <math.h>
# include "libft.h"
# include "../mlx_linux/mlx.h"

# define HEIGHT 1000
# define WIDTH 1000
# define MAX_IT 50
# define C_R 0.285
# define C_I	0.01

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_complex {
	double	r;
	double	i;
}			t_complex;

typedef union s_color {
	int	hex;
	struct
	{
		char	r;
		char	g;
		char	b;
	};
}	t_color;

typedef struct s_window {
	void		*mlx;
	void		*win;
	t_complex	c;
	char		*fractal;
	int			color;
	int			max_it;
	double		zoom;
	double		offset_x;
	double		offset_y;
}				t_window;

//FRACTALS.C
int			mandelbrot(t_window *app, t_complex c);
int			julia(t_window *app, t_complex z);
int			burningship(t_window *app, t_complex c);
//HOOKS.C
t_complex	get_complex_plane(t_window app, int x, int y);
void		panning_events(int keycode, t_window *app);
int			hooks_triggers(int keycode, t_window *app);
int			mouse_hooks_triggers(int mousecode, int x, int y, t_window *app);
void		hooks(t_window app);
//IMAGE.C
t_image		init_img(void *mlx);
void		pixel_put(t_image *img, int x, int y, int color);
int			select_fractal(t_window app, t_complex z);
void		img_to_win(t_window *app);
//COLORS.C
int			get_colors(int it, int max_it, int shift);
//MAIN.C
void		parse_args(t_window *app, int ac, char **av);
//WINDOW.C
int			init_window(t_window *app, char **av, double c_r, double c_i);
int			destroy_window(t_window *app);

#endif
