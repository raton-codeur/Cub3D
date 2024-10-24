/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 15:35:54 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1');
}

int	draw_ray_in_map(t_data *data, double angle)
{
	int	i;
	int	x;
	int	y;

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

int	get_length_in_wall(int length_in_map)
{
	return (W_HEIGHT - ((length_in_map * W_HEIGHT) / (W_WIDTH / 2)));
}

int	get_ray_position(int i)
{
	return (i * W_WIDTH / NB_RAYS);
}

void	draw_ray_in_wall(t_data *data, int x, int length)
{
	int	y_start;
	int	y;

	y_start = (W_HEIGHT - length) / 2;
	y = 0;
	while (y < length)
	{
		mlx_put_pixel(data->walls, x, y_start + y, 0x00FF00FF);
		y++;
	}
}

void	cast_ray(t_data *data, double angle, int i)
{
	draw_ray_in_wall(data, get_ray_position(i), get_length_in_wall(draw_ray_in_map(data, angle)));
}

void	cast_rays(t_data *data)
{
	double	angle;
	double	angle_end;
	double	step;
	int		i;

	angle = data->angle - ANGLE_VIEW / 2;
	angle_end = angle + ANGLE_VIEW;
	step = ANGLE_VIEW / NB_RAYS;
	i = 0;
	while (angle < angle_end)
	{
		cast_ray(data, angle, i);
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		// data->player->instances[0].x -= STEP * cos(data->angle);
		// data->player->instances[0].y -= STEP * sin(data->angle);
		// data->position.x -= (int)(STEP * cos(data->angle));
		// data->position.y -= (int)(STEP * sin(data->angle));
		data->player->instances[0].y += STEP;
		data->y += STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		// data->player->instances[0].x += STEP * cos(data->angle);
		// data->player->instances[0].y += STEP * sin(data->angle);
		// data->position.x += (int)(STEP * cos(data->angle));
		// data->position.y += (int)(STEP * sin(data->angle));
		data->player->instances[0].y -= STEP;
		data->y -= STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->player->instances[0].x -= STEP;
		data->x -= STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->player->instances[0].x += STEP;
		data->x += STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle -= 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle += 0.05;
	cast_rays(data);
}
