/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:01:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 10:58:28 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	move_up(t_data *data)
{
	data->new_pos = data->pos_x + STEP_MOVE * data->dir_x;
	if (data->map[data->new_pos][data->pos_y] != '1'
		&& data->map[(int)(new)][(int)(data->pos_y)] != 'D')
	{
		data->pos_x = new;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	new = data->pos_y + STEP_MOVE * data->dir_y;
	if (data->map[(int)(data->pos_x)][(int)(new)] != '1'
		&& data->map[(int)(data->pos_x)][(int)(new)] != 'D')
	{
		data->pos_y = new;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}

void	move_down(t_data *data)
{
	double	new;

	new = data->pos_x - STEP_MOVE * data->dir_x;
	if (data->map[(int)(new)][(int)(data->pos_y)] != '1'
		&& data->map[(int)(new)][(int)(data->pos_y)] != 'D')
	{
		data->pos_x = new;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	new = data->pos_y - STEP_MOVE * data->dir_y;
	if (data->map[(int)(data->pos_x)][(int)(new)] != '1'
		&& data->map[(int)(data->pos_x)][(int)(new)] != 'D')
	{
		data->pos_y = new;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}

void	move_left(t_data *data)
{
	double	new;

	new = data->pos_x + STEP_MOVE * data->dir_y;
	if (data->map[(int)(new)][(int)(data->pos_y)] != '1'
		&& data->map[(int)(new)][(int)(data->pos_y)] != 'D')
	{
		data->pos_x = new;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	new = data->pos_y - STEP_MOVE * data->dir_x;
	if (data->map[(int)(data->pos_x)][(int)(new)] != '1'
		&& data->map[(int)(data->pos_x)][(int)(new)] != 'D')
	{
		data->pos_y = new;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}

void	move_right(t_data *data)
{
	double	new;

	new = data->pos_x - STEP_MOVE * data->dir_y;
	if (data->map[(int)(new)][(int)(data->pos_y)] != '1'
		&& data->map[(int)(new)][(int)(data->pos_y)] != 'D')
	{
		data->pos_x = new;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	new = data->pos_y + STEP_MOVE * data->dir_x;
	if (data->map[(int)(data->pos_x)][(int)(new)] != '1'
		&& data->map[(int)(data->pos_x)][(int)(new)] != 'D')
	{
		data->pos_y = new;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}
