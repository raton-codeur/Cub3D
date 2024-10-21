/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:53:13 by jteste            #+#    #+#             */
/*   Updated: 2024/10/21 16:08:51 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	extension_checker(char *path)
{
	int		len;

	len = ft_strlen(path);
	if (len < 5)
	{
		ft_putendl_fd("Error\nInvalid file extension", 2);
		return (false);
	}
	if (ft_strncmp(&path[len - 4], ".cub", 4) != 0)
	{
		ft_putendl_fd("Error\nInvalid file extension", 2);
		return (false);
	}
	return (true);
}

bool	parser(t_data *data)
{
	if (!extension_checker(data->path_map))
		return (false);
	load_cub_file(data); // gestion erreur a voir
	
	return (true);
}
