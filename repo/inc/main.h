/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 23:42:10 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <sys/time.h>
# include <time.h>

# define STEP_MOVE 0.2 // 0.5 // le ratio de dir utilisé pour déplacer le joueur
# define STEP_ROTATE_X 0.1 // 0.05 // l'angle (en radians) utilisé pour changer l'angle de vue horizontal avec les touches gauche droite
# define STEP_ROTATE_Y 100 // valeur d'incrémentation de la hauteur du regard pour les touches haut bas
# define FOG_HEIGHT 0.3 // le ratio de la hauteur de la fenêtre pour lequel un mur comporte du brouillard
# define FOG_MAX 0.2 // le ratio de la hauteur du brouillard pour lequel le brouillard est maximal
# define PLAYER_COLOR 0xFF0000FF
# define FOG_RED 0x50
# define FOG_GREEN 0x50
# define FOG_BLUE 0x50
# define RAY_COLOR 0x00FF00FF
# define RAY_COLOR_FOG 0x00FF0000
# define WALL_COLOR_N 0x0000FFFF
# define WALL_COLOR_S 0xFFFF00FF
# define WALL_COLOR_W 0xFF0000FF
# define WALL_COLOR_E 0x00FF00FF
# define MAP_COLOR_WALL 0x000000FF
# define MAP_COLOR_BG 0xFFFFFFFF
# define MAP_COLOR_DOOR 0xA9A9A9FF
# define MAZE_START_I 1
# define MAZE_START_J 1
# define MAZE_DIR_START 'S'
# define MAZE_MAX 50

# define NORTH_PATH "textures/no.png"
# define SOUTH_PATH "textures/so.png"
# define WEST_PATH "textures/we.png"
# define EAST_PATH "textures/ea.png"

enum e_error
{
	DEFAULT,
	MALLOC,
	SIZE,
	MAZE
};

// un mur c'est les coordonnées d'une case + une direction
typedef struct s_maze_cell
{
	uint32_t	i;
	uint32_t	j;
	int			d;
}	t_wall;

typedef struct s_data
{
	//constantes
	uint32_t		w_width; // la largeur de la fenetre en pixels
	uint32_t		w_height; // la hauteur de la fenetre en pixels
	uint32_t		box_size; // la taille (en pixels) d'un côté d'une case de la map
	double			ray_dir_ratio; // le ratio du ray dir utilisé pour avancer le tracer du rayon dans la minimap
	char			**map; // la map sous forme d'un tableau de colonnes
	uint32_t		map_width; // la largeur de la map (en cases)
	uint32_t		map_height; // la hauteur de la map (en cases)
	uint32_t		ceil_color; // la couleur du plafond
	uint32_t		floor_color; // la couleur du sol
	int				i_start; // la coordonnée horizontale de départ du joueur
	int				j_start; // la coordonnée verticale de départ du joueur
	char			dir_start; // la direction de départ du joueur. 'N', 'S', 'W' ou 'E'
	uint32_t		fog_end; // la hauteur du brouillard
	uint32_t		fog_max; // la hauteur du brouillard maximal
	uint32_t		fog_color; // la couleur du brouillard
	double			visible_max; // la distance maximale de visibilité (selon FOG_HEIGHT et FOG_MAX) (au carré)

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
	double			xpos; // la position horizontale de la souris
	double			ypos; // la position verticale de la souris

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
	double			pos_x; // coordonnée horizontale du joueur
	double			pos_y; // coordonnée verticale du joueur
	double			dir_x; // vecteur de direction où regarde le joueur
	double			dir_y; // vecteur de direction où regarde le joueur
	double			plane_x; // vecteur du plan de la caméra. toujours perpendiculaire à dir
	double			plane_y; // vecteur du plan de la caméra. toujours perpendiculaire à dir
	uint32_t		x; // l'indice de la colonne de pixels de l'écran où on dessine la ligne de mur
	uint32_t		y; // l'indice de la ligne de pixels de l'écran où on dessine la ligne de mur
	double			camera_x; // de -1 à 1 selon x. c'est pour calculer ray_dir à partir de dir et plane
	double			ray_dir_x; // vecteur de direction du rayon qu'on lance depuis le joueur (voir schéma)
	double			ray_dir_y; // vecteur de direction du rayon qu'on lance depuis le joueur (voir schéma)
	int				step_i; // 1 si ray_dir_x est positif, -1 sinon. ça donne le sens de direction du rayon quand il doit se déplacer horizontalement
	int				step_j; // pareil que step i mais pour le déplacement vertical
	double			delta_dist_x; // la longueur du rayon entre deux cases horizontales (à un facteur près car c'est le ratio avec delta_dist y qui compte. ce facteur est la longueur de ray_dir)
	double			delta_dist_y; // pareil que delta_dist_x mais pour les cases verticales
	uint32_t		i; // coordonnée horizontale de la case couramment visitée par le rayon. on commence évidemment par la case de pos_x
	uint32_t		j; // coordonnée verticale de la case couramment visitée par le rayon. on commence évidemment par la case de pos_y
	double			side_dist_x; // initialement, c'est la longueur du rayon entre le joueur et le mur horizontal le plus proche (toujours à un facteur près, car c'est le ratio avec side dist y qui compte. ce facteur est ray_dir). à chaque tour, si side_dist_x < side_dist_y, le rayon doit avancer horizontalement (selon step i). on incrémente alors side_dist_x de delta_dist_x
	double			side_dist_y; // pareil que side_dist_x mais pour les murs verticaux
	int				hit; // 0 de base. passe à 1 quand on tombe sur un mur
	double			hit_x; // la coordonnée horizontale du point de la case où le rayon a touché un mur
	double			hit_y; // la coordonnée verticale du point de la case où le rayon a touché un mur
	int				side; // 0 si le rayon a touché un mur horizontal, 1 si le rayon a touché un mur vertical
	double			perp_wall_dist; // la composante perpendiculaire au plan de la caméra de [ la distance entre le joueur et le point du mur touché ] (voir schéma). 
	uint32_t		true_wall_height; // la hauteur de la ligne de mur qu'on devrait dessiner sur un écran infini
	uint32_t		wall_height; // la hauteur de la ligne de mur à dessiner sur l'écran
	double			fog_ratio; // la proportion de brouillard selon wall_height. entre 0 et 1
	uint32_t		horizon; // l'indice selon y de l'horizon sur l'écran
	int				depth_config; // 0 pour rien, 1 pour la map, 2 pour la minimap
	int				fog_state; // 1 si on active le brouillard, 0 sinon
	int				mouse_state; // 0 de base, 1 pour le mode interactif
	uint32_t		pixel; // la couleur du pixel à dessiner
	double			ray_x; // pour dessiner le rayon sur la minimap
	double			ray_y; // pour dessiner le rayon sur la minimap
	double			d; // pour la distance (au carré) du rayon dans la minimap
	uint32_t		tex_x; // l'indice de la bande de pixels de la texture à afficher
	uint32_t		tex_y; // l'indice en y d'un pixels de texture
	t_wall			*walls; // la pile des murs pour construire le labyrinthe
	int				wall_count; // pour se déplacer dans walls
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;

	double xd;
	double yd;
	uint32_t mini_w_2;
	double mini_step;
	double mini_x;
	double mini_y;
	double mini_dir_x;
	double mini_dir_y;
	double mini_plane_x;
	double mini_plane_y;
	uint32_t	mini_ray_x;
	uint32_t	mini_ray_y;
	double mini_ray_dir_x;
	double mini_ray_dir_y;
	


	int				src_x;
	int				src_y;
	float			rel_x;
	float			rel_y;
	float			rotated_x;
	float			rotated_y;
	float			mini_center_x;
	float			mini_center_y;
	float			theta;
	float			cos_theta;
	float			sin_theta;

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

/* utils.c */
void		fill_image(mlx_image_t *image, uint32_t color);
void		fill_image_circle(mlx_image_t *image, uint32_t color);
void		erase_image(mlx_image_t *image);
void		print_map(t_data *data);
mlx_image_t	*get_img_from_png(t_data *data, const char *file);
// uint32_t	get_pixel(mlx_texture_t *t, uint32_t x, uint32_t y);
// uint32_t	get_pixel(mlx_image_t *img, uint32_t x, uint32_t y);
long long	get_absolute_timestamp(void);
long long	get_timestamp(t_data *data);
uint32_t	get_rgb(mlx_image_t *img, uint32_t x, uint32_t y);
void		mlx_put_pixel_rgb(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t rgb);
// uint32_t	get_color(t_data *data, uint32_t x, uint32_t y);

/* maze.c */
void		generate_maze(t_data *data);

/* maze_utils.c */
void		pass_wall(t_data *data, uint32_t i, uint32_t j, int d);
void		open_path(t_data *data, t_wall w);
int			current_is_inner_unexplored(t_data *data);
void		add_walls(t_data *data, uint32_t i, uint32_t j);

/* draw_minimap.c */
// void		draw_minimap(t_data *data);

/* mini_map.c */
// void		fill_mini_player(t_data *data, int x, int y);
// void		draw_mini_map(t_data *data);

// /* minimap_rays.c */
// void		copy_map_rays(t_data *d, int start_x, int start_y, uint32_t i);
// void		render_rotated_rays(t_data *d, uint32_t i, uint32_t j);

// /* rotate_rays.c */
// void		render_rotated_rays(t_data *d, uint32_t i, uint32_t j);

// /* rotate_minimap.c */
// void		render_rotated_minimap(t_data *d, uint32_t i, uint32_t j);

/* doors.c */
void		check_doors(t_data *data, int i, int j);
void		get_closest_door(t_data *d);
void		open_door(t_data *d, mlx_key_data_t keydata);


#endif
