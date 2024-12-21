/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:50:27 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 09:50:48 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_ray_map(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > data->ray_dir_ratio
		|| fabs(data->ray_y - data->hit_y) > data->ray_dir_ratio)
	{
		mlx_put_pixel(data->map_rays, data->ray_x * data->box_size,
			data->ray_y * data->box_size, RAY_COLOR);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
	}
	mlx_put_pixel(data->map_rays,
		(data->hit_x - 0.05 * data->ray_dir_x) * data->box_size,
		(data->hit_y - 0.05 * data->ray_dir_y) * data->box_size, RAY_COLOR);
}


// void	world_to_minimap(t_data *data, double world_x, double world_y, double *mini_x, double *mini_y)
// {
// 	// Décale par rapport à la position du joueur
// 	double dx = world_x - data->pos_x;
// 	double dy = world_y - data->pos_y;

// 	// Applique la rotation inverse (rotation vers la droite)
// 	*mini_x = dx * data->mini_base_x + dy * data->mini_base_y;
// 	*mini_y = dx * data->mini_perp_x + dy * data->mini_perp_y;

// 	// Convertit en coordonnées de pixels sur la minimap
// 	*mini_x = *mini_x * data->mini_box_size + data->mini_w_2;
// 	*mini_y = *mini_y * data->mini_box_size + data->mini_w_2;
// }


void	draw_ray_minimap(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > data->ray_dir_ratio
		|| fabs(data->ray_y - data->hit_y) > data->ray_dir_ratio)
	{
		data->xd = data->ray_x - data->pos_x;
		data->yd = data->ray_y - data->pos_y;
		data->mini_x = data->xd * data->mini_base_x + data->yd * data->mini_base_y;
		data->mini_y = data->xd * data->mini_perp_x + data->yd * data->mini_perp_y;
		data->mini_x = data->mini_x * data->mini_box_size + data->mini_w_2;
		data->mini_y = data->mini_y * data->mini_box_size + data->mini_w_2;
		if (data->mini_x < 0 || data->mini_x >= data->minimap->width || data->mini_y < 0 || data->mini_y >= data->minimap->width)
			break;			
		mlx_put_pixel(data->minimap, data->mini_x, data->mini_y, RAY_COLOR);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
	}
}
