/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:24 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/15 09:10:45 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	fill_background(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

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
	data->background = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (data->background == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->background, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->background), mlx_perror_exit(data));
	fill_background(data);
}
