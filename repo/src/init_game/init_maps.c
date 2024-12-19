/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 12:03:24 by qhauuy           ###   ########.fr       */
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

// void	init_minimap(t_data *data)
// {
// 	data->minimap
// 		= mlx_new_image(data->mlx, 10 * data->box_size, 10 * data->box_size);
// 	if (data->minimap == NULL)
// 		return (mlx_perror_exit(data));
// 	if (mlx_image_to_window(data->mlx, \
// 		data->minimap, data->box_size, data->box_size) == -1)
// 	{
// 		mlx_delete_image(data->mlx, data->minimap);
// 		return (mlx_perror_exit(data));
// 	}
// 	fill_image_circle(data->minimap, MAP_COLOR_BG);
// 	mlx_set_instance_depth(&data->minimap->instances[0], -1);
// }

void	init_mini_player_and_rays(t_data *data)
{
	data->minimap_player = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap_player == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap_player, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_player);
		return (mlx_perror_exit(data));
	}
	data->minimap_rays = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap_rays == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap_rays, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_rays);
		return (mlx_perror_exit(data));
	}
}

void	init_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap);
		return (mlx_perror_exit(data));
	}
	data->minimap_bg = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap_bg == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap_bg, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_bg);
		return (mlx_perror_exit(data));
	}
}
