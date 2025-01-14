/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:28 by jteste            #+#    #+#             */
/*   Updated: 2025/01/14 13:38:22 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_spaces(char *str, int i, int len)
{
	while (i < len && ft_isspace(str[i]) == true)
		i++;
	return (i);
}

void	extension_checker(t_data *data)
{
	int		i;
	int		len;
	int		start;
	char	*buf;

	len = ft_strlen(data->path_map);
	if (len < 5)
		perror_exit("Invalid file extension", data);
	i = 0;
	start = skip_spaces(data->path_map, i, len);
	i = start;
	while (data->path_map[i])
		i++;
	if (i < len)
	{
		buf = ft_substr(data->path_map, start, i);
		if (!buf)
			return (perror_exit("Memory allocation failed", data));
		free(data->path_map);
		data->path_map = buf;
		len = ft_strlen(data->path_map);
	}
	if (ft_strncmp(&data->path_map[i - 4], ".cub", 4) != 0)
		perror_exit("Invalid file extension", data);
}

bool	check_split_content(char **split)
{
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		j = 0;
		j = skip_spaces(split[i], j, ft_strlen(split[i]));
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_split_content_size(char **split)
{
	if (ft_strlen(split[0]) == 0 || ft_strlen(split[0]) > 3)
		return (false);
	if (ft_strlen(split[1]) == 0 || ft_strlen(split[1]) > 3)
		return (false);
	if (ft_strlen(split[2]) == 0 || ft_strlen(split[2]) > 3)
		return (false);
	return (true);
}

char	*remove_newline(char *str, t_data *data)
{
	int		i;
	char	*buff;

	i = 0;
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == '\n')
	{
		buff = ft_substr(str, 0, i - 1);
		if (!buff)
			return (perror_exit("Memory allocation failed", data), NULL);
		free(str);
		return (buff);
	}
	return (str);
}
