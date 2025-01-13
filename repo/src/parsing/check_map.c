/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:57:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 15:23:49 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_map_size(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
		i++;
	data->map_height = i;
	if (data->map_height < 3)
		return (perror_exit("Map is too small", data));
}

void	check_non_leading_spaces(t_data *d, int i, int j)
{
	while (d->map[i])
	{
		j = skip_spaces(d->map[i], 0, ft_strlen(d->map[i]));
		while (d->map[i][j] != '\0')
		{
			if (spaces(d->map[i][j]) == 1)
			{
				if (j > 0 && d->map[i][j - 1] != '1' &&
				!spaces(d->map[i][j - 1]))
					return (perror_exit("Map is not closed", d));
				if (d->map[i][j + 1] != '\0'
				&& d->map[i][j + 1] != '1' && !spaces(d->map[i][j + 1]))
					return (perror_exit("Map is not closed", d));
				if (i > 0 && (size_t)j < ft_strlen(d->map[i - 1])
					&& d->map[i -1][j] != '1' && !spaces(d->map[i -1][j]))
					return (perror_exit("Map is not closed", d));
				if (d->map[i + 1] && (size_t)j < ft_strlen(d->map[i + 1])
					&& d->map[i + 1][j] != '1' && !spaces(d->map[i + 1][j]))
					return (perror_exit("Map is not closed", d));
			}
			j++;
		}
		i++;
	}
}

void	first_and_last_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		j = skip_spaces(data->map[i], j, ft_strlen(data->map[i]));
		if (data->map[i][j] == '\0')
		{
			i++;
			continue ;
		}
		if (data->map[i][j] != '1')
			return (perror_exit("Map is not closed", data));
		j = ft_strlen(data->map[i]) - 1;
		while (j > 0 && ft_isspace(data->map[i][j]) == 1)
			j--;
		if (data->map[i][j] != '1')
			return (perror_exit("Map is not closed", data));
		i++;
	}
}

void	check_map_lines(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i > 0 && ft_strlen(data->map[i]) > ft_strlen(data->map[i - 1])
				&& (size_t)j >= ft_strlen(data->map[i - 1]))
			{
				if (data->map[i][j] != '1' && ft_isspace(data->map[i][j]) == 0)
					return (perror_exit("Map is not closed", data));
			}
			if ((uint32_t)i < data->map_height - 1 && ft_strlen(data->map[i])
				> ft_strlen(data->map[i + 1])
				&& (size_t)j >= ft_strlen(data->map[i + 1]))
			{
				if (data->map[i][j] != '1' && ft_isspace(data->map[i][j]) == 0)
					return (perror_exit("Map is not closed", data));
			}
			j++;
		}
		i++;
	}
}

void	check_zero(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = skip_spaces(data->map[i], 0, ft_strlen(data->map[i]));
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '0')
			{
				if (j > 0 && ft_isspace(data->map[i][j - 1]) == 1)
					return (perror_exit("Map is not closed", data));
				if (data->map[i][j + 1] != '\0'
				&& ft_isspace(data->map[i][j + 1]) == 1)
					return (perror_exit("Map is not closed", data));
				if (i > 0 && (size_t)j < ft_strlen(data->map[i - 1])
					&& ft_isspace(data->map[i - 1][j]) == 1)
					return (perror_exit("Map is not closed", data));
				if (data->map[i + 1] && (size_t)j < ft_strlen(data->map[i + 1])
					&& ft_isspace(data->map[i + 1][j]) == 1)
					return (perror_exit("Map is not closed", data));
			}
			j++;
		}
		i++;
	}
}
