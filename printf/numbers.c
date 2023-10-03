/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:29:42 by juaparra          #+#    #+#             */
/*   Updated: 2023/10/03 19:49:21 by juaparra         ###   ########.fr       */
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

void	ft_unsigned_number(unsigned int n, int *len)
{
	if (n > 9)
		ft_unsigned_number(n / 10, len);
	ft_putchar((n % 10) + '0', len);
}

void	ft_hexadecimal(unsigned int n, int *len, char x_or_x)
{
	char	*base;
	char	string[25];
	int		i;

	if (x_or_x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (n != 0)
	{
		string[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	while (i-- > 0)
		ft_putchar(string[i], len);
}

void	ft_pointer(size_t pointer, int *len)
{
	write(1, "0x", 2);
	*len += 2;
	if (pointer == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	ft_hexadecimal(pointer, len, 'x');
}
