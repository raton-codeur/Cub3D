/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:52:24 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/12 12:15:23 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
				if (data->i != -1 || data->j != -1)
					return (perror_exit("Multiple player", data));
				data->j = j;
				data->i = i;
				data->player_dir = data->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (data->i == -1 || data->j == -1)
		perror_exit("No player", data);
}

static bool	is_char_in_set(char c)
{
	if (c != '0' && c != '1' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E' && c != ' ')
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
