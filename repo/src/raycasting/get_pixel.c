/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:19:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 17:44:45 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	get_pixel_wall(t_data *data)
{
	data->r = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4];
	data->g = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4 + 1];
	data->b = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4 + 2];
	data->pixel = data->r << 24 | data->g << 16 | data->b << 8 | 255;
}

void	get_pixel_wall_fog(t_data *data)
{
	data->r = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4] * (1 - data->fog_ratio) + \
		FOG_RED * data->fog_ratio;
	data->g = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4 + 1] * (1 - data->fog_ratio) + \
		FOG_GREEN * data->fog_ratio;
	data->b = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4 + 2] * (1 - data->fog_ratio) + \
		FOG_BLUE * data->fog_ratio;
	data->pixel = data->r << 24 | data->g << 16 | data->b << 8 | 255;
}

void	get_pixel_fog_extra(t_data *data)
{
	if (data->wall_height + 2 * data->i < data->fog_max)
		data->fog_ratio = 1;
	else if (data->wall_height + 2 * data->i < data->fog_end)
		data->fog_ratio = 0.5 + 0.5 * \
		cos(M_PI * (data->wall_height + 2 * data->i - data->fog_max) / \
		(data->fog_end - data->fog_max));
	data->pixel = data->fog_color | (uint8_t)(255 * data->fog_ratio);
}
