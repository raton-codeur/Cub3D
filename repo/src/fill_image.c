/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:36:50 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 16:36:58 by qhauuy           ###   ########.fr       */
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

void	fill_zone(mlx_image_t *img, t_u_points limits, unsigned int color)
{
	unsigned int	x;
	unsigned int	y;

	x = limits.a_x;
	while (x < limits.b_x)
	{
		y = limits.a_y;
		while (y < limits.b_y)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
