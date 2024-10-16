/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/16 17:54:23 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_bg(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->bg, x, y, CEIL_COLOR);
			else
				mlx_put_pixel(data->bg, x, y, FLOOR_COLOR);
			y++;
		}
		x++;
	}
}

void	init(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data->mlx == NULL)
		return (mlx_print_error(), exit(1));
	data->bg = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->bg == NULL)
		return (mlx_print_error(), mlx_terminate(data->mlx), exit(1));
	if (mlx_image_to_window(data->mlx, data->bg, 0, 0) == -1)
		return (mlx_print_error(), mlx_terminate(data->mlx), exit(1));
	fill_bg(data);
}
