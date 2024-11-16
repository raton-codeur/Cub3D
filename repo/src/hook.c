/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 17:13:11 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "raycasting.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		mlx_set_instance_depth(&data->map_img->instances[0], \
			-data->map_img->instances[0].z);
		mlx_set_instance_depth(&data->rays->instances[0], \
			-data->rays->instances[0].z);
		mlx_set_instance_depth(&data->player->instances[0], \
			-data->player->instances[0].z);
	}
}

void	erase_image(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}

void	check_movement_keys(t_data *data)
{
	double	new;

	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		new = data->pos_x + STEP_MOVE * data->dir_x;
		if (data->map[(int)(new)][(int)(data->pos_y)] != '1')
			data->pos_x = new;
		data->player->instances[0].x
			= data->pos_x * data->box_size - data->player->width / 2;
		new = data->pos_y + STEP_MOVE * data->dir_y;
		if (data->map[(int)(data->pos_x)][(int)(new)] != '1')
			data->pos_y = new;
		data->player->instances[0].y
			= data->pos_y * data->box_size - data->player->width / 2;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		new = data->pos_x - STEP_MOVE * data->dir_x;
		if (data->map[(int)(new)][(int)(data->pos_y)] != '1')
			data->pos_x = new;
		data->player->instances[0].x
			= data->pos_x * data->box_size - data->player->width / 2;
		new = data->pos_y - STEP_MOVE * data->dir_y;
		if (data->map[(int)(data->pos_x)][(int)(new)] != '1')
			data->pos_y = new;
		data->player->instances[0].y
			= data->pos_y * data->box_size - data->player->width / 2;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		new = data->pos_x + STEP_MOVE * data->dir_y;
		if (data->map[(int)(new)][(int)(data->pos_y)] != '1')
			data->pos_x = new;
		data->player->instances[0].x
			= data->pos_x * data->box_size - data->player->width / 2;
		new = data->pos_y - STEP_MOVE * data->dir_x;
		if (data->map[(int)(data->pos_x)][(int)(new)] != '1')
			data->pos_y = new;
		data->player->instances[0].y
			= data->pos_y * data->box_size - data->player->width / 2;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		new = data->pos_x - STEP_MOVE * data->dir_y;
		if (data->map[(int)(new)][(int)(data->pos_y)] != '1')
			data->pos_x = new;
		data->player->instances[0].x
			= data->pos_x * data->box_size - data->player->width / 2;
		new = data->pos_y + STEP_MOVE * data->dir_x;
		if (data->map[(int)(data->pos_x)][(int)(new)] != '1')
			data->pos_y = new;
		data->player->instances[0].y
			= data->pos_y * data->box_size - data->player->width / 2;
	}
}

void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->dir_x
			= data->dir_x * cos(STEP_VIEW) - data->dir_y * sin(STEP_VIEW);
		data->dir_y
			= data->dir_x * sin(STEP_VIEW) + data->dir_y * cos(STEP_VIEW);
		data->plane_x
			= data->plane_x * cos(STEP_VIEW) - data->plane_y * sin(STEP_VIEW);
		data->plane_y
			= data->plane_x * sin(STEP_VIEW) + data->plane_y * cos(STEP_VIEW);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->dir_x
			= data->dir_x * cos(-STEP_VIEW) - data->dir_y * sin(-STEP_VIEW);
		data->dir_y
			= data->dir_x * sin(-STEP_VIEW) + data->dir_y * cos(-STEP_VIEW);
		data->plane_x
			= data->plane_x * cos(-STEP_VIEW) - data->plane_y * sin(-STEP_VIEW);
		data->plane_y
			= data->plane_x * sin(-STEP_VIEW) + data->plane_y * cos(-STEP_VIEW);
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	draw_ray(data, -1, 0x00000000);
	draw_ray(data, 1, 0x00000000);
	erase_image(data->walls);
	check_movement_keys(data);
	check_rotation_keys(data);
	draw_ray(data, -1, 0x00FF00FF);
	draw_ray(data, 1, 0x00FF00FF);
	dda(data);
}
