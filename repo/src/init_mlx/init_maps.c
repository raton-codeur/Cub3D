/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/28 02:46:16 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	fill_map(t_data *data)
{
	uint32_t x;
	uint32_t y;

	x = 0;
	while (x < data->map_img->width)
	{
		y = 0;
		while (y < data->map_img->height)
		{
			mlx_put_pixel(data->map_img, x, y, get_color(data, x, y));
			y++;
		}
		x++;
	}
}

void	init_map(t_data *data)
{
	data->map_img = mlx_new_image(data->mlx,
			data->map_width * data->box_size,
			data->map_height * data->box_size);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->map_img);
		return (mlx_perror_exit(data));
	}
	fill_map(data);
	mlx_set_instance_depth(&data->map_img->instances[0], -1);
}

void	init_minimap(t_data *data)
{
	data->minimap
		= mlx_new_image(data->mlx, 10 * data->box_size, 10 * data->box_size);
	if (data->minimap == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, \
		data->minimap, data->box_size, data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap);
		return (mlx_perror_exit(data));
	}
	fill_image_circle(data->minimap, MAP_COLOR_BG);
	mlx_set_instance_depth(&data->minimap->instances[0], -1);
}
