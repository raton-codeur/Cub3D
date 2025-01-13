/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:33:10 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 16:23:12 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	play_animation(t_data *data)
{
	double	current_time;

	if (data->animation_active == 0)
		return ;
	current_time = get_time_in_ms();
	if (current_time - data->last_update >= (double)data->frame_delay)
	{
		((mlx_image_t *)(data->current_frame->content))->enabled = 0;
		data->frame_index++;
		if (data->frame_index < data->total_frames)
		{
			data->current_frame = data->current_frame->next;
			((mlx_image_t *)(data->current_frame->content))->enabled = 1;
		}
		else
		{
			data->frame_index = 0;
			data->current_frame = data->sprite_frames;
			((mlx_image_t *)(data->current_frame->content))->enabled = 1;
			data->animation_active = 0;
		}
		data->last_update = current_time;
	}
}

void	shot_with_gun(t_data *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		if (data->animation_active == 0)
		{
			data->animation_active = 1;
			data->last_update = get_time_in_ms();
		}
	}
}

static void	init_frames_vars(t_data *data)
{
	data->current_frame = data->sprite_frames;
	data->frame_index = 0;
	data->total_frames = 5;
	data->frame_delay = 50;
	data->last_update = get_time_in_ms();
	data->animation_active = 0;
}

static void	init_frames(t_data *data)
{
	mlx_image_t		*frame;

	data->sprite_frames = NULL;
	frame = get_img_from_png(data, "textures/gun/1.png");
	if (frame == NULL)
		mlx_perror_exit(data);
	list_add_back(&data->sprite_frames, list_new(frame));
	frame = get_img_from_png(data, "textures/gun/2.png");
	if (frame == NULL)
		mlx_perror_exit(data);
	list_add_back(&data->sprite_frames, list_new(frame));
	frame = get_img_from_png(data, "textures/gun/3.png");
	if (frame == NULL)
		mlx_perror_exit(data);
	list_add_back(&data->sprite_frames, list_new(frame));
	frame = get_img_from_png(data, "textures/gun/4.png");
	if (frame == NULL)
		mlx_perror_exit(data);
	list_add_back(&data->sprite_frames, list_new(frame));
	frame = get_img_from_png(data, "textures/gun/5.png");
	if (frame == NULL)
		mlx_perror_exit(data);
	list_add_back(&data->sprite_frames, list_new(frame));
}

void	init_sprite(t_data *data)
{
	int		frame_height;
	int		i;
	t_list	*tmp;

	i = 0;
	init_frames(data);
	init_frames_vars(data);
	frame_height = ((mlx_image_t *)(data->sprite_frames->content))->height;
	tmp = data->sprite_frames;
	while (data->sprite_frames->next)
	{
		if (i == 0)
			mlx_image_to_window(data->mlx, data->sprite_frames->content,
				(data->w_width / 2), data->w_height - frame_height);
		else
		{
			mlx_image_to_window(data->mlx, data->sprite_frames->content,
				(data->w_width / 2), data->w_height - frame_height);
			((mlx_image_t *)(data->sprite_frames->content))->enabled = false;
		}
		data->sprite_frames = data->sprite_frames->next;
		i++;
	}
	data->sprite_frames = tmp;
}
