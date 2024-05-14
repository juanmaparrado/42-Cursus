/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:48:41 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/14 19:41:05 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fr_init(t_fr *fr)
{
	fr->w_size = 800;
	fr->max_iterations = 1000;
	fr->julia_x = -0.7269;
	fr->julia_y = 0.1889;
	fr->min_i = -2.0;
	fr->min_r = -2.0;
	fr->max_r = 2.0;
	fr->max_i = 2.0;
	fr->color_shift = 0;
}
