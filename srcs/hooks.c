/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:41:03 by tmichel-          #+#    #+#             */
/*   Updated: 2023/06/28 20:33:34 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex_plane(t_window app, int x, int y)
{
	double	r;
	double	i;

	r = (-2 / app.zoom) + x * (4 / app.zoom) / WIDTH + app.offset_x;
	i = (-2 / app.zoom) + y * (4 / app.zoom) / HEIGHT + app.offset_y;
	return ((t_complex){
		.r = r,
		.i = i
	});
}

void	panning_events(int keycode, t_window *app)
{
	if (keycode == XK_Right)
		app->offset_x -= 0.1 / app->zoom;
	if (keycode == XK_Left)
		app->offset_x += 0.1 / app->zoom;
	if (keycode == XK_Up)
		app->offset_y += 0.1 / app->zoom;
	if (keycode == XK_Down)
		app->offset_y -= 0.1 / app->zoom;
}

int	hooks_triggers(int keycode, t_window *app)
{
	if (keycode == XK_r)
	{
		app->zoom = 1.0;
		app->offset_x = 0;
		app->offset_y = 0;
		app->max_it = MAX_IT;
	}
	if (keycode == XK_Escape)
		destroy_window(app);
	if (keycode == XK_a)
		app->max_it += 10;
	if (keycode == XK_s && app->max_it > 0)
		app->max_it -= 10;
	if (keycode == XK_1)
		app->color = 1;
	if (keycode == XK_2)
		app->color = 2;
	if (keycode == XK_3)
		app->color = 3;
	panning_events(keycode, app);
	img_to_win(app);
	return (1);
}

int	mouse_hooks_triggers(int mousecode, int x, int y, t_window *app)
{
	if (mousecode == 4)
	{
		app->zoom *= 1.5;
		app->offset_x += ((double)x - WIDTH / 2) / WIDTH * (4 / app->zoom);
		app->offset_y += ((double)y - HEIGHT / 2) / HEIGHT * (4 / app->zoom);
	}
	if (mousecode == 5)
		app->zoom /= 1.5;
	img_to_win(app);
	return (1);
}

void	hooks(t_window *app)
{
	mlx_hook(app->win, 2, 1L, hooks_triggers, app);
	mlx_hook(app->win, 17, 0, destroy_window, app);
	mlx_mouse_hook(app->win, mouse_hooks_triggers, app);
}
