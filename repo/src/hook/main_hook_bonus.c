/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 22:50:52 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "raycasting.h"

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
	check_movement_keys(data);
	check_rotation_keys(data);
	get_closest_door(data);
	dda(data);
	if (data->depth_config == 2)
		draw_mini_map(data);
}
