/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:10:30 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/02 16:28:28 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_mini_player(t_data *data)
{
	int mini_center_x = data->minimap->width / 2;
	int mini_center_y = data->minimap->height / 2;
	int mini_radius = data->box_size / 4;
	int mini_radius_2 = mini_radius * mini_radius;
	int x = 0;
	int y = 0;
	int d;

	while (x < (int)data->minimap->width)
	{
		y = 0;
		while (y < (int)data->minimap->height)
		{
			d = (mini_center_x - x) * (mini_center_x - x) + (mini_center_y - y) * (mini_center_y - y);
			if (d <= mini_radius_2)
			{
				mlx_put_pixel(data->minimap, x, y, 0xFF0000FF);
			}
			y++;
		}
		x++;
	}
}

static void	copy_map_area(t_data *data, int start_x, int start_y, uint32_t i)
{
	int			src_x;
	int			src_y;
	uint32_t	dst_index;
	uint32_t	src_index;
	uint32_t	j;

	while (i < data->minimap->height)
	{
		j = 0;
		while (j < data->minimap->width)
		{
			src_x = start_x + j;
			src_y = start_y + i;
			dst_index = (i * data->minimap->width + j) * 4;
			if (src_x >= 0 && src_x < (int)data->map_img->width
				&& src_y >= 0 && src_y < (int)data->map_img->height)
			{
				src_index = (src_y * data->map_img->width + src_x) * 4;
				ft_memcpy(&data->minimap->pixels[dst_index],
					&data->map_img->pixels[src_index], 4);
			}
			else
				ft_memset(&data->minimap->pixels[dst_index], 0, 4);
			j++;
		}
		i++;
	}
}

static void	apply_alpha_to_minimap(t_data *data)
{
	uint32_t	i;
	uint32_t	j;
	float		distance;
	float		radius;
	uint32_t	dst_index;

	radius = data->minimap->width / 2;
	i = 0;
	while (i < data->minimap->height)
	{
		j = 0;
		while (j < data->minimap->width)
		{
			dst_index = (i * data->minimap->width + j) * 4;
			distance = sqrtf((j - data->minimap->width / 2)
					* (j - data->minimap->width / 2)
					+ (i - data->minimap->height / 2)
					* (i - data->minimap->height / 2));
			if (distance > radius)
				data->minimap->pixels[dst_index + 3] = 0;
			j++;
		}
		i++;
	}
}

static void	render_rotated_minimap(t_data *d, uint32_t i, uint32_t j)
{
	int			map_x;
	int			map_y;
	uint32_t	dst_index;
	uint32_t	src_index;

	while (i < d->minimap->height)
	{
		j = 0;
		while (j < d->minimap->width)
		{
			d->rel_x = j - d->mini_center_x;
			d->rel_y = i - d->mini_center_y;
			d->rotated_x = d->rel_x * d->cos_theta - d->rel_y * d->sin_theta;
			d->rotated_y = d->rel_x * d->sin_theta + d->rel_y * d->cos_theta;
			map_x = (int)(d->pos_x * d->box_size + d->rotated_x);
			map_y = (int)(d->pos_y * d->box_size + d->rotated_y);
			dst_index = (i * d->minimap->width + j) * 4;
			if (map_x >= 0 && map_x < (int)d->map_img->width
				&& map_y >= 0 && map_y < (int)d->map_img->height)
			{
				src_index = (map_y * d->map_img->width + map_x) * 4;
				ft_memcpy(&d->minimap->pixels[dst_index],
					&d->map_img->pixels[src_index], 4);
			}
			else
				ft_memset(&d->minimap->pixels[dst_index], 0, 4);
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_data *data)
{
	int		start_x;
	int		start_y;

	data->theta = atan2(data->dir_y, data->dir_x);
	data->cos_theta = cos(data->theta);
	data->sin_theta = sin(data->theta);
	start_x = data->pos_x * data->box_size - data->minimap->width / 2;
	start_y = data->pos_y * data->box_size - data->minimap->height / 2;
	data->mini_center_x = data->minimap->width / 2;
	data->mini_center_y = data->minimap->height / 2;
	copy_map_area(data, start_x, start_y, 0);
	render_rotated_minimap(data, 0, 0);
	fill_mini_player(data);
	apply_alpha_to_minimap(data);
}
