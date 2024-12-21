/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:14:08 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/21 18:22:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	first_and_last_line(t_data *data)
{
	int	i;
	int	j;

	j = skip_spaces(data->map[0], 0, ft_strlen(data->map[0]));
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1' && data->map[0][j] != ' ')
			perror_exit("Map is not closed", data);
		j++;
	}
	i = data->map_height - 1;
	j = 0;
	j = skip_spaces(data->map[i], j, ft_strlen(data->map[i]));
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1' && data->map[i][j] != ' ')
			perror_exit("Map is not closed", data);
		j++;
	}
}
