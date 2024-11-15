/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:16:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/15 11:07:29 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "main.h"

/* draw_ray.c */
void	draw_ray(t_data *data, double camera_x, uint32_t color);

/* dda.c */
void	dda(t_data *data);

#endif