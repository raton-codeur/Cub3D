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

static void	erase_image(mlx_image_t *image)
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

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)(y / SIZE_BOX)][(int)(x / SIZE_BOX)] == '1');
}

/* on veut tracer une droite à partir du player */
double	draw_ray(t_data *data, double dir_x, double dir_y)
{
	double x;
	double y;
	double step_x;
	double step_y;

	x = data->pos_x;
	y = data->pos_y;
	step_x = dir_x / 10;
	step_y = dir_y / 10;
	while (!is_wall(data, x, y))
	{
		mlx_put_pixel(data->rays, x, y, 0x00FF00FF);
		x += step_x;
		y += step_y;
	}
	return (sqrt((x - data->pos_x) * (x - data->pos_x) + (y - data->pos_y) * (y - data->pos_y)));
}
double	get_wall_height(double length_ray)
{
	return (W_HEIGHT - (length_ray * W_HEIGHT * 2 / W_WIDTH));
}

void	draw_wall_x(t_data *data, uint32_t x_start, uint32_t length)
{
	uint32_t	y_start;
	uint32_t	y;
	uint32_t	x;

	y_start = (data->walls->height - length) / 2;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < length)
		{
			mlx_put_pixel(data->walls, x_start + x, y_start + y, 0x00FF00FF);
			y++;
		}
		x++;
	}
}

void cast_rays(t_data *data)
{
	double camera_x, ray_dir_x, ray_dir_y, length_ray, wall_x_height;
	for (int x = 0; x < (int)data->walls->width; x++)
	{
		camera_x = 2 * x / (double)data->walls->width - 1;
		ray_dir_x = data->dir_x + data->plane_x * camera_x;
		ray_dir_y = data->dir_y + data->plane_y * camera_x;
		length_ray = draw_ray(data, ray_dir_x, ray_dir_y);
		wall_x_height = get_wall_height(length_ray);
		draw_wall_x(data, x, wall_x_height);
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_image(data->rays);
	erase_image(data->walls);
	check_keys(data);
	cast_rays(data);	
}
