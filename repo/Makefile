NAME = cub3D
NAME_BONUS = cub3D_bonus
CFLAGS = -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast -fsanitize=address
INCLUDES = -I libft -I MLX42/include -I inc -I .
LDFLAGS = -ldl -lglfw -pthread -lm -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a
# on peut retrouver tous les .c avec la commande : find src -name "*.c" | awk '{printf "%s \\\n", $0}'
OBJS = $(patsubst src/%, tmp/%, $(SRCS:.c=.o))
SRCS = $(shell find src -name "*.c" )
OBJS_BONUS = $(patsubst src/%, tmp/%, $(SRCS:.c=.o))
SRCS_BONUS = src/raycasting/get_pixel.c \

tmp/%.o : src/%.c
	@ mkdir -p $(dir $@)
	@ cc $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "compilation for $(NAME) : %d / %d\n" $$(find tmp -type f | wc -l) $(words $(SRCS))

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@ cc $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ && printf "$@ created\n"

$(NAME_BONUS) : $(LIBFT) $(MLX) $(OBJS_BONUS)
	@ cc $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ && printf "$@ created\n"

$(LIBFT) :
	@ make --no-print-directory -C libft

$(MLX) :
	@ cmake MLX42 -B MLX42/build && make --no-print-directory -C MLX42/build -j4

all : $(NAME) $(NAME_BONUS)

clean :
	@ make clean --no-print-directory -C libft
	@ rm -rf tmp
	@ printf "temporary files have been removed\n"

fclean : clean
	@ make fclean --no-print-directory -C libft
	@ rm -rf MLX42/build 
	@ rm -f $(NAME) $(NAME_BONUS)
	@ printf "libraries and executables have been removed\n"

re : fclean all

bonus : $(NAME_BONUS)

test : clean all
# @ ./$(NAME) maps/map_sujet.cub
# @ ./$(NAME) maps/simple.cub
	@ ./$(NAME) maps/simple2.cub

.PHONY : all clean fclean re bonus test
