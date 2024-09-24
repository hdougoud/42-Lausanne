/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:11:34 by kchatel           #+#    #+#             */
/*   Updated: 2024/06/30 15:11:57 by kchatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_col_up(int col, char *arg)
{
	return (arg[col * 2] - 48);
}

int	get_col_down(int col, char *arg)
{
	return (arg[(SIZE * 2) + col * 2] - 48);
}

int	get_row_left(int row, char *arg)
{
	return (arg[(SIZE * 4) + row * 2] - 48);
}

int	get_row_right(int row, char *arg)
{
	return (arg[(SIZE * 6) + row * 2] - 48);
}
