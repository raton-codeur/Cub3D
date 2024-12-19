/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_for_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:18:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 18:45:13 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	render_game_for_x(t_data *data)
{
	if (data->horizon < data->wall_height / 2)
	{
		data->i = data->wall_height / 2 - data->horizon;
		data->y = 0;
	}
	else
	{
		data->y = data->horizon - data->wall_height / 2;
		data->i = 0;
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
	if (data->depth_config)
		draw_ray_in_map(data);
}
