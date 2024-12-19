/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:52:18 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 11:47:20 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	draw_minimap(t_data *data)
// {
// 	uint32_t start_x, start_y, x, y, color;
// 	start_x = (data->pos_x - 5) * data->box_size;
// 	start_y = (data->pos_y - 5) * data->box_size;
// 	x = 0;
// 	while (x < data->minimap->width)
// 	{
// 		y = 0;
// 		while (y < data->minimap->height)
// 		{
// 			if (start_x + x >= 0 && start_x + x < data->map_img->width
// 				&& start_y + y >= 0 && start_y + y < data->map_img->height)
// 			{
// 				color = get_rgb(data->map_img, start_x + x, start_y + y);
// 				mlx_put_pixel_rgb(data->minimap, x, y, color);
// 			}
// 			else 
// 				mlx_put_pixel_rgb(data->minimap, x, y, 0xFFFFFF00);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_minimap(t_data *data)
// {
// 	uint32_t x;
// 	uint32_t y;
// 	uint32_t x_start;
// 	uint32_t y_start;

// 	x_start = (data->pos_x - 5) * data->box_size;
// 	y_start = (data->pos_y - 5) * data->box_size;
// 	x = 0;
// 	while (x < data->minimap->width)
// 	{
// 		y = 0;
// 		while (y < data->minimap->height)
// 		{
// 			if (x_start + x >= 0 && x_start + x < data->map_img->width
// 				&& y_start + y >= 0 && y_start + y < data->map_img->height)
// 			{
// 				mlx_put_pixel_rgb(data->minimap, x, y, get_color(data, x_start + x, y_start + y));
// 			}
// 			else
// 				mlx_put_pixel_rgb(data->minimap, x, y, 0xFFFFFF00);
// 			y++;
// 		}
// 		x++;
// 	}
// }
