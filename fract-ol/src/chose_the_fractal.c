/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_the_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:44:17 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/14 19:40:05 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_leaf(void *p);

void	chose_julia(t_fr *fr, char *set)
{
	if (set[1] == '1')
	{
		fr->julia_x = 0.285;
		fr->julia_y = 0.01;
	}
	else if (set[1] == '2')
	{
		fr->julia_x = 0.0;
		fr->julia_y = 0.8;
	}
	else if (set[1] == '3')
	{
		fr->julia_x = -0.8;
		fr->julia_y = 0.156;
	}
	fr->type = 'J';
	mlx_loop_hook(fr->mlx, draw_julia, fr);
}

void	fr_chose(char *set, t_fr *fr)
{
	if (set[0] == 'J')
	{
		chose_julia(fr, set);
	}
	else if (set[0] == 'M')
	{
		fr->type = 'M';
		mlx_loop_hook(fr->mlx, draw_mandelbrot, fr);
	}
	else if (set[0] == 'L')
	{
		fr->type = 'L';
		mlx_loop_hook(fr->mlx, draw_leaf, fr);
	}
}

int	ft_fr(char *set)
{
	t_fr	*fr;

	(void)set;
	fr = malloc(sizeof(t_fr));
	fr_init(fr);
	fr->mlx = mlx_init(fr->w_size, fr->w_size, "Fract", true);
	if (!fr->mlx)
		return (EXIT_FAILURE);
	fr->img = mlx_new_image(fr->mlx, fr->w_size, fr->w_size);
	if (!fr->img || (mlx_image_to_window(fr->mlx, fr->img, 0, 0) < 0))
		return (EXIT_FAILURE);
	mlx_loop_hook(fr->mlx, hook, fr);
	fr_chose(set, fr);
	mlx_scroll_hook(fr->mlx, scrollfunc, fr);
	mlx_loop_hook(fr->mlx, color_shift, fr);
	mlx_loop_hook(fr->mlx, move_julia, fr);
	mlx_loop(fr->mlx);
	mlx_delete_image(fr->mlx, fr->img);
	mlx_close_window(fr->mlx);
	mlx_terminate(fr->mlx);
	free(fr);
	return (EXIT_SUCCESS);
}

void	ft_print_error(void)
{
	ft_putstr_fd("\nWrong input!\n", 2);
	ft_putstr_fd("\n===== Available fr Sets =====\n\n", 2);
	ft_putstr_fd("Type M to display Mandelbrot set\n", 2);
	ft_putstr_fd("Type J1, J2 or J3 to display Julia set\n", 2);
	ft_putstr_fd("Type B to display Mandelbox set\n", 2);
	ft_putstr_fd("Type L to display Leave :)\n\n", 2);
	ft_putstr_fd("===== Additional features ======\n\n", 2);
	ft_putstr_fd("Z, X, C and V: change Julia set parameters\n", 2);
	ft_putstr_fd("SPACE KEY: color shift\n", 2);
	ft_putstr_fd("ARROWS KEYS: move the view\n", 2);
	ft_putstr_fd("MOUSE SCROLL: zoom in and out\n\n", 2);
}
