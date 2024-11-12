/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/12 13:55:12 by qhauuy           ###   ########.fr       */
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
# define STEP_MOVE 0.2 // le pas de déplacement du joueur en pixels
# define STEP_VIEW 0.05 // le pas de changement de l'angle de vue en radians
# define I_START 1 // l'indice de la ligne de map de départ du joueur
# define J_START 2 // l'indice de la colonne de map de départ du joueur
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
	double		pos_x; // coordonnées horizontale du joueur
	double		pos_y; // coordonnées verticale du joueur
	double		dir_x; // vecteur de direction où regarde le joueur
	double		dir_y; 
	double		plane_x; // vecteur du plan de la caméra
	double		plane_y;
	double		x; // coordonnée pour le dda
	double		y; // coordonnée pour le dda
	int			i; // coordonnée pour le dda
	int			j; // coordonnée pour le dda
	double		ray_dir_x; // vecteur de direction du rayon
	double		ray_dir_y;
	double		delta_dist_x; // la longueur du rayon entre deux cases horizontales 
	double		delta_dist_y; // la longueur du rayon entre deux cases verticales
	double		side_dist_x; // longueur du rayon entre la position du joueur et la prochaine case horizontale
	double		side_dist_y; // longueur du rayon entre la position du joueur et la prochaine case verticale
	double		perp_wall_dist; // pour calculer la longueur du rayon
	int			step_i; // la prochaine case dans laquelle va le rayon. 1 ou -1
	int			step_j; // la prochaine case dans laquelle va le rayon. 1 ou -1
	int			hit; // 1 si le rayon touche un mur, 0 sinon
	int			side; // 0 si le rayon touche un mur horizontal, 1 sinon
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);

/* utils.c */
void		fill_image(mlx_image_t *image, unsigned int color);
void		print_map(t_data *data);

#endif