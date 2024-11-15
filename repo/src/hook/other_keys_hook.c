/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_keys_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:16 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/15 10:23:23 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	other_keys_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		mlx_set_instance_depth(&data->map_img->instances[0], -data->map_img->instances[0].z);
		mlx_set_instance_depth(&data->rays->instances[0], -data->rays->instances[0].z);
		mlx_set_instance_depth(&data->player->instances[0], -data->player->instances[0].z);
	}
}
