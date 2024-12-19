/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:17:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/15 19:48:20 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_player_map(t_data *data)
{
	data->player_map = mlx_new_image(data->mlx, \
		data->box_size / 2, data->box_size / 2);
	if (data->player_map == NULL)
		return (mlx_perror_exit(data));
	fill_image_circle(data->player_map, PLAYER_COLOR);
	data->pos_x = data->i_start + 0.5;
	data->pos_y = data->j_start + 0.5;
	if (mlx_image_to_window(data->mlx, data->player_map, \
		data->pos_x * data->box_size - data->player_map->width / 2, \
		data->pos_y * data->box_size - data->player_map->width / 2) == -1)
	{
		mlx_delete_image(data->mlx, data->player_map);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->player_map->instances[0], -1);
}

void	init_player_minimap(t_data *data)
{
	data->player_minimap = mlx_new_image(data->mlx, \
		data->box_size / 2, data->box_size / 2);
	if (data->player_minimap == NULL)
		return (mlx_perror_exit(data));
	fill_image_circle(data->player_minimap, PLAYER_COLOR);
	if (mlx_image_to_window(data->mlx, data->player_minimap, \
		data->box_size + data->minimap->width / 2, \
		data->box_size + data->minimap->height / 2) == -1)
	{
		mlx_delete_image(data->mlx, data->player_minimap);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->player_minimap->instances[0], -1);
}
