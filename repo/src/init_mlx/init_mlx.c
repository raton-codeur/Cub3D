/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/21 13:54:53 by hakgyver         ###   ########.fr       */
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

void	init_wall_img(t_data *data)
{
	data->wall = get_img_from_png(data, "textures/mur.png");
	if (data->wall == NULL)
		return (mlx_perror_exit(data));
}

// void	fill_fog_sides(t_data *data)
// {
// 	int x;
// 	int y;
// 	uint32_t color;
// 	double factor;

// 	color = 0x70707000;
// 	y = 0;
// 	while (y < (int)data->fog->height / 3)
// 	{
// 		x = 0;
// 		while (x < W_WIDTH)
// 		{
// 			factor = pow(1 - (3 * y / (double)data->fog->height), 2);
// 			mlx_put_pixel(data->fog, x, data->fog->height / 3 - y, color + 255 * factor);
// 			mlx_put_pixel(data->fog, x, data->fog->height * 2 / 3 + y, color + 255 * factor);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	fill_fog_center(t_data *data)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < (int)data->fog->height / 3)
// 	{
// 		x = 0;
// 		while (x < W_WIDTH)
// 		{
// 			mlx_put_pixel(data->fog, x, data->fog->height / 3 + y, 0x707070FF);
// 			x++;
// 		}
// 		y++;
// 	}
// }


void fill_fog(t_data *data)
{
	int x, y;
	uint32_t color;
	double factor;

	color = 0x70707000;
	y = 0;
	while (y < (int)data->fog->height / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			factor = pow(1 - (2 * y / (double)data->fog->height), 2);
			mlx_put_pixel(data->fog, x, data->fog->height / 2 - y, color + 255 * factor);
			mlx_put_pixel(data->fog, x, data->fog->height / 2 + y, color + 255 * factor);
			x++;
		}
		y++;
	}
}


void	init_fog(t_data*data)
{
	data->fog = mlx_new_image(data->mlx, W_WIDTH, (W_HEIGHT * 3) / 5);
	if (data->fog == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->fog, 0, W_HEIGHT / 5) == -1)
	{
		mlx_delete_image(data->mlx, data->fog);
		return (mlx_perror_exit(data));
	}
	// fill_fog_center(data);
	// fill_fog_sides(data);
	fill_fog(data);
}

void	init_mlx(t_data *data)
{
	init_background(data);
	init_fog(data);
	init_walls(data);
	init_wall_img(data);
	init_map(data);
	init_rays(data);
	init_player(data);
}
