/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:19:36 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/20 18:47:28 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	int x;
	int y;
	int	color;

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
