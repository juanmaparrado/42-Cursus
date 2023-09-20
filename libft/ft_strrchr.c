/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:31:23 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/20 11:49:52 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	i = -1;
	str = 0;
	while (s[++i])
	{
		if (s[i] == (char)c)
			str = &s[i];
	}
	if (str != 0)
		return ((char *)str);
	return (NULL);
}
