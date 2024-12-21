/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:27:54 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 12:39:05 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	get_pixel_map(t_data *data)
{
	if (data->x % data->box_size == 0 || data->y % data->box_size == 0)
		data->pixel = 0x000000FF;
	else if (data->map[data->x / data->box_size][data->y / data->box_size] \
		== '1')
		data->pixel = COLOR_WALL;
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
