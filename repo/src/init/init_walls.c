/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:46:49 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 17:00:08 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_walls(t_data *data)
{
	data->walls = mlx_new_image(data->mlx, data->background->width, data->background->height);
	if (data->walls == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->walls, W_WIDTH / 2, 0) == -1)
		return (mlx_delete_image(data->mlx, data->walls), mlx_perror_exit(data));
	fill_image(data->walls, 0x000000FF);
}
