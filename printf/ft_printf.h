/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:50 by juaparra          #+#    #+#             */
/*   Updated: 2023/10/03 18:35:26 by juaparra         ###   ########.fr       */
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
void	ft_putnbr(int n, int *len);
void ft_unsigned_number(unsigned int n, int *len);
static void	ft_print_check(char s, va_list args, int *len);
int			ft_printf(char const *, ...)


#endif