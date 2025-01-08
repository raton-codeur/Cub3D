NAME = cub3D
NAME_BONUS = cub3D_bonus
CFLAGS = -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast -fsanitize=address # revoir
INCLUDES = -I libft -I MLX42/include -I inc -I inc_bonus
LDFLAGS = -ldl -lglfw -pthread -lm -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -w # revoir
LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a
OBJS = $(patsubst src/%, tmp/%, $(SRCS:.c=.o))
OBJS_BONUS = $(patsubst src_bonus/%, tmp_bonus/%, $(SRCS_BONUS:.c=.o))
# find src -name "*.c" | awk '{printf "%s \\\n", $0}' > f | code f
SRCS = $(shell find src -name "*.c")
SRCS_BONUS = $(shell find src_bonus -name "*.c")

all : $(NAME) $(NAME_BONUS)

tmp/%.o : src/%.c
	@ mkdir -p $(dir $@)
	@ cc $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "compilation for $(NAME) : %d / %d\n" $$(find tmp -type f | wc -l) $(words $(SRCS)) # revoir

tmp_bonus/%.o : src_bonus/%.c
	@ mkdir -p $(dir $@)
	@ cc $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "compilation for $(NAME_BONUS) : %d / %d\n" $$(find tmp_bonus -type f | wc -l) $(words $(SRCS_BONUS)) # revoir

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@ cc $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ && printf "$@ created\n"

$(NAME_BONUS) : $(LIBFT) $(MLX) $(OBJS_BONUS)
	@ cc $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $@ && printf "$@ created\n"

$(LIBFT) :
	@ make --no-print-directory -C libft

$(MLX) :
	@ cmake MLX42 -B MLX42/build && make --no-print-directory -C MLX42/build -j4

clean :
	@ make clean --no-print-directory -C libft
	@ rm -rf tmp tmp_bonus
	@ printf "temporary files have been removed\n"

fclean : clean
	@ make fclean --no-print-directory -C libft
	@ rm -rf MLX42/build 
	@ rm -f $(NAME) $(NAME_BONUS)
	@ printf "libraries and executables have been removed\n"

re : fclean all

bonus : $(NAME_BONUS)

test : clean $(NAME)
	./$(NAME) ../config.cub

ttest : clean $(NAME_BONUS)
	./$(NAME_BONUS) ../config.cub

.PHONY : all clean fclean re bonus
