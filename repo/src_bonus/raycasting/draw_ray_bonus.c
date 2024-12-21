/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:11:58 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 17:45:31 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

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
