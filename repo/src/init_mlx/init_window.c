/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:15:52 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/20 12:04:14 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_window(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - W_WIDTH) / 2, (monitor_height - W_HEIGHT) / 2);
}
