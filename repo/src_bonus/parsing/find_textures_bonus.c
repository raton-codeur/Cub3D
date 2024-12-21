/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:35:11 by jteste            #+#    #+#             */
/*   Updated: 2024/11/12 13:33:04 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	check_texture_name(char *texture, t_data *data)
{
	int		len;

	len = ft_strlen(texture);
	if (len < 5)
		perror_exit("Invalid texture file name", data);
	if (ft_strncmp(&texture[len - 4], ".png", 4) != 0)
		perror_exit("Texture must be a .png file", data);
	if (ft_strchr(texture, ' ') != NULL || ft_strchr(texture, '\t') != NULL)
		perror_exit("Invalid texture file name", data);
}

void	check_textures(t_data *data)
{
	if (data->north_texture == NULL || data->south_texture == NULL
		|| data->west_texture == NULL || data->east_texture == NULL)
		perror_exit("Missing texture", data);
	check_texture_name(data->north_texture, data);
	check_texture_name(data->south_texture, data);
	check_texture_name(data->west_texture, data);
	check_texture_name(data->east_texture, data);
}

void	copy_texture(t_data *data, char **dest, int i, int j)
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
		return (perror_exit("Memory allocation failed", data));
}

void	find_textures_no_so(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "NO", 2) == 0)
		{
			data->north_texture_line = i;
			copy_texture(data, &data->north_texture, i, j + 2);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "SO", 2) == 0)
		{
			data->south_texture_line = i;
			copy_texture(data, &data->south_texture, i, j + 2);
		}
	}
}

void	find_textures_we_ea(t_data *data, int i, int j)
{
	while (data->cub_file[++i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (ft_strncmp(data->cub_file[i] + j, "WE", 2) == 0)
		{
			data->west_texture_line = i;
			copy_texture(data, &data->west_texture, i, j + 2);
		}
		else if (ft_strncmp(data->cub_file[i] + j, "EA", 2) == 0)
		{
			data->east_texture_line = i;
			copy_texture(data, &data->east_texture, i, j + 2);
		}
	}
}
