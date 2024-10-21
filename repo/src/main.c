/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/21 16:06:05 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	init(&data, argc, argv);
	if (!parser(&data))
		return (free_all(&data), 1);
	// mlx_key_hook(data.mlx, esc_hook, &data);
	// mlx_loop_hook(data.mlx, player_hook, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
