/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2025/01/14 14:23:32 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static void	init_dimensions(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	data->w_width = 1920;
	data->w_height = 1080;
	mlx_set_window_size(data->mlx, data->w_width, data->w_height);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - data->w_width) / 2, \
		(monitor_height - data->w_height) / 2);
	data->mini_box_size = data->w_height / 40;
	if (data->map_width > data->map_height)
		data->box_size = data->w_height / 2.0 / data->map_width;
	else
		data->box_size = data->w_height / 2.0 / data->map_height;
	if (data->box_size < 10)
		error_exit(SIZE, data);
	if (data->box_size > data->mini_box_size)
		data->box_size = data->mini_box_size;
}

static void	fill_background(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < data->background->width)
	{
		y = 0;
		while (y < data->background->height)
		{
			if (y < data->background->height / 2)
				mlx_put_pixel(data->background, x, y, data->ceil_color);
			else
				mlx_put_pixel(data->background, x, y, data->floor_color);
			y++;
		}
		x++;
	}
}

static void	init_background(t_data *data)
{
	data->background = mlx_new_image(data->mlx, \
		data->w_width, data->w_height * 2);
	if (data->background == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, \
		data->background, 0, -(data->w_height / 2)) == -1)
	{
		mlx_delete_image(data->mlx, data->background);
		return (mlx_perror_exit(data));
	}
	fill_background(data);
	mlx_set_instance_depth(&data->background->instances[0], 0);
}

static void	init_game_img(t_data *data)
{
	data->game = mlx_new_image(data->mlx, data->w_width, data->w_width);
	if (data->game == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->game, 0, 0) == -1)
	{
		mlx_delete_image(data->mlx, data->game);
		return (mlx_perror_exit(data));
	}
	mlx_set_instance_depth(&data->game->instances[0], 1);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init(1, 1, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	init_dimensions(data);
	init_background(data);
	init_game_img(data);
	init_map(data);
	init_map_rays(data);
	init_map_player(data);
	init_minimap(data);
	init_minimap_player(data);
	data->mini_half = data->minimap->width / 2;
	data->mini_r_2 = data->mini_half * data->mini_half;
	data->mini_ray_limit = data->mini_r_2 - 500;
	data->step_ray_map = 3.0 / data->box_size;
	data->step_ray_minimap = 4.0 / data->mini_box_size;
}
