/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:11:51 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/19 15:31:35 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	init_dir(t_data *data)
{
	if (data->dir_start == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (data->dir_start == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (data->dir_start == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else if (data->dir_start == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
}

static	void	init_after_parsing(t_data *data)
{
	data->ceil_color = data->ceil_rgb->hex;
	data->floor_color = data->floor_rgb->hex;
	init_dir(data);
	get_map_dimensions(data);
	reverse_map(data);
}

void	clean_parsing(t_data *data)
{
	init_after_parsing(data);
}
