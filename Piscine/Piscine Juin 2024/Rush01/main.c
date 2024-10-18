/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:12:34 by kchatel           #+#    #+#             */
/*   Updated: 2024/06/30 15:12:37 by kchatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_valid(int map[SIZE][SIZE], t_pos pos, int val, char *arg)
{
	int	i;

	i = 0;
	while (i < SIZE)
		if (map[i++][pos.row] == val)
			return (0);
	i = 0;
	while (i < SIZE)
		if (map[pos.col][i++] == val)
			return (0);
	if (pos.row == SIZE - 1)
	{
		if (!check_up(map, pos, val, arg)
			|| !check_down(map, pos, val, arg))
			return (0);
	}
	if (pos.col == SIZE - 1)
	{
		if (!check_left(map, pos, val, arg)
			|| !check_right(map, pos, val, arg))
			return (0);
	}
	return (1);
}

t_pos	get_next_pos(t_pos pos)
{
	t_pos	next_pos;

	if (pos.row == SIZE - 1)
	{
		next_pos.col = pos.col + 1;
		next_pos.row = 0;
	}
	else
	{
		next_pos.col = pos.col;
		next_pos.row = pos.row + 1;
	}
	return (next_pos);
}

int	place_box(int map[SIZE][SIZE], t_pos pos, int val, char *arg)
{
	t_pos	next_pos;

	if (pos.col > SIZE - 1)
	{
		show_solution(map);
		return (1);
	}
	while (val <= SIZE)
	{
		if (is_valid(map, pos, val, arg))
		{
			map[pos.col][pos.row] = val;
			next_pos = get_next_pos(pos);
			if (place_box(map, next_pos, 1, arg))
				return (1);
			map[pos.col][pos.row] = 0;
		}
		val++;
	}
	return (0);
}

void	initialize_map(int map[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		map[SIZE][SIZE];
	t_pos	p;

	p.col = 0;
	p.row = 0;
	if (check_args(argc, argv))
		return (0);
	initialize_map(map);
	if (!place_box(map, p, 1, argv[1]))
		display_error();
}
