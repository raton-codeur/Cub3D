/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/28 02:05:42 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

// static void	fill_map_box(t_data *data, int x_start, int y_start, uint32_t color)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < data->box_size)
// 	{
// 		y = 0;
// 		while (y < data->box_size)
// 		{
// 			if (x == 0 || x == data->box_size - 1
// 				|| y == 0 || y == data->box_size - 1)
// 				mlx_put_pixel(\
// 					data->map_img, x_start + x, y_start + y, 0x000000FF);
// 			else
// 				mlx_put_pixel(\
// 					data->map_img, x_start + x, y_start + y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// static void	fill_map(t_data *data)
// {
// 	int			i;
// 	int			j;
// 	uint32_t	color;

// 	i = 0;
// 	while (i < data->map_width)
// 	{
// 		j = 0;
// 		while (j < data->map_height)
// 		{
// 			if (data->map[i][j] == '1')
// 				color = MAP_COLOR_WALL;
// 			else
// 				color = MAP_COLOR_BG;
// 			fill_map_box(data, i * data->box_size, j * data->box_size, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

uint32_t	get_color(t_data *data, uint32_t x, uint32_t y)
{
	if (x % data->box_size == 0 || x % data->box_size == data->box_size - 1
		|| y % data->box_size == 0 || y % data->box_size == data->box_size - 1)
		return (0x000000FF);
	else if (data->map[x / data->box_size][y / data->box_size] == '1')
		return (MAP_COLOR_WALL);
	else
		return (MAP_COLOR_BG);
}

static void	fill_map(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

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
