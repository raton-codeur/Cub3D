/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:17:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 14:29:06 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	fill_player(t_data *data)
{
	int	x;
	int	y;
	int	radius_2;
	int	radius;

	radius = data->player->width / 2;
	radius_2 = radius * radius;
	x = 0;
	while (x < (int)data->player->width)
	{
		y = 0;
		while (y < (int)data->player->height)
		{
			if ((radius - x) * (radius - x) + (radius - y) * (radius - y) \
				<= radius_2)
				mlx_put_pixel(data->player, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}

void	init_player(t_data *data)
{
	data->player = mlx_new_image(data->mlx, \
		data->box_size / 2, data->box_size / 2);
	if (data->player == NULL)
		return (mlx_perror_exit(data));
	fill_player(data);
	data->pos_x = data->i_start + 0.5;
	data->pos_y = data->j_start + 0.5;
	if (mlx_image_to_window(data->mlx, data->player, \
		data->pos_x * data->box_size - data->player->width / 2, \
		data->pos_y * data->box_size - data->player->width / 2) == -1)
	{
		mlx_delete_image(data->mlx, data->player);
		return (mlx_perror_exit(data));
	}
}
