/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:27:14 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/14 14:24:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	get_map_dimensions(t_data *data)
{
	data->map_width = ft_strlen(data->map[0]);
	data->map_height = array_size((void **)data->map);
}

static char	**init_new_map(t_data *data)
{
	char	**new_map;
	int		j;

	new_map = ft_calloc(data->map_width + 1, sizeof(char *));
	if (new_map == NULL)
		return (error_exit(MALLOC, data), NULL);
	j = 0;
	while (j < (int)data->map_width)
	{
		new_map[j] = ft_calloc(data->map_height + 1, sizeof(char));
		if (new_map[j] == NULL)
		{
			deep_free((void **)new_map);
			return (error_exit(MALLOC, data), NULL);
		}
		j++;
	}
	return (new_map);
}

void	reverse_map(t_data *data)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = init_new_map(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			new_map[j][i] = data->map[i][j];
			j++;
		}
		i++;
	}
	deep_free((void **)data->map);
	data->map = new_map;
}
