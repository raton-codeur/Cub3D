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
	data->player->instances[0].x = data->pos_x * SIZE_BOX - SIZE_PLAYER / 2;
	data->player->instances[0].y = data->pos_y * SIZE_BOX - SIZE_PLAYER / 2;
}

void print_position(t_data *data)
{
	printf("x = %f, y = %f\n", data->pos_x, data->pos_y);
}

int	is_wall(t_data *data, double x, double y)
{
	return (data->map[(int)x][(int)y] == '1');
}

void	draw_ray(t_data *data, double camera_x, uint32_t color)
{
	double x, y;

	data->ray_dir_x = data->dir_x + data->plane_x * camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * camera_x;
	x = data->pos_x;
	y = data->pos_y;
	while (!is_wall(data, x, y))
	{
		mlx_put_pixel(data->rays, x * SIZE_BOX, y * SIZE_BOX, color);
		x += data->ray_dir_x * 0.01;
		y += data->ray_dir_y * 0.01;
	}
}

void draw_wall_line(t_data *data)
{
	data->y_start = (data->walls->height - data->line_height) / 2;
	data->y_end = data->y_start + data->line_height;
	data->y = data->y_start;
	while (data->y < data->y_end)
	{
		mlx_put_pixel(data->walls, data->x, data->y, data->color);
		data->y++;
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	draw_ray(data, -1, 0);
	// draw_ray(data, 0, 0);
	draw_ray(data, 1, 0);
	erase_image(data->walls);
	check_keys(data);
	// print_position(data);
	draw_ray(data, -1, 0x00FF00FF);
	// draw_ray(data, 0, 0x00FF00FF);
	draw_ray(data, 1, 0x00FF00FF);
	data->x = 0;
	while (data->x < data->walls->width)
	{
		// data->x = data->walls->width / 2;
		data->i = (int)data->pos_x;
		data->j = (int)data->pos_y;
		data->camera_x = 2 * data->x / (double)data->walls->width - 1;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
		if (data->ray_dir_x < 0)
		{
			data->step_i = -1;
			data->side_dist_x = (data->pos_x - data->i) * data->delta_dist_x;
		}
		else
		{
			data->step_i = 1;
			data->side_dist_x = (data->i + 1.0 - data->pos_x) * data->delta_dist_x;
		}
		if (data->ray_dir_y < 0)
		{
			data->step_j = -1;
			data->side_dist_y = (data->pos_y - data->j) * data->delta_dist_y;
		}
		else
		{
			data->step_j = 1;
			data->side_dist_y = (data->j + 1.0 - data->pos_y) * data->delta_dist_y;
		}
		data->hit = 0;
		while (data->hit == 0)
		{
			if (data->side_dist_x < data->side_dist_y)
			{
				data->side_dist_x += data->delta_dist_x;
				data->i += data->step_i;
				data->side = 0;
			}
			else
			{
				data->side_dist_y += data->delta_dist_y;
				data->j += data->step_j;
				data->side = 1;
			}
			if (data->map[data->i][data->j] == '1')
				data->hit = 1;
		}
		if (data->side == 0 && data->step_i == -1)
			data->color = 0xFF0000FF;
		else if (data->side == 0 && data->step_i == 1)
			data->color = 0x00FF00FF;
		else if (data->side == 1 && data->step_j == -1)
			data->color = 0x0000FFFF;
		else
			data->color = 0xFFFF00FF;
		// printf("mur touché en i = %d, j = %d\n", data->i, data->j);
		if (data->side == 0)
			data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
		else
			data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
		// printf("distance : %f\n", data->perp_wall_dist);
		data->line_height = W_HEIGHT / data->perp_wall_dist;
		if (data->line_height < 0)
			data->line_height = 0;
		if (data->line_height > W_HEIGHT)
			data->line_height = W_HEIGHT;
		// printf("hauteur du mur = %d\n", data->line_height);
		draw_wall_line(data);
		data->x++;
	}
}
 