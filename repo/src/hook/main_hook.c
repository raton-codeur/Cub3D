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

void	draw_wall_part(t_data *data, uint32_t x_start, uint32_t length)
{
	uint32_t	y_start;
	uint32_t	y;
	uint32_t	x;

	y_start = (data->walls->height - length) / 2;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < length)
		{
			mlx_put_pixel(data->walls, x_start + x, y_start + y, 0x00FF00FF);
			y++;
		}
		x++;
	}
}

void draw_walls(t_data *data, uint32_t *wall_heights)
{
	uint32_t i;
	uint32_t wall_x_position;

	i = 0;
	while (i < NB_RAYS)
	{
		wall_x_position = get_wall_x_position(data, i);
		draw_wall_part(data, wall_x_position, wall_heights[i]);
		i++;
	}
}

void	cast_rays(t_data *data)
{
	double	 angle;
	double	 step;
	uint32_t i;
	double	 ray_length;
	uint32_t wall_heights[NB_RAYS];

	angle = data->angle - ANGLE_VIEW / 2;
	step = ANGLE_VIEW / NB_RAYS;
	i = 0;
	while (i < NB_RAYS)
	{
		ray_length = cos(angle - data->angle) * cast_ray(data, angle);
		wall_heights[i] = get_wall_height(ray_length);
		angle += step;
		i++;
	}
	draw_walls(data, wall_heights);
}

static void	erase_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * sizeof(uint32_t));
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_ray(data);
	erase_image(data->walls);
	check_movement_keys(data);
	check_angle_keys(data);
	cast_rays(data);
	draw_ray(data);
}
