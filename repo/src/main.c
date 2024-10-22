/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/22 14:03:57 by jteste           ###   ########.fr       */
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
	printf("north_texture: %s", data.north_texture);
	printf("south_texture: %s", data.south_texture);
	printf("west_texture: %s", data.west_texture);
	printf("east_texture: %s", data.east_texture);
	printf("floor_color: %s", data.floor_color);
	printf("ceil_color: %s", data.ceil_color);
	
	// mlx_key_hook(data.mlx, esc_hook, &data);
	// mlx_loop_hook(data.mlx, player_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
