// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   rotate_rays.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/05 13:56:09 by hakgyver          #+#    #+#             */
// /*   Updated: 2024/12/19 17:17:29 by qhauuy           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "main.h"

// static void	copy_rays_pixel(t_data *d, uint32_t dst_index,
// 	int map_x, int map_y)
// {
// 	uint32_t	src_index;

// 	src_index = (map_y * d->map_rays->width + map_x) * 4;
// 	ft_memcpy(&d->minimap_rays->pixels[dst_index],
// 		&d->map_rays->pixels[src_index], 4);
// }

// static int	within_bounds(t_data *d, int map_x, int map_y)
// {
// 	return (map_x >= 0 && map_x < (int)d->map_rays->width
// 		&& map_y >= 0 && map_y < (int)d->map_rays->height);
// }

// static void	rotated_coords(t_data *d, uint32_t i, uint32_t j)
// {
// 	d->rel_x = j - d->mini_center_x;
// 	d->rel_y = i - d->mini_center_y;
// 	d->rotated_x = d->rel_x * d->cos_theta - d->rel_y * d->sin_theta;
// 	d->rotated_y = d->rel_x * d->sin_theta + d->rel_y * d->cos_theta;
// }

// static void	process_minimap_pixel(t_data *d, uint32_t i, uint32_t j)
// {
// 	int			map_x;
// 	int			map_y;
// 	uint32_t	dst_index;

// 	rotated_coords(d, i, j);
// 	map_x = (int)(d->pos_x * d->box_size + d->rotated_x);
// 	map_y = (int)(d->pos_y * d->box_size + d->rotated_y);
// 	dst_index = (i * d->minimap_rays->width + j) * 4;
// 	if (within_bounds(d, map_x, map_y))
// 		copy_rays_pixel(d, dst_index, map_x, map_y);
// 	else
// 		ft_memset(&d->minimap_rays->pixels[dst_index], 0, 4);
// }

// void	render_rotated_rays(t_data *d, uint32_t i, uint32_t j)
// {
// 	while (i < d->minimap_rays->height)
// 	{
// 		j = 0;
// 		while (j < d->minimap_rays->width)
// 		{
// 			process_minimap_pixel(d, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }
