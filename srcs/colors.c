/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:51:43 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/06 11:22:34 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_colors(int it, int max_it, int shift)
{
	double	t;
	t_color	color;

	t = (double)it / max_it;
	color = (t_color){
		.r = 9 * (1 - t) * t * t * t * 255,
		.g = 15 * (1 - t) * (1 - t) * t * t * 255,
		.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255};
	if (shift == 2)
	{
		color = (t_color){
			.g = 9 * (1 - t) * t * t * t * 255, .b = 15 * (1 - t) * (1 - t)
			* t * t * 255, .r = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255};
	}
	if (shift == 3)
	{
		color = (t_color){
			.b = 9 * (1 - t) * t * t * t * 255, .r = 15 * (1 - t) * (1 - t)
			* t * t * 255, .g = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255};
	}
	return (color.hex);
}
