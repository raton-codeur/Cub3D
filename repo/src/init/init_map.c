/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 15:00:30 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	get_row_size(char *row)
{
	int	i;

	if (!row)
		return (0);
	i = 0;
	while (row[i] && row[i] != '\n')
		i++;
	return (i);
}

static int	get_nb_columns(char **map)
{
	int	i;
	int	max;

	if (!map)
		return (0);
	i = 0;
	max = 0;
	while (map[i])
	{
		if (get_row_size(map[i]) > max)
			max = get_row_size(map[i]);
		i++;
	}
	return (max);
}

static void	print_box(t_data *data, int x_start, int y_start, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_BOX)
	{
		x = 0;
		while (x < SIZE_BOX)
		{
			if (y == SIZE_BOX - 1 || x == SIZE_BOX - 1)
				mlx_put_pixel(data->map_img, x_start + x, y_start + y, 0x000000FF);
			else
				mlx_put_pixel(data->map_img, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
}

void	print_map(t_data *data)
{
	int			x;
	int			y;
	uint32_t	color;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (x < get_row_size(data->map[y]))
		{
			if (data->map[y][x] == '1')
				color = 0x000000FF;
			else
				color = 0xFFFFFFFF;
			print_box(data, x * SIZE_BOX, y * SIZE_BOX, color);
			x++;
		}
		y++;
	}
}

void	init_map(t_data *data)
{
	int	nb_rows;
	int	nb_columns;

	nb_rows = array_size((void **)data->map);
	nb_columns = get_nb_columns(data->map);
	data->map_img = mlx_new_image(data->mlx, nb_columns * SIZE_BOX, nb_rows * SIZE_BOX);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->map_img), mlx_perror_exit(data));
	print_map(data);
}
