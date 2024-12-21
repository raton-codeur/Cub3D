/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:52:24 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/21 18:22:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static void	check_player(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = skip_spaces(data->map[i], 0, ft_strlen(data->map[i]));
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'W' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'N')
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

static	bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			j = skip_spaces(data->map[i], j, ft_strlen(data->map[i]));
			if (is_player(data->map[i][j]))
			{
				if (data->i_start != -1 || data->j_start != -1)
					return (perror_exit("Multiple player start in map", data));
				data->i_start = j;
				data->j_start = i;
				data->dir_start = data->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (data->i_start == -1 || data->j_start == -1)
		perror_exit("No player start in map", data);
	check_player(data, 0, 0);
}

static bool	is_char_in_set(char c)
{
	if (c != '0' && c != '1' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E' && c != ' ' && c != 'D')
		return (false);
	return (true);
}

void	check_map_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			j = skip_spaces(data->map[i], j, ft_strlen(data->map[i]));
			if (!is_char_in_set(data->map[i][j]))
				return ((perror_exit("Invalid character in map", data)));
			j++;
		}
		i++;
	}
}
