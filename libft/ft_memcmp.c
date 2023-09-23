/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:38:31 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/22 19:38:31 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	unsigned int		i;

	ptr1 = (const unsigned char *)str1;
	ptr2 = (const unsigned char *)str2;
	if (len == 0)
		return (0);
	while (ptr1[i] && i < len - 1 && ptr1[i] == ptr2[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
