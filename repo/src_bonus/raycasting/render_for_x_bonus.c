/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_for_x_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:18:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 18:51:55 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static void	render_extra_fog(t_data *data)
{
	data->y = data->horizon + data->wall_height / 2;
	data->i = 0;
	while (data->wall_height + 2 * data->i < data->fog_end)
	{
		get_pixel_fog_extra(data);
		mlx_put_pixel(data->game, data->x, data->y, data->pixel);
		if (2 * data->horizon - data->y < data->w_height)
			mlx_put_pixel(data->game, data->x, \
			2 * data->horizon - data->y, data->pixel);
		data->y++;
		data->i++;
	}
}

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
		if (data->fog_state)
			get_pixel_wall_fog(data);
		else
			get_pixel_wall(data);
		mlx_put_pixel(data->game, data->x, data->y, data->pixel);
		data->i++;
		data->y++;
	}
	if (data->fog_state)
		render_extra_fog(data);
}

void	render_for_x(t_data *data)
{
	render_game_for_x(data);
	if (data->depth_config && data->fog_state)
		draw_ray_map_fog(data);
	else if (data->depth_config)
		draw_ray_map(data);
	
	if (data->depth_config)
	{
		if (data->depth_config)
	if (data->depth_config == 1)
		draw_ray_map(data);
	else if (data->depth_config == 2)
		draw_ray_minimap(data);}

}
