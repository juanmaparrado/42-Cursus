/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:31:23 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/23 11:12:18 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	i = -1;
	str = 0;
	while (s[++i])
	{
		if (s[i] == (const char)c)
			str = &s[i];
	}
	if (s[i] == (const char)c)
		str = ((char *)&s[i]);
	return ((char *)str);
}
