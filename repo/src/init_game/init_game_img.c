/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:22:30 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/15 19:22:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_game_img(t_data *data)
{
	data->game = mlx_new_image(data->mlx, data->w_width, data->w_width);
	if (data->game == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->game, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->game);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->game->instances[0], 1);
}
