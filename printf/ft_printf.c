/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:12:49 by juaparra          #+#    #+#             */
/*   Updated: 2023/10/03 18:29:48 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_check(char s, va_list args, int *len)
{
	if (s == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (s == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (s == 'c')
		ft_putchar(va_arg(args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_putnumber(va_arg(args, int), len);
	else if (s == 'u')
		ft_unsigned_number(va_arg(args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

//si no es ninguno de los anteriores, se resta 1 a i para que no se pierda el caracter

int	ft_printf(char const *, ...)
{
	va_list args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_print_check(str[i], args, &len , &i);
		}
		else
		{
			ft_putchar((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}