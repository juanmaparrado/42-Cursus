/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:04:45 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/29 23:15:37 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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

# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double real;
	double ima;
}				t_complex;

typedef struct	s_fractal
{
	//MLX
	char	*name;
	mlx_t	*mlx_connection; // mlx_init()
	void	*mlx_window; //mlx_new_window()
	//IMAGE
	mlx_image_t	*img;
	//NÚMBER BONDARIES
	void	*colors;
	double	esc_value; //hypotenuse
	int		iteration_def;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	zoom;
	double	x;
	double	y;
}			t_fractal;

//UTILS
void	data_init(t_fractal *fractal);
void	push_error(void);
void	check_params(char *str);
int		check_args(int ac, char **av, t_fractal *fractal);
void	init_mandelbrot(t_fractal *fractal);

//fractal
void	fractal_render(t_fractal *fractal);
void	handle_pixel(t_fractal *fractal);
void	choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal);

//MATHS
double		map(double n, double mew_min, double new_max, double old_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex a);
double		ft_atodbl(int i, double n, double t, char *str);

#endif