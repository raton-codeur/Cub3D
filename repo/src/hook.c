/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/28 01:28:28 by qhauuy           ###   ########.fr       */
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
		if (data->depth_config == 1)
			data->depth_config = 0;
		else
			data->depth_config = 1;
		check_depth_config(data);
	}
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
	{
		if (data->depth_config == 2)
			data->depth_config = 0;
		else
			data->depth_config = 2;
		check_depth_config(data);
	}
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		data->fog_state = !data->fog_state;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		// rotation de pi radians
		double	old_dir_x;
		double	old_plane_x;

		old_dir_x = data->dir_x;
		old_plane_x = data->plane_x;
		data->dir_x = old_dir_x * cos(-M_PI) - data->dir_y * sin(-M_PI);
		data->dir_y = old_dir_x * sin(-M_PI) + data->dir_y * cos(-M_PI);
		data->plane_x
			= old_plane_x * cos(-M_PI) - data->plane_y * sin(-M_PI);
		data->plane_y
			= old_plane_x * sin(-M_PI) + data->plane_y * cos(-M_PI);
	}
}

void	check_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}

void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data);
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_image(data->rays_map);
	erase_image(data->game);
	check_movement_keys(data);
	check_rotation_keys(data);
	dda(data);
}
