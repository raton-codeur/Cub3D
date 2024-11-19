/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:47:43 by hakgyver          #+#    #+#             */
/*   Updated: 2024/11/19 14:00:31 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	color_range(t_data *data)
{
	if (data->floor_rgb->r < 0 || data->floor_rgb->r > 255)
		perror_exit("Invalid floor color", data);
	if (data->floor_rgb->g < 0 || data->floor_rgb->g > 255)
		perror_exit("Invalid floor color", data);
	if (data->floor_rgb->b < 0 || data->floor_rgb->b > 255)
		perror_exit("Invalid floor color", data);
	if (data->ceil_rgb->r < 0 || data->ceil_rgb->r > 255)
		perror_exit("Invalid ceil color", data);
	if (data->ceil_rgb->g < 0 || data->ceil_rgb->g > 255)
		perror_exit("Invalid ceil color", data);
	if (data->ceil_rgb->b < 0 || data->ceil_rgb->b > 255)
		perror_exit("Invalid ceil color", data);
}

static bool	check_split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (false);
	return (true);
}

static char	*remove_leading_ws(char *str, t_data *data)
{
	int		i;
	int		start;
	char	*buff;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	start = i;
	while (str[i])
		i++;
	buff = ft_substr(str, start, i - start);
	if (!buff)
		perror_exit("Memory allocation failed", data);
	return (buff);
}

static void	colors_to_rgb(t_data *data, t_color *color, char *str, char **spt)
{
	char	*s2;

	s2 = remove_leading_ws(str, data);
	spt = ft_split(s2, ",");
	free(s2);
	if (spt == NULL)
		return (perror_exit("Memory allocation failed", data));
	if (!check_split_size(spt))
		return (deep_free((void **)spt),
			perror_exit("Invalid color", data));
	s2 = remove_newline(spt[2], data);
	if (s2 == NULL)
		return (deep_free((void **)spt),
			perror_exit("Memory allocation failed", data));
	spt[2] = s2;
	if (!check_split_content(spt))
		return (deep_free((void **)spt),
			perror_exit("Invalid color", data));
	if (!check_split_content_size(spt))
		return (deep_free((void **)spt),
			perror_exit("Invalid color", data));
	color->r = ft_atoi(spt[0]);
	color->g = ft_atoi(spt[1]);
	color->b = ft_atoi(spt[2]);
	deep_free((void **)spt);
}

void	fill_rgb_colors(t_data *data)
{
	check_color_string(data, data->floor_color_str);
	check_color_string(data, data->ceil_color_str);
	colors_to_rgb(data, data->floor_rgb, data->floor_color_str, NULL);
	colors_to_rgb(data, data->ceil_rgb, data->ceil_color_str, NULL);
	color_range(data);
}
