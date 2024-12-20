/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:29:21 by hakgyver          #+#    #+#             */
/*   Updated: 2024/12/20 15:31:51 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
