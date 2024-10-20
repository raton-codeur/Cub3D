/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/20 16:52:08 by qhauuy           ###   ########.fr       */
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
				mlx_put_pixel(data->background, x, y, CEIL_COLOR);
			else
				mlx_put_pixel(data->background, x, y, FLOOR_COLOR);
			y++;
		}
		x++;
	}
}

void	init_mlx(t_data *data)
{
	int	monitor_width;
	int	monitor_height;

	// mlx
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data->mlx == NULL)
		return (mlx_perror_exit(data), exit(1));
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_set_window_pos(data->mlx, (monitor_width - WIDTH) / 2, (monitor_height - HEIGHT) / 2);

	// background
	data->background = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->background == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->background, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->background), mlx_perror_exit(data));
	fill_bg(data);
}

void	init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	load_map(data);
	init_mlx(data);
	init_map(data);
}
