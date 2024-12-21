/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 10:45:20 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <time.h>
# include <sys/time.h>

# define STEP_MOVE 0.2
# define STEP_ROTATE_X 0.1
# define STEP_ROTATE_Y 100
# define FOG_HEIGHT 0.3
# define FOG_MAX 0.2
# define COLOR_PLAYER 0xFF0000FF
# define FOG_RED 0x50
# define FOG_GREEN 0x50
# define FOG_BLUE 0x50
# define COLOR_RAY 0x00FF00FF
# define COLOR_RAY_FOG 0x00FF0000
# define WALL_COLOR_N 0x0000FFFF
# define WALL_COLOR_S 0xFFFF00FF
# define WALL_COLOR_W 0xFF0000FF
# define WALL_COLOR_E 0x00FF00FF
# define COLOR_WALL 0x000000FF
# define COLOR_MAP 0xFFFFFFFF
# define MAP_COLOR_DOOR 0xA9A9A9FF
# define MAZE_START_I 1
# define MAZE_START_J 1
# define MAZE_DIR_START 'S'
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
	//constantes
	uint32_t		w_width;
	uint32_t		w_height;
	uint32_t		box_size;
	double			ray_dir_ratio;
	char			**map;
	uint32_t		map_width;
	uint32_t		map_height;
	uint32_t		ceil_color;
	uint32_t		floor_color;
	int				i_start;
	int				j_start;
	char			dir_start;
	uint32_t		fog_end;
	uint32_t		fog_max;
	uint32_t		fog_color;
	double			visible_max;
	uint32_t		mini_box_size;
	uint32_t		mini_w_2;
	uint32_t		mini_w_22;

	// mlx
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

	// pour le parsing
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

	// variables
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	uint32_t		x;
	uint32_t		y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				step_i;
	int				step_j;
	double			delta_dist_x;
	double			delta_dist_y;
	uint32_t		i;
	uint32_t		j;
	double			side_dist_x;
	double			side_dist_y;
	int				hit;
	double			hit_x;
	double			hit_y;
	int				side;
	double			perp_wall_dist;
	uint32_t		wall_height;
	double			fog_ratio;
	uint32_t		horizon;
	int				depth_config;
	int				fog_state;
	int				mouse_state;
	uint32_t		pixel;
	double			ray_x;
	double			ray_y;
	double			d;
	uint32_t		tex_x;
	uint32_t		tex_y;
	t_wall			*walls;
	int				wall_count;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	double			xpos;
	double			ypos;
	double			mini_base_x;
	double			mini_base_y;
	double			xd;
	double			yd;
	double			mini_xd;
	double			mini_yd;

	// pour les portes
	int				p_x;
	int				p_y;
	int				door_to_open_x;
	int				door_to_open_y;
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);
void		print_error(int code);
void		error_exit(int code, t_data *data);

/* render_map.c */
void		render_map(t_data *data);

/* render_minimap.c */
void		render_minimap(t_data *data);

/* utils.c */
void		fill_circle(mlx_image_t *image, uint32_t color);
void		erase(mlx_image_t *image);

/* maze.c */
void		generate_maze(t_data *data);

/* maze_utils.c */
void		pass_wall(t_data *data, uint32_t i, uint32_t j, int d);
void		open_path(t_data *data, t_wall w);
int			current_is_inner_unexplored(t_data *data);
void		add_walls(t_data *data, uint32_t i, uint32_t j);

/* doors.c */
void		check_doors(t_data *data, int i, int j);
void		get_closest_door(t_data *d);
void		open_door(t_data *d, mlx_key_data_t keydata);

#endif
