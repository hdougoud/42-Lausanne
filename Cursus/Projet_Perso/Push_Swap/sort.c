/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:11:28 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/08 03:39:24 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_result(t_tab tab)
{
	int i;
	
	i = 0;
	while (i < tab.size)
	{
		if (tab.array[i] > tab.array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void sort_tab(t_tab tab_a, t_tab tab_b)
{
	tab_b.size = 2;
	tab_b.array[1] = 10;
 	
	if (check_result(tab_a) == 1)
	{
		printf("%s\n", "stack not sorted");
		exit(EXIT_FAILURE);
	}
	else 
		printf("%s\n", "stack sorted :)");
}
