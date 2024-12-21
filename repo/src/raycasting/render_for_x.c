/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_for_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:18:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 11:09:25 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	render_game_for_x(t_data *data)
{
	if (data->wall_height > data->w_height)
	{
		data->y = 0;
		data->i = (data->wall_height - data->w_height) / 2;
	}
	else
	{
		data->i = 0;
		data->y = (data->w_height - data->wall_height) / 2;
	}
	while (data->i < data->wall_height && data->y < data->w_height)
	{
		data->tex_y = data->tex->height * data->i / data->wall_height;
		get_pixel_wall(data);
		mlx_put_pixel(data->game, data->x, data->y, data->pixel);
		data->i++;
		data->y++;
	}
}

void	render_for_x(t_data *data)
{
	render_game_for_x(data);
	if (data->depth_config == 1)
		draw_ray_map(data);
	else if (data->depth_config == 2)
		draw_ray_minimap(data);
}
