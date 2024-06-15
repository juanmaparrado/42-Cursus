# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra <juaparra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 10:07:49 by juaparra          #+#    #+#              #
#    Updated: 2024/06/15 11:57:56 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CCC := clang -Wall -Wextra -Werror

#Libs
LIBFT := lib/libft/libft.a
FT_PRINTF := lib/printf/libftprintf.a

OBJDIR := obj

SRC = src/pipex.c src/utils.c

OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

all : $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : src/%.c | $(OBJDIR)
	@$(CCC) -c $< -o $@
	@echo "Compiled $< into $@"

$(LIBFT):
	@echo "Compiling libft.........."
	@make -s -C lib/libft
	@echo "#### libft compiled ####"

$(FT_PRINTF) : $(LIBFT)
		@echo "Compiling ft_printf.........."
	@make -s -C lib/printf
	@echo "#### ft_printf compiled ####"

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Compiling pipex....."
	@$(CCC) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "###### PIPEX COMPILED ######"

clean :
	@rm -rf $(OBJDIR)
	@echo "#### Cleaned object files ####"

fclean : clean
	@rm -f $(NAME)
	@make -s -C lib/libft fclean
	@make -s -C lib/printf fclean
	@echo "Cleaned all build "

re : fclean all

.PHONY: all clean fclean re $(LIBFT) $(FT_PRINTF)

