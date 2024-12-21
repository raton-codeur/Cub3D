/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dimensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:20:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 12:33:43 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_dimensions(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	if (monitor_width < 2500) // a supp
	{
		data->w_width = 1600;
		data->w_height = 900;
	}
	else 
	{
		data->w_width = 1920;
		data->w_height = 1080;
	}
	mlx_set_window_size(data->mlx, data->w_width, data->w_height);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - data->w_width) / 2, \
		(monitor_height - data->w_height) / 2);
	if (data->map_width > data->map_height)
		data->box_size = data->w_width / 2.0 / data->map_width;
	else
		data->box_size = data->w_height / 2.0 / data->map_height;
	if (data->box_size < 10)
		error_exit(SIZE, data);
}
