/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:02:39 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 23:23:54 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	iterate_dda(t_data *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->i += data->step_i;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->j += data->step_j;
			data->side = 1;
		}
		if (data->map[data->i][data->j] == '1'
			|| data->map[data->i][data->j] == 'D')
			data->hit = 1;
	}
}

static void	get_texture_infos(t_data *data)
{
	if (data->side == 1 && data->step_j == -1)
	{
		data->tex = data->north;
		data->tex_x = data->tex->width * (data->hit_x - (int)data->hit_x);
	}
	else if (data->side == 1)
	{
		data->tex = data->south;
		data->tex_x = data->tex->width * (1 - (data->hit_x - (int)data->hit_x));
	}
	else if (data->side == 0 && data->step_i == -1)
	{
		data->tex = data->west;
		data->tex_x = data->tex->width * (1 - (data->hit_y - (int)data->hit_y));
	}
	else
	{
		data->tex = data->east;
		data->tex_x = data->tex->width * (data->hit_y - (int)data->hit_y);
	}
}

static void	get_dda_results(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->hit_x = data->pos_x + data->ray_dir_x * data->perp_wall_dist;
	data->hit_y = data->pos_y + data->ray_dir_y * data->perp_wall_dist;
	get_texture_infos(data);
	data->wall_height = data->w_height / data->perp_wall_dist;
}

void	get_pixel_minimap(t_data *data)
{
	if (data->xd < 0 || data->yd < 0 || data->xd >= data->map_width
		|| data->yd >= data->map_height)
		data->pixel = MAP_COLOR_BG;
	else if ((data->xd - (int)data->xd) < 0.05
		|| (data->yd - (int)data->yd) < 0.05)
		data->pixel = 0x000000FF;
	else if (data->map[(int)data->xd][(int)data->yd] == '1')
		data->pixel = MAP_COLOR_WALL;
	else
		data->pixel = MAP_COLOR_BG;
}

void	render_minimap(t_data *data)
{
	data->mini_dir_x = -data->dir_y;
	data->mini_dir_y = data->dir_x;
	data->x = 0;
	while (data->x < data->minimap->width)
	{
		data->y = 0;
		while (data->y < data->minimap->width)
		{
			if ((2 * data->x - data->minimap->width) * (2 * data->x - data->minimap->width) + (2 * data->y - data->minimap->width) * (2 * data->y - data->minimap->width) <= data->mini_w_2)
			{
				data->mini_x = (data->x - data->minimap->width / 2.0) * data->mini_step;
				data->mini_y = (data->y - data->minimap->width / 2.0) * data->mini_step;
				data->xd = data->pos_x + data->mini_x * data->mini_dir_x + data->mini_y * -data->mini_dir_y;
				data->yd = data->pos_y + data->mini_x * data->mini_dir_y + data->mini_y * data->mini_dir_x;
				get_pixel_minimap(data);
				mlx_put_pixel(data->minimap, data->x, data->y, data->pixel);
			}
			data->y++;
		}
		data->x++;
	}
}


void	dda(t_data *data)
{
	erase_image(data->game);
	if (data->depth_config == 1)
		erase_image(data->map_rays);
	if (data->depth_config == 2)
		render_minimap(data);
	data->x = 0;
	while (data->x < data->w_width)
	{
		init_dda(data);
		iterate_dda(data);
		get_dda_results(data);
		render_for_x(data);
		data->x++;
	}
}
