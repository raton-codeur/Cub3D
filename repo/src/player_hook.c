/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/21 17:18:01 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	player_hook(void *param)
{
	t_data	*data;

	data = param;
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
}
