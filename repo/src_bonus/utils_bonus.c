/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:02 by qhauuy            #+#    #+#             */
/*   Updated: 2025/01/13 16:30:16 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

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
