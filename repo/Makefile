NAME = cub3D
NAME_BONUS = cub3D_bonus
CFLAGS = -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast -fsanitize=address
INCLUDES = -I libft -I MLX42/include -I . -I inc -I inc_bonus
LDFLAGS = -ldl -lglfw -pthread -lm -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a
OBJS = $(patsubst src/%, tmp/%, $(SRCS:.c=.o))
OBJS_BONUS = $(patsubst src_bonus/%, tmp_bonus/%, $(SRCS_BONUS:.c=.o))
# find src -name "*.c" | awk '{printf "%s \\\n", $0}' > f | code f
SRCS = src/raycasting/get_pixel.c \
src/raycasting/dda.c \
src/raycasting/render_for_x.c \
src/raycasting/draw_ray.c \
src/raycasting/init_dda.c \
src/render_maps.c \
src/init_game/init_game.c \
src/init_game/init_map.c \
src/init_game/init_minimap.c \
src/init_game/init_players.c \
src/utils.c \
src/main.c \
src/free.c \
src/parsing/clean_parsing.c \
src/parsing/parsing.c \
src/parsing/find_colors_2.c \
src/parsing/find_textures.c \
src/parsing/check_map.c \
src/parsing/reverse_map.c \
src/parsing/load_map.c \
src/parsing/parsing_utils.c \
src/parsing/find_map.c \
src/parsing/find_colors.c \
src/parsing/check_map_2.c \
src/parsing/split_parsing.c \
src/parsing/parsing_utils_2.c \
src/parsing/check_map_3.c \
src/parsing/clean_map.c \
src/parsing/check_colors.c \
src/parsing/check_maze.c \
src/parsing/load_cub_file.c \
src/hook/rotate.c \
src/hook/move.c \
src/hook/key_hook.c \
src/hook/main_hook.c \
src/hook/set_depth.c
SRCS_BONUS = src_bonus/raycasting/get_pixel_bonus.c \
src_bonus/raycasting/draw_ray_bonus.c \
src_bonus/raycasting/render_for_x_bonus.c \
src_bonus/raycasting/dda_bonus.c \
src_bonus/main_bonus.c \
src_bonus/maze_bonus.c \
src_bonus/maze_utils_bonus.c \
src_bonus/doors_bonus.c \
src_bonus/render_maps_bonus.c \
src_bonus/init_game/init_game_bonus.c \
src_bonus/hook/main_hook_bonus.c \
src_bonus/hook/rotate_bonus.c \
src_bonus/hook/move_bonus.c \
src_bonus/hook/key_hook_bonus.c \
src_bonus/hook/mouse_hook_bonus.c \
src_bonus/free_bonus.c

tmp/%.o : src/%.c
	@ mkdir -p $(dir $@)
	@ cc $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "compilation for $(NAME) : %d / %d\n" $$(find tmp -type f | wc -l) $(words $(SRCS))

tmp_bonus/%.o : src_bonus/%.c
	@ mkdir -p $(dir $@)
	@ cc $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "compilation for $(NAME_BONUS) : %d / %d\n" $$(find tmp_bonus -type f | wc -l) $(words $(SRCS_BONUS))

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@ cc $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ && printf "$@ created\n"

$(NAME_BONUS) : $(LIBFT) $(MLX) $(OBJS_BONUS)
	@ cc $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $@ && printf "$@ created\n"

$(LIBFT) :
	@ make --no-print-directory -C libft

$(MLX) :
	@ cmake MLX42 -B MLX42/build && make --no-print-directory -C MLX42/build -j4

all : $(NAME) $(NAME_BONUS)

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
	@ ./$(NAME) ../maps/simple.cub

ttest : clean $(NAME_BONUS)
	@ ./$(NAME_BONUS) ../maps/simple.cub

.PHONY : all clean fclean re bonus test ttest
