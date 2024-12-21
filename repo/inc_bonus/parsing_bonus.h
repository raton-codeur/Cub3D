/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:47:15 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 18:15:23 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "main_bonus.h"

# define FILLER '1'

/* parsing_bonus.c */
void		parsing(t_data *data, int argc, char **argv);

/* load_cub_file_bonus.c */
void		load_cub_file(t_data *data);

/* find_textures_bonus.c */
void		find_textures_no_so(t_data *data, int i, int j);
void		find_textures_we_ea(t_data *data, int i, int j);
void		copy_texture(t_data *data, char **dest, int i, int j);
void		check_textures(t_data *data);

/* find_colors_bonus.c */
void		find_colors(t_data *data, int i, int j);
void		fill_rgb_colors(t_data *data);

/* check_maze_bonus.c */
void		check_maze(t_data *data);

/* check_colors_bonus.c */
void		check_color_string(t_data *data, char *color);

/* find_map_bonus.c */
void		find_map(t_data *data, int i, int j);
void		remove_newline_from_map(t_data *data);

/* check_map_bonus.c */
void		get_map_size(t_data *data);
void		first_and_last_char(t_data *data);
void		check_non_leading_spaces(t_data *data, int i, int j);
void		check_map_lines(t_data *data, int i, int j);
void		check_zero(t_data *data, int i, int j);

/* check_map_2_bonus.c */
void		check_map_chars(t_data *data);
void		find_player(t_data *data);

/* check_map_3_bonus.c */
void		first_and_last_line(t_data *data);

/* clean_map_bonus.c */
void		normalize_map_rows(t_data *data, int max_len);
void		fill_spaces(t_data *data);

/* parsing_utils_bonus.c */
int			skip_spaces(char *str, int i, int len);
void		extension_checker(t_data *data);
bool		check_split_content(char **split);
bool		check_split_content_size(char **split);
char		*remove_newline(char *str, t_data *data);

/* parsing_utils_2_bonus.c */
void		check_cub_order(t_data *data);
void		texture_count(t_data *data, int i, int j, int count);
void		color_count(t_data *data, int i, int j, int count);
bool		spaces(char c);

/* clean_parsing_bonus.c */
void		clean_parsing(t_data *data);

/* reverse_map_bonus.c */
void		reverse_map(t_data *data);
void		get_map_dimensions(t_data *data);
void		print_map(t_data *data);

/* split_parsing_bonus.c */
char		**split_parsing(char const *s, char c, t_data *data);

#endif