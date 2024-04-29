/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:49:13 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/29 23:34:44 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if(!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->ima = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->ima = z->ima;
	}
}

void	handle_pixel(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (map(fractal->x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.ima = (map(fractal->y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	choose_fractal(&z, &c, fractal);
	while (i < fractal->iteration_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.ima * z.ima) > fractal->esc_value)
		{
			color = map(i, BLACK, GREEN, fractal->iteration_def);
			mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, fractal->x, fractal->y, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < HEIGHT)
	{
		fractal->x = 0;
		while (fractal->x < WIDTH)
		{
			handle_pixel(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_image_to_window(fractal->mlx_connection,fractal->img, 0, 0);
}