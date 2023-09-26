/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:47:02 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/26 18:37:32 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_poscmp(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		l;
	char	*str;

	i = 0;
	start = 0;
	while (s1[start] && ft_poscmp(set, s1[start]))
		start++;
	l = ft_strlen(s1);
	while (l > start && ft_poscmp(set, s1[l - 1]))
		l--;
	str = (char *)malloc(sizeof(char) * (l - start + 1));
	if (!str)
		return (NULL);
	while (start < l)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
