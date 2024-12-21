/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:16:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 18:17:05 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "main_bonus.h"

/* dda_bonus.c */
void	dda(t_data *data);

/* init_dda_bonus.c */
void	init_dda(t_data *data);

/* render_for_x_bonus.c */
void	render_for_x(t_data *data);

/* draw_ray_bonus.c */
void	draw_ray_map(t_data *data);
void	draw_ray_minimap(t_data *data);
void	draw_ray_map_fog(t_data *data);
void	draw_ray_minimap_fog(t_data *data);

/* get_pixel_bonus.c */
void	get_pixel_wall(t_data *data);
void	get_pixel_wall_fog(t_data *data);
void	get_pixel_fog_extra(t_data *data);

#endif