/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:23:06 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/26 18:23:48 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	l;
	long	n1;

	n1 = (long)n;
	l = ft_size(n1);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!(s))
		return (NULL);
	s[l] = '\0';
	if (n1 < 0)
	{
		s[0] = '-';
		n1 *= -1;
	}
	if (n1 == 0)
		s[0] = '0';
	while (n1 > 9)
	{
		s[--l] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	if (n1 > 0)
		s[--l] = n1 + '0';
	return (s);
}
