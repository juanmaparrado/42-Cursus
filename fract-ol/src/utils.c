/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:48:41 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/29 22:04:14 by juaparra         ###   ########.fr       */
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
	ft_putstr_fd("Usage: ./fractol [mandelbrot] or \n", 2);
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
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbroot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)) )
	{
		fractal->name = argv[1];
		if (argc == 4)
		{
			check_params(argv[2]);
			check_params(argv[3]);
			fractal->julia_x = ft_atodbl(0.0,0.0, 1.0, argv[2]);
			fractal->julia_y = ft_atodbl(0.0,0.0, 1.0, argv[3]);
		}
		else
		{
			push_error();
			return (0);
		}
	}
	else
	{
		push_error();
		return(0);
	}
	return (1);
}