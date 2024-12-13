/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 17:31:27 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_negatif(t_stack **stack)
{
	int		negative;
	t_stack	*index;

	negative = 0;
	index = *stack;
	while(index)
	{
		if (index->nb < 0)
			negative = index->nb;
		index = index->next;
	}
	if (negative == 0)
		return ;
	//TODO modifier tout les nombre EX: negatif = -122 stack->nb = stack->(nb + 122)
	while()
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	t_stack	*index; //decaler les negatif pour qu'il deviennent positif
	int		bits;
	int		bnodes;

	check_negatif(stack_a);
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
}
