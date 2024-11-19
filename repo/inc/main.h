/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/19 14:34:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define W_WIDTH 2560 // 1920 // la largeur de la fenêtre
# define W_HEIGHT 1440 // 1080 // hauteur de la fenêtre
# define CEIL_COLOR 0x87CEEBFF
# define FLOOR_COLOR 0x707070FF
# define PATH_MAP "maps/simple.cub"
# define SIZE_BOX 50.0 // la largeur d'une case de la minimap en pixels
# define SIZE_PLAYER (SIZE_BOX / 2) // la largeur du joueur sur la minimap en pixels
# define STEP_MOVE 0.2 // le pas de déplacement du joueur en pixels
# define STEP_VIEW 0.05 // le pas de changement de l'angle de vue en radians
# define I_START 2
# define J_START 3

enum e_error
{
	DEFAULT,
	MALLOC
};

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	uint32_t		hex;
}	t_color;

typedef struct s_data
{
	// char		*path_map;
	// char		**cub_file;
	// char		*north_texture;
	// int			north_texture_line;
	// char		*south_texture;
	// int			south_texture_line;
	// char		*west_texture;
	// int			west_texture_line;
	// char		*east_texture;
	// int			east_texture_line;
	// char		*floor_color_str;
	// int			floor_color_line;
	// t_color		*floor_rgb;
	// char		*ceil_color_str;
	// int			ceil_color_line;
	// t_color		*ceil_rgb;
	// int			map_size;
	// int			map_line;
	
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
	t_color			*floor_rgb;
	char			*ceil_color_str;
	int				ceil_color_line;
	t_color			*ceil_rgb;
	int				map_size;
	int				map_max_row;
	int				map_line;
	char			**map;

	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*map_img;
	mlx_image_t	*player;
	mlx_image_t	*rays;
	mlx_image_t	*walls;
	mlx_image_t	*wall;
	int			map_width;
	int			map_height;
	int			show_map;
	uint32_t	ceil_color;
	uint32_t	floor_color;
	int			box_size;
	int			i_start;
	int			j_start;
	char		dir_start;

	// (voir schéma)
	double		pos_x; // coordonnée horizontale du joueur
	double		pos_y; // coordonnée verticale du joueur
	double		dir_x; // vecteur de direction où regarde le joueur
	double		dir_y;
	double		plane_x; // vecteur du plan de la caméra. toujours perpendiculaire à dir
	double		plane_y;

	// dda :

	// constant pour un rayon :
	uint32_t	x; // l'indice de la colonne de pixels de l'écran où on dessine la ligne de mur
	double		camera_x; // de -1 à 1 selon x. c'est pour calculer ray_dir à partir de dir et plane
	double		ray_dir_x; // vecteur de direction du rayon qu'on lance depuis le joueur (voir schéma)
	double		ray_dir_y;
	int			step_i; // 1 si ray_dir_x est positif, -1 sinon. ça donne le sens de direction du rayon quand il doit se déplacer horizontalement
	int			step_j; // pareil que step i mais pour le déplacement vertical
	double		delta_dist_x; // la longueur du rayon entre deux cases horizontales (à un facteur près car c'est le ratio avec delta_dist y qui compte. ce facteur est la longueur de ray_dir)
	double		delta_dist_y; // pareil que delta_dist_x mais pour les cases verticales

	// variable 
	int			i; // coordonnée horizontale de la case couramment visitée par le rayon. on commence évidemment par la case de pos_x
	int			j; // coordonnée verticale de la case couramment visitée par le rayon. on commence évidemment par la case de pos_y
	double		side_dist_x; // initialement, c'est la longueur du rayon entre le joueur et le mur horizontal le plus proche (toujours à un facteur près, car c'est le ratio avec side dist y qui compte. ce facteur est ray_dir). à chaque tour, si side_dist_x < side_dist_y, le rayon doit avancer horizontalement (selon step i). on incrémente alors side_dist_x de delta_dist_x
	double		side_dist_y; // pareil que side_dist_x mais pour les murs verticaux

	// fin de boucle 
	int			hit; // 0 de base. passe à 1 quand on tombe sur un mur
	int			side; // 0 si le rayon a touché un mur horizontal, 1 si le rayon a touché un mur vertical
	double		perp_wall_dist; // la composante perpendiculaire au plan de la caméra de [ la distance entre le joueur et le point du mur touché ] (voir schéma). 
	int			line_height; // la hauteur de la ligne de mur à dessiner sur l'écran
	uint32_t	y; // pour dessiner la ligne de mur
	uint32_t	y_start; // la coordonnée du point de départ de la ligne à dessiner sur l'écran
	uint32_t	y_end; // la coordonnée du point d'arrivée de la ligne à dessiner sur l'écran
	uint32_t	color; // la couleur de la ligne de mur
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);
void		print_error(int code);
void		error_exit(int code, t_data *data);

/* hook.c */
void		key_hook(mlx_key_data_t keydata, void *param);
void		main_hook(void *param);

/* move.c */
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

/* rotate.c */
void		rotate_right(t_data *data);
void		rotate_left(t_data *data);

#endif
