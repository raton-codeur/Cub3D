/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 19:46:05 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static uint32_t	get_color(t_data *data, uint32_t x, uint32_t y)
{
	if (x % data->box_size == 0 || x % data->box_size == data->box_size - 1
		|| y % data->box_size == 0 || y % data->box_size == data->box_size - 1)
		return (0x000000FF);
	else if (data->map[x / data->box_size][y / data->box_size] == '1')
		return (MAP_COLOR_WALL);
	else if (data->map[x / data->box_size][y / data->box_size] == 'D')
		return (MAP_COLOR_DOOR);
	else
		return (MAP_COLOR_BG);
}

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

void	init_map_rays(t_data *data)
{
	data->map_rays = mlx_new_image(data->mlx, \
		data->map_img->width, data->map_img->height);
	if (data->map_rays == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_rays, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->map_rays);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->map_rays->instances[0], -1);
}

void	init_map_player(t_data *data)
{
	data->map_player = mlx_new_image(data->mlx, \
		data->box_size / 2, data->box_size / 2);
	if (data->map_player == NULL)
		return (mlx_perror_exit(data));
	fill_image_circle(data->map_player, PLAYER_COLOR);
	data->pos_x = data->i_start + 0.5;
	data->pos_y = data->j_start + 0.5;
	if (mlx_image_to_window(data->mlx, data->map_player, \
		data->pos_x * data->box_size - data->map_player->width / 2, \
		data->pos_y * data->box_size - data->map_player->width / 2) == -1)
	{
		mlx_delete_image(data->mlx, data->map_player);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->map_player->instances[0], -1);
}
