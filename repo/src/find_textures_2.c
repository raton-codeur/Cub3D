/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:20:39 by jteste            #+#    #+#             */
/*   Updated: 2024/10/22 14:22:34 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool check_color(t_data *data)
{
	if (data->floor_rgb->r < 0 || data->floor_rgb->r > 255)
		return (perror("Invalid floor color"), false);
	if (data->floor_rgb->g < 0 || data->floor_rgb->g > 255)
		return (perror("Invalid floor color"), false);
	if (data->floor_rgb->b < 0 || data->floor_rgb->b > 255)
		return (perror("Invalid floor color"), false);
	if (data->ceil_rgb->r < 0 || data->ceil_rgb->r > 255)
		return (perror("Invalid ceil color"), false);
	if (data->ceil_rgb->g < 0 || data->ceil_rgb->g > 255)
		return (perror("Invalid ceil color"), false);
	if (data->ceil_rgb->b < 0 || data->ceil_rgb->b > 255)
		return (perror("Invalid ceil color"), false);
	return (true);
}
