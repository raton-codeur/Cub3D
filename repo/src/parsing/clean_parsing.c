/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:11:51 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/11 20:33:16 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

static void	load_walls(t_data *data)
{
	data->wall_no = mlx_load_png(data->north_texture);
	if (data->wall_no == NULL)
		mlx_perror_exit(data);
	data->wall_so = mlx_load_png(data->south_texture);
	if (data->wall_so == NULL)
		mlx_perror_exit(data);
	data->wall_we = mlx_load_png(data->west_texture);
	if (data->wall_we == NULL)
		mlx_perror_exit(data);
	data->wall_ea = mlx_load_png(data->east_texture);
	if (data->wall_ea == NULL)
		mlx_perror_exit(data);
}

static	void	init_after_parsing(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	init_dir(data);
	if (data->maze_line != -1)
		generate_maze(data);
	else
		get_map_dimensions(data);
	reverse_map(data);
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	// mlx_set_window_size(data->mlx, monitor_width, monitor_height);
	mlx_set_window_pos(data->mlx, \
		(monitor_width - W_WIDTH) / 2, (monitor_height - W_HEIGHT) / 2);
	load_walls(data);
}

void	clean_parsing(t_data *data)
{
	init_after_parsing(data);
	free_parsing(data);
}
