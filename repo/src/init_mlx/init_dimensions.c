/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dimensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:20:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/28 00:20:50 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_dimensions(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	data->mlx = mlx_init(1, 1, "Cub3D", false);
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
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
