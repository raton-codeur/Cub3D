/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maze_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:30:37 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 16:07:24 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static void	init_maze(t_data *data)
{
	char	**spt;
	int		w;
	int		h;

	w = 0;
	h = 0;
	spt = ft_split(data->maze_str, " ");
	if (spt == NULL)
		return (perror_exit("Memory allocation failed", data));
	if (array_size((void **)spt) != 2)
		return (deep_free((void **)spt), perror_exit("Invalid maze", data));
	w = ft_atoi(spt[0]);
	h = ft_atoi(spt[1]);
	deep_free((void **)spt);
	if (w < 0 || h < 0 || w > MAZE_MAX || h > MAZE_MAX)
		return (perror_exit("Invalid maze size", data));
	data->map_width = w * 2 + 1;
	data->map_height = h * 2 + 1;
	data->i_start = MAZE_START_I;
	data->j_start = MAZE_START_J;
	data->dir_start = MAZE_DIR_START;
}

static bool	check_if_maze(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cub_file[i])
	{
		j = skip_spaces(data->cub_file[i], 0, ft_strlen(data->cub_file[i]));
		while (data->cub_file[i][j])
		{
			if (ft_strncmp(&data->cub_file[i][j], "M", 1) == 0)
			{
				data->maze_line = i;
				copy_texture(data, &data->maze_str, i, j + 1);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

void	check_maze(t_data *data)
{
	if (check_if_maze(data) == true)
		init_maze(data);
	else
	{
		data->maze_str = NULL;
		data->maze_line = -1;
	}
}
