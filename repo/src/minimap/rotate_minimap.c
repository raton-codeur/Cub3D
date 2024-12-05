/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:41:37 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/05 13:55:00 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	copy_minimap_pixel(t_data *d, uint32_t dst_index,
	int map_x, int map_y)
{
	uint32_t	src_index;

	src_index = (map_y * d->map_img->width + map_x) * 4;
	ft_memcpy(&d->minimap->pixels[dst_index],
		&d->map_img->pixels[src_index], 4);
}

static int	is_within_bounds(t_data *d, int map_x, int map_y)
{
	return (map_x >= 0 && map_x < (int)d->map_img->width
		&& map_y >= 0 && map_y < (int)d->map_img->height);
}

static void	calculate_rotated_coords(t_data *d, uint32_t i, uint32_t j)
{
	d->rel_x = j - d->mini_center_x;
	d->rel_y = i - d->mini_center_y;
	d->rotated_x = d->rel_x * d->cos_theta - d->rel_y * d->sin_theta;
	d->rotated_y = d->rel_x * d->sin_theta + d->rel_y * d->cos_theta;
}

static void	process_minimap_pixel(t_data *d, uint32_t i, uint32_t j)
{
	int			map_x;
	int			map_y;
	uint32_t	dst_index;

	calculate_rotated_coords(d, i, j);
	map_x = (int)(d->pos_x * d->box_size + d->rotated_x);
	map_y = (int)(d->pos_y * d->box_size + d->rotated_y);
	dst_index = (i * d->minimap->width + j) * 4;
	if (is_within_bounds(d, map_x, map_y))
		copy_minimap_pixel(d, dst_index, map_x, map_y);
	else
		ft_memset(&d->minimap->pixels[dst_index], 0, 4);
}

void	render_rotated_minimap(t_data *d, uint32_t i, uint32_t j)
{
	while (i < d->minimap->height)
	{
		j = 0;
		while (j < d->minimap->width)
		{
			process_minimap_pixel(d, i, j);
			j++;
		}
		i++;
	}
}
