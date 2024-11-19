/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/11/19 14:22:26 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	rgb_color_to_hex(t_color *color)
{
	return ((color->r << 24) | (color->g << 16) | color->b << 8 | 0xFF);
}

void	find_colors(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "F", 1) == 0)
		{
			data->floor_color_line = i;
			copy_texture(data, &data->floor_color_str, i, j + 1);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "C", 1) == 0)
		{
			data->ceil_color_line = i;
			copy_texture(data, &data->ceil_color_str, i, j + 1);
		}
	}
	if (data->floor_color_str == NULL || data->ceil_color_str == NULL)
		return (perror_exit("Missing color", data));
	data->floor_rgb = ft_calloc(1, sizeof(t_color));
	if (data->floor_rgb == NULL)
		return (perror_exit("Memory allocation failed", data));
	data->ceil_rgb = ft_calloc(1, sizeof(t_color));
	if (data->ceil_rgb == NULL)
		return (perror_exit("Memory allocation failed", data));
}
