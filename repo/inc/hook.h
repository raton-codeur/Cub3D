/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:16:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/15 10:22:39 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "main.h"

/* other_keys_hook.c */
void	other_keys_hook(mlx_key_data_t keydata, void *param);

/* main_hook.c */
void	main_hook(void *param);

/* check_keys.c */
void	check_movement_keys(t_data *data);
void	check_angle_keys(t_data *data);

#endif