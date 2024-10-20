/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:19:36 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/20 16:19:54 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_length(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static void	get_dimensions(t_data *data, int *nb_columns, int *nb_rows)
{
	int	i;

	i = 0;
	*nb_rows = 0;
	*nb_columns = 0;
	while (data->map[i])
	{
		*nb_rows += 1;
		if (get_length(data->map[i]) > *nb_columns)
			*nb_columns = get_length(data->map[i]);
		i++;
	}
}

static void	print_box(t_data *data, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_BOX)
	{
		x = 0;
		while (x < SIZE_BOX)
		{
			mlx_put_pixel(data->map_img, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
}

static void	print_boxes(t_data *data, int y_max)
{
	int x;
	int y;
	int	color;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < get_length(data->map[y]))
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

void	print_map(t_data *data)
{
	int	x_max;
	int	y_max;

	get_dimensions(data, &x_max, &y_max);
	data->map_img = mlx_new_image(data->mlx, x_max * SIZE_BOX, y_max * SIZE_BOX);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->map_img), mlx_perror_exit(data));
	print_boxes(data, y_max);
}
