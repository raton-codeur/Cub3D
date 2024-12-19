/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:51 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 12:05:21 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "main.h"

/* init_game.c */
void		init_game(t_data *data);
mlx_image_t	*get_img_from_png(t_data *data, const char *file);

/* init_dimensions.c */
void		init_dimensions(t_data *data);

/* init_window.c */
void		init_window(t_data *data);

/* init_background.c */
void		init_background(t_data *data);

/* init_maps.c */
void		init_map(t_data *data);
void		init_minimap(t_data *data);
void		init_mini_player_and_rays(t_data *data);

/* init_rays.c */
void		init_rays_map(t_data *data);
void		init_rays_minimap(t_data *data);

/* init_players.c*/
void		init_player_map(t_data *data);
void		init_player_minimap(t_data *data);

/* init_game_img.c */
void		init_game_img(t_data *data);

#endif