/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_after_parsing_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:11:51 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 17:38:01 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static void	init_dir(t_data *data)
{
	if (data->dir_start == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (data->dir_start == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (data->dir_start == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else if (data->dir_start == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
}

static void	free_parsing(t_data *data)
{
	free(data->path_map);
	data->path_map = NULL;
	deep_free((void **)data->cub_file);
	data->cub_file = NULL;
	free(data->north_texture);
	data->north_texture = NULL;
	free(data->south_texture);
	data->south_texture = NULL;
	free(data->west_texture);
	data->west_texture = NULL;
	free(data->east_texture);
	data->east_texture = NULL;
	free(data->floor_color_str);
	data->floor_color_str = NULL;
	free(data->ceil_color_str);
	data->ceil_color_str = NULL;
	free(data->maze_str);
	data->maze_str = NULL;
}

static void	init_textures(t_data *data)
{
	data->north = mlx_load_png(data->north_texture);
	if (data->north == NULL)
		mlx_perror_exit(data);
	data->south = mlx_load_png(data->south_texture);
	if (data->south == NULL)
		mlx_perror_exit(data);
	data->west = mlx_load_png(data->west_texture);
	if (data->west == NULL)
		mlx_perror_exit(data);
	data->east = mlx_load_png(data->east_texture);
	if (data->east == NULL)
		mlx_perror_exit(data);
	data->door = mlx_load_png("textures/door.png");
	if (data->door == NULL)
		mlx_perror_exit(data);
}

void	init_after_parsing(t_data *data)
{
	init_textures(data);
	init_dir(data);
	if (data->maze_line != -1)
		generate_maze(data);
	else
	{
		get_map_dimensions(data);
		reverse_map(data);
	}
	free_parsing(data);
}
