/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/15 10:25:21 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "hook.h"

void reverse_map(t_data *data)
{
	int i, j;
	char **new_map;
	
	j = 0;
	while (data->map[0][j])
		j++;
	data->map_width = j;
	data->map_height = array_size((void **)data->map);
	new_map = ft_calloc(data->map_width + 1, sizeof(char *));
	if (new_map == NULL)
		return (error_exit(MALLOC, data));
	j = 0;
	while (j < data->map_width)
	{
		new_map[j] = ft_calloc(data->map_height + 1, sizeof(char));
		if (new_map[j] == NULL)
			return (error_exit(MALLOC, data));
		j++;
	}
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

void print_map(t_data *data)
{
	int i;
	int j;

	printf("--- map ---\n      ");
	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		printf("%3d", j);
		j++;
	}
	printf("\n");
	while (data->map[i])
	{
		printf("%3d : ", i);
		j = 0;
		while (data->map[i][j])
		{
			printf("%3c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void init_dir(t_data *data)
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

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parse_map(&data, argc, argv);
	data.ceil_color = CEIL_COLOR;
	data.floor_color = FLOOR_COLOR;
	data.i_start = I_START;
	data.j_start = J_START;
	data.dir_start = 'S';
	init_dir(&data);
	// print_map(&data);
	reverse_map(&data);
	init_mlx(&data);
	mlx_key_hook(data.mlx, other_keys_hook, &data);
	mlx_loop_hook(data.mlx, main_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
