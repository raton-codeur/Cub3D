/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/10/23 11:43:31 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	color_range(t_data *data)
{
	if (data->floor_rgb->r < 0 || data->floor_rgb->r > 255)
		return (perror("Invalid floor color"), false);
	if (data->floor_rgb->g < 0 || data->floor_rgb->g > 255)
		return (perror("Invalid floor color"), false);
	if (data->floor_rgb->b < 0 || data->floor_rgb->b > 255)
		return (perror("Invalid floor color"), false);
	if (data->ceil_rgb->r < 0 || data->ceil_rgb->r > 255)
		return (perror("Invalid ceil color"), false);
	if (data->ceil_rgb->g < 0 || data->ceil_rgb->g > 255)
		return (perror("Invalid ceil color"), false);
	if (data->ceil_rgb->b < 0 || data->ceil_rgb->b > 255)
		return (perror("Invalid ceil color"), false);
	return (true);
}

static bool	check_split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (ft_putendl_fd("Error/n Invalid color", 2), false);
	return (true);
}

static bool	colors_to_rgb(t_color *color, char *str)
{
	char	**split;

	split = ft_split(str, ",");
	if (split == NULL)
		return (perror("Memory allocation failed"), false);
	if (!check_split_size(split))
	{
		deep_free((void **)split);
		return (false);
	}
	if (!check_split_content(split))
	{
		deep_free((void **)split);
		return (false);
	}
	remove_ws_from_split(split);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	deep_free((void **)split);
	return (true);
}

bool	find_colors(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "F", 1) == 0)
		{
			if (!copy_texture(data, &data->floor_color, i, j + 1))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "C", 1) == 0)
		{
			if (!copy_texture(data, &data->ceil_color, i, j + 1))
				return (false);
		}
	}
	data->floor_rgb = ft_calloc(1, sizeof(t_color));
	if (data->floor_rgb == NULL)
		return (perror("Memory allocation failed"), false);
	data->ceil_rgb = ft_calloc(1, sizeof(t_color));
	if (data->ceil_rgb == NULL)
		return (perror("Memory allocation failed"), false);
	return (true);
}

bool	fill_rgb_colors(t_data *data)
{
	if (!colors_to_rgb(data->floor_rgb, data->floor_color))
		return (false);
	if (!colors_to_rgb(data->ceil_rgb, data->ceil_color))
		return (false);
	if (!color_range(data))
		return (false);
	return (true);
}
