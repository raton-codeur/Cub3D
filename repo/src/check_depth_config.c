/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_depth_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/27 10:49:32 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	set_depth(mlx_image_t *img, int depth)
{
	mlx_set_instance_depth(&img->instances[0], depth);
}

void	check_depth_config(t_data *data)
{
	if (data->depth_config == 1)
	{
		set_depth(data->player_map, 4);
		set_depth(data->rays_map, 3);
		set_depth(data->map_img, 2);
		set_depth(data->minimap, -1);
		set_depth(data->rays_minimap, -1);
	}
	else if (data->depth_config == 2)
	{
		set_depth(data->rays_minimap, 3);
		set_depth(data->minimap, 2);
		set_depth(data->map_img, -1);
		set_depth(data->rays_map, -1);
		set_depth(data->player_map, -1);
	}
	else
	{
		set_depth(data->player_map, -1);
		set_depth(data->map_img, -1);
		set_depth(data->minimap, -1);
		set_depth(data->rays_map, -1);
		set_depth(data->rays_minimap, -1);
	}
}
