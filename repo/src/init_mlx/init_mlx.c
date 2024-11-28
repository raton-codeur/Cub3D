/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/28 01:17:05 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_mlx(t_data *data)
{
	init_dimensions(data);
	init_background(data);
	init_game(data);
	init_map(data);
	init_minimap(data);
	init_player_map(data);
	init_player_minimap(data);
	init_rays_map(data);
	init_rays_minimap(data);
	data->fog_height = (data->height / 2) * FOG_RATIO;
	data->visible_max = 1 / (FOG_RATIO * FOG_MAX * FOG_RATIO * FOG_MAX);
	data->step_ray_map = 3.0 / data->box_size;
	data->start_time = get_absolute_timestamp();
}
