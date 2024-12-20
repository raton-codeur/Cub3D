/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:49:55 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/20 14:55:07 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	get_time_in_ms(void)
{
	double			time_in_ms;

	time_in_ms = mlx_get_time() * 1000;
	return (time_in_ms);
}
