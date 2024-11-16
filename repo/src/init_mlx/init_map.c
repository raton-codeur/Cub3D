/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 14:26:19 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	print_box(t_data *data, int x_start, int y_start, uint32_t color)
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

void	display_map(t_data *data)
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
			print_box(data, i * data->box_size, j * data->box_size, color);
			j++;
		}
		i++;
	}
}

void	init_map(t_data *data)
{
	if (data->map_width > data->map_height)
		data->box_size = W_WIDTH / 3 / data->map_width;
	else
		data->box_size = W_HEIGHT / 3 / data->map_height;
	data->map_img = mlx_new_image(data->mlx, \
		data->map_width * data->box_size, \
		data->map_height * data->box_size);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->map_img);
		return (mlx_perror_exit(data));
	}
	display_map(data);
	data->show_map = 1;
}
