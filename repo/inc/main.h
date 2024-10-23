/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 16:11:22 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 3500 // la largeur de la fenêtre
# define HEIGHT 1500 // hauteur de la fenêtre
# define CEIL_COLOR 0x409ec9FF
# define FLOOR_COLOR 0x8B4513FF
# define PATH_MAP "maps/simple.cub"
# define SIZE_BOX ((double)50) // la taille d'une case de la minimap
# define SIZE_PLAYER ((double)25) // la taille du joueur
# define SIZE_PLAYER_HALF (SIZE_PLAYER / 2)
# define STEP ((double)3) // le nombre de pixels qu'on parcourt sur la minimap à chaque coup
# define R_START 2 // la ligne de départ du joueur
# define C_START 2 // la colonne de départ du joueur
# define O_START 0 // l'orientation de départ du joueur
# define ANGLE_VIEW 1.04719755 // l'angle de vue en radians

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// typedef struct s_points
// {
// 	double	a_x;
// 	double	a_y;
// 	double	b_x;
// 	double	b_y;
// }	t_points;

typedef struct s_u_points
{
	unsigned int	a_x;
	unsigned int	a_y;
	unsigned int	b_x;
	unsigned int	b_y;
}	t_u_points;

typedef struct s_data
{
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*map_img;
	mlx_image_t	*player;
	mlx_image_t *rays;
	t_point		position;
	double		angle;
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);

/* esc_hook.c */
void		esc_hook(mlx_key_data_t keydata, void *param);

/* map_hook.c */
void		map_hook(void *param);

#endif