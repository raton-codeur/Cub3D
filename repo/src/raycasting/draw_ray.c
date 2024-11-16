/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:06:25 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 13:57:52 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_ray(t_data *data, double camera_x, uint32_t color)
{
	double	x;
	double	y;

	data->ray_dir_x = data->dir_x + data->plane_x * camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * camera_x;
	x = data->pos_x;
	y = data->pos_y;
	while (data->map[(int)x][(int)y] != '1')
	{
		mlx_put_pixel(data->rays, \
			x * data->box_size, y * data->box_size, color);
		x += data->ray_dir_x / 30;
		y += data->ray_dir_y / 30;
	}
}
