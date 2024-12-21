/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:59 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/20 16:14:13 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_y(t_data *data, int step)
{
	if (data->horizon + step < 0
		|| data->horizon + step >= data->w_height)
		return ;
	data->horizon += step;
	data->background->instances[0].y = data->horizon - data->w_height;
}
