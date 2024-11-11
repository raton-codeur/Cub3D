/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:31:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/11 16:39:15 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_rays(t_data *data)
{
	data->rays = mlx_new_image(data->mlx, data->map_img->width, data->map_img->height);
	if (data->rays == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->rays, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->rays), mlx_perror_exit(data));
}
