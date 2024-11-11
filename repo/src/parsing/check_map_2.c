/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:52:24 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/11 16:37:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_char_in_set(char c)
{
	if (c != '0' && c != '1' && c != 'N' 
		&& c != 'S' && c != 'W' && c != 'E' && c != ' ')
		return (false);
	return (true);
}
bool	check_map_chars(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			j = skip_spaces(data->map[i], j,ft_strlen(data->map[i]));
			if (!is_char_in_set(data->map[i][j]))
				return (ft_putendl_fd("Error\nInvalid character in map", 2), false);
			j++;
		}
		i++;
	}
	return (true);
}