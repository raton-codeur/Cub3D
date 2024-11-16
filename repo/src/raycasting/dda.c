/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:02:39 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 14:58:02 by qhauuy           ###   ########.fr       */
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
	data->line_height = W_HEIGHT / data->perp_wall_dist;
	if (data->line_height < 0)
		data->line_height = 0;
	if (data->line_height > W_HEIGHT)
		data->line_height = W_HEIGHT;
}

void	draw_wall_line(t_data *data)
{
	data->y_start = (data->walls->height - data->line_height) / 2;
	data->y_end = data->y_start + data->line_height;
	data->y = data->y_start;
	while (data->y < data->y_end)
	{
		mlx_put_pixel(data->walls, data->x, data->y, data->color);
		data->y++;
	}
}

void	dda(t_data *data)
{
	data->x = 0;
	while (data->x < data->walls->width)
	{
		init_dda_variables(data);
		iterate_dda(data);
		get_dda_results(data);
		draw_wall_line(data);
		data->x++;
	}
}
