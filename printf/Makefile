# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:06:21 by juaparra          #+#    #+#              #
#    Updated: 2023/11/23 20:56:25 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_printf.c basic.c pointers.c hexa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re