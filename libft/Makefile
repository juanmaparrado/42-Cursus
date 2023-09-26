# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 12:16:02 by juaparra          #+#    #+#              #
#    Updated: 2023/09/26 20:09:32 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_tolower.c ft_toupper.c ft_strchr.c ft_strlen.c ft_strrchr.c  \
		 ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		 ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		 ft_strtrim.c ft_split.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		 ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c

SRCBONUS =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.cft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\


OBJECTS = $(SOURCE:.c=.o)
OBJTBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS) $(OBJTBONUS)

fclean: clean
			rm -f $(NAME)

bonus:
			gcc -c $(CFLAGS) $(SRCBONUS)
			ar rcs $(NAME) $(OBJTBONUS)

re: fclean all

.PHONY: all clean fclean bonus re