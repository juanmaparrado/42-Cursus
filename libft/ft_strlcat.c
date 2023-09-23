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
	if (!len)
		return (ft_strlen(dest) + len);
	while (dest[i] && i < len)
		i++;
	j = i;
	while (src[i - j] && i < len - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (i < len)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
