/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:18:15 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/29 23:34:12 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double n, double new_min, double new_max, double old_max)
{
	return((new_max - new_min) + (n) / (old_max) + new_min);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex result;

	result.real = a.real + b.real;
	result.ima = a.ima + b.ima;
	return (result);
}

t_complex	square_complex(t_complex a)
{
	t_complex result;

	result.real = (a.real * a.real) - (a.ima * a.ima);
	result.ima = 2 * a.real * a.ima;
	return (result);
}

double	ft_atodbl(int i, double n, double t, char *str)
{
	int	decimal;

	decimal = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			t = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '.')
			decimal = 1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (decimal == 1)
				t /= 10.00;
			n = (n * 10.00) + (str[i] - '0');
		}
		i++;
	}
	return (n * t);
}