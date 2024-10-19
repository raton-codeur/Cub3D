/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:16 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/19 13:55:03 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action > 0)
		data->cat->instances[0].y -= 20;
	if (keydata.key == MLX_KEY_DOWN && keydata.action > 0)
		data->cat->instances[0].y += 20;
	if (keydata.key == MLX_KEY_LEFT && keydata.action > 0)
		data->cat->instances[0].x -= 20;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action > 0)
		data->cat->instances[0].x += 20;
}
