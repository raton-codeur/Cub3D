/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:57:11 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/11 16:38:01 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int 	get_map_size(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
bool	first_and_last_line(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	
	j = skip_spaces(data->map[i], j,ft_strlen(data->map[i]));
	while (data->map[i][j] != '\0')
	{
		if (data->map[i][j] != '1' && data->map[i][j] != ' ')
			return (ft_putendl_fd("Error\nMap is not closed", 2), false);
		j++;
	}
	i = data->map_size - 1;
	j = 0;
	j = skip_spaces(data->map[i], j,ft_strlen(data->map[i]));
	while (data->map[i][j] != '\0')
	{
		if (data->map[i][j] != '1' && data->map[i][j] != ' ')
			return (ft_putendl_fd("Error\nMap is not closed", 2), false);
		j++;
	}
	return (true);
}

bool	first_and_last_char(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		j = skip_spaces(data->map[i], j,ft_strlen(data->map[i]));
		if (data->map[i][j] != '1')
			return (ft_putendl_fd("Error\nMap is not closed", 2), false);
		j = ft_strlen(data->map[i]) - 1;
		if (data->map[i][j] != '1')
			return (ft_putendl_fd("Error\nMap is not closed", 2), false);
		i++;
	}
	return (true);		
}

bool	check_non_leading_spaces(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		j = skip_spaces(data->map[i], j,ft_strlen(data->map[i]));
		while (data->map[i][j] != '\0')
		{
			j++;
			if (data->map[i][j] == ' ')
			{
				if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != ' ')
					return (ft_putendl_fd("Error\nMap is not closed", 2), false);
				if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != ' ')
					return (ft_putendl_fd("Error\nMap is not closed", 2), false);	
			}
		}
		i++;
	}
	return (true);
}

bool	check_map_lines(t_data *data)
{	
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i > 0 && ft_strlen(data->map[i]) > ft_strlen(data->map[i - 1]) && (size_t)j >= ft_strlen(data->map[i - 1]))
			{
				if (data->map[i][j] != '1')
					return (ft_putendl_fd("Error\nMap is not closed", 2), false);
			}
			if (i < data->map_size - 1 && ft_strlen(data->map[i]) > ft_strlen(data->map[i + 1]) && (size_t)j >= ft_strlen(data->map[i + 1]))
			{
				if (data->map[i][j] != '1')
					return (ft_putendl_fd("Error\nMap is not closed", 2), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
	