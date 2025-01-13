/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2025/01/13 16:08:30 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static void	color_range(t_data *data, int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		perror_exit("Invalid color range", data);
}

static uint32_t	colors_to_rgb(t_data *data, char *str)
{
	char	**spt;
	int		r;
	int		g;
	int		b;

	spt = split_parsing(str, ',', data);
	if (spt == NULL)
		return (perror_exit("Memory allocation failed", data), 0);
	if (!check_split_content(spt))
		return (deep_free((void **)spt),
			perror_exit("Invalid color", data), 0);
	if (array_size((void **)spt) != 3)
		return (deep_free((void **)spt),
			perror_exit("Invalid color", data), 0);
	r = ft_atoi(spt[0]);
	g = ft_atoi(spt[1]);
	b = ft_atoi(spt[2]);
	color_range(data, r, g, b);
	deep_free((void **)spt);
	return ((r << 24) | (g << 16) | b << 8 | 0xFF);
}

void	fill_rgb_colors(t_data *data)
{
	check_color_string(data, data->floor_color_str);
	check_color_string(data, data->ceil_color_str);
	data->floor_color = colors_to_rgb(data, data->floor_color_str);
	data->ceil_color = colors_to_rgb(data, data->ceil_color_str);
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
}
