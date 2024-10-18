/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:13:17 by kchatel           #+#    #+#             */
/*   Updated: 2024/06/30 15:13:21 by kchatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# define SIZE 4

typedef struct s_pos {
	int	col;
	int	row;
}	t_pos;

int		get_col_up(int col, char *arg);
int		get_col_down(int col, char *arg);
int		get_row_left(int row, char *arg);
int		get_row_right(int row, char *arg);
void	ft_putchar(char c);
void	display_error(void);
void	show_solution(int map[SIZE][SIZE]);
int		check_args(char argc, char **argv);
int		check_up(int map[SIZE][SIZE], t_pos pos, int val, char *arg);
int		check_down(int map[SIZE][SIZE], t_pos pos, int val, char *arg);
int		check_left(int map[SIZE][SIZE], t_pos pos, int val, char *arg);
int		check_right(int map[SIZE][SIZE], t_pos pos, int val, char *arg);
int		is_valid(int map[SIZE][SIZE], t_pos pos, int val, char *arg);
t_pos	get_next_pos(t_pos pos);
int		place_box(int map[SIZE][SIZE], t_pos pos, int val, char *arg);
void	initialize_map(int map[SIZE][SIZE]);

#endif
