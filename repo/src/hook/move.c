/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:01:26 by qhauuy            #+#    #+#             */
/*   Updated: 2025/01/08 18:16:15 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	move_up(t_data *data)
{
	data->new_pos = data->pos_x + STEP_MOVE * data->dir_x;
	if (data->map[(int)data->new_pos][(int)data->pos_y] != '1')
	{
		data->pos_x = data->new_pos;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	data->new_pos = data->pos_y + STEP_MOVE * data->dir_y;
	if (data->map[(int)data->pos_x][(int)data->new_pos] != '1')
	{
		data->pos_y = data->new_pos;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}

void	move_down(t_data *data)
{
	data->new_pos = data->pos_x - STEP_MOVE * data->dir_x;
	if (data->map[(int)data->new_pos][(int)data->pos_y] != '1')
	{
		data->pos_x = data->new_pos;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	data->new_pos = data->pos_y - STEP_MOVE * data->dir_y;
	if (data->map[(int)data->pos_x][(int)data->new_pos] != '1')
	{
		data->pos_y = data->new_pos;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}

void	move_left(t_data *data)
{
	data->new_pos = data->pos_x + STEP_MOVE * data->dir_y;
	if (data->map[(int)data->new_pos][(int)data->pos_y] != '1')
	{
		data->pos_x = data->new_pos;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	data->new_pos = data->pos_y - STEP_MOVE * data->dir_x;
	if (data->map[(int)data->pos_x][(int)data->new_pos] != '1')
	{
		data->pos_y = data->new_pos;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}

void	move_right(t_data *data)
{
	data->new_pos = data->pos_x - STEP_MOVE * data->dir_y;
	if (data->map[(int)data->new_pos][(int)data->pos_y] != '1')
	{
		data->pos_x = data->new_pos;
		data->map_player->instances[0].x
			= data->pos_x * data->box_size - data->map_player->width / 2;
	}
	data->new_pos = data->pos_y + STEP_MOVE * data->dir_x;
	if (data->map[(int)data->pos_x][(int)data->new_pos] != '1')
	{
		data->pos_y = data->new_pos;
		data->map_player->instances[0].y
			= data->pos_y * data->box_size - data->map_player->width / 2;
	}
}
