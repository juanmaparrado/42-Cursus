/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:29:42 by juaparra          #+#    #+#             */
/*   Updated: 2023/10/03 18:35:02 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnumber(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		*len += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = n * -1;
		ft_putnumber(n, len);
	}
	else
	{
		if (n > 9)
			ft_putnumber(n / 10, len);
		ft_putchar((n % 10) + '0', len);
	}
}

void ft_unsigned_number(unsigned int n, int *len)
{
	if (n > 9)
		ft_unsigned_number(n / 10, len);
	ft_putchar((n % 10) + '0', len);
}