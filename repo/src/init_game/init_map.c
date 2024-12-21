/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 11:13:57 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

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
	render_map(data);
	mlx_set_instance_depth(&data->map_img->instances[0], -1);
}

void	init_map_rays(t_data *data)
{
	data->map_rays = mlx_new_image(data->mlx, \
		data->map_img->width, data->map_img->height);
	if (data->map_rays == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_rays, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->map_rays);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->map_rays->instances[0], -1);
}

void	init_map_player(t_data *data)
{
	data->map_player = mlx_new_image(data->mlx, \
		data->box_size / 2, data->box_size / 2);
	if (data->map_player == NULL)
		return (mlx_perror_exit(data));
	fill_circle(data->map_player, COLOR_PLAYER);
	data->pos_x = data->i_start + 0.5;
	data->pos_y = data->j_start + 0.5;
	if (mlx_image_to_window(data->mlx, data->map_player, \
		data->pos_x * data->box_size - data->map_player->width / 2, \
		data->pos_y * data->box_size - data->map_player->width / 2) == -1)
	{
		mlx_delete_image(data->mlx, data->map_player);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->map_player->instances[0], -1);
}
