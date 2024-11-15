/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/11/15 09:10:28 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		return (ft_putendl_fd("Error\nInvalid color", 2), false);
	return (true);
}

static char	*remove_leading_ws(char *str)
{
	int		i;
	int		start;
	char	*buff;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	start = i;
	while (str[i])
		i++;
	buff = ft_substr(str, start, i - start);
	if (!buff)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	return (buff);
}

static bool	colors_to_rgb(t_color *color, char *str)
{
	char	**split;
	char	*trimmed_str;

	trimmed_str = remove_leading_ws(str);
	if (trimmed_str == NULL)
		return (perror("Memory allocation failed"), false);
	split = ft_split(trimmed_str, ",");
	free(trimmed_str);
	if (split == NULL)
		return (perror("Memory allocation failed"), false);
	if (!check_split_size(split))
		return (deep_free((void **)split), false);
	trimmed_str = remove_newline(split[2]);
	if (trimmed_str == NULL)
		return (deep_free((void **)split), false);
	split[2] = trimmed_str;
	if (!check_split_content(split))
		return (deep_free((void **)split), false);
	if (!check_split_content_size(split))
		return (deep_free((void **)split), false);
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
			data->floor_color_line = i;
			if (!copy_texture(data, &data->floor_color_str, i, j + 1))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "C", 1) == 0)
		{
			data->ceil_color_line = i;
			if (!copy_texture(data, &data->ceil_color_str, i, j + 1))
				return (false);
		}
	}
	if (data->floor_color_str == NULL || data->ceil_color_str == NULL)
		return (ft_putendl_fd("Error\nMissing color", 2), false);
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
	if (!colors_to_rgb(data->floor_rgb, data->floor_color_str))
		return (false);
	if (!colors_to_rgb(data->ceil_rgb, data->ceil_color_str))
		return (false);
	if (!color_range(data))
		return (false);
	return (true);
}

unsigned int	rgb_color_to_hex(t_color *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}
