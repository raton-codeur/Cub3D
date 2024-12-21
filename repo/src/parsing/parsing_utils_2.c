/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:08:47 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/21 11:22:31 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_cub_order(t_data *data)
{
	if (data->map_line < data->north_texture_line
		|| data->map_line < data->south_texture_line
		|| data->map_line < data->west_texture_line
		|| data->map_line < data->east_texture_line
		|| data->map_line < data->floor_color_line
		|| data->map_line < data->ceil_color_line)
		// || data->map_line < data->maze_line)
		perror_exit("Map must be at the end of the file", data);
}

void	texture_count(t_data *data, int i, int j, int count)
{
	while (data->cub_file[i])
	{
		j = 0;
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		while (data->cub_file[i][j])
		{
			if (ft_strncmp(data->cub_file[i] + j, "NO", 2) == 0)
				count++;
			else if (ft_strncmp(data->cub_file[i] + j, "SO", 2) == 0)
				count++;
			else if (ft_strncmp(data->cub_file[i] + j, "WE", 2) == 0)
				count++;
			else if (ft_strncmp(data->cub_file[i] + j, "EA", 2) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count < 4)
		perror_exit("Missing texture", data);
	else if (count > 4)
		perror_exit("Too many textures", data);
}

void	color_count(t_data *data, int i, int j, int count)
{
	while (data->cub_file[i])
	{
		j = 0;
		j = skip_spaces(data->cub_file[i], j, ft_strlen(data->cub_file[i]));
		while (data->cub_file[i][j])
		{
			if (ft_strncmp(data->cub_file[i] + j, "C", 1) == 0)
				count++;
			else if (ft_strncmp(data->cub_file[i] + j, "F", 1) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count < 2)
		perror_exit("Missing Color", data);
	else if (count > 2)
		perror_exit("Too many Colors", data);
}

bool	spaces(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}
