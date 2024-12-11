/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_maze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:36:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/11 20:32:49 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <time.h>

void	pass_wall(t_data *data, uint32_t i, uint32_t j, int d)
{
	data->i = i;
	data->j = j;
	if (d == 0)
		data->j -= 2;
	else if (d == 1)
		data->j += 2;
	else if (d == 2)
		data->i -= 2;
	else if (d == 3)
		data->i += 2;
}

void	open_path(t_data *data, t_wall w)
{
	if (w.d == 0)
	{
		data->map[w.i][w.j - 1] = '0';
		data->map[w.i][w.j - 2] = '0';
	}
	else if (w.d == 1)
	{
		data->map[w.i][w.j + 1] = '0';
		data->map[w.i][w.j + 2] = '0';
	}
	else if (w.d == 2)
	{
		data->map[w.i - 1][w.j] = '0';
		data->map[w.i - 2][w.j] = '0';
	}
	else if (w.d == 3)
	{
		data->map[w.i + 1][w.j] = '0';
		data->map[w.i + 2][w.j] = '0';
	}
}

int	current_is_inner_unexplored(t_data *data)
{
	return (data->i % 2 == 1 && data->i > 0 && data->i < data->map_width
		&& data->j % 2 == 1 && data->j > 0 && data->j < data->map_height
		&& data->map[data->i][data->j] == '1');
}

void	init_maze(t_data *data)
{
	uint32_t	i;
	uint32_t	j;

	data->map = ft_calloc(data->map_width + 1, sizeof(char *));
	if (data->map == NULL)
		error_exit(MALLOC, data);
	i = 0;
	while (i < (uint32_t)data->map_width)
	{
		data->map[i] = ft_calloc(data->map_height + 1, sizeof(char));
		if (data->map[i] == NULL)
			error_exit(MALLOC, data);
		j = 0;
		while (j < (uint32_t)data->map_height)
			data->map[i][j++] = '1';
		i++;
	}
	data->map[data->i_start][data->j_start] = 'S';
	data->walls_maze
		= ft_calloc(data->map_width * data->map_height + 1, sizeof(t_wall));
	if (data->walls_maze == NULL)
		error_exit(MALLOC, data);
	srand(time(NULL));
}

void	add_walls(t_data *data, uint32_t i, uint32_t j)
{
	int	d;

	d = 0;
	while (d < 4)
	{
		pass_wall(data, i, j, d);
		if (current_is_inner_unexplored(data))
			data->walls_maze[data->wall_count++] = (t_wall){i, j, d};
		d++;
	}
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
		wall = data->walls_maze[i];
		data->walls_maze[i] = data->walls_maze[--data->wall_count];
		pass_wall(data, wall.i, wall.j, wall.d);
		if (current_is_inner_unexplored(data))
		{
			open_path(data, wall);
			add_walls(data, data->i, data->j);
		}
	}
}
