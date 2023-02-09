/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:19:02 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/06 11:15:44 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_window *app, t_complex c)
{
	int			it;
	t_complex	z;

	it = 0;
	z = (t_complex){};
	while (it < app->max_it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (it);
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + c.r,
			.i = 2 * z.r * z.i + c.i
		};
		it++;
	}
	return (0);
}

int	julia(t_window *app, t_complex z)
{
	int			it;

	it = 0;
	while (it < app->max_it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (it);
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + app->c.r,
			.i = 2 * z.r * z.i + app->c.i
		};
		it++;
	}
	return (0);
}

int	burningship(t_window *app, t_complex c)
{
	int			it;
	t_complex	z;

	it = 0;
	z = (t_complex){};
	while (it < app->max_it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (it);
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + c.r,
			.i = 2 * z.r * z.i + c.i
		};
		it++;
	}
	return (0);
}
