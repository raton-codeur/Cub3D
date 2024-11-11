/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:22 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/11 16:24:57 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_all(t_data *data)
{
	deep_free((void **)data->cub_file);
	deep_free((void **)data->map);
	free(data->path_map);
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	free(data->floor_color);
	free(data->ceil_color);
	free(data->floor_rgb);
	free(data->ceil_rgb);
	if (data->mlx)
		mlx_terminate(data->mlx);
}

void	perror_exit(char *s, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	free_all(data);
	exit(1);
}

void	mlx_perror_exit(t_data *data)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	free_all(data);
	exit(1);
}

