/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:05 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/06 12:03:57 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	count_map_lines(t_data *data, int i)
{
	int	count;

	count = 0;
	while (data->cub_file[++i])
	{
		if (data->cub_file[i][0] == '\0')
			break ;
		count++;
	}
	return (count);
}

bool	find_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map = ft_calloc(count_map_lines(data, i) + 1, sizeof(char *));
	if (data->map == NULL)
		return (perror("Memory allocation failed"), false);
	data->map[count_map_lines(data, i)] = NULL;
	while (data->cub_file[i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (data->cub_file[i][j] == '1')
		{
			data->map_line = i;
			j = 0;
			while (data->cub_file[i])
			{
				data->map[j] = ft_strdup(data->cub_file[i]);
				if (data->map[j] == NULL)
					return (perror("1 Memory allocation failed"), false);
				i++;
				j++;
			}
		}
		else
			i++;
	}
	return (true);
}

bool	remove_newline_from_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		data->map[i] = remove_newline(data->map[i]);
		if (data->map[i] == NULL)
			return (perror("Memory allocation failed"), false);
		i++;
	}
	return (true);
}
