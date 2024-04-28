/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:04:45 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/28 14:29:14 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "lib/libft/libft.h"
#include "lib/MLX42/include/MLX42/MLX42.h"
#include "math.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_complex
{
	double real;
	double imagin;
}	t_complex;

typedef struct s_fractal
{
	char	*name;
} t_fractal;



#endif