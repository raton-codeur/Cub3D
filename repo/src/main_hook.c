/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 16:58:32 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1');
}

double	draw_ray_in_map(t_data *data, double angle)
{
	double	i;
	double	x;
	double	y;

	i = 0;
	x = data->x + i * cos(angle);
	y = data->y + i * sin(angle);
	while (!is_wall(data, x, y))
	{
		mlx_put_pixel(data->rays, x, y, 0x00FF00FF);
		i++;
		x = data->x + i * cos(angle);
		y = data->y + i * sin(angle);
	}
	return (i);
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
	double	 ray_length_in_map;
	uint32_t wall_x_position;
	uint32_t wall_height;

	angle = data->angle - ANGLE_VIEW / 2;
	step = ANGLE_VIEW / NB_RAYS;
	i = 0;
	while (i < NB_RAYS)
	{
		wall_x_position = get_wall_x_position(data, i);
		ray_length_in_map = draw_ray_in_map(data, angle);
		wall_height = get_wall_height(ray_length_in_map);
		draw_wall(data, wall_x_position, wall_height);
		angle += step;
		i++;
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	fill_image(data->rays, 0);
	fill_image(data->walls, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		data->x = data->x + STEP_MOVE * cos(data->angle);
		data->y = data->y + STEP_MOVE * sin(data->angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		data->x = data->x - STEP_MOVE * cos(data->angle);
		data->y = data->y - STEP_MOVE * sin(data->angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->x = data->x + STEP_MOVE * cos(data->angle - M_PI_2);
		data->y = data->y + STEP_MOVE * sin(data->angle - M_PI_2);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->x = data->x + STEP_MOVE * cos(data->angle + M_PI_2);
		data->y = data->y + STEP_MOVE * sin(data->angle + M_PI_2);
	}
	data->player->instances[0].x = data->x - SIZE_PLAYER / 2;
	data->player->instances[0].y = data->y - SIZE_PLAYER / 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle -= STEP_VIEW;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle += STEP_VIEW;
	cast_rays(data);
}
