/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/04 14:01:35 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	fill_map_box(t_data *data, int x_start, int y_start, uint32_t color)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->box_size)
	{
		y = 0;
		while (y < data->box_size)
		{
			if (x == 0 || x == data->box_size - 1
				|| y == 0 || y == data->box_size - 1)
				mlx_put_pixel(\
					data->map_img, x_start + x, y_start + y, 0x000000FF);
			else
				mlx_put_pixel(\
					data->map_img, x_start + x, y_start + y, color);
			y++;
		}
		x++;
	}
}

void	fill_map(t_data *data)
{
	int			i;
	int			j;
	uint32_t	color;

	i = 0;
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{
			if (data->map[i][j] == '1')
				color = 0x000000FF;
			else
				color = 0xFFFFFFFF;
			fill_map_box(data, i * data->box_size, j * data->box_size, color);
			j++;
		}
		i++;
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
