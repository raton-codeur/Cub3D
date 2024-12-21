/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:18:34 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 16:43:47 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H

# include "main_bonus.h"

/* main_hook_bonus.c */
void		main_hook(void *param);

/* key_hook_bonus.c */
void		key_hook(mlx_key_data_t keydata, void *param);

/* mouse_hook_bonus.c */
void		mouse_hook(\
	mouse_key_t button, action_t action, modifier_key_t mods, void *param);
void		cursor_hook(double xpos, double ypos, void *param);

/* move_bonus.c */
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

/* rotate_bonus.c */
void		rotate_x(t_data *data, double step);
void		rotate_y(t_data *data, int step);

/* set_depth.c */
void		set_depth(t_data *data);

#endif