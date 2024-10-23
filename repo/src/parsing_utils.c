/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:28 by jteste            #+#    #+#             */
/*   Updated: 2024/10/23 11:41:24 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	skip_spaces(char *str, int i, int len)
{
	while (i < len && ft_isspace(str[i]) == true)
		i++;
	return (i);
}

bool	extension_checker(char *path)
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

bool	remove_ws_from_split(char **split)
{
	int		i;
	int		j;
	int		start;
	char	*buff;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (ft_isspace(split[i][j]))
			j++;
		start = j;
		while (split[i][j] && !ft_isspace(split[i][j]))
			j++;
		if (start > 0 || split[i][j])
		{
			buff = ft_substr(split[i], start, j - start);
			if (!buff)
				return (perror("Memory allocation failed"), false);
			free(split[i]);
			split[i] = buff;
		}
		i++;
	}
	return (true);
}

bool	check_split_content(char **split)
{
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && !ft_isspace(split[i][j]))
				return (ft_putendl_fd("Error\nInvalid color", 2), false);
			j++;
		}
		i++;
	}
	return (true);
}
