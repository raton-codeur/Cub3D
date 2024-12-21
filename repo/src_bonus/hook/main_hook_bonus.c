/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 16:46:03 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_bonus.h"
#include "raycasting_bonus.h"

static void	check_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}

static void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_x(data, STEP_ROTATE_X);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_x(data, -STEP_ROTATE_X);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		rotate_y(data, STEP_ROTATE_Y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		rotate_y(data, -STEP_ROTATE_Y);
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_get_time() < data->time + 0.033)
		return ;
	data->time = mlx_get_time();
	check_movement_keys(data);
	check_rotation_keys(data);
	// get_closest_door(data);
	erase(data->game);
	if (data->depth_config == 1)
		erase(data->map_rays);
	if (data->depth_config == 2)
		render_minimap(data);
	dda(data);
}
