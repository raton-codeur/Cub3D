/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/20 17:40:04 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	player_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->player->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->player->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player->instances[0].x += 5;
}
