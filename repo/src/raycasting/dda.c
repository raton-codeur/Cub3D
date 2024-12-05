/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:02:39 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/05 14:44:51 by hakgyver         ###   ########.fr       */
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
	data->camera_x = 2 * data->x / (double)data->walls->width - 1;
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
		data->color = 0xFF0000FF;
	else if (data->side == 0 && data->step_i == 1)
		data->color = 0x00FF00FF;
	else if (data->side == 1 && data->step_j == -1)
		data->color = 0x0000FFFF;
	else
		data->color = 0xFFFF00FF;
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->hit_x = data->pos_x + data->ray_dir_x * data->perp_wall_dist;
	data->hit_y = data->pos_y + data->ray_dir_y * data->perp_wall_dist;
	data->wall_height = W_HEIGHT / data->perp_wall_dist / 2;
	if (data->wall_height < 0)
		data->wall_height = 0;
	if (data->wall_height > W_HEIGHT / 2)
		data->wall_height = W_HEIGHT / 2;
	data->wall_height_norm = 2.0 * data->wall_height / W_HEIGHT;
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
		mlx_put_pixel(data->walls, data->x, W_HEIGHT_2 + data->y, data->color);
		mlx_put_pixel(data->walls, data->x, W_HEIGHT_2 - data->y, data->color);
		data->y++;
	}
}

void	draw_game(t_data *data)
{
	data->y = 0;
	while (data->y < data->wall_height)
	{
		mlx_put_pixel(data->walls, data->x, W_HEIGHT_2 + data->y, data->color);
		mlx_put_pixel(data->walls, data->x, W_HEIGHT_2 - data->y, data->color);
		data->y++;
	}
	if (data->fog_state)
		shade_background(data);
}

void draw_map_fog(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	data->d = 0;
	while (data->d < data->visible_max && (fabs(data->ray_x - data->hit_x) > 0.1 || fabs(data->ray_y - data->hit_y) > 0.1))
	{
		data->factor = 1 - data->d / data->visible_max;
		mlx_put_pixel(data->rays_map, data->ray_x * data->box_size,
			data->ray_y * data->box_size, (RAY_COLOR & 0xFFFFFF00) + data->factor * 255);
		data->ray_x += data->ray_dir_x * 0.1;
		data->ray_y += data->ray_dir_y * 0.1;
		data->d = (data->ray_x - data->pos_x) * (data->ray_x - data->pos_x)
			+ (data->ray_y - data->pos_y) * (data->ray_y - data->pos_y);
	}
}

void draw_map(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > 0.1 || fabs(data->ray_y - data->hit_y) > 0.1)
	{
		mlx_put_pixel(data->rays_map, data->ray_x * data->box_size,
			data->ray_y * data->box_size, RAY_COLOR);
		data->ray_x += data->ray_dir_x * 0.1;
		data->ray_y += data->ray_dir_y * 0.1;
	}
	mlx_put_pixel(data->rays_map,
		(data->hit_x - 0.05 * data->ray_dir_x) * data->box_size,
		(data->hit_y - 0.05 * data->ray_dir_y) * data->box_size, RAY_COLOR);
}

void draw_for_x(t_data *data)
{
	draw_game(data);
	if (data->config == 1 && data->fog_state)
		draw_map_fog(data);
}

void	dda(t_data *data)
{
	data->x = 0;
	while (data->x < data->walls->width)
	{
		init_dda_variables(data);
		iterate_dda(data);
		get_dda_results(data);
		draw_for_x(data);
		draw_map(data);
		data->x++;
	}
}
