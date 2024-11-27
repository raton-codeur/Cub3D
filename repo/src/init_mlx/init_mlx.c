/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/27 11:14:00 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_dimensions(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	data->mlx = mlx_init(1, 1, "Cub3D", false);
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	printf("monitor_width = %d\n", monitor_width);
	printf("monitor_height = %d\n", monitor_height);
	data->width = monitor_width * 2 / 3;
	data->height = monitor_height * 2 / 3;
	data->height_2 = data->height / 2;
	mlx_set_window_size(data->mlx, data->width, data->height);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - data->width) / 2, (monitor_height - data->height) / 2);
	if (data->map_width > data->map_height)
		data->box_size = data->width / 3.0 / data->map_width;
	else
		data->box_size = data->height / 3.0 / data->map_height;
	if (data->box_size < 10)
		error_exit(SIZE, data);
}

void	init_mlx(t_data *data)
{
	init_dimensions(data);
	init_background(data);
	init_game(data);
	init_map(data);
	init_minimap(data);
	init_player_map(data);
	init_rays_map(data);
	init_rays_minimap(data);
	data->fog_height = (data->height / 2) * FOG_RATIO;
	data->visible_max = 1 / (FOG_RATIO * FOG_MAX * FOG_RATIO * FOG_MAX);
	data->step_ray_map = 3.0 / data->box_size;
}
