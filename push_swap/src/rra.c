/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:35:01 by juaparra          #+#    #+#             */
/*   Updated: 2024/07/16 12:35:02 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	rra(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	write(1, "rra\n", 4);
}
