/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:50:48 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/13 20:55:27 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "J1", 3)) || !(ft_strncmp(argv[1], "J2", 3))
			|| !(ft_strncmp(argv[1], "J3", 3)) || !(ft_strncmp(argv[1], "M", 2))
			|| !(ft_strncmp(argv[1], "L", 2)))
			return (ft_fr(argv[1]));
		else
			ft_print_error();
	}
	else
		ft_print_error();
	return (0);
}