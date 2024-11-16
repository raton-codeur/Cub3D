/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:15:52 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 14:11:17 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_window(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3D", false);
	if (data->mlx == NULL)
		return (mlx_perror_exit(data));
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - W_WIDTH) / 2, (monitor_height - W_HEIGHT) / 2);
}
