/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/26 17:50:53 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "raycasting.h"

void depth(mlx_image_t *img, int depth)
{
	mlx_set_instance_depth(&img->instances[0], depth);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		data->depth = (data->depth + 1) % 3;
		if (data->depth == 0)
		{
			depth(data->walls, 5);
			depth(data->background, 4);
			depth(data->player, 3);
			depth(data->rays, 2);
			depth(data->map_img, 1);
			depth(data->minimap, 0);
		}
		else if (data->depth == 1)
		{
			depth(data->player, 5);
			depth(data->rays, 4);
			depth(data->map_img, 3);
			depth(data->walls, 2);
			depth(data->background, 1);
			depth(data->minimap, 0);
		}
		else
		{
			depth(data->rays, 5);
			depth(data->minimap, 4);
			depth(data->walls, 3);
			depth(data->background, 2);
			depth(data->player, 1);
			depth(data->map_img, 0);
		}
	}
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		data->fog_state = !data->fog_state;
}

void	erase_image(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}

void	check_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}

void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data);
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_image(data->rays);
	erase_image(data->walls);
	check_movement_keys(data);
	check_rotation_keys(data);
	dda(data);
}
