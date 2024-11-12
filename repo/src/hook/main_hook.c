/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 19:09:110 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	erase_image(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}

void	check_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		data->pos_x += STEP_MOVE * data->dir_x;
		data->pos_y += STEP_MOVE * data->dir_y;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		data->pos_x -= STEP_MOVE * data->dir_x;
		data->pos_y -= STEP_MOVE * data->dir_y;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->pos_x += STEP_MOVE * data->dir_y;
		data->pos_y -= STEP_MOVE * data->dir_x;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->pos_x -= STEP_MOVE * data->dir_y;
		data->pos_y += STEP_MOVE * data->dir_x;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)) // rotate right
	{
		data->dir_x = data->dir_x * cos(STEP_VIEW) - data->dir_y * sin(STEP_VIEW);
		data->dir_y = data->dir_x * sin(STEP_VIEW) + data->dir_y * cos(STEP_VIEW);
		data->plane_x = data->plane_x * cos(STEP_VIEW) - data->plane_y * sin(STEP_VIEW);
		data->plane_y = data->plane_x * sin(STEP_VIEW) + data->plane_y * cos(STEP_VIEW);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)) // rotate left
	{
		data->dir_x = data->dir_x * cos(-STEP_VIEW) - data->dir_y * sin(-STEP_VIEW);
		data->dir_y = data->dir_x * sin(-STEP_VIEW) + data->dir_y * cos(-STEP_VIEW);
		data->plane_x = data->plane_x * cos(-STEP_VIEW) - data->plane_y * sin(-STEP_VIEW);
		data->plane_y = data->plane_x * sin(-STEP_VIEW) + data->plane_y * cos(-STEP_VIEW);
	}
	data->player->instances[0].x = data->pos_x - SIZE_PLAYER / 2;
	data->player->instances[0].y = data->pos_y - SIZE_PLAYER / 2;
}

void print_position(t_data *data)
{
	printf("x = %f = %d, y = %f = %d\n", data->pos_x, (int)(data->pos_x / SIZE_BOX), data->pos_y, (int)(data->pos_y / SIZE_BOX));
}

int get_map_i(double x)
{
	return ((int)(x / SIZE_BOX));
}

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[get_map_i(y)][get_map_i(x)] == '1');
}

// void	draw_ray(t_data *data, double camera_x)
// {
// 	data->ray_dir_x = data->dir_x + data->plane_x * camera_x;
// 	data->ray_dir_y = data->dir_y + data->plane_y * camera_x;
// 	data->ray_x = data->pos_x;
// 	data->ray_y = data->pos_y;
// 	while (!is_wall(data, data->ray_x, data->ray_y))
// 	{ 
// 		mlx_put_pixel(data->rays, data->ray_x, data->ray_y, 0x00FF00FF);
// 		data->ray_x += data->ray_dir_x / 10;
// 		data->ray_y += data->ray_dir_y / 10;
// 	}
// }

void	draw_ray(t_data *data, double camera_x)
{
	data->ray_dir_x = data->dir_x + data->plane_x * camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * camera_x;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->ray_i = get_map_i(data->pos_x);
	data->ray_j = get_map_i(data->pos_y);
	while (!is_wall(data, data->x, data->y))
	{ 
		mlx_put_pixel(data->rays, data->x, data->y, 0x00FF00FF);
		data->x += step_x;
		data->y += step_y;
	}
}


void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_image(data->rays);
	erase_image(data->walls);
	check_keys(data);
	// print_position(data);
	draw_ray(data, 0);
	// double side_dist_x, side_dist_y;
	// side_dist_x = fabs(1 / data->pos_x);
	// side_dist_y = fabs(1 / data->pos_y);
	// printf("side dist x : %f, side dist y : %f\n", side_dist_x, side_dist_y);
}
