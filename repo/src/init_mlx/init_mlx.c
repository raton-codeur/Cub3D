/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/27 10:41:07 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

mlx_image_t	*get_img_from_png(t_data *data, const char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*result;

	texture = mlx_load_png(file);
	if (texture == NULL)
		return (NULL);
	result = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (result);
}

void	init_mlx(t_data *data)
{
	if (data->map_width > data->map_height)
		data->box_size = W_WIDTH / 3 / data->map_width;
	else
		data->box_size = W_HEIGHT / 3 / data->map_height;
	init_background(data);
	init_walls(data);
	init_map(data);
	init_minimap(data);
	init_player_map(data);
	init_rays_map(data);
	init_rays_minimap(data);
	data->fog_height = (W_HEIGHT / 2) * FOG_RATIO;
	data->visible_max = 1 / (FOG_RATIO * FOG_MAX * FOG_RATIO * FOG_MAX);
}
