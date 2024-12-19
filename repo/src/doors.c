/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:02:35 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/19 12:31:32 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_doors(t_data *data, int i, int j)
{
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'D')
			{
				if (j > 0 && ft_isspace(data->map[i][j - 1]) == 1)
					return (perror_exit("Map is not closed", data));
				if (data->map[i][j + 1] != '\0'
				&& ft_isspace(data->map[i][j + 1]) == 1)
					return (perror_exit("Map is not closed", data));
				if (i > 0 && (size_t)j < ft_strlen(data->map[i - 1])
					&& ft_isspace(data->map[i - 1][j]) == 1)
					return (perror_exit("Map is not closed", data));
				if (data->map[i + 1] && (size_t)j < ft_strlen(data->map[i + 1])
					&& ft_isspace(data->map[i + 1][j]) == 1)
					return (perror_exit("Map is not closed", data));
			}
			j++;
		}
		i++;
	}
}

void	get_closest_door(t_data *d)
{
	d->p_x = (int)d->pos_x;
	d->p_y = (int)d->pos_y;
	if (d->p_x > 0 && d->map[d->p_x - 1][d->p_y] == 'D')
	{
		d->door_to_open_x = d->p_x - 1;
		d->door_to_open_y = d->p_y;
	}
	else if (d->map[d->p_x + 1] && d->map[d->p_x + 1][d->p_y] == 'D')
	{
		d->door_to_open_x = d->p_x + 1;
		d->door_to_open_y = d->p_y;
	}
	else if (d->p_y > 0 && d->map[d->p_x][d->p_y - 1] == 'D')
	{
		d->door_to_open_x = d->p_x;
		d->door_to_open_y = d->p_y - 1;
	}
	else if (d->map[d->p_x][d->p_y + 1] == 'D')
	{
		d->door_to_open_x = d->p_x;
		d->door_to_open_y = d->p_y + 1;
	}
}

static bool	is_player_near_door(t_data *d)
{
	if (d->p_x - 1 == d->door_to_open_x && d->p_y == d->door_to_open_y)
		return (true);
	else if (d->p_x + 1 == d->door_to_open_x && d->p_y == d->door_to_open_y)
		return (true);
	else if (d->p_x == d->door_to_open_x && d->p_y - 1 == d->door_to_open_y)
		return (true);
	else if (d->p_x == d->door_to_open_x && d->p_y + 1 == d->door_to_open_y)
		return (true);
	return (false);
}

void	open_door(t_data *d, mlx_key_data_t keydata)
{
	if (d->door_to_open_x == -1 || d->door_to_open_y == -1)
		return ;
	if (d->map[d->door_to_open_x][d->door_to_open_y] == 'D'
		&& is_player_near_door(d))
	{
		if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		{
			d->map[d->door_to_open_x][d->door_to_open_y] = '0';
			return ;
		}
	}
	else if (d->map[d->door_to_open_x][d->door_to_open_y] == '0'
		&& is_player_near_door(d))
	{
		if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		{
			d->map[d->door_to_open_x][d->door_to_open_y] = 'D';
			return ;
		}
	}
}
