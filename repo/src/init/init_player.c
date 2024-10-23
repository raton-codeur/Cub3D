/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:17:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 16:07:34 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_player(t_data *data)
{
	data->player = mlx_new_image(data->mlx, SIZE_PLAYER, SIZE_PLAYER);
	if (data->player == NULL)
        return (mlx_perror_exit(data));
	fill_image(data->player, 0xFF0000FF);
	if (mlx_image_to_window(data->mlx, data->player, C_START * SIZE_BOX, R_START * SIZE_BOX) == -1)
		return (mlx_delete_image(data->mlx, data->player), mlx_perror_exit(data));
	data->position.x = data->player->instances[0].x + SIZE_PLAYER_HALF;
	data->position.y = data->player->instances[0].y + SIZE_PLAYER_HALF;
}
