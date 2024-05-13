/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:04:45 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/13 20:56:17 by juaparra         ###   ########.fr       */
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

typedef struct s_fr
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	double			n;
	double			w_size;
	long long		max_iterations;
	double			a_real;
	double			b_img;
	double			julia_x;
	double			julia_y;

	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			color_shift;
	char			type;

}					t_fr;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				tp;
}					t_color;

union				u_colour
{
	unsigned int	number;
	unsigned char	channels[4];
};

void				draw_julia(void *p);
void				draw_mandelbrot(void *p);
void				draw_mandelbox(void *p);
void				fr_init(t_fr *fr);
void				ft_error(void);
void				ft_print_error(void);
int32_t				ft_fr(char *set);
void				ft_print_error(void);
void				draw_leaf(void *p);
void				fr_chose(char *set, t_fr *fr);

int					calculate_mandelbrot(t_fr *f, int x, int y);
int					calculate_julia(t_fr *f);
int32_t				ft_fr(char *set);

// colors
int					foo(int continuous_index);
void				color_shift(void *p);

// hooks
void				hook(void *ptr);
void				scrollfunc(double xdelta, double ydelta, void *param);

void				move_julia(void *ptr);

#endif