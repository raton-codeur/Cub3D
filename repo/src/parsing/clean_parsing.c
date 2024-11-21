/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:11:51 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/21 09:12:36 by qhauuy           ###   ########.fr       */
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
	free(data->floor_rgb);
	data->floor_rgb = NULL;
	free(data->ceil_color_str);
	data->ceil_color_str = NULL;
	free(data->ceil_rgb);
	data->ceil_rgb = NULL;
}

static	void	init_after_parsing(t_data *data)
{
	data->ceil_color = data->ceil_rgb->hex;
	data->floor_color = data->floor_rgb->hex;
	init_dir(data);
	get_map_dimensions(data);
	reverse_map(data);
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	// data->wall_no = get_img_from_png(data, data->north_texture);
	// data->wall_so = get_img_from_png(data, data->south_texture);
	// data->wall_we = get_img_from_png(data, data->west_texture);
	// data->wall_ea = get_img_from_png(data, data->east_texture);
	// if (data->wall_no == NULL || data->wall_so == NULL
	// 	|| data->wall_we == NULL || data->wall_ea == NULL)
	// 	perror_exit("Error\nCannot load textures", data);
}
 
void	clean_parsing(t_data *data)
{
	init_after_parsing(data);
	free_parsing(data);
}
