/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/20 17:42:53 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	t_data	data;

	init(&data);
	mlx_key_hook(data.mlx, esc_hook, &data);
	mlx_loop_hook(data.mlx, player_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
