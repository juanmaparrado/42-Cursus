/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:01:23 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/02 21:01:28 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	(void)keydata;
	if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx_connection);
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_KP_ADD))
		fractal->iteration_def += 10;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_KP_SUBTRACT))
		fractal->iteration_def -= 10;
	fractal_render(fractal);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	xdelta = 0;
	if (ydelta > 0)
		fractal->zoom *= 1.05;
	else if (ydelta < 0)
		fractal->zoom /= 1.05;
	fractal_render(fractal);
}