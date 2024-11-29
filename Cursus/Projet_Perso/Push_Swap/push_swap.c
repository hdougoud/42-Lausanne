/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:46 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/29 16:28:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static int	*convert_tab(int argc, char **argv)
{
	int	i;
	int	*nb_tab;

	i = 1;
	nb_tab = malloc(sizeof(int) * (argc - 1));
	if (!nb_tab)
	{
		free(nb_tab);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		nb_tab[i] = ft_atoi(argv[i]);
		i++;
	}
	return (nb_tab);
}

void	print_tab(int argc, int *tab)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("digit %d\n", tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_tab	tab_a;
	t_tab	tab_b;

	i = 1;
	tab_a.size = argc - 1;
	tab_b.size = argc - 1;
	check_errors(argc, argv);
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i ++;
	}
	tab_a.tab = convert_tab(argc, argv);
	tab_b.tab = malloc(sizeof(int) * (tab_b.size));
	if (!tab_b.tab)
	{
		free(tab_a.tab);
		exit(EXIT_FAILURE);
	}
	print_tab(argc, tab_a.tab);
	print_tab(argc, tab_b.tab);
	printf("arguments %d\n", argc);
	free(tab_a.tab);
	free(tab_b.tab);
	exit(EXIT_SUCCESS);
}
