# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 12:36:54 by juaparra          #+#    #+#              #
#    Updated: 2024/07/16 12:36:55 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CCC := clang -Wall -Wextra -Werror

OBJDIR := obj

SRC = $(wildcard src/*.c)

OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

all : $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : src/%.c | $(OBJDIR)
	@$(CCC) -c $< -o $@
	@echo "Compiled $< into $@"

$(NAME): $(OBJ)
	@echo "Compiling push_swap....."
	@$(CCC) $(OBJ) -o $(NAME)
	@echo "###### push_swap compiled ######"

clean :
	@rm -rf $(OBJDIR)
	@echo "#### Cleaned object files ####"

fclean : clean
	@rm -f $(NAME)
	@echo "Cleaned all build "

re : fclean all

.PHONY: all clean fclean re $(LIBFT) $(FT_PRINTF)