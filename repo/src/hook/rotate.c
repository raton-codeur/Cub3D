/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:11:56 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 11:03:07 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_x(t_data *data, double step)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = old_dir_x * cos(step) - data->dir_y * sin(step);
	data->dir_y = old_dir_x * sin(step) + data->dir_y * cos(step);
	data->plane_x
		= old_plane_x * cos(step) - data->plane_y * sin(step);
	data->plane_y
		= old_plane_x * sin(step) + data->plane_y * cos(step);
}
