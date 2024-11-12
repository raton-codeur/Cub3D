/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/12 11:04:19 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define W_WIDTH 3500 // la largeur de la fenêtre
# define W_HEIGHT 1500 // hauteur de la fenêtre
# define CEIL_COLOR 0x409ec9FF
# define FLOOR_COLOR 0x8B4513FF
# define PATH_MAP "maps/simple.cub"
# define SIZE_BOX 50.0 // la largeur d'une case de la minimap en pixels
# define SIZE_PLAYER (SIZE_BOX / 2) // la largeur du joueur sur la minimap en pixels
# define STEP_MOVE 5.0 // le pas de déplacement du joueur en pixels
# define STEP_VIEW 0.05 // le pas de changement de l'angle de vue en radians
# define ROW_START 2 // l'indice de la ligne de départ du joueur
# define COL_START 2 // l'indice de la colonne de départ du joueur
# define ANGLE_START 0 // l'orientation de départ du joueur en radians
# define ANGLE_VIEW (M_PI / 3) // l'angle de vue en radians
# define NB_RAYS 500 // le nombre de rayons lancés

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
	int			map_size;
	int			map_line;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*map_img;
	mlx_image_t	*player;
	mlx_image_t	*rays;
	mlx_image_t	*walls;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		x;
	double		y;
	int			i;
	int			j;
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);

/* utils.c */
void		fill_image(mlx_image_t *image, unsigned int color);
void		print_map(t_data *data);

#endif