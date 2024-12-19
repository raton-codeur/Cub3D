/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 17:04:52 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

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
