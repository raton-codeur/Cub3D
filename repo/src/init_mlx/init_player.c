/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:17:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/12 10:48:36 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	fill_player(t_data *data)
{
	int	x;
	int	y;
	int	r2;
	int	half_width;

	half_width = SIZE_PLAYER / 2;
	r2 = half_width * half_width;
	x = 0;
	while (x < SIZE_PLAYER)
	{
		y = 0;
		while (y < SIZE_PLAYER)
		{
			if ((half_width - x) * (half_width - x) + (half_width - y) * (half_width - y) <= r2)
				mlx_put_pixel(data->player, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}

void	init_player(t_data *data)
{
	data->player = mlx_new_image(data->mlx, SIZE_PLAYER, SIZE_PLAYER);
	if (data->player == NULL)
		return (mlx_perror_exit(data));
	fill_player(data);
	if (mlx_image_to_window(data->mlx, data->player, COL_START * SIZE_BOX, ROW_START * SIZE_BOX) == -1)
		return (mlx_delete_image(data->mlx, data->player), mlx_perror_exit(data));
	data->pos_x = data->player->instances[0].x + (double)SIZE_PLAYER / 2;
	data->pos_y = data->player->instances[0].y + (double)SIZE_PLAYER / 2;
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_x = 0;
	data->plane_y = 0.66;
}
