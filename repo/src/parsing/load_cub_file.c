/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:51:34 by jteste            #+#    #+#             */
/*   Updated: 2024/11/11 16:38:10 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	count_lines(t_data *data)
{
	int		fd;
	int		result;
	char	*line;

	fd = open(data->path_map, O_RDONLY);
	if (fd == -1)
		return (perror("Cannot open .cub file"), free_all(data), exit(1), 1);
	result = 0;
	line = get_next_line(fd);
	while (line)
	{
		result++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (result);
}

bool	load_cub_file(t_data *data)
{
	int		fd;
	char	*line;
	int		nb_lines;
	int		i;

	i = 0;
	nb_lines = count_lines(data);
	data->cub_file = ft_calloc(nb_lines + 1, sizeof(char *));
	if (data->cub_file == NULL)
		return (perror("Memory allocation failed"), false);
	data->cub_file[nb_lines] = NULL;
	fd = open(data->path_map, O_RDONLY);
	if (fd == -1)
		return (perror("Cannot open .cub file"), false);
	line = NULL;
	while (line || i == 0)
	{
		line = get_next_line(fd);
		data->cub_file[i++] = ft_strdup(line);
		free(line);
	}
	close(fd);
	return (true);
}