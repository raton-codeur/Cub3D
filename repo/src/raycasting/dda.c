/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:02:39 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/29 09:43:29 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "raycasting.h"

void	init_dda_variables_2(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_i = -1;
		data->side_dist_x = (data->pos_x - data->i) * data->delta_dist_x;
	}
	else
	{
		data->step_i = 1;
		data->side_dist_x = (data->i + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_j = -1;
		data->side_dist_y = (data->pos_y - data->j) * data->delta_dist_y;
	}
	else
	{
		data->step_j = 1;
		data->side_dist_y = (data->j + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

void	init_dda_variables(t_data *data)
{
	data->i = (int)data->pos_x;
	data->j = (int)data->pos_y;
	data->camera_x = 2 * data->x / (double)data->game->width - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	init_dda_variables_2(data);
}

void	iterate_dda(t_data *data)
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
		if (data->map[data->i][data->j] == '1')
			data->hit = 1;
	}
}

void	shade_wall(t_data *data)
{
	data->factor = data->wall_height_norm / FOG_RATIO;
	if (data->factor < FOG_MAX)
		data->factor = 1;
	else
		data->factor
			= 0.5 - 0.5 * cos(M_PI / (1 - FOG_MAX) * (data->factor - 1));
	data->r = (data->color >> 24 & 0xFF) * (1 - data->factor)
		+ (FOG_COLOR >> 24 & 0xFF) * data->factor;
	data->g = (data->color >> 16 & 0xFF) * (1 - data->factor)
		+ (FOG_COLOR >> 16 & 0xFF) * data->factor;
	data->b = (data->color >> 8 & 0xFF) * (1 - data->factor)
		+ (FOG_COLOR >> 8 & 0xFF) * data->factor;
	data->color = (data->r << 24) + (data->g << 16) + (data->b << 8) + 0xFF;
}

void	get_dda_results(t_data *data)
{
	if (data->side == 0 && data->step_i == -1)
		data->color = WALL_COLOR_W;
	else if (data->side == 0 && data->step_i == 1)
		data->color = WALL_COLOR_E;
	else if (data->side == 1 && data->step_j == -1)
		data->color = WALL_COLOR_N;
	else
		data->color = WALL_COLOR_S;
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->hit_x = data->pos_x + data->ray_dir_x * data->perp_wall_dist;
	data->hit_y = data->pos_y + data->ray_dir_y * data->perp_wall_dist;
	data->wall_height = data->height_2 / data->perp_wall_dist;
	if (data->wall_height < 0)
		data->wall_height = 0;
	if (data->wall_height > data->height_2)
		data->wall_height = data->height_2;
	data->wall_height_norm = 2.0 * data->wall_height / data->height;
	if (data->fog_state && data->wall_height_norm < FOG_RATIO)
		shade_wall(data);
}

void	shade_background(t_data *data)
{
	while (data->y < data->fog_height)
	{
		data->factor = (double)data->y / data->fog_height;
		if (data->factor < FOG_MAX)
			data->factor = 1;
		else
			data->factor
				= 0.5 - 0.5 * cos(M_PI / (1 - FOG_MAX) * (data->factor - 1));
		data->color = (FOG_COLOR & 0xFFFFFF00) + data->factor * 255;
		mlx_put_pixel(data->game, data->x, data->height_2 + data->y, data->color);
		mlx_put_pixel(data->game, data->x, data->height_2 - data->y, data->color);
		data->y++;
	}
}

void	draw_game(t_data *data)
{
	data->y = 0;
	while (data->y < data->wall_height)
	{
		mlx_put_pixel(data->game, data->x, data->height_2 + data->y, data->color);
		mlx_put_pixel(data->game, data->x, data->height_2 - data->y, data->color);
		data->y++;
	}
	if (data->fog_state)
		shade_background(data);
}

void	draw_map_fog(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	data->d = 0;
	while (data->d < data->visible_max && (fabs(data->ray_x - data->hit_x) > data->step_ray_map || fabs(data->ray_y - data->hit_y) > data->step_ray_map))
	{
		data->factor = 1 - data->d / data->visible_max;
		mlx_put_pixel(data->rays_map, data->ray_x * data->box_size, data->ray_y * data->box_size, (RAY_COLOR & 0xFFFFFF00) + data->factor * 255);
		data->ray_x += data->ray_dir_x * data->step_ray_map;
		data->ray_y += data->ray_dir_y * data->step_ray_map;
		data->d = (data->ray_x - data->pos_x) * (data->ray_x - data->pos_x)
			+ (data->ray_y - data->pos_y) * (data->ray_y - data->pos_y);
	}
}

void	draw_map(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > data->step_ray_map || fabs(data->ray_y - data->hit_y) > data->step_ray_map)
	{
		mlx_put_pixel(data->rays_map, data->ray_x * data->box_size,
			data->ray_y * data->box_size, RAY_COLOR);
		data->ray_x += data->ray_dir_x * data->step_ray_map;
		data->ray_y += data->ray_dir_y * data->step_ray_map;
	}
	mlx_put_pixel(data->rays_map,
		(data->hit_x - 0.05 * data->ray_dir_x) * data->box_size,
		(data->hit_y - 0.05 * data->ray_dir_y) * data->box_size, RAY_COLOR);
}

void draw_minimap(t_data *data)
{
	uint32_t start_x, start_y, x, y, color;
	start_x = (data->pos_x - 5) * data->box_size;
	start_y = (data->pos_y - 5) * data->box_size;
	x = 0;
	while (x < data->minimap->width)
	{
		y = 0;
		while (y < data->minimap->height)
		{
			if (start_x + x >= 0 && start_x + x < data->map_img->width
				&& start_y + y >= 0 && start_y + y < data->map_img->height)
			{
				color = get_rgb(data->map_img, start_x + x, start_y + y);
				mlx_put_pixel_rgb(data->minimap, x, y, color);
			}
			else 
				mlx_put_pixel_rgb(data->minimap, x, y, 0xFFFFFF00);
			y++;
		}
		x++;
	}
}

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

void draw_for_x(t_data *data)
{
	draw_game(data);
	if (data->depth_config == 1 && data->fog_state)
		draw_map_fog(data);
	else if (data->depth_config == 1)
		draw_map(data);
	// if (data->depth_config == 2 && get_timestamp(data) % 2000 < 1000)
	if (data->depth_config == 2 && rand() % 10 == 0)
	// if (data->depth_config == 2)
		draw_minimap(data);
}

void	dda(t_data *data)
{
	data->x = 0;
	while (data->x < data->game->width)
	{
		init_dda_variables(data);
		iterate_dda(data);
		get_dda_results(data);
		draw_for_x(data);
		data->x++;
	}
}
