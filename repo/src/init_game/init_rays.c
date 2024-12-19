/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:31:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 11:49:24 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_rays_map(t_data *data)
{
	data->rays_map = mlx_new_image(data->mlx, \
		data->map_img->width, data->map_img->height);
	if (data->rays_map == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->rays_map, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->rays_map);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->rays_map->instances[0], -1);
}

// void	init_minimap_rays(t_data *data)
// {
// 	data->minimap_rays = mlx_new_image(data->mlx, \
// 		data->minimap->width, data->minimap->height);
// 	if (data->minimap_rays == NULL)
// 		return (mlx_perror_exit(data));
// 	if (mlx_image_to_window(data->mlx, data->minimap_rays, \
// 		data->box_size, data->box_size) == -1)
// 	{
// 		mlx_delete_image(data->mlx, data->minimap_rays);
// 		return (mlx_perror_exit(data));
// 	}
// 	mlx_set_instance_depth(&data->minimap_rays->instances[0], -1);
// }
