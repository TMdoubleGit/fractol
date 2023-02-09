/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:09:40 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/06 10:55:18 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_window(t_window *app, char **av, double c_r, double c_i)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "Fractol");
	if (!app->win)
		return (0);
	if (!c_r)
		c_r = C_R;
	if (!c_i)
		c_i = C_I;
	app->c = (t_complex){c_r, c_i};
	app->fractal = av[1];
	if (!app->fractal)
		return (0);
	app->color = 1;
	app->max_it = MAX_IT;
	app->zoom = 1.0;
	app->offset_x = 0.0;
	app->offset_y = 0.0;
	return (1);
}

int	destroy_window(t_window *app)
{
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free (app->mlx);
	ft_printf("Fractol has been closed successfully !");
	exit (0);
	return (0);
}
