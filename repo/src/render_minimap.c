/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:48:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 10:15:44 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_pixel_minimap(t_data *data)
{
	if (data->xd < 0 || data->yd < 0 || data->xd >= data->map_width
		|| data->yd >= data->map_height)
		data->pixel = MAP_COLOR_BG;
	else if ((data->xd - (int)data->xd) < 0.05
		|| (data->yd - (int)data->yd) < 0.05)
		data->pixel = 0x000000FF;
	else if (data->map[(int)data->xd][(int)data->yd] == '1')
		data->pixel = MAP_COLOR_WALL;
	else
		data->pixel = MAP_COLOR_BG;
}

static void	get_coordinates(t_data *data)
{
	data->mini_xd = (data->x - (double)data->mini_w_2) / data->mini_box_size;
	data->mini_yd = (data->y - (double)data->mini_w_2) / data->mini_box_size;
	data->xd = data->pos_x + data->mini_xd * data->mini_base_x + \
		data->mini_yd * -data->mini_base_y;
	data->yd = data->pos_y + data->mini_xd * data->mini_base_y + \
		data->mini_yd * data->mini_base_x;
}

void	render_minimap(t_data *data)
{
	data->mini_base_x = -data->dir_y;
	data->mini_base_y = data->dir_x;
	data->x = 0;
	while (data->x < data->minimap->width)
	{
		data->y = 0;
		while (data->y < data->minimap->width)
		{
			if ((data->x - data->mini_w_2) * (data->x - data->mini_w_2) + \
			(data->y - data->mini_w_2) * (data->y - data->mini_w_2) \
			<= data->mini_w_22)
			{
				get_coordinates(data);
				get_pixel_minimap(data);
				mlx_put_pixel(data->minimap, data->x, data->y, data->pixel);
			}
			data->y++;
		}
		data->x++;
	}
}
