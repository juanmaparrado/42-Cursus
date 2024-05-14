# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 19:36:59 by juaparra          #+#    #+#              #
#    Updated: 2024/05/14 19:46:33 by juaparra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=	fractol
CC :=	gcc

CFLAGS :=	-Wall -Wextra -Werror

LIBFT =	lib/libft/libft.a

MLX42 =	./lib/MLX42/build/libmlx42.a

MLX42_INSTALL :=	mlx_install

MLX42_DIR :=	lib/MLX42

EXTRA_LINUX :=	-I include -ldl -lX11 -lXext -lglfw -pthread -lm

EXTRA_MAC :=	-Iinclude -lglfw -L"/Users/juaparra/.brew/opt/glfw/lib/"

OBJDIR :=	obj

SRC	=	src/calculate_fractals.c src/chose_the_fractal.c src/colors.c \
		src/draw_fractal.c src/fractal_init.c src/hooks.c


OBJ =	$(patsubst src/%.c,$(OBJDIR)/%.o, $(SRC))


$(OBJDIR)/%.o : src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@


all : $(NAME)

$(LIBFT) :
	@echo "$(YELLOW)Compiling libft...$(DEF_COLOR)"
	@make -s -C lib/libft
	@echo "$(GREEN)Libft compiled.$(DEF_COLOR)"

$(MLX42) :
	@echo "$(YELLOW)Compiling MLX42...$(DEF_COLOR)"
	@make -s -C lib/MLX42/build
	@echo "$(GREEN)MLX42 compiled.$(DEF_COLOR)"

$(NAME) : $(OBJ) $(LIBFT) $(MLX42)
	@echo "$(YELLOW)Compiling fract-ol...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ src/main.c $(EXTRA_MAC)



	@echo "$(GREEN)fractol ready.$(DEF_COLOR)"


$(OBJDIR) :
	@mkdir -p $(OBJDIR)


clean :
	@make -s clean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@echo "$(RED)Objects cleaned...$(DEF_COLOR)"

fclean : clean
	@make -s fclean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(NAME)
	@echo "$(RED)fract-ol cleaned...$(DEF_COLOR)"

re : fclean all

norm :
	@echo "$(CYAN)Norminette  src/$(GREEN)"
	@norminette -R CheckForbiddenSourceHeader src/
	@echo "$(DEF_COLOR)"

$(MLX42_INSTALL) :
	@echo "$(YELLOW)INSTALLING MLX42...$(DEF_COLOR)"
	@cd $(MLX42_DIR); \
	cmake -B build; \
	make -s -C build -j4;
	@echo "$(GREEN)MLX42 INSTALLED.$(DEF_COLOR)"
