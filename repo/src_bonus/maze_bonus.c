/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:18:24 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 11:14:22 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	init_maze(t_data *data)
{
	uint32_t	i;
	uint32_t	j;

	data->map = ft_calloc(data->map_width + 1, sizeof(char *));
	if (data->map == NULL)
		error_exit(MALLOC, data);
	i = 0;
	while (i < data->map_width)
	{
		data->map[i] = ft_calloc(data->map_height + 1, sizeof(char));
		if (data->map[i] == NULL)
			error_exit(MALLOC, data);
		j = 0;
		while (j < data->map_height)
			data->map[i][j++] = '1';
		i++;
	}
	data->map[data->i_start][data->j_start] = data->dir_start;
	data->walls
		= ft_calloc(data->map_width * data->map_height + 1, sizeof(t_wall));
	if (data->walls == NULL)
		error_exit(MALLOC, data);
	srand(time(NULL));
}

void	generate_maze(t_data *data)
{
	t_wall	wall;
	int		i;

	init_maze(data);
	add_walls(data, data->i_start, data->j_start);
	while (data->wall_count > 0)
	{
		i = rand() % data->wall_count;
		wall = data->walls[i];
		data->walls[i] = data->walls[--data->wall_count];
		pass_wall(data, wall.i, wall.j, wall.d);
		if (current_is_inner_unexplored(data))
		{
			open_path(data, wall);
			add_walls(data, data->i, data->j);
		}
	}
}
