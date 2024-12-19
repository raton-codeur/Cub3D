/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 21:19:28 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init(1, 1, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	init_dimensions(data);
	init_background(data);
	init_game_img(data);
	init_map(data);
	init_map_rays(data);
	init_map_player(data);
	init_minimap(data);
	init_minimap_player(data);
	data->mini_w_2 = data->minimap->width * data->minimap->width;
	data->mini_step = 10.0 / data->box_size;
	data->ray_dir_ratio = 3.0 / data->box_size;
	data->horizon = data->w_height / 2;
	data->fog_end = FOG_HEIGHT * data->w_height;
	data->fog_max = FOG_MAX * data->fog_end;
	data->visible_max = 1 / (FOG_HEIGHT * FOG_MAX * FOG_HEIGHT * FOG_MAX);
	data->fog_color = FOG_RED << 24 | FOG_GREEN << 16 | FOG_BLUE << 8;
}
