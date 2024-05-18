# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 12:13:06 by juaparra          #+#    #+#              #
#    Updated: 2024/05/18 12:13:06 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME := pipex

# Compiler and flags
CCC := gcc -Wall -Wextra -Werror

# Libraries
LIBFT := lib/libft/libft.a
FT_PRINTF := lib/printf/libftprintf.a

# Directories
OBJDIR := obj
# Source files
SRC = src/pipex.c src/utils.c

# Object files
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Default target
all: $(NAME)

# Create object directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CCC) -c $< -o $@
	@echo "Compiled $< into $@"

# Build libft library
$(LIBFT):
	@echo "Compiling libft....."
	@make -s -C lib/libft
	@echo "###### LIBFT COMPILED ######"

# Build ft_printf library
$(FT_PRINTF): $(LIBFT)
	@echo "Compiling ft_printf....."
	@make -s -C lib/printf
	@echo "###### FT_PRINTF COMPILED ######"


$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Compiling pipex....."
	@$(CCC) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "###### PIPEX COMPILED ######"


clean:
	@rm -rf $(OBJDIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@make -s -C lib/libft fclean
	@make -s -C lib/printf fclean
	@echo "Cleaned all build "

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re $(LIBFT) $(FT_PRINTF)

