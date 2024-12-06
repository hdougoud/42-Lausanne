/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:33:24 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/06 16:05:30 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*check_fill_array(int argc, char **argv, int *tab)
{
	char	buffer[13];
	int		tab_pos;
	int		x;
	int		y;
	int		i;

	y = 0;
	tab_pos = 0;
	while(++y < argc)
	{
		x = 0;
		while(argv[y][x])
		{
			i = 0;
			while(argv[y][x] && argv[y][x] != ' ')
				buffer[i++] = argv[y][x++];
			buffer[i] = '\0';
			tab[tab_pos] = ft_atoi(buffer);
			tab_pos++;
			if (argv[y][x] != '\0')
				x++;
		}
	}
	return (tab);
}

static int *check_create_array(int argc, char **argv, int *tab_size)
{
	int	*tab;
	int	i;
	int	j;

	j = 0;
	tab = NULL;
	(*tab_size) = 0;
	while(++j < argc)
	{
		i = 0;
		while(argv[j][i])
		{
			if (argv[j][i] == ' ')
				(*tab_size)++;
			i++;
		}
		(*tab_size)++;
	}
	tab = malloc(sizeof(int) * (*tab_size));
	if (!tab)
		show_error();
	return (tab);
}

int	*check_duplicate(int argc, char **argv, int *tab_size)
{
	int	*tab;
	int	i;
	int	position;

	i = 0;
	tab = check_create_array(argc, argv, tab_size);
	tab = check_fill_array(argc, argv, tab);
	while (i < *tab_size)
	{
		position = 0;
		while (position < *tab_size)
		{
			if (position > *tab_size)
				break;
			else if (i == position)
				position++;
			else if (tab[position] == tab[i])
				show_error();
			else
				position++;
		}
		i++;
	}
	return (tab);
}
