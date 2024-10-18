/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:56:32 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/23 16:56:36 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int x, int i, int y)
{
	int	j;

	j = 0;
	while (++j <= x)
	{
		if (i == 1 && j == 1)
			ft_putchar('/');
		else if (i == 1 && j == x)
			ft_putchar('\\');
		else if (i == y && j == 1)
			ft_putchar('\\');
		else if (i == y && j == x)
			ft_putchar('/');
		else if (i == 1 || i == y || j == 1 || j == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (++i <= y)
	{
		print_line(x, i, y);
	}
}
