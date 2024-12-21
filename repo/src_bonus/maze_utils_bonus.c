/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:22:42 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 15:46:27 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

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

void	add_walls(t_data *data, uint32_t i, uint32_t j)
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
