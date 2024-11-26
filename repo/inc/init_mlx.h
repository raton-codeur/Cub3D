/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:51 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/26 19:09:23 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H

# define INIT_H

# include "main.h"

/* init_mlx.c */
void		init_mlx(t_data *data);
mlx_image_t	*get_img_from_png(t_data *data, const char *file);

/* init_window.c */
void		init_window(t_data *data);

/* init_background.c */
void		init_background(t_data *data);

/* init_map.c */
void		init_map(t_data *data);
void		init_minimap(t_data *data);

/* init_rays.c */
void	init_rays_map(t_data *data);
void	init_rays_minimap(t_data *data);


/* init_player.c*/
void	init_player_map(t_data *data);

/* init_walls.c */
void		init_walls(t_data *data);

#endif