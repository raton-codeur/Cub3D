NAME = cub3D
FLAGS = -Wall -Werror -Wextra -I libft -I MLX42/include
LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a
OBJS = $(addprefix tmp/, $(notdir $(SRCS:.c=.o)))
SRCS = $(shell find src -name "*.c")

all : $(NAME)

tmp/%.o : src/%.c
	@ mkdir -p tmp
	@ cc $(FLAGS) -c $< -o $@ && printf "\rcompilation for $(NAME) : %d / %d" $$(ls tmp | wc -w) $(words $(SRCS))

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@ cc $(FLAGS) -lglfw $(OBJS) $(LIBFT) $(MLX) -o $@ && printf "\n$@ created\n"

$(LIBFT) :
	@ make --no-print-directory -C libft

$(MLX) :
	@ cmake MLX42 -B MLX42/build && make --no-print-directory -C MLX42/build -j4

clean :
	@ make clean --no-print-directory -C libft
	@ rm -rf tmp && printf "$(NAME) cleaned\n"

fclean : clean
	@ make fclean --no-print-directory -C libft > /dev/null && printf "libft.a deleted\n"
	@ rm -rf MLX42/build && printf "MLX deleted\n"
	@ rm -f $(NAME) $(NAME_BONUS) && printf "$(NAME) and bonus deleted\n"

re : fclean all

.PHONY : all clean fclean re bonus

test : all
	@ ./$(NAME)
