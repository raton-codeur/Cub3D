/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/26 19:10:01 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define W_WIDTH 2560 // 1920 // la largeur de la fenêtre
# define W_HEIGHT 1440 // 1080 // hauteur de la fenêtre
# define W_HEIGHT_2 (W_HEIGHT / 2)
# define PATH_MAP "maps/simple.cub"
# define STEP_MOVE 0.2 // le pas de déplacement du joueur en pixels
# define STEP_VIEW 0.05 // le pas de changement de l'angle de vue en radians
# define FOG_COLOR 0x505050FF
# define RAY_COLOR 0x00FF00FF
# define FOG_RATIO 0.3 // ratio de wall_height_norm à partir duquel on commence à appliquer le brouillard
# define FOG_MAX 0.2 // ratio de FOG_RATIO jusqu'auquel le brouillard est maximal
# define STEP_MAP 0.1

enum e_error
{
	DEFAULT,
	MALLOC
};

typedef struct s_data
{
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
	char			**map;
	mlx_t			*mlx;
	mlx_image_t		*background;
	mlx_image_t		*map_img;
	mlx_image_t		*minimap;
	mlx_image_t		*player_map;
	mlx_image_t		*rays_map;
	mlx_image_t		*rays_minimap;
	mlx_image_t		*walls;
	// mlx_image_t		*wall_no;
	// mlx_image_t		*wall_so;
	// mlx_image_t		*wall_we;
	// mlx_image_t		*wall_ea;
	int				map_width;
	int				map_height;
	int				depth; // 0 pour rien, 1 pour la map, 2 pour la minimap
	uint32_t		ceil_color;
	uint32_t		floor_color;
	int				box_size;
	int				i_start;
	int				j_start;
	char			dir_start;
	uint32_t		fog_height; // la hauteur du brouillard
	int				fog_state;
	double			factor; // entre 0 et 1 pour faire des dégradés
	uint32_t		y; // pour dessiner la ligne de mur
	uint32_t		r;
	uint32_t		g;
	uint32_t		b;
	double			ray_x; // pour dessiner le rayon sur la minimap
	double			ray_y; // pour dessiner le rayon sur la minimap
	double			visible_max; // la distance maximale de visibilité selon le brouillard (au carré)
	double			d; // pour la distance (au carré) du rayon dans la minimap

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
	double		hit_x; // la coordonnée horizontale du point de la case où le rayon a touché un mur
	double		hit_y; // la coordonnée verticale du point de la case où le rayon a touché un mur
	int			side; // 0 si le rayon a touché un mur horizontal, 1 si le rayon a touché un mur vertical
	double		perp_wall_dist; // la composante perpendiculaire au plan de la caméra de [ la distance entre le joueur et le point du mur touché ] (voir schéma). 
	uint32_t	wall_height; // la hauteur de la ligne de mur à dessiner sur l'écran
	double		wall_height_norm; // wall_height normalisé entre 0 et 1
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
void		erase_image(mlx_image_t *image);

/* move.c */
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

/* rotate.c */
void		rotate_right(t_data *data);
void		rotate_left(t_data *data);

/* utils.c */
void fill_image(mlx_image_t *image, uint32_t color);


#endif
