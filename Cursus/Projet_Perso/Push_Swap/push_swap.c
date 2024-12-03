/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:46 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/03 16:36:27 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// static int	*convert_tab(int tab_size, char **argv)
// {
// 	int	i;
// 	int	*nb_tab;

// 	i = 1;
// 	nb_tab = malloc(sizeof(int) * (tab_size));
// 	if (!nb_tab)
// 	{
// 		free(nb_tab);
// 		exit(EXIT_FAILURE);
// 	}
// 	while (i - 1 < tab_size)
// 	{
// 		nb_tab[i - 1] = ft_atoi(argv[i]);
// 		i++;
// 	}
// 	return (nb_tab);
// }

// void	print_tab(int argc, int *tab, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (i < argc)
// 	{
// 		printf("digit %d	%c\n", tab[i], c);
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	// int	i;
	// t_tab	tab_a;
	// t_tab	tab_b;

	// i = 1;
	// tab_a.size = argc - 1;
	// tab_b.size = argc - 1;
	check_errors(argc, argv);
	// while (i < argc)
	// {
	// 	printf("valeur tab %s\n", argv[i]);
	// 	i ++;
	// }
	// tab_a.tab = convert_tab(tab_a.size, argv);
	// tab_b.tab = malloc(sizeof(int) * (tab_b.size));
	// if (!tab_b.tab)
	// {
	// 	free(tab_a.tab);
	// 	exit(EXIT_FAILURE);
	// }
	// print_tab(tab_a.size, tab_a.tab, 'A');
	// print_tab(tab_b.size, tab_b.tab, 'B');
	// printf("arguments %d\n", argc);
	// free(tab_a.tab);
	// free(tab_b.tab);
	exit(EXIT_SUCCESS);
}
