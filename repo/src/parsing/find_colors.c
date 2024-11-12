/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/11/12 13:33:37 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	color_range(t_data *data)
{
	if (data->floor_rgb->r < 0 || data->floor_rgb->r > 255)
		perror_exit("Invalid floor color", data);
	if (data->floor_rgb->g < 0 || data->floor_rgb->g > 255)
		perror_exit("Invalid floor color", data);
	if (data->floor_rgb->b < 0 || data->floor_rgb->b > 255)
		perror_exit("Invalid floor color", data);
	if (data->ceil_rgb->r < 0 || data->ceil_rgb->r > 255)
		perror_exit("Invalid ceil color", data);
	if (data->ceil_rgb->g < 0 || data->ceil_rgb->g > 255)
		perror_exit("Invalid ceil color", data);
	if (data->ceil_rgb->b < 0 || data->ceil_rgb->b > 255)
		perror_exit("Invalid ceil color", data);
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

static char	*remove_leading_ws(char *str, t_data *data)
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
		perror_exit("Memory allocation failed", data);
	return (buff);
}

static void	colors_to_rgb(t_data *data, t_color *color, char *str, char **spt)
{
	char	*s2;

	s2 = remove_leading_ws(str, data);
	spt = ft_split(s2, ",");
	free(s2);
	if (spt == NULL)
		return (perror_exit("Memory allocation failed", data));
	if (!check_split_size(spt))
		return (deep_free((void **)spt),
			perror_exit("Memory allocation failed", data));
	s2 = remove_newline(spt[2], data);
	if (s2 == NULL)
		return (deep_free((void **)spt),
			perror_exit("Memory allocation failed", data));
	spt[2] = s2;
	if (!check_split_content(spt))
		return (deep_free((void **)spt),
			perror_exit("Memory allocation failed", data));
	if (!check_split_content_size(spt))
		return (deep_free((void **)spt),
			perror_exit("Memory allocation failed", data));
	color->r = ft_atoi(spt[0]);
	color->g = ft_atoi(spt[1]);
	color->b = ft_atoi(spt[2]);
	deep_free((void **)spt);
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

void	fill_rgb_colors(t_data *data)
{
	colors_to_rgb(data, data->floor_rgb, data->floor_color, NULL);
	colors_to_rgb(data, data->ceil_rgb, data->ceil_color, NULL);
	color_range(data);
}

unsigned int	rgb_color_to_hex(t_color *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}
