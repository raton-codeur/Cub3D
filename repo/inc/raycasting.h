/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:16:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 16:58:24 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "main.h"

/* dda.c */
void	dda(t_data *data);

/* init_dda.c */
void	init_dda(t_data *data);

/* render_for_x.c */
void	render_for_x(t_data *data);

/* draw_ray.c */
void	draw_ray_map(t_data *data);
void	draw_ray_minimap(t_data *data);

/* get_pixel.c */
void	get_pixel_wall(t_data *data);

#endif