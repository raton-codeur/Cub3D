/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 19:09:110 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1');
}

void	erase_ray(t_data *data)
{
	double	i;
	double	x;
	double	y;

	i = 0;
	x = data->x + i * cos(data->angle);
	y = data->y + i * sin(data->angle);
	while (!is_wall(data, x, y))
	{
		mlx_put_pixel(data->rays, x, y, 0);
		i++;
		x = data->x + i * cos(data->angle);
		y = data->y + i * sin(data->angle);
	}
}

void	draw_ray(t_data *data)
{
	double	i;
	double	x;
	double	y;

	i = 0;
	x = data->x + i * cos(data->angle);
	y = data->y + i * sin(data->angle);
	while (!is_wall(data, x, y))
	{
		mlx_put_pixel(data->rays, x, y, 0x00FF00FF);
		i++;
		x = data->x + i * cos(data->angle);
		y = data->y + i * sin(data->angle);
	}
}

double	cast_ray(t_data *data, double angle)
{
	double	t;
	double	x;
	double	y;

	t = 0;
	x = data->x + t * cos(angle);
	y = data->y + t * sin(angle);
	while (!is_wall(data, x, y))
	{
		t++;
		x = data->x + t * cos(angle);
		y = data->y + t * sin(angle);
	}
	return (t);
}

double	get_wall_height(double length_in_map)
{
	return (W_HEIGHT - (length_in_map * W_HEIGHT * 2 / W_WIDTH));
}

uint32_t	get_wall_x_position(t_data *data, uint32_t i)
{
	return (i * data->walls->width / NB_RAYS);
}

void	draw_wall(t_data *data, uint32_t x, uint32_t length)
{
	uint32_t	y_start;
	uint32_t	y;

	y_start = (data->walls->height - length) / 2;
	y = 0;
	while (y < length)
	{
		mlx_put_pixel(data->walls, x, y_start + y, 0x00FF00FF);
		y++;
	}
}

void	cast_rays(t_data *data)
{
	double	 angle;
	double	 step;
	uint32_t i;
	double	 ray_length;
	uint32_t wall_x_position;
	uint32_t wall_height;

	angle = data->angle - ANGLE_VIEW / 2;
	step = ANGLE_VIEW / NB_RAYS;
	i = 0;
	while (i < NB_RAYS)
	{
		wall_x_position = get_wall_x_position(data, i);
		ray_length = cast_ray(data, angle);
		wall_height = get_wall_height(ray_length);
		draw_wall(data, wall_x_position, wall_height);
		angle += step;
		i++;
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_ray(data);
	fill_image(data->walls, 0);
	check_movement_keys(data);
	check_angle_keys(data);
	cast_rays(data);
	draw_ray(data);
}
