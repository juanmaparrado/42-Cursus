/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:04:45 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/28 20:18:35 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "lib/libft/libft.h"
#include "lib/MLX42/include/MLX42/MLX42.h"
#include "math.h"

#define WIDTH 800
#define HEIGHT 800
// Definición de colores en formato hexadecimal ARGB
# define BLACK       0x000000FF
# define WHITE       0xFFFFFFFF
# define RED         0xFF0000FF
# define GREEN       0x00FF00FF
# define BLUE        0x0000FFFF
# define YELLOW      0xFFFF00FF
# define MAGENTA     0xFF00FFFF
# define CYAN        0x00FFFFFF
# define ORANGE      0xFFA500FF
# define PURPLE      0x660066FF
# define GRAY        0x808080FF
# define LIGHT_GRAY  0xD3D3D3FF
# define DARK_GRAY   0xA9A9A9FF

typedef struct s_complex
{
	double real;
	double imagin;
}	t_complex;

typedef struct s_fractal
{
	char	*name;
	mlx_t	*mlx_connection; //mlx_init()
	void	*mlx_window; //mlx_new_window()
	//image
	mlx_image_t	*img;
} t_fractal;



#endif