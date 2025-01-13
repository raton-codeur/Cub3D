/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:53:13 by jteste            #+#    #+#             */
/*   Updated: 2025/01/13 17:37:44 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static void	extract_textures_and_colors(t_data *data)
{
	texture_count(data, 0, 0, 0);
	color_count(data, 0, 0, 0);
	find_textures_no_so(data, -1, 0);
	find_textures_we_ea(data, -1, 0);
	check_textures(data);
	find_colors(data, -1, 0);
	fill_rgb_colors(data);
}

static void	extract_map(t_data *data)
{
	find_map(data, 0, 0);
	if (data->map == NULL)
		perror_exit("Missing map", data);
	remove_newline_from_map(data);
}

static void	check_map(t_data *data)
{
	get_map_size(data);
	check_map_chars(data);
	first_and_last_char(data);
	first_and_last_line(data);
	check_non_leading_spaces(data, 0, 0);
	check_map_lines(data, 0, 0);
	check_zero(data, 0, 0);
	check_doors(data, 0, 0);
	fill_spaces(data);
	normalize_map_rows(data, 0);
	find_player(data);
}

static	void	parsing_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->i_start = -1;
	data->j_start = -1;
}

void	parsing(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (ft_putendl_fd("Error\nUsage: ./cub3D <map.cub>", 2), exit(1));
	parsing_init(data);
	data->path_map = ft_strdup(ft_strtrim(argv[1], " "));
	if (data->path_map == NULL)
		return (perror_exit("Malloc failed", data));
	extension_checker(data);
	load_cub_file(data);
	extract_textures_and_colors(data);
	extract_map(data);
	check_map(data);
	check_maze(data);
	check_cub_order(data);
	init_after_parsing(data);
}
