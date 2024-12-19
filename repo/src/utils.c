/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:02 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/18 17:00:03 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_image(mlx_image_t *image, uint32_t color)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < image->width)
	{
		j = 0;
		while (j < image->height)
		{
			mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

void	fill_image_circle(mlx_image_t *img, uint32_t color)
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

void	erase_image(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}

void	print_map(t_data *data)
{
	uint32_t	i;
	uint32_t	j;

	printf("      ");
	i = 0;
	while (i < data->map_width)
	{
		printf("%3d", i);
		i++;
	}
	printf("\n");
	j = 0;
	while (j < data->map_height)
	{
		printf("%3d : ", j);
		i = 0;
		while (i < data->map_width)
			printf("%3c", data->map[i++][j]);
		printf("\n");
		j++;
	}
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

// uint32_t	get_pixel(mlx_texture_t *t, uint32_t x, uint32_t y)
// {
// 	uint8_t	r;
// 	uint8_t	g;
// 	uint8_t	b;
// 	uint8_t	a;

// 	r = t->pixels[y * t->width * 4 + x * 4];
// 	g = t->pixels[y * t->width * 4 + x * 4 + 1];
// 	b = t->pixels[y * t->width * 4 + x * 4 + 2];
// 	a = t->pixels[y * t->width * 4 + x * 4 + 3];
// 	return (r << 24 | g << 16 | b << 8 | a);
// }
// uint32_t	get_pixel(mlx_image_t *img, uint32_t x, uint32_t y)
// {
// 	uint8_t r, g, b, a;
// 	r = img->pixels[y * img->width * 4 + x * 4];
// 	g = img->pixels[y * img->width * 4 + x * 4 + 1];
// 	b = img->pixels[y * img->width * 4 + x * 4 + 2];
// 	a = img->pixels[y * img->width * 4 + x * 4 + 3];
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

uint32_t get_rgb(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t r, g, b;
	r = img->pixels[y * img->width * 4 + x * 4];
	g = img->pixels[y * img->width * 4 + x * 4 + 1];
	b = img->pixels[y * img->width * 4 + x * 4 + 2];
	return (r << 24 | g << 16 | b << 8);
}

void mlx_put_pixel_rgb(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t rgb)
{
	mlx_put_pixel(img, x, y, rgb | img->pixels[y * img->width * 4 + x * 4 + 3]);
}

uint32_t	get_color(t_data *data, uint32_t x, uint32_t y)
{
	if (x % data->box_size == 0 || x % data->box_size == data->box_size - 1
		|| y % data->box_size == 0 || y % data->box_size == data->box_size - 1)
		return (0x000000FF);
	else if (data->map[x / data->box_size][y / data->box_size] == '1')
		return (MAP_COLOR_WALL);
	else
		return (MAP_COLOR_BG);
}
