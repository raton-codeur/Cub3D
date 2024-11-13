/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/13 22:16:44 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "hook.h"

void reverse_map(t_data *data)
{
	int i, j;
	int height, width;
	char **new_map;
	
	j = 0;
	while (data->map[0][j])
		j++;
	width = j;
	height = array_size((void **)data->map);
	new_map = ft_calloc(width + 1, sizeof(char *));
	if (new_map == NULL)
		return (error_exit(MALLOC, data));
	j = 0;
	while (j < width)
	{
		new_map[j] = ft_calloc(height + 1, sizeof(char));
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

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	parse_map(&data, argc, argv);
	// print_map(&data);
	init_mlx(&data);
	reverse_map(&data);
	mlx_key_hook(data.mlx, esc_hook, &data);
	mlx_loop_hook(data.mlx, main_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
