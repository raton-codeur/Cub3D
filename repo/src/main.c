/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2025/01/10 10:14:33 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_game.h"
#include "hook.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parsing(&data, argc, argv);
	init_game(&data);
	printf("dim : w = %d, h = %d\n", data.map_width, data.map_height);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop_hook(data.mlx, main_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
