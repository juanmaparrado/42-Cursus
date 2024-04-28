/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:50:48 by juaparra          #+#    #+#             */
/*   Updated: 2024/04/28 14:29:11 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv, t_fractal *fractal)
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbroot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)) )
	{
		fractal->name = argv[1];
		if (argc == 4)
		{
			//ToDo
			//check_params(argv[2]);
			//check_params(argv[3]);
		}
	}
	else
	{
		//ToDo
		//definir mensaje personalizado
		msg_error();
		return(0);
	}

}