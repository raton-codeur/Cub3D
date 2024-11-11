/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:08:47 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/11 16:38:14 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_cub_order(t_data *data)
{
	if (data->map_line < data->north_texture_line
		|| data->map_line < data->south_texture_line
		|| data->map_line < data->west_texture_line
		|| data->map_line < data->east_texture_line
		|| data->map_line < data->floor_color_line
		|| data->map_line < data->ceil_color_line)
		return (ft_putendl_fd("Error\nMap is not the last element", 2), false);
	return (true);
}
