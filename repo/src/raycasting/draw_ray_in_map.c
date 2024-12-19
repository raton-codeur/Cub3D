/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_in_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:50:27 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 09:53:17 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_ray_in_map(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > data->ray_dir_ratio
		|| fabs(data->ray_y - data->hit_y) > data->ray_dir_ratio)
	{
		mlx_put_pixel(data->rays_map, data->ray_x * data->box_size,
			data->ray_y * data->box_size, RAY_COLOR);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
	}
	mlx_put_pixel(data->rays_map,
		(data->hit_x - 0.05 * data->ray_dir_x) * data->box_size,
		(data->hit_y - 0.05 * data->ray_dir_y) * data->box_size, RAY_COLOR);
}

void	draw_ray_in_map_fog(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	data->d = 0;
	while (data->d < data->visible_max
		&& (fabs(data->ray_x - data->hit_x) > data->ray_dir_ratio \
		|| fabs(data->ray_y - data->hit_y) > data->ray_dir_ratio))
	{
		data->fog_ratio = 1 - data->d / data->visible_max;
		mlx_put_pixel(data->rays_map, data->ray_x * data->box_size, \
			data->ray_y * data->box_size, \
			RAY_COLOR_FOG + data->fog_ratio * 255);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
		data->d = (data->ray_x - data->pos_x) * (data->ray_x - data->pos_x)
			+ (data->ray_y - data->pos_y) * (data->ray_y - data->pos_y);
	}
}
