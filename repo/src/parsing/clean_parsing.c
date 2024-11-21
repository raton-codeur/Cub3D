/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:11:51 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/21 12:52:42 by hakgyver         ###   ########.fr       */
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
}

// static void	load_walls(t_data *data)
// {
// 	data->wall_no = get_img_from_png(data, data->north_texture);
// 	if (data->wall_no == NULL)
// 		mlx_perror_exit(data);
// 	data->wall_so = get_img_from_png(data, data->south_texture);
// 	if (data->wall_so == NULL)
// 		mlx_perror_exit(data);
// 	data->wall_we = get_img_from_png(data, data->west_texture);
// 	if (data->wall_we == NULL)
// 		mlx_perror_exit(data);
// 	data->wall_ea = get_img_from_png(data, data->east_texture);
// 	if (data->wall_ea == NULL)
// 		mlx_perror_exit(data);
// }

static	void	init_after_parsing(t_data *data)
{
	init_dir(data);
	get_map_dimensions(data);
	reverse_map(data);
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	// load_walls(data);
}

void	clean_parsing(t_data *data)
{
	init_after_parsing(data);
	free_parsing(data);
}
