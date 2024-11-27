/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:51:42 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/27 10:41:09 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	count_lines(t_data *data)
{
	int		fd;
	int		result;
	char	*line;

	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		return (perror("Cannot open map"), free_all(data), exit(1), 1);
	result = 0;
	line = get_next_line(fd);
	while (line || result == 0)
	{
		line = get_next_line(fd);
		result++;
		free(line);
	}
	close(fd);
	return (result);
}

void	load_map(t_data *data)
{
	int		fd;
	char	*line;
	int		nb_lines;
	int		i;

	nb_lines = count_lines(data);
	data->map = ft_calloc(nb_lines + 1, sizeof(char *));
	if (data->map == NULL)
		perror_exit("Memory allocation failed", data);
	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		return (perror("Cannot open map"), free_all(data), exit(1));
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->map[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
}
