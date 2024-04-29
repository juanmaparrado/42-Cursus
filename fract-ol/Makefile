# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 21:34:06 by juaparra          #+#    #+#              #
#    Updated: 2024/04/29 23:42:18 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42 = lib/MLX42
LIBFT = lib/libft
SRC_DIR = src/
OBJ_DIR = obj/

DEF_COLOR = \033[0;39m
MAGENTA   = \033[35;1m
YELLOW    = \033[33;1m
GREEN     = \033[32;1m
WHITE     = \033[37;1m
RESET     = \033[0m
GRAY 	  = \033[0;90m
BLUE      = \033[34;1m
CYAN      = \033[37;1m
RED		  = \033[31;1m

SRC_FILES = utils main maths fractal

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	$(OBJ)
			@make all -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(GREEN)Compilation successful!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(BLUE)Compiling, please wait.: $(RESET)$(addsuffix .c, $(SRC_FILES))"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -frf $(OBJ_DIR)
			@make clean -C $(MLX42)
			@make all clean -C $(LIBFT)
			@echo "$(RED)Cleaning libraries MLX and LIBFT, please wait.$(RESET)"
			@echo "$(RED)Cleaning program executables, please wait.$(RESET)"

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@rm -rf $(OBJ_BONUS)
			@make fclean -C $(MLX42)
			@make fclean -C $(LIBFT)
			@echo "$(YELLOW)Cleaning libraries.$(RESET)"
			@echo "$(YELLOW)Cleaning program objects.$(RESET)"

re: fclean all
			@echo "$(MAGENTA)Program recompiled$(RESET)"

norm:
			@norminette $(SRC) $(LIBFT) $(SRC_BONUS)

.PHONY: all bonus clean fclean re norm