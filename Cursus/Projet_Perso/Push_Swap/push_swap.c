/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:46 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/06 16:04:20 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(t_tab tab_a, t_tab tab_b) //DEBUG FUNCTION
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_a.size > i || tab_b.size > i)
	{
		if (i < tab_a.size)
			printf("PUSHSWAP	TAB_A[%d]%d", i,  tab_a.array[i]);
		else
			printf("PUSHSWAP	TAB_A[]	");
		if (j < tab_b.size)
			printf("		TAB_B[%d]%d\n", i, tab_b.array[i]);
		else
			printf("		TAB_B[]\n");
		i++;
		j++;
	}
	//printf("\nTAB SIZE	TAB_A %d			TAB_B %d\n\n", tab_a.size, tab_b.size);
	printf("\n--------------------------------------------------------\n\n");
}
	
int	main(int argc, char **argv)
{
	t_tab	tab_a;
	t_tab	tab_b;
	
	tab_a.size = 0;
	tab_a.array = check_errors(argc, argv, &tab_a.size);
	tab_b.array = malloc(sizeof(int) * tab_a.size);
	if (!tab_b.array)
	{
		free(tab_a.array);
		show_error();
	}
	// print_tab(tab_a, tab_b);
	// swap(&tab_a.array);
	print_tab(tab_a, tab_b);
	push(&tab_a, &tab_b);
	print_tab(tab_a, tab_b);
	push(&tab_a, &tab_b);
	print_tab(tab_a, tab_b);
	push(&tab_a, &tab_b);
	print_tab(tab_a, tab_b);
	rotate(&tab_a);
	// print_tab(tab_a, tab_b);
	// double_rotate(&tab_a, &tab_b);
	print_tab(tab_a, tab_b);
	double_rotate(&tab_a, &tab_b);
	print_tab(tab_a, tab_b);
	free(tab_a.array);
	free(tab_b.array);
	exit(EXIT_SUCCESS);
}
