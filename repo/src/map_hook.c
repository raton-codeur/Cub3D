/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 18:05:29 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1');
}

int	cast_ray(t_data *data, double angle)
{
	int	i;
	int	next_x;
	int	next_y;

	i = 0;
	next_x = data->position.x + i * cos(angle);
	next_y = data->position.y + i * sin(angle);
	while (!is_wall(data, next_x, next_y))
	{
		mlx_put_pixel(data->rays, next_x, next_y, 0x00FF00FF);
		next_x = data->position.x + i * cos(angle);
		next_y = data->position.y + i * sin(angle);
		i++;
	}
	return (i);
}

void	cast_rays(t_data *data)
{
	double angle;

	angle = data->angle - ANGLE_VIEW / 2;
	while (angle < data->angle + ANGLE_VIEW / 2)
	{
		cast_ray(data, angle);
		angle += 0.01;
	}
}


int convert_length(int length_in_map)
{
	return (W_HEIGHT - 20 - ((length_in_map * W_HEIGHT)/(W_WIDTH / 2)));
}

void	cast_ray_draw_wall(t_data *data, double angle)
{
	int length_in_map = cast_ray(data, angle);
	int x = data->walls->width / 2;
	int y_start = (W_HEIGHT - convert_length(length_in_map)) / 2;
	int y = 0;
	while (y < convert_length(length_in_map))
	{
		mlx_put_pixel(data->walls, x, y_start + y, 0x00FF00FF);
		y++;
	}
}

void	map_hook(void *param)
{
	t_data	*data;

	data = param;
	fill_image(data->rays, 0x00000000);
	fill_image(data->walls, 0x00000000);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		data->player->instances[0].y += STEP;
		data->position.y += STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		data->player->instances[0].y -= STEP;
		data->position.y -= STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->player->instances[0].x -= STEP;
		data->position.x -= STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->player->instances[0].x += STEP;
		data->position.x += STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle -= 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle += 0.05;
	cast_ray_draw_wall(data, data->angle);
}
