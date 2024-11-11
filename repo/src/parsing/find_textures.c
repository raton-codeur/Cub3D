/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:35:11 by jteste            #+#    #+#             */
/*   Updated: 2024/11/11 16:38:08 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	check_texture_name(char *texture)
{
	int		len;

	len = ft_strlen(texture);
	if (len < 5)
	{
		ft_putendl_fd("Error\nInvalid texture file name", 2);
		return (false);
	}
	if (ft_strncmp(&texture[len - 4], ".png", 4) != 0)
	{
		ft_putendl_fd("Error\nTexture must be a .png file", 2);
		return (false);
	}
	if (ft_strchr(texture, ' ') != NULL || ft_strchr(texture, '\t') != NULL)
	{
		ft_putendl_fd("Error\nInvalid texture file name", 2);
		return (false);
	}
	return (true);
}

bool	check_textures(t_data *data)
{
	if (data->north_texture == NULL || data->south_texture == NULL
		|| data->west_texture == NULL || data->east_texture == NULL)
	{
		ft_putendl_fd("Error\nMissing texture", 2);
		return (false);
	}
	if (!check_texture_name(data->north_texture)
		|| !check_texture_name(data->south_texture)
		|| !check_texture_name(data->west_texture)
		|| !check_texture_name(data->east_texture))
		return (false);
	return (true);
}

bool	copy_texture(t_data *data, char **dest, int i, int j)
{
	int	end;

	end = ft_strlen(data->cub_file[i]);
	while (ft_isspace(data->cub_file[i][j]) == true)
		j++;
	while ((ft_isspace(data->cub_file[i][end]) == true)
		|| (data->cub_file[i][end] == '\0') || (data->cub_file[i][end] == '\n'))
		end--;
	*dest = ft_substr(data->cub_file[i] + j, 0, end - j + 1);
	if (dest == NULL)
		return (perror("Memory allocation failed"), false);
	return (true);
}

bool	find_textures_no_so(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "NO", 2) == 0)
		{
			data->north_texture_line = i;
			if (!copy_texture(data, &data->north_texture, i, j + 2))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "SO", 2) == 0)
		{
			data->south_texture_line = i;
			if (!copy_texture(data, &data->south_texture, i, j + 2))
				return (false);
		}
	}
	return (true);
}

bool	find_textures_we_ea(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "WE", 2) == 0)
		{
			data->west_texture_line = i;
			if (!copy_texture(data, &data->west_texture, i, j + 2))
				return (false);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "EA", 2) == 0)
		{
			data->east_texture_line = i;
			if (!copy_texture(data, &data->east_texture, i, j + 2))
				return (false);
		}
	}
	return (true);
}
