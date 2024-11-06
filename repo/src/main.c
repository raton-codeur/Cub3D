/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/06 15:22:40 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data, argc, argv);
	if (!parser(&data))
		return (free_all(&data), 1);
	for (size_t i = 0; data.map[i]; i++)
		printf("%s\n", data.map[i]);
	// mlx_key_hook(data.mlx, esc_hook, &data);
	// mlx_loop_hook(data.mlx, player_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
