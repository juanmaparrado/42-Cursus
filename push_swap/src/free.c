/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:33:22 by juaparra          #+#    #+#             */
/*   Updated: 2024/07/16 12:33:24 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	ft_free(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
	}
	if (d->sb)
	{
		free(d->sb);
	}
	if (d->sp)
	{
		free(d->sp);
	}
	if (d)
	{
		free(d);
	}
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_free2(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
		d->sa = NULL;
	}
	if (d->sb)
	{
		free(d->sb);
		d->sb = NULL;
	}
	if (d->sp)
	{
		free(d->sp);
		d->sp = NULL;
	}
	if (d)
	{
		free(d);
		d = NULL;
	}
	exit(0);
}
