/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:48:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/20 17:21:39 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_row_size(char *row)
{
	int	i;

	if (!row)
		return (0);
	i = 0;
	while (row[i] && row[i] != '\n')
		i++;
	return (i);
}

static int	get_nb_columns(char **map)
{
	int	i;
	int	max;

	if (!map)
		return (0);
	i = 0;
	max = 0;
	while (map[i])
	{
		if (get_row_size(map[i]) > max)		
			max = get_row_size(map[i]);
		i++;
	}
	return (max);
}

static void	fill_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < SIZE_BOX)
	{
		y = 0;
		while (y < SIZE_BOX)
		{
			mlx_put_pixel(data->player, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}

void	init_map(t_data *data)
{
	int	nb_rows;
	int	nb_columns;

    // image pour la minimap
	nb_rows = array_size((void **)data->map); // attention aux lignes vides à la fin ?
	nb_columns = get_nb_columns(data->map);
	data->map_img = mlx_new_image(data->mlx, nb_columns * SIZE_BOX, nb_rows * SIZE_BOX);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->map_img), mlx_perror_exit(data));
    
    // image pour le player
    data->player = mlx_new_image(data->mlx, SIZE_BOX, SIZE_BOX);
    if (data->player == NULL)
        return (mlx_perror_exit(data));
    if (mlx_image_to_window(data->mlx, data->player, 0, 0) == -1)
    	{return (mlx_delete_image(data->mlx, data->player), mlx_perror_exit(data));}
	fill_player(data);
}
