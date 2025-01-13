/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:02:38 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/10 10:53:44 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	compare_with_tab(char *line, int i)
{
	if (ft_strncmp(line + i, "EA\t", 3) != 0
		&& ft_strncmp(line + i, "NO\t", 3) != 0
		&& ft_strncmp(line + i, "SO\t", 3) != 0
		&& ft_strncmp(line + i, "WE\t", 3) != 0
		&& ft_strncmp(line + i, "C\t", 2) != 0
		&& ft_strncmp(line + i, "F\t", 2) != 0
		&& ft_strncmp(line + i, "1", 1) != 0
		&& ft_strncmp(line + i, "0", 1) != 0)
		return (false);
	return (true);
}

static bool	compare_with_space(char *line, int i)
{
	if (ft_strncmp(line + i, "EA ", 3) != 0
		&& ft_strncmp(line + i, "NO ", 3) != 0
		&& ft_strncmp(line + i, "SO ", 3) != 0
		&& ft_strncmp(line + i, "WE ", 3) != 0
		&& ft_strncmp(line + i, "C ", 2) != 0
		&& ft_strncmp(line + i, "F ", 2) != 0
		&& ft_strncmp(line + i, "1", 1) != 0
		&& ft_strncmp(line + i, "0", 1) != 0)
		return (false);
	return (true);
}

bool	check_keys(char *line)
{
	int	i;

	i = 0;
	i = skip_spaces(line, i, ft_strlen(line));
	if (i == (int)ft_strlen(line))
		return (true);
	if (line[i] == '\0')
		return (true);
	if (compare_with_tab(line, i) == false
		&& compare_with_space(line, i) == false)
		return (false);
	return (true);
}
