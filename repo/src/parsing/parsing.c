/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:53:13 by jteste            #+#    #+#             */
/*   Updated: 2024/11/11 18:13:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	extract_textures_and_colors(t_data *data)
{
	if (!find_textures_no_so(data, -1, 0))
		return (false);
	if (!find_textures_we_ea(data, -1, 0))
		return (false);
	if (!check_textures(data))
		return (false);
	if (!find_colors(data, -1, 0))
		return (false);
	if (!fill_rgb_colors(data))
		return (false);
	data->ceil_rgb->hex = rgb_color_to_hex(data->ceil_rgb);
	data->floor_rgb->hex = rgb_color_to_hex(data->floor_rgb);
	return (true);
}

static bool	extract_map(t_data *data)
{
	if (!find_map(data, 0, 0))
		return (false);
	if (data->map == NULL)
		return (ft_putendl_fd("Error\nMissing map", 2), false);
	if (!remove_newline_from_map(data))
		return (false);
	return (true);
}

static bool	check_map(t_data *data)
{
	data->map_size = get_map_size(data->map);
	if(data->map_size < 3)
		return (ft_putendl_fd("Error\nMap is too small", 2), false);
	if(!first_and_last_line(data))
		return (false);
	if(!first_and_last_char(data))
		return (false);
	if(!check_non_leading_spaces(data))
		return (false);
	if(!check_map_lines(data))
		return (false);
	if(!check_map_chars(data))
		return (false);
	return (true);
}

void	parse_map(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (ft_putendl_fd("Error\nUsage: ./cub3D <map.cub>", 2), exit(1));
	data->path_map = ft_strdup(argv[1]);
	if (data->path_map == NULL)
		return (ft_putendl_fd("Malloc Error", 2), exit(1));
	if (!extension_checker(data->path_map))
		return (free_all(data), exit(1));
	if (!load_cub_file(data))
		return (free_all(data), exit(1));
	if (!extract_textures_and_colors(data))
		return (free_all(data), exit(1));
	if (!extract_map(data))
		return (free_all(data), exit(1));
	if (!check_cub_order(data))
		return (free_all(data), exit(1));
	if (!check_map(data))
		return (free_all(data), exit(1));
}
