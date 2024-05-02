/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:48:41 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/02 20:38:33 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->iteration_def = 60;
	fractal->zoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
}

void	push_error(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Usage: ./fractol [mandelbroot] or \n", 2);
	ft_putstr_fd("./fractol [julia] <X num> <Y num> \n", 2);
	exit(EXIT_FAILURE);
}

void	check_params(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			while(j < i)
			{
				if (str[j++] == '.')
					push_error();
			}
		}
		if (str[i] == '+' || str[i] == '-')
		{
			if (i != 0 || ft_isdigit(str[i + 1]) == 0)
				push_error();
		}
		if (ft_isdigit(str[i++]) == 0)
			push_error();
	}
}

int	check_args(int ac, char **av, t_fractal *fractal)
{
	if (ac > 1)
	{
		if (ac == 2 && !ft_strncmp(av[1], "mandelbroot", 10))
			fractal->name = av[1];
		else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		{
			check_params(av[2]);
			check_params(av[3]);
			fractal->name = av[1];
			fractal->julia_x = ft_atodbl(0.0, 0.0, 1.0, av[2]);
			fractal->julia_y = ft_atodbl(0.0, 0.0, 1.0, av[3]);
		}
		else
		{
			ft_putstr_fd("esta entrando al check args", 2);
			push_error();
			return (0);
		}
	}
	else
	{
		ft_putstr_fd("esta entrando al check args", 2);
		push_error();
		return (0);
	}
	return (1);
}

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx_connection)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
	data_init(fractal);
}