/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:21:18 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/20 11:40:26 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	if (s[i] == '\0')
		return (NULL);
}