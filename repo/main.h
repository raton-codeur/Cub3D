/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/06 12:32:28 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1920 // la largeur de la fenêtre
# define HEIGHT 1080 // hauteur de la fenêtre
# define CEIL_COLOR 0x409ec9FF
# define FLOOR_COLOR 0x8B4513FF
# define PATH_MAP "maps/simple.cub"
# define SIZE_BOX 50 // la taille d'une case de la minimap

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	unsigned int	hex;
}	t_color;

typedef struct s_data
{
	char		*path_map;
	char		**cub_file;
	char		*north_texture;
	int			north_texture_line;
	char		*south_texture;
	int			south_texture_line;
	char		*west_texture;
	int			west_texture_line;
	char		*east_texture;
	int			east_texture_line;
	char		*floor_color;
	int			floor_color_line;
	t_color		*floor_rgb;
	char		*ceil_color;
	int			ceil_color_line;
	t_color		*ceil_rgb;
	char		**map;
	int			map_line;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*map_img;
	mlx_image_t	*player;
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);

/* init.c */
void		init(t_data *data, int argc, char **argv);

/* load_map.c */
void		load_map(t_data *data);

/* init_map.c */
void		init_map(t_data *data);
int			get_row_size(char *row);

/* esc_hook.c */
void		esc_hook(mlx_key_data_t keydata, void *param);

/* print_map.c */
void		print_map(t_data *data);

/* player_hook.c */
void		player_hook(void *param);

/////////////////PARSING////////////////////

/* parsing.c */
bool		parser(t_data *data);

/* load_cub_file.c */
bool		load_cub_file(t_data *data);

/* find_textures.c */
bool		find_textures(t_data *data, int i, int j);
bool		copy_texture(t_data *data, char **dest, int i, int j);
bool		check_textures(t_data *data);

/* find_colors.c */
bool				find_colors(t_data *data, int i, int j);
bool				fill_rgb_colors(t_data *data);
unsigned int		rgb_color_to_hex(t_color *color);

/* find_map.c */
bool		find_map(t_data *data, int i, int j);
bool		remove_newline_from_map(t_data *data);

/* parsing_utils.c */
int			skip_spaces(char *str, int i, int len);
bool		extension_checker(char *path);
bool		check_split_content(char **split);
bool		check_split_content_size(char **split);
char		*remove_newline(char *str);

/* parsing_utils_2.c */
bool		check_cub_order(t_data *data);

#endif