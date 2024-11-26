/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/26 09:31:17 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

mlx_image_t	*get_img_from_png(t_data *data, const char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*result;

	texture = mlx_load_png(file);
	if (texture == NULL)
		return (NULL);
	result = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (result);
}

// void	init_wall_img(t_data *data)
// {
// 	data->wall = get_img_from_png(data, "textures/mur.png");
// 	if (data->wall == NULL)
// 		return (mlx_perror_exit(data));
// }

void	init_mlx(t_data *data)
{
	init_background(data);
	init_walls(data);
	// init_wall_img(data);
	init_map(data);
	init_rays(data);
	init_player(data);
	data->fog_height = W_HEIGHT * 0.3;
	data->fog_state = 1;
}
