/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:51 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 16:07:12 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_BONUS_H
# define INIT_GAME_BONUS_H

# include "main_bonus.h"

/* init_game_bonus.c */
void		init_game(t_data *data);

/* init_dimensions.c */
void		init_dimensions(t_data *data);

/* init_background.c */
void		init_background(t_data *data);

/* init_game_img.c */
void		init_game_img(t_data *data);

/* init_map.c */
void		init_map(t_data *data);
void		init_map_rays(t_data *data);
void		init_map_player(t_data *data);

/* init_minimap.c */
void		init_minimap(t_data *data);
void		init_minimap_player(t_data *data);

#endif