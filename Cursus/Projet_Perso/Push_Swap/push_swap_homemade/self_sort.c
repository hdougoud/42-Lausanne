/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/11 18:50:48 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_higher(t_stack **stack_a, t_stack **stack_b, int higher, int nodes)
{
	t_stack *index;
	int position;

	index = *stack_a;
	position = 0;
	while(index->nb != higher)
	{
		position++;
		index = index->next;
	}
	if (position > nodes/2)
	{
		while((*stack_a)->nb != higher)
			reverse_rotate_a(stack_a);
	}
	else
	{
		while((*stack_a)->nb != higher)
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}

void	self_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	t_stack *index;
	int number;

	while(*stack_a)
	{
		index = *stack_a;
		number = index->nb;
		while(index->next)
		{
			index = index->next;
			if(number > index->nb)
				number = index->nb;
		}
		push_higher(stack_a, stack_b, number, nodes);
	}
	while(*stack_b)
		push_a(stack_b, stack_a);
}
