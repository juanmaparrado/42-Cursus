/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:34:13 by juaparra          #+#    #+#             */
/*   Updated: 2024/07/16 12:34:14 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	pb(t_list *d)
{
	int	i;

	i = d->sib;
	d->sib = d->sib + 1;
	d->sia = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	d->sb[0] = d->sa[0];
	i = 0;
	while (i <= d->sia - 1)
	{
		d->sa[i] = d->sa[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}
