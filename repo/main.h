/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/16 17:55:18 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define CEIL_COLOR 0x409ec9FF
# define FLOOR_COLOR 0x8B4513FF

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*bg;
}	t_data;

/* utils.c */
void	mlx_print_error(void);

/* init.c */
void	init(t_data *data);

/* hooks.c */
void	ft_key_hook(mlx_key_data_t keydata, void *param);

#endif