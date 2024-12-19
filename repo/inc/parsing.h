/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:06:17 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 11:29:31 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "main.h"
# include "init_mlx.h"

# define FILLER '1'

/* parsing.c */
void		parsing(t_data *data, int argc, char **argv);

/* load_cub_file.c */
void		load_cub_file(t_data *data);

/* find_textures.c */
void		find_textures_no_so(t_data *data, int i, int j);
void		find_textures_we_ea(t_data *data, int i, int j);
void		copy_texture(t_data *data, char **dest, int i, int j);
void		check_textures(t_data *data);

/* find_colors.c */
void		find_colors(t_data *data, int i, int j);
void		fill_rgb_colors(t_data *data);

/* check_maze.c */
void		check_maze(t_data *data);

/* check_colors.c */
void		check_color_string(t_data *data, char *color);

/* find_map.c */
void		find_map(t_data *data, int i, int j);
void		remove_newline_from_map(t_data *data);

/* check_map.c */
void		get_map_size(t_data *data);
void		first_and_last_char(t_data *data);
void		check_non_leading_spaces(t_data *data, int i, int j);
void		check_map_lines(t_data *data, int i, int j);
void		check_zero(t_data *data, int i, int j);

/* check_map_2.c */
void		check_map_chars(t_data *data);
void		find_player(t_data *data);

/* check_map_3.c */
void		first_and_last_line(t_data *data);

/* clean_map.c */
void		normalize_map_rows(t_data *data, int max_len);
void		fill_spaces(t_data *data);

/* parsing_utils.c */
int			skip_spaces(char *str, int i, int len);
void		extension_checker(t_data *data);
bool		check_split_content(char **split);
bool		check_split_content_size(char **split);
char		*remove_newline(char *str, t_data *data);

/* parsing_utils_2.c */
void		check_cub_order(t_data *data);
void		texture_count(t_data *data, int i, int j, int count);
void		color_count(t_data *data, int i, int j, int count);
bool		spaces(char c);

/* clean_parsing.c */
void		clean_parsing(t_data *data);

/* reverse_map.c */
void		reverse_map(t_data *data);
void		get_map_dimensions(t_data *data);
void		print_map(t_data *data);

/* split_parsing.c */
char		**split_parsing(char const *s, char c, t_data *data);

#endif