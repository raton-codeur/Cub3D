/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:53:13 by jteste            #+#    #+#             */
/*   Updated: 2024/11/06 12:09:52 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	extract_textures_and_colors(t_data *data)
{
	if (!find_textures(data, -1, 0))
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

bool	extract_map(t_data *data)
{
	if (!find_map(data))
		return (false);
	if (data->map == NULL)
		return (ft_putendl_fd("Error\nMissing map", 2), false);
	if (!remove_newline_from_map(data))
		return (false);
	return (true);
}

bool	parser(t_data *data)
{
	if (!extension_checker(data->path_map))
		return (false);
	if (!load_cub_file(data))
		return (false);
	if (!extract_textures_and_colors(data))
		return (false);
	if (!extract_map(data))
		return (false);
	if (!check_cub_order(data))
		return (false);
	// if	(!map_checker(data));
	// 	return(true);
	// clean_after_parsing(data);
	return (true);
}
