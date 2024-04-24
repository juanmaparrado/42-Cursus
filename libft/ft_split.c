/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:50:10 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/29 16:54:29 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			count++;
	}
	return (count);
}

/*static void	delete(char **s)
{
	while (*s)
		free(s++);
	free(s);

}*/

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	str = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && (*s != c))
			{
				++len;
				++s;
			}
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	str[i] = 0;
	return (str);
}
