/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:02 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 10:39:25 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_circle(mlx_image_t *img, uint32_t color)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	radius;
	uint32_t	radius_2;

	radius = img->width / 2;
	radius_2 = radius * radius;
	i = 0;
	while (i < img->width)
	{
		j = 0;
		while (j < img->height)
		{
			if ((radius - i) * (radius - i) + (radius - j) * (radius - j) \
				<= radius_2)
				mlx_put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	erase(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}
