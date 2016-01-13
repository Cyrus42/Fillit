/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:09:21 by gahubaul          #+#    #+#             */
/*   Updated: 2016/01/07 14:09:23 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 545
# define Y (ym + yt - yo)
# define X (xm + xt - xo)
# define SIZE size_map(map)
# define TETRI what_is_tetri(tetri)

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_check_block(char *buff);
int			ft_check_block_next(char *buff, int i, int line);

int			ft_count_sharp(char *buff);
int			ft_count_enter(char *buff);
int			ft_count_char_sharp_line(char *buff);
int			ft_count_char_tetri(char *buff);

int			ft_count_sharp(char *buff);
int			ft_count_enter(char *buff);
int			ft_count_char_sharp_line(char *buff);
int			ft_count_back(char *buff);

int			check_line(char *line);
int			check_column(char **column, int x);
int			ft_x_tetri_origin(char **tetri);
int			ft_y_tetri_origin(char **tetri);

int			count_tetri(char *buff);
void		ft_error(char *argv);

int			size_map(char **map);
char		**ft_creat_map(int size_map);
char		***ft_tab_buff(char *buff);
void		add_tetri_to_table(char *buff, char ***table, int count);
void		replace_sharp(char ***tab, int count);

void		ft_full_map_point(char **map, int size);
int			what_is_tetri(char **tetri);
int			add_tetri(char **map, int y_map, int x_map, char **tetri);

void		ft_error_exit(char *str);
void		ft_print_map(char **map, int size_map);
void		delete_tetri(char **map, int tetri, int size_map);
void		ft_putchar(char c);

void		ft_resolve(char ***tetri, int maxtetri);
void		recursive(char ***tetri, char **map, int maxtetri, int n_tetri);

#endif
