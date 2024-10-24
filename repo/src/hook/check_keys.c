/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:23:11 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 19:23:20 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	check_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		data->x += STEP_MOVE * cos(data->angle);
		data->y += STEP_MOVE * sin(data->angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		data->x -= STEP_MOVE * cos(data->angle);
		data->y -= STEP_MOVE * sin(data->angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->x += STEP_MOVE * cos(data->angle - M_PI_2);
		data->y += STEP_MOVE * sin(data->angle - M_PI_2);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->x += STEP_MOVE * cos(data->angle + M_PI_2);
		data->y += STEP_MOVE * sin(data->angle + M_PI_2);
	}
	data->player->instances[0].x = data->x - SIZE_PLAYER / 2;
	data->player->instances[0].y = data->y - SIZE_PLAYER / 2;
}

void	check_angle_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle -= STEP_VIEW;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle += STEP_VIEW;
}
