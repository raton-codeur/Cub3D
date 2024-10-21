/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/21 17:19:00 by qhauuy           ###   ########.fr       */
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
# define SIZE_BOX ((double)50) // la taille d'une case de la minimap
# define SIZE_PLAYER ((double)25) // la taille du joueur
# define SIZE_PLAYER_HALF (SIZE_PLAYER / 2)
# define STEP ((double)3) // le nombre de pixels qu'on parcourt sur la minimap à chaque coup
# define R_START 2 // la ligne de départ du joueur
# define C_START 2 // la colonne de départ du joueur
# define O_START 'N' // l'orientation de départ du joueur

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_data
{
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*map_img;
	mlx_image_t	*player;
	t_point		position;
	double		angle;
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);

/* init.c */
void		init(t_data *data);

/* load_map.c */
void	load_map(t_data *data);

/* init_map.c */
void		init_map(t_data *data);
int			get_row_size(char *row);

/* esc_hook.c */
void		esc_hook(mlx_key_data_t keydata, void *param);

/* print_map.c */
void		print_map(t_data *data);

/* player_hook.c */
void		player_hook(void *param);

#endif