/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:17:31 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/20 14:22:59 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

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
		set_depth(data);
	}
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
	{
		if (data->depth_config == 2)
			data->depth_config = 0;
		else
			data->depth_config = 2;
		set_depth(data);
	}
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		data->fog_state = !data->fog_state;
	open_door(data, keydata);
	shot_with_gun(data, keydata);
}
