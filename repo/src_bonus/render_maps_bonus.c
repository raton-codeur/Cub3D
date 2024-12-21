/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:36:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 16:50:14 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	get_pixel_map(t_data *data)
{
	if (data->x % data->box_size == 0 || data->y % data->box_size == 0)
		data->pixel = 0x000000FF;
	data->i = data->map[data->x / data->box_size][data->y / data->box_size];
	if (data->i == '1')
		data->pixel = COLOR_WALL;
	else if (data->i == 'O')
		data->pixel = COLOR_OPEN;
	else if (data->i == 'C')
		data->pixel = COLOR_CLOSE;
	else
		data->pixel = COLOR_MAP;
}

void	render_map(t_data *data)
{
	data->x = 0;
	while (data->x < data->map_img->width)
	{
		data->y = 0;
		while (data->y < data->map_img->height)
		{
			get_pixel_map(data);
			mlx_put_pixel(data->map_img, data->x, data->y, data->pixel);
			data->y++;
		}
		data->x++;
	}
}

void	get_pixel_minimap(t_data *data)
{
	if (data->xd < 0 || data->yd < 0 || data->xd >= data->map_width
		|| data->yd >= data->map_height)
		data->pixel = COLOR_MAP;
	else if ((data->xd - (int)data->xd) < 0.05
		|| (data->yd - (int)data->yd) < 0.05)
		data->pixel = 0x000000FF;
	data->i = data->map[(int)data->xd][(int)data->yd];
	if (data->i == '1')
		data->pixel = COLOR_WALL;
	else if (data->i == 'O')
		data->pixel = COLOR_OPEN;
	else if (data->i == 'C')
		data->pixel = COLOR_CLOSE;
	else
		data->pixel = COLOR_MAP;
}

static void	get_coordinates(t_data *data)
{
	data->mini_xd = (data->x - (double)data->mini_half) / data->mini_box_size;
	data->mini_yd = (data->y - (double)data->mini_half) / data->mini_box_size;
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
			if ((data->x - data->mini_half) * (data->x - data->mini_half) + \
			(data->y - data->mini_half) * (data->y - data->mini_half) \
			<= data->mini_r_2)
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
