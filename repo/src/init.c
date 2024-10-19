/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/19 13:54:28 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2024/10/19 13:19:07 by qhauuy           ###   ########.fr       */
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

static mlx_image_t	*get_img_from_png(t_data *data, const char *file)
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

void	init(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data->mlx == NULL)
		return (mlx_print_error(), exit(1));
	data->background = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->background == NULL
		|| mlx_image_to_window(data->mlx, data->background, 0, 0) == -1)
		return (mlx_error_exit(data));
	fill_bg(data);
	data->cat = get_img_from_png(data, "textures/cat.png");
	if (data->cat == NULL
		|| mlx_image_to_window(data->mlx, data->cat, 0, 0) == -1)
		return (mlx_error_exit(data));
}
