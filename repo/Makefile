NAME = cub3D
NAME_BONUS = fractol_bonus
FLAGS = -Wall -Werror -Wextra -I . -I libft -I MLX42/include
LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a
OBJS = $(addprefix tmp/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix tmp/, $(notdir $(SRCS_BONUS:.c=.o)))
SRCS = $(addprefix src/, \
	fractol.c \
	select_fractal.c \
	select_fractal_utils.c \
	set_up_fractal.c \
	get_fractal_name.c \
	display_fractal.c \
	find_color.c \
	run_sequence.c \
	set_color.c \
	set_gray.c \
	my_scroll_hook.c \
	my_key_hook.c \
	my_key_precision_hook.c \
	my_mouse_hook.c \
	my_cursor_hook.c \
	print_usage.c \
	my_key_type_hook.c \
)
SRCS_BONUS = $(addprefix src/, \
	fractol_bonus.c \
	select_fractal_bonus.c \
	select_fractal_utils.c \
	set_up_fractal.c \
	get_fractal_name_bonus.c \
	display_fractal.c \
	find_color_bonus.c \
	run_sequence.c \
	run_sequence_bonus.c \
	set_color_bonus.c \
	set_gray.c \
	my_scroll_hook.c \
	my_key_hook_bonus.c \
	my_key_precision_hook.c \
	my_arrow_key_hook_bonus.c \
	my_mouse_hook.c \
	my_cursor_hook.c \
	print_usage_bonus.c \
	my_key_type_hook_bonus.c \
)

all : $(NAME) $(NAME_BONUS)

tmp/%.o : src/%.c
	@ mkdir -p tmp
	@ cc $(FLAGS) -c $< -o $@ && printf "\rcompilation for $(NAME) : %d / (%d mandatory %d bonus %d total)" $$(ls tmp | wc -w) $(words $(SRCS)) $(words $(SRCS_BONUS)) $$(ls src | wc -w)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@ cc $(FLAGS) -lglfw $(OBJS) $(LIBFT) $(MLX) -o $@ && printf "\n$@ created\n"

$(NAME_BONUS) : $(LIBFT) $(MLX) $(OBJS_BONUS)
	@ cc $(FLAGS) -lglfw $(OBJS_BONUS) $(LIBFT) $(MLX) -o $@ && printf "\n$@ created\n"

$(LIBFT) :
	@ make --no-print-directory -C libft

$(MLX) :
	@ cmake MLX42 -B MLX42/build && make --no-print-directory -C MLX42/build -j4

clean :
	@ make clean --no-print-directory -C libft
	@ rm -rf tmp && printf "$(NAME) and bonus cleaned\n"

fclean : clean
	@ make fclean --no-print-directory -C libft > /dev/null && printf "libft.a deleted\n"
	@ rm -rf MLX42/build && printf "MLX deleted\n"
	@ rm -f $(NAME) $(NAME_BONUS) && printf "$(NAME) and bonus deleted\n"

re : fclean all

bonus : $(NAME_BONUS)

.PHONY : all clean fclean re bonus