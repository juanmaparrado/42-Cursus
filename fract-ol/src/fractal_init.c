/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:48:41 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/13 20:42:40 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fr_init(t_fr *fr)
{
	fr->w_size = 400;
	fr->max_iterations = 1000;
	fr->julia_x = -0.7269;
	fr->julia_y = 0.1889;
	fr->min_i = -2.0;
	fr->min_r = -2.0;
	fr->max_r = 2.0;
	fr->max_i = 2.0;
	fr->color_shift = 0;
}