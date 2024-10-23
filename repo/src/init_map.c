/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:48:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 14:14:07 by qhauuy           ###   ########.fr       */
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
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < SIZE_PLAYER)
	{
		y = 0;
		while (y < SIZE_PLAYER)
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

    // map
	nb_rows = array_size((void **)data->map); // attention aux lignes vides à la fin ?
	nb_columns = get_nb_columns(data->map);
	data->map_img = mlx_new_image(data->mlx, nb_columns * SIZE_BOX, nb_rows * SIZE_BOX);
	if (data->map_img == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->map_img, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->map_img), mlx_perror_exit(data));
	print_map(data);

    // player
	data->player = mlx_new_image(data->mlx, SIZE_PLAYER, SIZE_PLAYER);
	if (data->player == NULL)
		{return (mlx_perror_exit(data));}
	fill_player(data);
	if (mlx_image_to_window(data->mlx, data->player, C_START * SIZE_BOX, R_START * SIZE_BOX) == -1)
		{return (mlx_delete_image(data->mlx, data->player), mlx_perror_exit(data));}
	data->position.x = data->player->instances[0].x + SIZE_PLAYER_HALF;
	data->position.y = data->player->instances[0].y + SIZE_PLAYER_HALF;

	// rays
	data->rays = mlx_new_image(data->mlx, data->map_img->width, data->map_img->height);
	if (data->rays == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->rays, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->rays), mlx_perror_exit(data));
}
