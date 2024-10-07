/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:10:43 by kchatel           #+#    #+#             */
/*   Updated: 2024/06/30 15:11:13 by kchatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_args(char argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		display_error();
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(argv[1][i] == ' '
			|| (argv[1][i] >= '1' && argv[1][i] <= SIZE + 48)))
		{
			display_error();
			return (1);
		}
		i++;
	}
	if (i != (SIZE * 4 * 2 - 1))
	{
		display_error();
		return (1);
	}
	return (0);
}

int	check_up(int map[SIZE][SIZE], t_pos pos, int val, char *arg)
{
	int	i;
	int	max;
	int	count;

	map[pos.col][pos.row] = val;
	i = 0;
	max = 0;
	count = 0;
	while (i < SIZE)
	{
		if (map[pos.col][i] > max)
		{
			max = map[pos.col][i];
			count++;
		}
		i++;
	}
	if (count != get_col_up(pos.col, arg))
	{
		map[pos.col][pos.row] = 0;
		return (0);
	}
	return (1);
}

int	check_down(int map[SIZE][SIZE], t_pos pos, int val, char *arg)
{
	int	i;
	int	max;
	int	count;

	map[pos.col][pos.row] = val;
	i = SIZE - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (map[pos.col][i] > max)
		{
			max = map[pos.col][i];
			count++;
		}
		i--;
	}
	if (count != get_col_down(pos.col, arg))
	{
		map[pos.col][pos.row] = 0;
		return (0);
	}
	return (1);
}

int	check_left(int map[SIZE][SIZE], t_pos pos, int val, char *arg)
{
	int	i;
	int	max;
	int	count;

	map[pos.col][pos.row] = val;
	i = 0;
	max = 0;
	count = 0;
	while (i < SIZE)
	{
		if (map[i][pos.row] > max)
		{
			max = map[i][pos.row];
			count++;
		}
		i++;
	}
	if (count != get_row_left(pos.row, arg))
	{
		map[pos.col][pos.row] = 0;
		return (0);
	}
	return (1);
}

int	check_right(int map[SIZE][SIZE], t_pos pos, int val, char *arg)
{
	int	i;
	int	max;
	int	count;

	map[pos.col][pos.row] = val;
	i = SIZE - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (map[i][pos.row] > max)
		{
			max = map[i][pos.row];
			count++;
		}
		i--;
	}
	if (count != get_row_right(pos.row, arg))
	{
		map[pos.col][pos.row] = 0;
		return (0);
	}
	return (1);
}
