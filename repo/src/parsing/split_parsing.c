/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:30:49 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/14 13:39:40 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	boolean;
	int	words;

	i = 0;
	words = 0;
	boolean = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && boolean == 0)
		{
			boolean = 1;
			words++;
		}
		else if (s[i] == c)
			boolean = 0;
		i++;
	}
	return (words);
}

static char	**ft_doubletabfree(int i, char **dest)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
	return (NULL);
}

static	char	**ft_filltab(char const *s, char c, char **dest, t_data *data)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[start] != '\0' && i < ft_countwords(s, c))
	{
		while (s[start] != '\0' && (s[start] == c || ft_isspace(s[start]) == 1))
			start++;
		end = start;
		while (s[end] != '\0' && (s[end] != c && ft_isspace(s[end]) == 0))
			end++;
		dest[i] = ft_substr(s, start, end - start);
		if (dest[i] == NULL)
			return (ft_doubletabfree(i, dest));
		i++;
		start = end;
	}
	while (s[start++] != '\0')
		if (ft_isspace(s[start]) == 1)
			return (ft_doubletabfree(i, dest),
				perror_exit("Invalid Color", data), NULL);
	
	return (dest);
}

char	**split_parsing(char const *s, char c, t_data *data)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	dest[ft_countwords(s, c)] = NULL;
	dest = ft_filltab(s, c, dest, data);
	return (dest);
}
