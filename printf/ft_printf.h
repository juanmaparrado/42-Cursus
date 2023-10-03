/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:50 by juaparra          #+#    #+#             */
/*   Updated: 2023/10/03 19:47:32 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //va_list
# include <unistd.h> //write
# include <stdlib.h> //malloc
# include <stddef.h> //size_t

void	ft_putchar(char c, int *len);
void	ft_putstr(char *arg, int *len);
void	ft_putnumber(int n, int *len);
void	ft_unsigned_number(unsigned int n, int *len);
void	ft_hexadecimal(unsigned int n, int *len, char x_or_x);
void	ft_pointer(size_t pointer, int *len);

int		ft_printf(char const *str, ...);
#endif