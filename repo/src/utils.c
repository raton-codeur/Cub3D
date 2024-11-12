/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:45:36 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/12 10:17:49 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_image(mlx_image_t *image, unsigned int color)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
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
