/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:21:02 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/22 21:21:02 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*aux;
	char	*dest;
	int		i;

	i = 0;
	aux = (char *)s1;
	dest = (char *)malloc(ft_strlen(aux) + 1);
	if (dest == NULL)
		return (NULL);
	while (aux[i] != '\0')
	{
		dest[i] = aux[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
