/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/02 15:43:33 by hakgyver         ###   ########.fr       */
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

void fill_minimap(t_data *data)
{
	int	x;
	int	y;
	int	radius_2;
	int	radius;
	int	player_radius_2;
	int d;

	radius = data->minimap->width / 2;
	radius_2 = radius * radius;
	player_radius_2 = data->box_size * data->box_size / 16;
	x = 0;
	while (x < (int)data->minimap->width)
	{
		y = 0;
		while (y < (int)data->minimap->height)
		{
			d = (radius - x) * (radius - x) + (radius - y) * (radius - y);
			if (d <= radius_2)
			{
				if (d <= player_radius_2)
					mlx_put_pixel(data->minimap, x, y, 0xFF0000FF);
				else
					mlx_put_pixel(data->minimap, x, y, 0xFFFFFFFF);
			}
			y++;
		}
		x++;
	}
}

void	init_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, 10 * data->box_size, 10 * data->box_size);
	if (data->minimap == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap, data->box_size, data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->minimap->instances[0], -1);
}
