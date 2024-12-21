/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:10:24 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 18:18:04 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

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

void	draw_ray_map_fog(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	data->ray_length = 0;
	while (data->ray_length < data->visible_max
		&& (fabs(data->ray_x - data->hit_x) >= data->step_ray_map \
		|| fabs(data->ray_y - data->hit_y) >= data->step_ray_map))
	{
		data->fog_ratio = 1 - data->ray_length / data->visible_max;
		mlx_put_pixel(data->map_rays, data->ray_x * data->box_size, \
			data->ray_y * data->box_size, \
			COLOR_RAY_FOG + data->fog_ratio * 255);
		data->ray_x += data->ray_dir_x * data->step_ray_map;
		data->ray_y += data->ray_dir_y * data->step_ray_map;
		data->ray_length = (data->ray_x - data->pos_x) * \
		(data->ray_x - data->pos_x) + (data->ray_y - data->pos_y) * \
		(data->ray_y - data->pos_y);
	}
}

void	draw_ray_minimap_fog(t_data *data)
{
	(void)data;
}
