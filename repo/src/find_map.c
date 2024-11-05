/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:05 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/05 15:57:58 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int  count_map_lines(t_data *data, int i)
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

bool    find_map(t_data *data)
{
        
}