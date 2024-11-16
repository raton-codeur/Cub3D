/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:46:49 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 14:15:37 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_walls(t_data *data)
{
	data->walls = mlx_new_image(data->mlx, \
		data->background->width, data->background->height);
	if (data->walls == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->walls, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->walls);
		return (mlx_perror_exit(data));
	}
}
