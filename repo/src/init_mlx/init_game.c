/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:46:49 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/27 10:58:19 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_game(t_data *data)
{
	data->game = mlx_new_image(data->mlx, data->width, data->width);
	if (data->game == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->game, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->game);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->game->instances[0], 1);
}
