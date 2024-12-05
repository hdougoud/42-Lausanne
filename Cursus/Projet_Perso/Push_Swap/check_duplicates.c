/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:33:24 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/05 11:35:17 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_array(int argc, char **argv, int *tab)
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

static int *create_array(int argc, char **argv, int *tab_size)
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
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	return (tab);
}

int	check_duplicate(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	position;
	int	tab_size;

	i = 0;
	tab = create_array(argc, argv, &tab_size);
	tab = fill_array(argc, argv, tab);
	while (i < tab_size)
	{
		position = 0;
		while (position < tab_size)
		{
			if (position > tab_size)
				break;
			else if (i == position)
				position++;
			else if (tab[position] == tab[i])
				return (1);
			else
				position++;
		}
		i++;
	}
	return (free(tab), 0);
}
