/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/12 14:00:37 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "hook.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parsing(&data, argc, argv);
	for (int i = 0; data.map[i]; i++)
		printf("map[%d] = \"%s\"\n", i, data.map[i]);
	printf("player position: %d, %d\n", data.i, data.j);
	printf("player direction: %c\n", data.player_dir);
	// init_mlx(&data);
	// mlx_key_hook(data.mlx, esc_hook, &data);
	// // mlx_loop_hook(data.mlx, main_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
