/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:10:19 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/20 13:45:05 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && i < n && str1[i] == str2[i])
			i++;
	if (i == n)
		i -= 1;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
