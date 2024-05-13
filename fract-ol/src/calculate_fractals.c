/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:45:38 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/13 20:45:50 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_julia(t_fr *f)
{
	int		i;
	double	tmp;

	i = 0;
	while (i <= f->max_iterations)
	{
		if ((f->b_img * f->b_img + f->a_real * f->a_real) > 4.0)
			break ;
		tmp = 2 * f->a_real * f->b_img + f->julia_y;
		f->a_real = f->a_real * f->a_real - f->b_img * f->b_img + f->julia_x;
		f->b_img = tmp;
		i++;
	}
	return (i);
}

int	calculate_mandelbrot(t_fr *f, int x, int y)
{
	int		i;
	double	tmp;
	double	mr;
	double	mi;

	i = 0;
	mr = f->min_r + (double)x * (f->max_r - f->min_r) / f->w_size;
	mi = f->max_i + (double)y * (f->min_i - f->max_i) / f->w_size;
	f->a_real = 0;
	f->b_img = 0;
	while (i <= f->max_iterations)
	{
		if ((f->b_img * f->b_img + f->a_real * f->a_real) > 4.0)
			break ;
		tmp = 2 * f->a_real * f->b_img + mi;
		f->a_real = f->a_real * f->a_real - f->b_img * f->b_img + mr;
		f->b_img = tmp;
		i++;
	}
	return (i);
}