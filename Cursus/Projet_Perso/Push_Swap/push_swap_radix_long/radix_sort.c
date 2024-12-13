/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 18:11:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_negatif(t_stack *stack)
{
	int		min;
	t_stack	*index;

	min = 0;
	index = stack;
	while (index)
	{
		if (index->nb < min)
			min = index->nb;
		index = index->next;
	}
	printf("%d\n", min);
	if (min == 0)
		return (0);
	min = -min;
	printf("%d\n", min);
	while (stack)
	{
		stack->nb = stack->nb + min;
		stack = stack->next;
	}
	return (min);
}

static void	restore_value(t_stack *stack, int min)
{
	while (stack)
	{
		stack->nb = stack->nb - min;
		stack = stack->next;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	int		min;
	int		bits;
	int		bnodes;

	min = check_negatif(*stack_a);
	bnodes = nodes;
	bits = 0;
	while (bits < 32)
	{
		while (bnodes > 0)
		{
			if ((((*stack_a)->nb >> bits) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			bnodes--;
		}
		bnodes = nodes;
		while (*stack_b)
			push_a(stack_b, stack_a);
		bits++;
	}
	if (min != 0)
		restore_value(*stack_a, min);
}
