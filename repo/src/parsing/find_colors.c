/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/11/12 14:51:38 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	rgb_color_to_hex(t_color *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}

void	find_colors(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "F", 1) == 0)
		{
			data->floor_color_line = i;
			copy_texture(data, &data->floor_color, i, j + 1);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "C", 1) == 0)
		{
			data->ceil_color_line = i;
			copy_texture(data, &data->ceil_color, i, j + 1);
		}
	}
	if (data->floor_color == NULL || data->ceil_color == NULL)
		return (perror_exit("Missing color", data));
	data->floor_rgb = ft_calloc(1, sizeof(t_color));
	if (data->floor_rgb == NULL)
		return (perror_exit("Memory allocation failed", data));
	data->ceil_rgb = ft_calloc(1, sizeof(t_color));
	if (data->ceil_rgb == NULL)
		return (perror_exit("Memory allocation failed", data));
}
