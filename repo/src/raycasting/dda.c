/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:02:39 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/25 15:00:200:25 by qhauuy           ###   ########.fr       */
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

	unsigned long r, g, b;
	double factor;
	r = data->color >> 24;
	g = data->color >> 16 & 0xFF;
	b = data->color >> 8 & 0xFF;
	double line_height_norm = (double)data->line_height / W_HEIGHT; // de 0 à 1
	if (line_height_norm < 0.2) // jusqu'à une hauteur de mur de 20% de W_HEIGHT, le mur sera gris
	{
		r = 70; g = 70; b = 70;
	}
	else if (line_height_norm < 0.7) // mur de hauteur entre 20% et 70%
	// le niveau de gris du mur varie en fonction de line_height_norm
	{
		factor = 0.5 + 0.5 * cos(M_PI * 2 * (line_height_norm - 0.2));
		r = r * (1 - factor) + 70 * factor;
		g = g * (1 - factor) + 70 * factor;
		b = b * (1 - factor) + 70 * factor;
	}
	// a partir d'une hauteur de 70%, le mur n'est pas gris

	data->color = (r << 24) + (g << 16) + (b << 8) + 0xFF;
}

void	draw_wall_line(t_data *data)
{
	double	factor;

	data->line_height /= 2;
	data->y = 0;
	while (data->y < data->line_height)
	{
		mlx_put_pixel(data->walls, data->x, data->walls->height / 2 + data->y, data->color);
		mlx_put_pixel(data->walls, data->x, data->walls->height / 2 - data->y, data->color);
		data->y++;
	}
	while (data->y < data->fog_height)
	{
		factor = (double)data->y / data->fog_height;
		if (factor < 0.3)
			factor = 1;
		else if (factor < 0.8)
			factor = 0.5 + 0.5 * cos(2 * M_PI * (factor - 0.3));
		else
			factor = 0;
		mlx_put_pixel(data->walls, data->x, data->walls->height / 2 + data->y, 0x46464600 + factor * 255);
		mlx_put_pixel(data->walls, data->x, data->walls->height / 2 - data->y, 0x48484800 + factor * 255);
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
