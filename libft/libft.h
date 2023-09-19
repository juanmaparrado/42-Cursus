/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:06:57 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/16 12:06:57 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H;
# define LIBFT_H;

#include	<unistd.h>;
#include	<stdlib.h>;

 int ft_isalpha(int c);
 int ft_isdigit(int c);
 int ft_isalnum(int c);
 int ft_isascii(int c);
 int ft_isprint(int c);
 size_t ft_strlen(const char *s);

#endif