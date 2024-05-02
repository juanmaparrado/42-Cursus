/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:50:48 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/02 21:04:07 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (check_args(argc, argv, &fractal) == 0)
		return (EXIT_FAILURE);
	init_mandelbrot(&fractal);
	fractal_render(&fractal);
	mlx_key_hook(fractal.mlx_connection, &my_keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx_connection, &ft_scrollhook, &fractal);
	mlx_loop(fractal.mlx_connection);
	mlx_terminate(fractal.mlx_connection);
	return (EXIT_SUCCESS);
}