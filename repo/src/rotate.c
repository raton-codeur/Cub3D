/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:11:56 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/16 18:15:29 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = old_dir_x * cos(STEP_VIEW) - data->dir_y * sin(STEP_VIEW);
	data->dir_y = old_dir_x * sin(STEP_VIEW) + data->dir_y * cos(STEP_VIEW);
	data->plane_x
		= old_plane_x * cos(STEP_VIEW) - data->plane_y * sin(STEP_VIEW);
	data->plane_y
		= old_plane_x * sin(STEP_VIEW) + data->plane_y * cos(STEP_VIEW);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = old_dir_x * cos(-STEP_VIEW) - data->dir_y * sin(-STEP_VIEW);
	data->dir_y = old_dir_x * sin(-STEP_VIEW) + data->dir_y * cos(-STEP_VIEW);
	data->plane_x
		= old_plane_x * cos(-STEP_VIEW) - data->plane_y * sin(-STEP_VIEW);
	data->plane_y
		= old_plane_x * sin(-STEP_VIEW) + data->plane_y * cos(-STEP_VIEW);
}
