/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:47:39 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/22 20:07:06 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char *)big);
	if (big[0] == '\0')
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == lit[j] &6 i + j < len)
		{
			if (lit[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (lit[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}