/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:31:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/05 14:43:34 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_rays_map(t_data *data)
{
	data->rays_map = mlx_new_image(data->mlx, \
		data->map_img->width, data->map_img->height);
	if (data->rays_map == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->rays_map, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->rays_map),
			mlx_perror_exit(data));
	mlx_set_instance_depth(&data->rays_map->instances[0], -1);
}
