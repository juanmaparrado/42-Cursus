/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:01:05 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/22 19:01:05 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < len)
		i++;
	while (src[j] && (i + j + 1) < len)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < len)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
