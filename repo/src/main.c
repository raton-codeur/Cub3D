/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/04 17:49:19 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "raycasting.h"

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
	return (data->i % 2 == 1 && data->i > 0 && data->i < data->width - 1
		&& data->j % 2 == 1 && data->j > 0 && data->j < data->height - 1
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
	data->map[MAZE_START_I][MAZE_START_J] = 'S';
	data->walls
		= ft_calloc(data->map_width * data->map_height + 1, sizeof(t_wall));
	if (data->walls == NULL)
		error_exit(MALLOC, data);
}

void add_walls(t_data *data, uint32_t i, uint32_t j)
{
	int	d;

	d = 0;
	while (d < 4)
	{
		pass_wall(data, i, j, d);
		if (current_is_inner_unexplored(data))
			data->walls[data->wall_count++] = (t_wall){i, j, d};
		d++;
	}
}

void	generate_maze(t_data *data)
{
	t_wall	wall;

	init_maze(data);
	add_walls(data, MAZE_START_I, MAZE_START_J);
	while (data->wall_count > 0)
	{
		data->i = rand() % data->wall_count;
		wall = data->walls[data->i];
		data->walls[data->i] = data->walls[--data->wall_count];
		pass_wall(data, wall.i, wall.j, wall.d);
		if (current_is_inner_unexplored(data))
		{
			open_path(data, wall);
			add_walls(data, data->i, data->j);
        }
	}
}

# define MAZE_WIDTH 10
# define MAZE_HEIGHT 15

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parsing(&data, argc, argv);
	deep_free((void *)data.map);
	data.width = MAZE_WIDTH * 2 + 1;
	data.height = MAZE_HEIGHT * 2 + 1;
	generate_maze(&data);
	print_map(&data);
	init_mlx(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop_hook(data.mlx, main_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
