/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/27 10:33:05 by qhauuy           ###   ########.fr       */
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
	int	monitor_width;
	int	monitor_height;

	data->width = 2560;
	data->height = 1440;
	data->height_2 = 1440 / 2;
	data->mlx = mlx_init(data->width, data->height, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - data->width) / 2, (monitor_height - data->height) / 2);

	if (data->map_width > data->map_height)
		data->box_size = data->width / 3.0 / data->map_width;
	else
		data->box_size = data->height / 3.0 / data->map_height;
	if (data->box_size < 10)
		error_exit(SIZE, data);
	init_background(data);
	init_walls(data);
	init_map(data);
	init_minimap(data);
	init_player_map(data);
	init_rays_map(data);
	init_rays_minimap(data);
	data->fog_height = (data->height / 2) * FOG_RATIO;
	data->visible_max = 1 / (FOG_RATIO * FOG_MAX * FOG_RATIO * FOG_MAX);
	data->step_ray_map = 3.0 / data->box_size;
}
