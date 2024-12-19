/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:35:10 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 20:13:27 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, data->w_height / 4, data->w_height / 4);
	if (data->minimap == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap, data->minimap->width / 10, data->minimap->width / 10) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->minimap->instances[0], -1);
}

void	init_minimap_player(t_data *data)
{
	data->minimap_player = mlx_new_image(data->mlx, data->minimap->width / 20, data->minimap->height / 20);
	if (data->minimap_player == NULL)
		return (mlx_perror_exit(data));
	fill_image_circle(data->minimap_player, PLAYER_COLOR);
	if (mlx_image_to_window(data->mlx, data->minimap_player, \
		data->minimap->width / 10 + data->minimap->width / 2 - data->minimap_player->width / 2, \
		data->minimap->width / 10 + data->minimap->width / 2 - data->minimap_player->width / 2 \
		) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_player);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->minimap_player->instances[0], -1);
}
