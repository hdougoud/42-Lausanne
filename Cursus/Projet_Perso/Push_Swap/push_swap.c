/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:46 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/05 16:08:01 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(int argc, int *tab, char c)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("digit %d	%c\n", tab[i], c);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab_a;
	//t_tab	tab_b;
	i = 0;
	tab_a.size = 0;
	tab_a.array = check_errors(argc, argv, &tab_a.size);
	while (i < tab_a.size)
	{
		printf("PUSHSWAP BEFORE%d\n", tab_a.array[i]);
		i++;
	}
	i = 0;
	swap(&tab_a.array);
	while (i < tab_a.size)
	{
		printf("PUSHSWAP AFTER%d\n", tab_a.array[i]);
		i++;
	}
	exit(EXIT_SUCCESS);
}
