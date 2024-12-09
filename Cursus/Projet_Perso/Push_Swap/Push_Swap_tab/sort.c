/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:11:28 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/09 12:47:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_result(t_tab tab)
{
	int i;
	
	i = 0;
	while (i < (tab.size - 1))
	{
		if (tab.array[i] > tab.array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort(t_tab *tab_a, t_tab *tab_b)
{
	int i;

	i = 0;
	if (tab_b->size == 100)
		return;
	while(1)
	{
		if (tab_a->array[0] > tab_a->array[1])
		{
			swap(tab_a);
			ft_printf("%s\n", "sa");
		}
		
		break;
	}
}

void sort_tab(t_tab *tab_a, t_tab *tab_b)
{
	if (check_result(*tab_a) == 0)
	{
		printf("%s\n", "stack sorted");
		exit(EXIT_SUCCESS);
	}
	else
		sort(tab_a, tab_b);
}
