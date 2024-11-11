/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/11 17:36:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "hook.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(&data, argc, argv);
	for (int i = 0; data.map[i]; i++)
		printf("map[%d] = \"%s\"\n", i, data.map[i]);
	init_mlx(&data);
	mlx_key_hook(data.mlx, esc_hook, &data);
	// mlx_loop_hook(data.mlx, main_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
