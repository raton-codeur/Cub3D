/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/11/21 11:57:38 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
}
