/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/19 18:29:25 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_length(char *line)
{
	int	i;
	
	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	get_dimensions(t_data *data, int *rows, int *columns)
{
	int	i;

	i = 0;
	*rows = 0;
	*columns = 0;
	while (data->map[i])
	{
		*rows += 1;
		if (get_length(data->map[i]) > *columns)
			*columns = get_length(data->map[i]);
		i++;
	}
}

void print_box(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE_BOX)
	{
		j = 0;
		while (j < SIZE_BOX)
		{
			mlx_put_pixel(data->map_img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void print_map(t_data *data)
{
	int max_length_row, max_length_column;

	get_dimensions(data, &max_length_row, &max_length_column);
	printf("max_length_row: %d\n", max_length_row);
	printf("max_length_column: %d\n", max_length_column);
	printf("dimensions de la minimap width x height : %d x %d\n", max_length_column * SIZE_BOX, max_length_row * SIZE_BOX);
	data->map_img = mlx_new_image(data->mlx, max_length_column * SIZE_BOX, max_length_row * SIZE_BOX);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->map_img), mlx_perror_exit(data));
		
	int i_row = 0;
	int i_column;
	int color;
	while (i_row < max_length_row)
	{
		i_column = 0;
		while (i_column < get_length(data->map[i_row]))
		{
			if (data->map[i_row][i_column] == '1')
				color = 0x000000FF;
			else
				color = 0xFFFFFFFF;
			print_box(data, i_column * SIZE_BOX, i_row * SIZE_BOX, color);
			i_column++;
		}
		i_row++;
	}
}

int	main(void)
{
	t_data	data;

	init(&data);
	print_map(&data);
	mlx_loop_hook(data.mlx, ft_key_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
