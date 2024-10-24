/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 19:14:52 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	load_map(data);
	init_window(data);
	init_background(data);
	init_map(data);
	init_rays(data);
	init_player(data);
	init_walls(data);
}
