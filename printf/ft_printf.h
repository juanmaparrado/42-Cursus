/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:50 by juaparra          #+#    #+#             */
/*   Updated: 2023/11/23 20:57:10 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //va_list
# include <unistd.h>

int	ft_print_char(int c);
int	ft_printf(const char *str, ...);
int	ft_print_string(char *str);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_hexadecimal(unsigned int num, const char word);

#endif