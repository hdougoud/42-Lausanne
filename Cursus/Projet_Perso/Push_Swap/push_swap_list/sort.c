/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:55:13 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/10 13:28:25 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_list(t_stack *stack)
{
	int sorted;

	sorted = 0;
	while(stack->next)
	{
		if ((stack->nb) > (stack->next->nb))
			sorted = 1;
		stack = stack->next;
	}
	return (sorted);
}

static int	count_list(t_stack *stack)
{
	int	i;
	
	i = 0;
	while(stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	check_sort(t_stack **stack_a, t_stack **stack_b)
{
	int nodes;
		
	nodes = count_list(*stack_a);
	if (check_list(*stack_a) == 0)
		return ;
	if (nodes == 2)
		sort_two_nodes(*stack_a);
}
