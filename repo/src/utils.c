/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:22 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/19 13:49:48 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	mlx_print_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
}

void	mlx_error_exit(t_data *data)
{
	mlx_print_error();
	mlx_terminate(data->mlx);
	exit(1);
}
