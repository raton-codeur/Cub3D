/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 17:07:110 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1'); // il y a une correspondance simple entre les coordonnées d'un pixel sur l'image de la map et ses coordonnées en "cases de map" : les coordonnées en terme de pixels sur l'image sont SIZE_BOX fois plus grandes que celles en terme de cases
}

double	draw_ray_in_map(t_data *data, double angle)
{
	double	t;
	double	x;
	double	y;

	/* pour tracer un rayon, on utilise les coordonnées paramétriques de droites. en effet, on peut définir une droite simplement par la donnée d'un de ses points et de son angle d'inclinaison. l'équation paramétrique de la droite passant par (x0, y0) et inclinée d'un angle theta est :
	x(t) = x0 + t * cos(theta)
	y(t) = y0 + t * sin(theta)
	elle est paramétrée par t, c'est à dire qu'il existe une valeur de t qui donne chaque point (x, y) de la droite.

	ici, on veut tracer la droite passant par le joueur et ayant l'angle donné en paramètre.

	on commence par t = 0, c'est à dire le joueur lui-même, et on incrémente t jusqu'à ce qu'on rencontre un mur
	*/
	t = 0;
	x = data->x + t * cos(angle);
	y = data->y + t * sin(angle);
	while (!is_wall(data, x, y))
	{
		mlx_put_pixel(data->rays, x, y, 0x00FF00FF);
		t++;
		x = data->x + t * cos(angle);
		y = data->y + t * sin(angle);
	}
	return (t);
}

double	get_wall_height(double length_in_map)
{
	return (W_HEIGHT - (length_in_map * W_HEIGHT * 2 / W_WIDTH)); // c'est la hauteur max d'un mur - un simple produit en croix :
	/*
	W_WIDTH / 2 <-> W_HEIGHT
	length_in_map <-> x
	*/
}

uint32_t	get_wall_x_position(t_data *data, uint32_t i)
{
	return (i * data->walls->width / NB_RAYS); // simple produit en croix :
	/*
	NB_RAYS <-> data->walls->width
	i <-> x
	*/

}

void	draw_wall_line(t_data *data, uint32_t x, uint32_t length)
{
	uint32_t	y_start;
	uint32_t	y;

	/* on veut centrer la ligne en hauteur ! */
	y_start = (data->walls->height - length) / 2; // simple calcul :
	/*
	a
	b
	b
	b
	b
	a

	a : vide
	b : mur

	l'indice de b c'est la hauteur totale - la hauteur du mur / 2
	*/
	y = 0;
	while (y < length)
	{
		mlx_put_pixel(data->walls, x, y_start + y, 0x00FF00FF);
		y++;
	}
}

void	cast_rays(t_data *data)
{
	double	 angle;
	double	 step;
	uint32_t i;
	double	 ray_length_in_map;
	uint32_t wall_x_position;
	uint32_t wall_height;

	// on commence avec l'angle tout à gauche par rapport au champ de vision
	angle = data->angle - ANGLE_VIEW / 2;
	step = ANGLE_VIEW / NB_RAYS; // le pas entre chaque angle
	i = 0;
	while (i < NB_RAYS)
	{
		/* pour chaque rayon lancé dans la map à partir du joueur, on veut tracer une "ligne de mur" dans le jeu. c'est une ligne verticale dont la hauteur est inversement proportionnelle à la longueur du rayon. */

		wall_x_position = get_wall_x_position(data, i); // la conversion entre l'indice du rayon dans le champ de vision et la position de la ligne de mur

		ray_length_in_map = draw_ray_in_map(data, angle); // on trace le rayon dans la minimap et on récupère sa longueur

		wall_height = get_wall_height(ray_length_in_map); // la conversion entre la longueur du rayon et la hauteur de la ligne de mur

		draw_wall_line(data, wall_x_position, wall_height);
		angle += step;
		i++;
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;

	// on reset les images des rays et des walls
	fill_image(data->rays, 0);
	fill_image(data->walls, 0);

	// si on avance le joueur, on modifie les coordonnées x et y de la data	
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		data->x = data->x + STEP_MOVE * cos(data->angle);
		data->y = data->y + STEP_MOVE * sin(data->angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		data->x = data->x - STEP_MOVE * cos(data->angle);
		data->y = data->y - STEP_MOVE * sin(data->angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->x = data->x + STEP_MOVE * cos(data->angle - M_PI_2);
		data->y = data->y + STEP_MOVE * sin(data->angle - M_PI_2);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->x = data->x + STEP_MOVE * cos(data->angle + M_PI_2);
		data->y = data->y + STEP_MOVE * sin(data->angle + M_PI_2);
	}
	// et on bouge l'image qui représente le joueur
	data->player->instances[0].x = data->x - SIZE_PLAYER / 2; // comme la position du joueur est au centre de l'image, les coordonnées de l'image sont décalées par rapport aux coordonnées du joueur de SIZE_PLAYER / 2
	data->player->instances[0].y = data->y - SIZE_PLAYER / 2;

	// si on tourne le joueur, on modifie l'angle de la data
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle -= STEP_VIEW;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle += STEP_VIEW;

	cast_rays(data);
}
