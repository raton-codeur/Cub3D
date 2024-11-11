/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:28 by jteste            #+#    #+#             */
/*   Updated: 2024/11/11 16:38:16 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

bool	check_split_content_size(char **split)
{
	if (ft_strlen(split[0]) == 0 || ft_strlen(split[0]) > 3)
		return (ft_putendl_fd("Error\nInvalid color", 2), false);
	if (ft_strlen(split[1]) == 0 || ft_strlen(split[1]) > 3)
		return (ft_putendl_fd("Error\nInvalid color", 2), false);
	if (ft_strlen(split[2]) == 0 || ft_strlen(split[2]) > 3)
		return (ft_putendl_fd("Error\nInvalid color", 2), false);
	return (true);
}

char	*remove_newline(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (!str)
		return (ft_putendl_fd("Error\nInvalid color", 2), NULL);
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == '\n')
	{
		buff = ft_substr(str, 0, i - 1);
		if (!buff)
			return (perror("Memory allocation failed"), NULL);
		free(str);
		return (buff);
	}
	return (str);
}
