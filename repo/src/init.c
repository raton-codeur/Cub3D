/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/19 16:59:39 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

mlx_image_t	*get_img_from_png(t_data *data, const char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*result;

	texture = mlx_load_png(file);
	if (texture == NULL)
		return (NULL);
	result = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (result);
}

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
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data->mlx == NULL)
		return (mlx_perror_exit(data), exit(1));
	data->background = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->background == NULL
		|| mlx_image_to_window(data->mlx, data->background, 0, 0) == -1)
		return (mlx_perror_exit(data));
	fill_bg(data);
}

void	init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	load_map(data);
	init_mlx(data);
}
