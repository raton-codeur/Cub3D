/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:29:21 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/13 16:19:51 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	clear_sprite(t_data *data, t_list **list)
{
	t_list	*node;
	t_list	*next_node;

	if (list == NULL || *list == NULL)
		return ;
	node = *list;
	*list = NULL;
	while (node)
	{
		next_node = node->next;
		if (node->content)
			mlx_delete_image(data->mlx, node->content);
		free(node);
		node = next_node;
	}
	data->sprite_frames = NULL;
}
