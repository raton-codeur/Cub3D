/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 17:05:18 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

// void	init_textures(t_data *data)
// {
// 	data->north = mlx_load_png(NORTH_PATH);
// 	if (data->north == NULL)
// 		mlx_perror_exit(data);
// 	data->south = mlx_load_png(SOUTH_PATH);
// 	if (data->south == NULL)
// 		mlx_perror_exit(data);
// 	data->west = mlx_load_png(WEST_PATH);
// 	if (data->west == NULL)
// 		mlx_perror_exit(data);
// 	data->east = mlx_load_png(EAST_PATH);
// 	if (data->east == NULL)
// 		mlx_perror_exit(data);
// }



void	init_mini_player_and_rays(t_data *data)
{
	data->minimap_player = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap_player == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap_player, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_player);
		return (mlx_perror_exit(data));
	}
	data->minimap_rays = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap_rays == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap_rays, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_rays);
		return (mlx_perror_exit(data));
	}
}

void	init_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap);
		return (mlx_perror_exit(data));
	}
	data->minimap_bg = mlx_new_image(data->mlx, 10 * data->box_size,
			10 * data->box_size);
	if (data->minimap_bg == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->minimap_bg, data->box_size,
			data->box_size) == -1)
	{
		mlx_delete_image(data->mlx, data->minimap_bg);
		return (mlx_perror_exit(data));
	}
} 



static void	init_mini_depth(t_data *data)
{
	mlx_set_instance_depth(&data->minimap->instances[0], -1);
	mlx_set_instance_depth(&data->minimap_bg->instances[0], -1);
	mlx_set_instance_depth(&data->minimap_player->instances[0], -1);
	mlx_set_instance_depth(&data->minimap_rays->instances[0], -1);
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
	init_player_map(data);
	init_rays_map(data);

	init_minimap(data);

	// init_player_minimap(data);
	// init_rays_minimap(data);
	
	init_mini_player_and_rays(data);
	init_mini_depth(data);
	
	draw_mini_map(data);

	data->ray_dir_ratio = 3.0 / data->box_size;
	data->horizon = data->w_height / 2;
	data->fog_end = FOG_HEIGHT * data->w_height;
	data->fog_max = FOG_MAX * data->fog_end;
	data->visible_max = 1 / (FOG_HEIGHT * FOG_MAX * FOG_HEIGHT * FOG_MAX);
	data->fog_color = FOG_RED << 24 | FOG_GREEN << 16 | FOG_BLUE << 8;
}
