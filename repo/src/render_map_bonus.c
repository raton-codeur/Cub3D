/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:36:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/20 16:37:07 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	get_pixel_map(t_data *data)
{
	if (data->i % data->box_size == 0 || data->y % data->box_size == 0)
		return (0x000000FF);
	else if (data->map[data->x / data->box_size][data->y / data->box_size] == '1')
		return (MAP_COLOR_WALL);
	else if (data->map[x / data->box_size][y / data->box_size] == 'D')
		return (MAP_COLOR_DOOR);
	else
		return (MAP_COLOR_BG);
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
