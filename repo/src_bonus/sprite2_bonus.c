/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:49:55 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 16:20:02 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

double	get_time_in_ms(void)
{
	double			time_in_ms;

	time_in_ms = mlx_get_time() * 1000;
	return (time_in_ms);
}
