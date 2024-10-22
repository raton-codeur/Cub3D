/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:35:11 by jteste            #+#    #+#             */
/*   Updated: 2024/10/22 15:15:23 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	copy_texture(t_data *data, char **dest, int i, int j)
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
