/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:06:17 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/11 16:42:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "main.h"

/* parsing.c */
void		parse_map(t_data *data, int argc, char **argv);

/* load_cub_file.c */
bool		load_cub_file(t_data *data);

/* find_textures.c */
bool		find_textures_no_so(t_data *data, int i, int j);
bool		find_textures_we_ea(t_data *data, int i, int j);
bool		copy_texture(t_data *data, char **dest, int i, int j);
bool		check_textures(t_data *data);


/* find_colors.c */
bool				find_colors(t_data *data, int i, int j);
bool				fill_rgb_colors(t_data *data);
unsigned int		rgb_color_to_hex(t_color *color);

/* find_map.c */
bool		find_map(t_data *data, int i, int j);
bool		remove_newline_from_map(t_data *data);

/* check_map.c */
int			get_map_size(char **map);
bool		first_and_last_line(t_data *data);
bool		first_and_last_char(t_data *data);
bool		check_non_leading_spaces(t_data *data);
bool		check_map_lines(t_data *data);

/* check_map_2.c */
bool		check_map_chars(t_data *data);

/* parsing_utils.c */
int			skip_spaces(char *str, int i, int len);
bool		extension_checker(char *path);
bool		check_split_content(char **split);
bool		check_split_content_size(char **split);
char		*remove_newline(char *str);

/* parsing_utils_2.c */
bool		check_cub_order(t_data *data);

#endif