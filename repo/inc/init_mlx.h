/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:51 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/11 16:45:18 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "main.h"

/* init.c */
void	init_mlx(t_data *data);

/* load_map.c */
// void	load_map(t_data *data);

/* init_window.c */
void	init_window(t_data *data);

/* init_background.c */
void	init_background(t_data *data);

/* init_map.c */
void	init_map(t_data *data);

/* init_rays.c */
void	init_rays(t_data *data);

/* init_player.c*/
void	init_player(t_data *data);

/* init_walls.c */
void	init_walls(t_data *data);

#endif