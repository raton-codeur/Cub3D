/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:05 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 16:08:50 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static int	count_map_lines(t_data *data, int i)
{
	int	count;

	count = 0;
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0] == '\0')
			break ;
		count++;
		i++;
	}
	return (count);
}

void	find_map(t_data *data, int i, int j)
{
	while (data->cub_file[i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		if (data->cub_file[i][j] == '1')
		{
			data->map = ft_calloc(count_map_lines(data, i) + 1, sizeof(char *));
			if (data->map == NULL)
				perror_exit("Memory allocation failed", data);
			data->map[count_map_lines(data, i)] = NULL;
			data->map_line = i;
			j = 0;
			while (data->cub_file[i])
			{
				data->map[j] = ft_strdup(data->cub_file[i]);
				if (data->map[j] == NULL)
					perror_exit("Memory allocation failed", data);
				i++;
				j++;
			}
		}
		else
			i++;
	}
}

static	bool	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

static void	remove_empty_line(t_data *data, int i, int j, int start)
{
	while (data->map[i])
	{
		if (is_line_empty(data->map[i]))
		{
			if (start == -1)
				start = i;
		}
		else
			start = -1;
		i++;
	}
	if (start != -1)
	{
		j = start;
		while (data->map[j])
		{
			free(data->map[j]);
			data->map[j] = NULL;
			j++;
		}
	}
}

void	remove_newline_from_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		data->map[i] = remove_newline(data->map[i], data);
		if (!data->map[i])
			perror_exit("Memory allocation failed", data);
		i++;
	}
	remove_empty_line(data, 0, 0, -1);
}
