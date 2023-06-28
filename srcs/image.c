/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:50:05 by tmichel-          #+#    #+#             */
/*   Updated: 2023/06/28 20:28:21 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*init_img(void *mlx)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return ((t_image *)0);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img->img)
		return ((t_image *)0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
			&img->endian);
	return (img);
}

void	pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	select_fractal(t_window app, t_complex z)
{
	if (!ft_strncmp(app.fractal, "Julia", 5))
		return (julia(&app, z));
	if (!ft_strncmp(app.fractal, "Mandelbrot", 10))
		return (mandelbrot(&app, z));
	if (!ft_strncmp(app.fractal, "Burningship", 11))
		return (burningship(&app, z));
	return (1);
}

void	img_to_win(t_window *app)
{
	t_image		*img;
	t_complex	z;
	int			it;
	int			x;
	int			y;

	img = init_img(app->mlx);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z = get_complex_plane(*app, x, y);
			it = select_fractal(*app, z);
			if (it)
				pixel_put(img, x, y, get_colors(it, app->max_it, app->color));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(app->mlx, app->win, img->img, app->offset_x,
		app->offset_y);
	mlx_destroy_image(app->mlx, img->img);
}
