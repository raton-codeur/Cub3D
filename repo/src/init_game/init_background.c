/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:24 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 10:51:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static void	fill_background(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < data->background->width)
	{
		y = 0;
		while (y < data->background->height)
		{
			if (y < data->background->height / 2)
				mlx_put_pixel(data->background, x, y, data->ceil_color);
			else
				mlx_put_pixel(data->background, x, y, data->floor_color);
			y++;
		}
		x++;
	}
}

void	init_background(t_data *data)
{
	data->background = mlx_new_image(data->mlx, \
		data->w_width, data->w_height * 2);
	if (data->background == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, \
		data->background, 0, -(data->w_height / 2)) == -1)
	{
		mlx_delete_image(data->mlx, data->background);
		return (mlx_perror_exit(data));
	}
	fill_background(data);
	mlx_set_instance_depth(&data->background->instances[0], 0);
}
