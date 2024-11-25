/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/25 15:52:49 by qhauuy           ###   ########.fr       */
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

void fill_fog(t_data *data)
{
	int x, y;
	double factor;

	y = 0;
	while (y < (int)(data->fog->height / 2))
	{
		x = 0;
		while (x < W_WIDTH)
		{
			factor = 2 * y / (double)data->fog->height;
			factor = 0.5 + 0.5 * cos(M_PI * factor) ;
			mlx_put_pixel(data->fog, x, data->fog->height / 2 - y, 0x70707000 + factor * 255);
			mlx_put_pixel(data->fog, x, data->fog->height / 2 + y, 0x70707000 + factor * 255);
			x++;
		}
		y++;
	}	
}

void	init_fog(t_data *data)
{
	data->fog = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT * 0.5);
	if (data->fog == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->fog, 0, (W_HEIGHT - data->fog->height) / 2) == -1)
	{
		mlx_delete_image(data->mlx, data->fog);
		return (mlx_perror_exit(data));
	}
	fill_fog(data);
}

void	init_mlx(t_data *data)
{
	init_background(data);
	init_walls(data);
	init_fog(data);
	// init_wall_img(data);
	init_map(data);
	init_rays(data);
	init_player(data);
}
