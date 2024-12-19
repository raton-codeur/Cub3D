/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 20:32:20 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "raycasting.h"

static void	check_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}

static void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_x(data, STEP_ROTATE_X);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_x(data, -STEP_ROTATE_X);
}





























// static void	copy_minimap_pixel(t_data *d, uint32_t dst_index,
// 	int map_x, int map_y)
// {
// 	uint32_t	src_index;

// 	src_index = (map_y * d->map_img->width + map_x) * 4;
// 	ft_memcpy(&d->minimap->pixels[dst_index],
// 		&d->map_img->pixels[src_index], 4);
// }

// static int	is_within_bounds(t_data *d, int map_x, int map_y)
// {
// 	return (map_x >= 0 && map_x < (int)d->map_img->width
// 		&& map_y >= 0 && map_y < (int)d->map_img->height);
// }

// static void	calculate_rotated_coords(t_data *d, uint32_t i, uint32_t j)
// {
// 	d->rel_x = j - d->mini_center_x;
// 	d->rel_y = i - d->mini_center_y;
// 	d->rotated_x = d->rel_x * d->cos_theta - d->rel_y * d->sin_theta;
// 	d->rotated_y = d->rel_x * d->sin_theta + d->rel_y * d->cos_theta;
// }

// static void	process_minimap_pixel(t_data *d, uint32_t i, uint32_t j)
// {
// 	int			map_x;
// 	int			map_y;
// 	uint32_t	dst_index;

// 	calculate_rotated_coords(d, i, j);
// 	map_x = (int)(d->pos_x * d->box_size + d->rotated_x);
// 	map_y = (int)(d->pos_y * d->box_size + d->rotated_y);
// 	dst_index = (i * d->minimap->width + j) * 4;
// 	if (is_within_bounds(d, map_x, map_y))
// 		copy_minimap_pixel(d, dst_index, map_x, map_y);
// 	else
// 		ft_memset(&d->minimap->pixels[dst_index], 0, 4);
// }

// void	render_rotated_minimap(t_data *d, uint32_t i, uint32_t j)
// {
// 	while (i < d->minimap->height)
// 	{
// 		j = 0;
// 		while (j < d->minimap->width)
// 		{
// 			process_minimap_pixel(d, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }




// static void	copy_rays_pixel(t_data *d, uint32_t dst_index,
// 	int map_x, int map_y)
// {
// 	uint32_t	src_index;

// 	src_index = (map_y * d->map_rays->width + map_x) * 4;
// 	ft_memcpy(&d->minimap_rays->pixels[dst_index],
// 		&d->map_rays->pixels[src_index], 4);
// }

// static int	within_bounds(t_data *d, int map_x, int map_y)
// {
// 	return (map_x >= 0 && map_x < (int)d->map_rays->width
// 		&& map_y >= 0 && map_y < (int)d->map_rays->height);
// }

// static void	rotated_coords(t_data *d, uint32_t i, uint32_t j)
// {
// 	d->rel_x = j - d->mini_center_x;
// 	d->rel_y = i - d->mini_center_y;
// 	d->rotated_x = d->rel_x * d->cos_theta - d->rel_y * d->sin_theta;
// 	d->rotated_y = d->rel_x * d->sin_theta + d->rel_y * d->cos_theta;
// }

// static void	process_minimap_pixel(t_data *d, uint32_t i, uint32_t j)
// {
// 	int			map_x;
// 	int			map_y;
// 	uint32_t	dst_index;

// 	rotated_coords(d, i, j);
// 	map_x = (int)(d->pos_x * d->box_size + d->rotated_x);
// 	map_y = (int)(d->pos_y * d->box_size + d->rotated_y);
// 	dst_index = (i * d->minimap_rays->width + j) * 4;
// 	if (within_bounds(d, map_x, map_y))
// 		copy_rays_pixel(d, dst_index, map_x, map_y);
// 	else
// 		ft_memset(&d->minimap_rays->pixels[dst_index], 0, 4);
// }

// void	render_rotated_rays(t_data *d, uint32_t i, uint32_t j)
// {
// 	while (i < d->minimap_rays->height)
// 	{
// 		j = 0;
// 		while (j < d->minimap_rays->width)
// 		{
// 			process_minimap_pixel(d, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void	copy_map_rays(t_data *d, int start_x, int start_y, uint32_t i)
// {
// 	uint32_t	dst_index;
// 	uint32_t	src_index;
// 	uint32_t	j;

// 	while (i < d->minimap_rays->height)
// 	{
// 		j = 0;
// 		while (j < d->minimap_rays->width)
// 		{
// 			d->src_x = start_x + j;
// 			d->src_y = start_y + i;
// 			dst_index = (i * d->minimap_rays->width + j) * 4;
// 			if (d->src_x >= 0 && d->src_x < (int)d->map_rays->width
// 				&& d->src_y >= 0 && d->src_y < (int)d->map_rays->height)
// 			{
// 				src_index = (d->src_y * d->map_rays->width + d->src_x) * 4;
// 				ft_memcpy(&d->minimap_rays->pixels[dst_index],
// 					&d->map_rays->pixels[src_index], 4);
// 			}
// 			else
// 				ft_memset(&d->minimap_rays->pixels[dst_index], 0, 4);
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void	fill_mini_bg(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < (int)data->minimap_bg->width)
// 	{
// 		y = 0;
// 		while (y < (int)data->minimap_bg->height)
// 		{
// 			mlx_put_pixel(data->minimap_bg, x, y, 0x000000FF);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	fill_mini_player(t_data *data, int x, int y)
// {
// 	int	mini_radius;
// 	int	mini_radius_2;
// 	int	d;

// 	mini_radius = data->box_size / 4;
// 	mini_radius_2 = mini_radius * mini_radius;
// 	while (x < (int)data->minimap_player->width)
// 	{
// 		y = 0;
// 		while (y < (int)data->minimap_player->height)
// 		{
// 			d = (data->mini_center_x - x) * (data->mini_center_x - x)
// 				+ (data->mini_center_y - y) * (data->mini_center_y - y);
// 			if (d <= mini_radius_2)
// 			{
// 				mlx_put_pixel(data->minimap_player, x, y, 0xFF0000FF);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

// static void	copy_map_area(t_data *d, int start_x, int start_y, uint32_t i)
// {
// 	uint32_t	dst_index;
// 	uint32_t	src_index;
// 	uint32_t	j;

// 	while (i < d->minimap->height)
// 	{
// 		j = 0;
// 		while (j < d->minimap->width)
// 		{
// 			d->src_x = start_x + j;
// 			d->src_y = start_y + i;
// 			dst_index = (i * d->minimap->width + j) * 4;
// 			if (d->src_x >= 0 && d->src_x < (int)d->map_img->width
// 				&& d->src_y >= 0 && d->src_y < (int)d->map_img->height)
// 			{
// 				src_index = (d->src_y * d->map_img->width + d->src_x) * 4;
// 				ft_memcpy(&d->minimap->pixels[dst_index],
// 					&d->map_img->pixels[src_index], 4);
// 			}
// 			else
// 				ft_memset(&d->minimap->pixels[dst_index], 0, 4);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	apply_alpha_to_minimap(mlx_image_t *minimap)
// {
// 	uint32_t	i;
// 	uint32_t	j;
// 	float		distance;
// 	float		radius;
// 	uint32_t	dst_index;

// 	radius = minimap->width / 2;
// 	i = 0;
// 	while (i < minimap->height)
// 	{
// 		j = 0;
// 		while (j < minimap->width)
// 		{
// 			dst_index = (i * minimap->width + j) * 4;
// 			distance = sqrtf((j - minimap->width / 2)
// 					* (j - minimap->width / 2)
// 					+ (i - minimap->height / 2)
// 					* (i - minimap->height / 2));
// 			if (distance > radius)
// 				minimap->pixels[dst_index + 3] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_mini_map(t_data *data)
// {
// 	int		start_x;
// 	int		start_y;

// 	data->theta = atan2(data->dir_y, data->dir_x) + M_PI / 2 ;
// 	data->cos_theta = cos(data->theta);
// 	data->sin_theta = sin(data->theta);
// 	start_x = data->pos_x * data->box_size - data->minimap->width / 2;
// 	start_y = data->pos_y * data->box_size - data->minimap->height / 2;
// 	data->mini_center_x = data->minimap->width / 2;
// 	data->mini_center_y = data->minimap->height / 2;
// 	copy_map_area(data, start_x, start_y, 0);
// 	copy_map_rays(data, start_x, start_y, 0);
// 	render_rotated_minimap(data, 0, 0);
// 	render_rotated_rays(data, 0, 0);
// 	fill_mini_player(data, 0, 0);
// 	fill_mini_bg(data);
// 	apply_alpha_to_minimap(data->minimap);
// 	apply_alpha_to_minimap(data->minimap_bg);
// 	apply_alpha_to_minimap(data->minimap_rays);
// }






















// int estDansCercle(t_data *data)
// {
// 	return (;
// }

void	get_pixel_minimap(t_data *data)
{
	if (data->xd < 0 || data->yd < 0 || data->xd >= data->map_width
		|| data->yd >= data->map_height)
		data->pixel = MAP_COLOR_BG;
	else if ((data->xd - (int)data->xd) < 0.05 || (data->yd - (int)data->yd) < 0.05)
		data->pixel = 0x000000FF;
	else if (data->map[(int)data->xd][(int)data->yd] == '1')
		data->pixel = MAP_COLOR_WALL;
	else
		data->pixel = MAP_COLOR_BG;
}

void	render_minimap(t_data *data)
{
	erase_image(data->minimap);
	data->x = 0;
	data->xd = data->pos_x - 5;
	while (data->x < data->minimap->width)
	{
		data->y = 0;
		data->yd = data->pos_y - 5;
		while (data->y < data->minimap->width)
		{
			if ((2 * data->x - data->minimap->width) * (2 * data->x - data->minimap->width) + (2 * data->y - data->minimap->width) * (2 * data->y - data->minimap->width) <= data->mini_w_2)
			{
				get_pixel_minimap(data);
				mlx_put_pixel(data->minimap, data->x, data->y, data->pixel);
			}
			data->y++;
			data->yd += data->minimap_step;
		}
		data->x++;
		data->xd += data->minimap_step;
	}
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	if (1 / data->mlx->delta_time > 30)
		printf(" depasse ");
	printf("fps : %f\n", 1 / data->mlx->delta_time);
	check_movement_keys(data);
	check_rotation_keys(data);
	dda(data);
	if (data->depth_config == 2)
		render_minimap(data);
}
