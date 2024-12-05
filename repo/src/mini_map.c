/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:10:30 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/05 14:30:07 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "raycasting.h"

void	fill_mini_bg(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)data->minimap_bg->width)
	{
		y = 0;
		while (y < (int)data->minimap_bg->height)
		{
			mlx_put_pixel(data->minimap_bg, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
}

void	fill_mini_player(t_data *data, int x, int y)
{
	int	mini_radius;
	int	mini_radius_2;
	int	d;

	mini_radius = data->box_size / 4;
	mini_radius_2 = mini_radius * mini_radius;
	while (x < (int)data->minimap_player->width)
	{
		y = 0;
		while (y < (int)data->minimap_player->height)
		{
			d = (data->mini_center_x - x) * (data->mini_center_x - x)
				+ (data->mini_center_y - y) * (data->mini_center_y - y);
			if (d <= mini_radius_2)
			{
				mlx_put_pixel(data->minimap_player, x, y, 0xFF0000FF);
			}
			y++;
		}
		x++;
	}
}

static void	copy_map_area(t_data *d, int start_x, int start_y, uint32_t i)
{
	uint32_t	dst_index;
	uint32_t	src_index;
	uint32_t	j;

	while (i < d->minimap->height)
	{
		j = 0;
		while (j < d->minimap->width)
		{
			d->src_x = start_x + j;
			d->src_y = start_y + i;
			dst_index = (i * d->minimap->width + j) * 4;
			if (d->src_x >= 0 && d->src_x < (int)d->map_img->width
				&& d->src_y >= 0 && d->src_y < (int)d->map_img->height)
			{
				src_index = (d->src_y * d->map_img->width + d->src_x) * 4;
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

static void	apply_alpha_to_minimap(mlx_image_t *minimap)
{
	uint32_t	i;
	uint32_t	j;
	float		distance;
	float		radius;
	uint32_t	dst_index;

	radius = minimap->width / 2;
	i = 0;
	while (i < minimap->height)
	{
		j = 0;
		while (j < minimap->width)
		{
			dst_index = (i * minimap->width + j) * 4;
			distance = sqrtf((j - minimap->width / 2)
					* (j - minimap->width / 2)
					+ (i - minimap->height / 2)
					* (i - minimap->height / 2));
			if (distance > radius)
				minimap->pixels[dst_index + 3] = 0;
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_data *data)
{
	int		start_x;
	int		start_y;

	data->theta = atan2(data->dir_y, data->dir_x) + M_PI / 2 ;
	data->cos_theta = cos(data->theta);
	data->sin_theta = sin(data->theta);
	start_x = data->pos_x * data->box_size - data->minimap->width / 2;
	start_y = data->pos_y * data->box_size - data->minimap->height / 2;
	data->mini_center_x = data->minimap->width / 2;
	data->mini_center_y = data->minimap->height / 2;
	copy_map_area(data, start_x, start_y, 0);
	copy_map_rays(data, start_x, start_y, 0);
	render_rotated_minimap(data, 0, 0);
	render_rotated_rays(data, 0, 0);
	fill_mini_player(data, 0, 0);
	fill_mini_bg(data);
	apply_alpha_to_minimap(data->minimap);
	apply_alpha_to_minimap(data->minimap_bg);
	apply_alpha_to_minimap(data->minimap_rays);
}
