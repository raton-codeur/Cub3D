/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:04:15 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/14 13:25:52 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_color_string(\
	t_data *data, char *color, int count_number, int count_comma)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (count_number == 1 && ft_isdigit(color[i]))
			perror_exit("Invalid color", data);
		if (color[i] == ',')
		{
			count_number = 0;
			count_comma++;
			i++;
		}
		else if (ft_isdigit(color[i]))
		{
			while (ft_isdigit(color[i]))
				i++;
			count_number++;
		}
		else
			i++;
	}
	if (count_comma != 2)
		perror_exit("Invalid color", data);
}
