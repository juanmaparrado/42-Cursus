NAME := fractol
CC := gcc

CFLAGS := -Wall -Wextra -Werror -g

FSANITIZE := -fsanitize=address -g3 -O3

LIBFT = lib/libft/libft.a

MLX42 = ./lib/MLX42/build/libmlx42.a

MLX42_INSTALL := mlx_install

MLX42_DIR := lib/MLX42

EXTRA := -I include -ldl -lX11 -lXext -lglfw -pthread -lm

EXTRA_MAC := -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/juaparra/.brew/opt/glfw/lib/" -Iinclude -lglfw -L"/Users/juaparra/.brew/opt/glfw/lib/"


OBJDIR := obj

OBJDIR_BONUS := obj_bonus

SRC = src/calculate_fractals.c src/chose_the_fractal.c src/colors.c src/draw_fractal.c src/fractal_init.c src/hooks.c


OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o, $(SRC))


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
	@$(CC) $(CFLAGS) -o $@ $^ src/main.c -I include -Llib/libft -lft -ldl -lX11 -lXext -lglfw -pthread -lm



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

re_bonus : fclean

norm :
	@echo "$(CYAN)Norminette src/$(GREEN)"
	@norminette src/
	@echo "$(CYAN)Norminette includes/ & bonus/includes/$(GREEN)"
	@norminette includes/
	@norminette bonus/includes/
	@echo "$(DEF_COLOR)"

$(MLX42_INSTALL) :
	@echo "$(YELLOW)INSTALLING MLX42...$(DEF_COLOR)"
	@cd $(MLX42_DIR); \
	cmake -B build; \
	make -s -C build -j4;
	@echo "$(GREEN)MLX42 INSTALLED.$(DEF_COLOR)"

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m