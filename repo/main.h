/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/22 15:15:59 by jteste           ###   ########.fr       */
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
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_data
{
	char		*path_map;
	char		**cub_file;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*floor_color;
	t_color		*floor_rgb;
	char		*ceil_color;
	t_color		*ceil_rgb;
	char		**map;
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

/* find_colors.c */
bool		find_colors(t_data *data, int i, int j);

/* parsing_utils.c */
int			skip_spaces(char *str, int i, int len);

#endif