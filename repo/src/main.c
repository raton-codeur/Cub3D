/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 13:01:47 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data, argc, argv);
	if (!parser(&data))
		return (free_all(&data), 1);
	printf("path_map: %s\n", data.path_map);
	printf("north_texture: %s\n", data.north_texture);
	printf("line = %d\n", data.north_texture_line);
	printf("south_texture: %s\n", data.south_texture);
	printf("line = %d\n", data.south_texture_line);
	printf("west_texture: %s\n", data.west_texture);
	printf("line = %d\n", data.west_texture_line);
	printf("east_texture: %s\n", data.east_texture);
	printf("line = %d\n", data.east_texture_line);
	printf("floor_color: %s\n", data.floor_color);
	printf("ceil_color_line: %d\n", data.floor_color_line);
	printf("ceil_color: %s\n", data.ceil_color);
	printf("ceil_color_line: %d\n", data.ceil_color_line);
	printf("floor_rgb->r,g,b: %d,%d,%d\n", data.floor_rgb->r, data.floor_rgb->g, data.floor_rgb->b);
	printf("ceil_rgb->r,g,b: %d,%d,%d\n", data.ceil_rgb->r, data.ceil_rgb->g, data.ceil_rgb->b);
	printf("floor_rgb->hex: 0x%06X\n", data.floor_rgb->hex);
	printf("ceil_rgb->hex: 0x%06X\n", data.ceil_rgb->hex);
	// mlx_key_hook(data.mlx, esc_hook, &data);
	// mlx_loop_hook(data.mlx, player_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
