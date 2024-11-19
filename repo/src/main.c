/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/19 16:25:10 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "raycasting.h"

void	get_map_dimensions(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[0][j])
		j++;
	data->map_width = j;
	data->map_height = array_size((void **)data->map);
}

static char	**init_new_map(t_data *data)
{
	char	**new_map;
	int		j;

	new_map = ft_calloc(data->map_width + 1, sizeof(char *));
	if (new_map == NULL)
		return (error_exit(MALLOC, data), NULL);
	j = 0;
	while (j < data->map_width)
	{
		new_map[j] = ft_calloc(data->map_height + 1, sizeof(char));
		if (new_map[j] == NULL)
		{
			deep_free((void **)new_map);
			return (error_exit(MALLOC, data), NULL);
		}
		j++;
	}
	return (new_map);
}

void	reverse_map(t_data *data)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = init_new_map(data);
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

void	print_map(t_data *data)
{
	int	i;
	int	j;

	printf("      ");
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

void	init_dir(t_data *data)
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
	parsing(&data, argc, argv);
	data.ceil_color = data.ceil_rgb->hex;
	data.floor_color = data.floor_rgb->hex;
	init_dir(&data);
	print_map(&data);
	get_map_dimensions(&data);
	reverse_map(&data);
	
	init_mlx(&data);
	
	// int alpha_min = 0;
	// int alpha_max = 255;
	int y;
	y = 0;
	int alpha;
	while (y < W_HEIGHT / 2)
	{
		alpha = y;
		printf("%d : %d\n", y, alpha);
		y++;
	}
	
	
	// mlx_key_hook(data.mlx, key_hook, &data);
	// mlx_loop_hook(data.mlx, main_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}



