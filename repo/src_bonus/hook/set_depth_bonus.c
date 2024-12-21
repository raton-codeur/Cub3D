/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_depth_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 18:32:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_bonus.h"

void	set_depth(t_data *data)
{
	if (data->depth_config == 1)
	{
		mlx_set_instance_depth(&data->map_player->instances[0], 4);
		mlx_set_instance_depth(&data->map_rays->instances[0], 3);
		mlx_set_instance_depth(&data->map_img->instances[0], 2);
		mlx_set_instance_depth(&data->minimap_player->instances[0], -1);
		mlx_set_instance_depth(&data->minimap->instances[0], -1);
	}
	else if (data->depth_config == 2)
	{
		mlx_set_instance_depth(&data->map_player->instances[0], -1);
		mlx_set_instance_depth(&data->map_rays->instances[0], -1);
		mlx_set_instance_depth(&data->map_img->instances[0], -1);
		mlx_set_instance_depth(&data->minimap_player->instances[0], 3);
		mlx_set_instance_depth(&data->minimap->instances[0], 2);
	}
	else
	{
		mlx_set_instance_depth(&data->map_player->instances[0], -1);
		mlx_set_instance_depth(&data->map_rays->instances[0], -1);
		mlx_set_instance_depth(&data->map_img->instances[0], -1);
		mlx_set_instance_depth(&data->minimap_player->instances[0], -1);
		mlx_set_instance_depth(&data->minimap->instances[0], -1);
	}
}
