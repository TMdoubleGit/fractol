/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:25:22 by tmichel-          #+#    #+#             */
/*   Updated: 2023/06/28 20:33:46 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_args(t_window *app, int ac, char **av)
{
	int	i;

	if (ac == 2)
		i = init_window(app, av, 0, 0);
	if (ac == 3)
		i = init_window(app, av, ft_atof(av[2]), 0);
	if (ac == 4)
		i = init_window(app, av, ft_atof(av[2]), ft_atof(av[3]));
	if (i == 0)
	{
		ft_printf("Error while initializing MLX App");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_window	app;

	if (ac < 2)
	{
		ft_printf("You can pick Mandelbrot or Julia.");
		exit(0);
	}
	if (!ft_strncmp(av[1], "Mandelbrot", 12) || !ft_strncmp(av[1], "Julia", 12)
		|| !ft_strncmp(av[1], "Burningship", 12))
	{
		parse_args(&app, ac, av);
		hooks(&app);
		img_to_win(&app);
		mlx_loop(app.mlx);
	}
	else
	{
		ft_printf("You can pick Mandelbrot, Julia or Burningship.");
		exit(0);
	}
	return (1);
}
