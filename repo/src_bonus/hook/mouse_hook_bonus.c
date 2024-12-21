/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:17:07 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 15:47:21 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_bonus.h"

void	mouse_hook(
	mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_data	*data;

	(void)mods;
	data = param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		data->mouse_state = !data->mouse_state;
		mlx_set_mouse_pos(data->mlx, data->w_width / 2, data->w_height / 2);
		data->xpos = data->w_width / 2;
		data->ypos = data->w_height / 2;
	}
	if (data->mouse_state == 1)
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	else
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
}

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_LEFT))
		return ;
	if (data->mouse_state == 1)
	{
		rotate_y(data, data->ypos - ypos);
		rotate_x(data, 0.001 * (xpos - data->xpos));
	}
	data->xpos = xpos;
	data->ypos = ypos;
}
