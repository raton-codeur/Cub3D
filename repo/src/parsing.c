/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:53:13 by jteste            #+#    #+#             */
/*   Updated: 2024/10/24 12:41:25 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	textures_and_colors(t_data *data)
{
	if (!find_textures(data, -1, 0))
		return (false);
	if (!check_textures(data))
		return (false);
	if (!find_colors(data, -1, 0))
		return (false);
	if (!fill_rgb_colors(data))
		return (false);
	return (true);
}

bool	parser(t_data *data)
{
	if (!extension_checker(data->path_map))
		return (false);
	if (!load_cub_file(data))
		return (false);
	if (!textures_and_colors(data))
		return (false);
	return (true);
}
