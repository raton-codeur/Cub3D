/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:10:24 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 12:22:44 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_ray_map(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) >= data->step_ray_map
		|| fabs(data->ray_y - data->hit_y) >= data->step_ray_map)
	{
		mlx_put_pixel(data->map_rays, data->ray_x * data->box_size,
			data->ray_y * data->box_size, COLOR_RAY);
		data->ray_x += data->ray_dir_x * data->step_ray_map;
		data->ray_y += data->ray_dir_y * data->step_ray_map;
	}
	mlx_put_pixel(data->map_rays,
		(data->hit_x - 0.05 * data->ray_dir_x) * data->box_size,
		(data->hit_y - 0.05 * data->ray_dir_y) * data->box_size, COLOR_RAY);
}

static void	get_coordinates(t_data *data)
{
	data->xd = data->ray_x - data->pos_x;
	data->yd = data->ray_y - data->pos_y;
	data->mini_xd = data->xd * data->mini_base_x + data->yd * data->mini_base_y;
	data->mini_yd = data->xd * -data->mini_base_y + data->yd * \
		data->mini_base_x;
	data->mini_xd = data->mini_xd * data->mini_box_size + data->mini_half;
	data->mini_yd = data->mini_yd * data->mini_box_size + data->mini_half;
}

void	draw_ray_minimap(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) >= data->step_ray_minimap
		|| fabs(data->ray_y - data->hit_y) >= data->step_ray_minimap)
	{
		get_coordinates(data);
		if ((data->mini_xd - data->mini_half) * (data->mini_xd - \
			data->mini_half) + (data->mini_yd - data->mini_half) * \
			(data->mini_yd - data->mini_half) > data->mini_ray_limit)
			return ;
		mlx_put_pixel(data->minimap, data->mini_xd, data->mini_yd, COLOR_RAY);
		data->ray_x += data->ray_dir_x * data->step_ray_minimap;
		data->ray_y += data->ray_dir_y * data->step_ray_minimap;
	}
}
