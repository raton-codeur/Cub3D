/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:57:11 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/07 15:14:03 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	j = skip_spaces(data->map[i], j,ft_strlen(data->map[i]));
	while (data->map[i][j] != '\0')
	{
		if (data->map[i][j] != '1' && data->map[i][j] != ' ')
			return (ft_putendl_fd("2 Error\nMap is not closed", 2), false);
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
			return (printf("sorti sur map[%d][%d]\n", i, j ), ft_putendl_fd("1 Error\nMap is not closed", 2), false);
		j = ft_strlen(data->map[i]) - 1;
		if (data->map[i][j] != '1')
			return (printf("sorti sur map[%d][%d]\n", i, j ), ft_putendl_fd("2 Error\nMap is not closed", 2), false);
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

	// If strlen(curr_row) > strlen(row_on_top) && current col > strlen(row_on_top), current character should be '1'
	// If strlen(curr_row) > strlen(row_on_bottom) && current col > strlen(row_on_bottom), current character should be '1'
	
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
			if (i > 0 && ft_strlen(data->map[i]) > ft_strlen(data->map[i - 1]) && (size_t)j > ft_strlen(data->map[i - 1]))
			{
				if (data->map[i][j] != '1')
					return (ft_putendl_fd("Error\nMap is not closed", 2), false);
			}
			if (i < data->map_size - 1 && ft_strlen(data->map[i]) > ft_strlen(data->map[i + 1]) && (size_t)j > ft_strlen(data->map[i + 1]))
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
	