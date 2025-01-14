/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2025/01/14 14:57:30 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <time.h>
# include <sys/time.h>

# define STEP_MOVE 0.29
# define STEP_ROTATE_X 0.1
# define STEP_ROTATE_Y 60
# define FOG_HEIGHT 0.3
# define FOG_MAX 0.2
# define COLOR_MAP 0xFFFFFFFF
# define COLOR_WALL 0x000000FF
# define COLOR_PLAYER 0xFF0000FF
# define COLOR_RAY 0x00FF00FF
# define COLOR_RAY_FOG 0x00FF0000
# define FOG_RED 0x50
# define FOG_GREEN 0x50
# define FOG_BLUE 0x50
# define COLOR_WALL 0x000000FF
# define COLOR_MAP 0xFFFFFFFF
# define COLOR_DOOR 0x7D7D7DFF
# define COLOR_END 0xFF0000FF
# define MAZE_START_I 1
# define MAZE_START_J 1
# define MAZE_DIR_START 'N'
# define MAZE_MAX 50

enum e_error
{
	DEFAULT,
	MALLOC,
	SIZE,
	MAZE
};

typedef struct s_maze_cell
{
	uint32_t	i;
	uint32_t	j;
	int			d;
}	t_wall;

typedef struct s_data
{
	char			**map;
	uint32_t		map_width;
	uint32_t		map_height;
	uint32_t		ceil_color;
	uint32_t		floor_color;
	int				i_start;
	int				j_start;
	char			dir_start;
	uint32_t		w_width;
	uint32_t		w_height;
	uint32_t		box_size;
	uint32_t		mini_box_size;
	uint32_t		mini_half;
	uint32_t		mini_r_2;
	uint32_t		mini_ray_limit;
	double			step_ray_map;
	double			step_ray_minimap;
	uint32_t		fog_end;
	uint32_t		fog_max;
	uint32_t		fog_color;
	double			visible_max;

	mlx_t			*mlx;
	mlx_image_t		*background;
	mlx_image_t		*game;
	mlx_image_t		*map_img;
	mlx_image_t		*map_rays;
	mlx_image_t		*map_player;
	mlx_image_t		*minimap;
	mlx_image_t		*minimap_player;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*tex;

	char			*path_map;
	char			**cub_file;
	char			*north_texture;
	int				north_texture_line;
	char			*south_texture;
	int				south_texture_line;
	char			*west_texture;
	int				west_texture_line;
	char			*east_texture;
	int				east_texture_line;
	char			*floor_color_str;
	int				floor_color_line;
	char			*ceil_color_str;
	int				ceil_color_line;
	int				map_line;

	char			*maze_str;
	int				maze_line;
	t_wall			*walls;
	int				wall_count;

	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				step_i;
	int				step_j;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				hit;
	double			hit_x;
	double			hit_y;
	int				side;
	double			perp_wall_dist;
	uint32_t		wall_height;
	uint32_t		tex_x;
	uint32_t		tex_y;
	double			fog_ratio;
	uint32_t		horizon;
	int				depth_config;
	int				fog_state;
	int				mouse_state;
	uint32_t		x;
	uint32_t		y;
	uint32_t		i;
	uint32_t		j;
	double			ray_x;
	double			ray_y;
	double			ray_length;
	uint32_t		pixel;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	double			mini_base_x;
	double			mini_base_y;
	double			xd;
	double			yd;
	double			mini_xd;
	double			mini_yd;
	double			new_pos;
	double			time;
	double			xpos;
	double			ypos;

	int				p_x;
	int				p_y;
	int				door_to_open_x;
	int				door_to_open_y;
	mlx_texture_t	*door;

	mlx_image_t		*sprite;
	t_list			*sprite_frames;
	t_list			*current_frame;
	int				frame_index;
	int				total_frames;
	int				frame_delay;
	int				last_update;
	int				animation_active;
}	t_data;

/* free_bonus.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);
void		print_error(int code);
void		error_exit(int code, t_data *data);

/* free2.c */
void		clear_sprite(t_data *data, t_list **list);

/* render_maps_bonus.c */
void		render_map(t_data *data);
void		render_minimap(t_data *data);

/* utils_bonus.c */
void		fill_circle(mlx_image_t *image, uint32_t color);
void		erase(mlx_image_t *image);
mlx_image_t	*get_img_from_png(t_data *data, const char *file);

/* maze_bonus.c */
void		generate_maze(t_data *data);

/* maze_utils_bonus.c */
void		pass_wall(t_data *data, uint32_t i, uint32_t j, int d);
void		open_path(t_data *data, t_wall w);
int			current_is_inner_unexplored(t_data *data);
void		add_walls(t_data *data, uint32_t i, uint32_t j);

/* doors_bonus.c */
void		check_doors(t_data *data, int i, int j);
void		get_closest_door(t_data *d);
void		open_door(t_data *d, mlx_key_data_t keydata);

/*sprite_bonus.c*/
void		init_sprite(t_data *data);
void		shot_with_gun(t_data *data, mlx_key_data_t keydata);
void		play_animation(t_data *data);

/*sprite2_bonus.c*/
double		get_time_in_ms(void);

#endif
