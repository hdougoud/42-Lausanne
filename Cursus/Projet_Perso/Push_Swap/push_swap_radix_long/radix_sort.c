/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 19:06:06 by hdougoud         ###   ########.fr       */
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

static int	get_binary(int nb)
{
	int i;

	i = 0;
	while(nb > 0)
	{
		nb /= 2;
		i++;
	}
	printf("%d\n", i);
	return (i);
}

static int	get_max_bits(t_stack *stack)
{
	int		max;

	max = get_binay(stack->nb);
	while(stack)
	{
		if (get_binay(stack->nb) > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (0);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	int		min;
	int		bits;
	int		bnodes;
	int 	max_bits;

	max_bits = get_max_bits(*stack_a);  //TODO : TEST INT_MAX ET INT_MIN
	return ;
	min = check_negatif(*stack_a);
	bnodes = nodes;
	bits = -1;
	while (++bits < max_bits)
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
	}
	if (min != 0)
		restore_value(*stack_a, min);
}
