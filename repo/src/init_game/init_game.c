/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 17:59:25 by qhauuy           ###   ########.fr       */
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
	fill_image(data->minimap, 0xffffffff);
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

void	init_game(t_data *data)
{
	data->mlx = mlx_init(1, 1, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	init_dimensions(data);
	init_background(data);
	init_game_img(data);

	init_map(data);
	init_map_rays(data);
	init_map_player(data);

	init_minimap(data);
	init_minimap_player(data);

	data->ray_dir_ratio = 3.0 / data->box_size;
	data->horizon = data->w_height / 2;
	data->fog_end = FOG_HEIGHT * data->w_height;
	data->fog_max = FOG_MAX * data->fog_end;
	data->visible_max = 1 / (FOG_HEIGHT * FOG_MAX * FOG_HEIGHT * FOG_MAX);
	data->fog_color = FOG_RED << 24 | FOG_GREEN << 16 | FOG_BLUE << 8;
}
