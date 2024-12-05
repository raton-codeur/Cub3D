/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:07:43 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/05 14:45:14 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	copy_map_rays(t_data *d, int start_x, int start_y, uint32_t i)
{
	uint32_t	dst_index;
	uint32_t	src_index;
	uint32_t	j;

	while (i < d->minimap_rays->height)
	{
		j = 0;
		while (j < d->minimap_rays->width)
		{
			d->src_x = start_x + j;
			d->src_y = start_y + i;
			dst_index = (i * d->minimap_rays->width + j) * 4;
			if (d->src_x >= 0 && d->src_x < (int)d->rays_map->width
				&& d->src_y >= 0 && d->src_y < (int)d->rays_map->height)
			{
				src_index = (d->src_y * d->rays_map->width + d->src_x) * 4;
				ft_memcpy(&d->minimap_rays->pixels[dst_index],
					&d->rays_map->pixels[src_index], 4);
			}
			else
				ft_memset(&d->minimap_rays->pixels[dst_index], 0, 4);
			j++;
		}
		i++;
	}
}
