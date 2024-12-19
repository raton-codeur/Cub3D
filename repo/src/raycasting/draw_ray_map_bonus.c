/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:11:58 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 22:12:29 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
		mlx_put_pixel(data->map_rays, data->ray_x * data->box_size, \
			data->ray_y * data->box_size, \
			RAY_COLOR_FOG + data->fog_ratio * 255);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
		data->d = (data->ray_x - data->pos_x) * (data->ray_x - data->pos_x)
			+ (data->ray_y - data->pos_y) * (data->ray_y - data->pos_y);
	}
}

void	draw_ray_minimap_fog(t_data *data)
{
	(void)data;
}