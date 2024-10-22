/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:35:11 by jteste            #+#    #+#             */
/*   Updated: 2024/10/22 14:57:49 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	skip_spaces(char *str, int i, int len)
{
	while (i < len && ft_isspace(str[i]) == true)
		i++;
	return (i);
}

static bool	copy_texture(t_data *data, char **dest, int i, int j)
{
	while (ft_isspace(data->cub_file[i][j]) == true)
		j++;
	*dest = ft_strdup(data->cub_file[i] + j);
	if (dest == NULL)
		return (perror("Memory allocation failed"), false);
	return (true);
}

bool	find_textures(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "NO", 2) == 0)
		{
			if (!copy_texture(data, &data->north_texture, i, j + 2))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "SO", 2) == 0)
		{
			if (!copy_texture(data, &data->south_texture, i, j + 2))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "WE", 2) == 0)
		{
			if (!copy_texture(data, &data->west_texture, i, j + 2))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "EA", 2) == 0)
		{
			if (!copy_texture(data, &data->east_texture, i, j + 2))
				return (false);
		}
	}
	return (true);
}

static bool	colors_to_rgb(t_data *data, t_color *color, char *str)
{
	char	**split;

	split = ft_split(str, ",");
	if (split == NULL)
		return (perror("Memory allocation failed"), false);
	color = ft_calloc(1, sizeof(t_color));
	if (color == NULL)
		return (perror("Memory allocation failed"), false);
	if (!ft_strisdigit(split[0]) || !ft_strisdigit(split[1]) || !ft_strisdigit(split[2]))
		return (perror("Invalid color"), false);
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
	// if (!colors_to_rgb(data))
	// 	return (false);
	// if (!check_colors_range(data))
	// 	return (false);
	return (true);
}

// {
// 	char	**split;

// 	split = ft_split(data->ceil_color, ",");
// 	if (split == NULL)
// 		return (perror("Memory allocation failed"), false);
// 	data->floor_rgb = ft_calloc(1, sizeof(t_color));
// 	if (data->floor_rgb == NULL)
// 		return (perror("Memory allocation failed"), false);
// 	if (!ft_strisdigit(split[0]) || !ft_strisdigit(split[1]) || !ft_strisdigit(split[2]))
// 		return (perror("Invalid color"), false);	
// 	data->floor_rgb->r = ft_atoi(split[0]);
// 	data->floor_rgb->g = ft_atoi(split[1]);
// 	data->floor_rgb->b = ft_atoi(split[2]);
// 	deep_free((void **)split);
// 	split = ft_split(data->floor_color, ",");
// 	if (split == NULL)
// 		return (perror("Memory allocation failed"), false);
// 	data->ceil_rgb = ft_calloc(1, sizeof(t_color));
// 	if (data->ceil_rgb == NULL)
// 		return (perror("Memory allocation failed"), false);
// 	data->ceil_rgb->r = ft_atoi(split[0]);
// 	data->ceil_rgb->g = ft_atoi(split[1]);
// 	data->ceil_rgb->b = ft_atoi(split[2]);
// 	return (true);
// }