/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/28 00:41:47 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

uint32_t get_rgb(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t r, g, b;
	r = img->pixels[y * img->width * 4 + x * 4];
	g = img->pixels[y * img->width * 4 + x * 4 + 1];
	b = img->pixels[y * img->width * 4 + x * 4 + 2];
	return (r << 24 | g << 16 | b << 8);
}

void mlx_put_pixel_rgb(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t rgb)
{
	mlx_put_pixel(img, x, y, rgb | img->pixels[y * img->width * 4 + x * 4 + 3]);
}

void	init_mlx(t_data *data)
{
	init_dimensions(data);
	init_background(data);
	init_game(data);
	init_map(data);
	init_minimap(data);
	init_player_map(data);
	init_player_minimap(data);
	init_rays_map(data);
	init_rays_minimap(data);
	data->fog_height = (data->height / 2) * FOG_RATIO;
	data->visible_max = 1 / (FOG_RATIO * FOG_MAX * FOG_RATIO * FOG_MAX);
	data->step_ray_map = 3.0 / data->box_size;

	
	// uint32_t x, y, color;
	// x = 0;
	// while (x < data->minimap->width)
	// {
	// 	y = 0;
	// 	while (y < data->minimap->height)
	// 	{
	// 		color = get_rgb(data->map_img, x, y);
	// 		mlx_put_pixel_rgb(data->minimap, x, y, color);
	// 		y++;
	// 	}
	// 	x++;
	// }

	uint32_t x, y, color, start_x, start_y;
	start_x = (data->pos_x - 5) * data->box_size; // les coordonnees du pixel de la map point en haut à gauche par rapport au joueur
	start_y = (data->pos_y - 5) * data->box_size;
	// x et y pour parcourir les pixels de minimap

	// on peut passer dune coordonnee dans la map de jeu à une coordonnee en pixel avec un facteur de box_size

	x = 0;
	while (x < data->minimap->width)
	{
		y = 0;
		while (y < data->minimap->height)
		{
			color = get_rgb(data->map_img, start_x + x, start_y + y);
			mlx_put_pixel_rgb(data->minimap, start_x + x, start_y + y, color);
			y++;
		}
		x++;
	}
	
	
}


