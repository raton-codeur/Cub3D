/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/19 16:30:36 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "raycasting.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parsing(&data, argc, argv);
	data.ceil_color = data.ceil_rgb->hex;
	data.floor_color = data.floor_rgb->hex;
	init_dir(&data);
	print_map(&data);
	get_map_dimensions(&data);
	reverse_map(&data);
	
	init_mlx(&data);
	
	// int alpha_min = 0;
	// int alpha_max = 255;
	int y;
	y = 0;
	int alpha;
	while (y < W_HEIGHT / 2)
	{
		alpha = y;
		printf("%d : %d\n", y, alpha);
		y++;
	}
	
	
	// mlx_key_hook(data.mlx, key_hook, &data);
	// mlx_loop_hook(data.mlx, main_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}



