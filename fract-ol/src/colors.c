/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:18:15 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/14 19:41:00 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	foo(int continuous_index)
{
	union u_colour	c;

	c.channels[0] = (unsigned char)(sin(0.016 * continuous_index + 4) * 125);
	c.channels[1] = (unsigned char)(sin(0.013 * continuous_index + 2) * 125);
	c.channels[2] = (unsigned char)(sin(0.01 * continuous_index + 1) * 125);
	c.channels[3] = 255;
	return (c.number);
}

void	color_shift(void *p)
{
	t_fr	*f;

	f = p;
	if (mlx_is_key_down(f->mlx, MLX_KEY_SPACE))
		f->color_shift++;
}
