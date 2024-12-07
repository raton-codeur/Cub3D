/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:51 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/05 14:47:01 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX_H

# define INIT_MLX_H

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
void		init_mini_player_and_rays(t_data *data);

/* init_rays.c */
void		init_rays_map(t_data *data);
void		init_rays_minimap(t_data *data);

/* init_player.c*/
void		init_player_map(t_data *data);

/* init_walls.c */
void		init_walls(t_data *data);

#endif