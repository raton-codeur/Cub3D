/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:54:21 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 16:07:44 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static	int	get_map_max_lenght(t_data *data)
{
	int	i;
	int	max_len;
	int	len;

	i = 0;
	max_len = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	normalize_map_rows(t_data *data, int max_len)
{
	char	*buff;
	int		i;
	int		j;

	max_len = get_map_max_lenght(data);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) < (size_t)max_len)
		{
			buff = ft_calloc(max_len + 1, sizeof(char));
			if (!buff)
				perror_exit("Malloc failed", data);
			ft_strlcpy(buff, data->map[i], ft_strlen(data->map[i]) + 1);
			j = ft_strlen(data->map[i]);
			while (j < max_len)
			{
				buff[j] = FILLER;
				j++;
			}
			free(data->map[i]);
			data->map[i] = buff;
		}
		i++;
	}
}

void	fill_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ' || data->map[i][j] == '\t')
				data->map[i][j] = FILLER;
			j++;
		}
		i++;
	}
}
