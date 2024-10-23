/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 16:34:27 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1');
}

void	erase_ray(t_data *data)
{
	int	i;
	int	next_x;
	int	next_y;

	i = 0;
	next_x = data->position.x + i * cos(data->angle);
	next_y = data->position.y + i * sin(data->angle);
	while (!is_wall(data, next_x, next_y))
	{
		mlx_put_pixel(data->rays, next_x, next_y, 0x00000000);
		next_x = data->position.x + i * cos(data->angle);
		next_y = data->position.y + i * sin(data->angle);
		i++;
	}
}

void	cast_ray(t_data *data)
{
	int	i;
	int	next_x;
	int	next_y;

	i = 0;
	next_x = data->position.x + i * cos(data->angle);
	next_y = data->position.y + i * sin(data->angle);
	while (!is_wall(data, next_x, next_y))
	{
		mlx_put_pixel(data->rays, next_x, next_y, 0x00FF00FF);
		next_x = data->position.x + i * cos(data->angle);
		next_y = data->position.y + i * sin(data->angle);
		i++;
	}
}

void	map_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_ray(data);
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
	cast_ray(data);
}
