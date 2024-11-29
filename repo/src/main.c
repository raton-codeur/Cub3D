/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/29 10:52:59 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "init_mlx.h"
#include "raycasting.h"

void	create_maze(t_data *data)
{
	int	fd;
	

	fd = open("maps/maze.cub", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_exit(MAZE, data);
	if (write(fd, INIT_CUB, ft_strlen(INIT_CUB)) == -1)
		error_exit(DEFAULT, data);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_data	data;

	create_maze(&data);
	parsing(&data, argc, argv);
	init_mlx(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop_hook(data.mlx, main_hook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}



