/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 12:30:17 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define STEP_MOVE 0.3
# define STEP_ROTATE_X 0.1
# define COLOR_MAP 0xFFFFFFFF
# define COLOR_WALL 0x000000FF
# define COLOR_PLAYER 0xFF0000FF
# define COLOR_RAY 0x00FF00FF

enum e_error
{
	DEFAULT,
	MALLOC,
	SIZE,
	MAZE
};

typedef struct s_data
{
	uint32_t		w_width;
	uint32_t		w_height;
	uint32_t		box_size;
	double			step_ray_map;
	double			step_ray_minimap;
	char			**map;
	uint32_t		map_width;
	uint32_t		map_height;
	uint32_t		ceil_color;
	uint32_t		floor_color;
	int				i_start;
	int				j_start;
	char			dir_start;
	uint32_t		mini_box_size;
	uint32_t		mini_half;
	uint32_t		mini_r_2;
	uint32_t		mini_ray_limit;

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
	int				depth_config;
	uint32_t		x;
	uint32_t		y;
	uint32_t		i;
	uint32_t		j;
	double			ray_x;
	double			ray_y;
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

#endif
