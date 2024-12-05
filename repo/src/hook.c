/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/05 14:46:09 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "raycasting.h"

void	depth(mlx_image_t *img, int depth)
{
	mlx_set_instance_depth(&img->instances[0], depth);
}

void	check_depth_config(t_data *data)
{
	if (data->config == 1)
	{
		depth(data->player_map, 4);
		depth(data->rays_map, 3);
		depth(data->map_img, 2);
		depth(data->minimap, -1);
		depth(data->minimap_bg, -1);
		depth(data->minimap_rays, -1);
		depth(data->minimap_player, -1);
	}
	else if (data->config == 2)
	{
		depth(data->minimap_player, 5);
		depth(data->minimap_rays, 4);
		depth(data->minimap, 3);
		depth(data->minimap_bg, 2);
		depth(data->map_img, -1);
		depth(data->rays_map, -1);
		depth(data->player_map, -1);
	}
	else
	{
		depth(data->player_map, -1);
		depth(data->map_img, -1);
		depth(data->minimap, -1);
		depth(data->minimap_bg, -1);
		depth(data->minimap_rays, -1);
		depth(data->minimap_player, -1);
		depth(data->rays_map, -1);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		if (data->config == 1)
			data->config = 0;
		else
			data->config = 1;
		check_depth_config(data);
	}
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
	{
		if (data->config == 2)
			data->config = 0;
		else
			data->config = 2;
		check_depth_config(data);
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
	erase_image(data->rays_map);
	erase_image(data->walls);
	check_movement_keys(data);
	check_rotation_keys(data);
	dda(data);
	draw_mini_map(data);
}
