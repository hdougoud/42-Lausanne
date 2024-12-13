/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 16:53:35 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	t_stack	*index;
	int		bits;
	int		bnodes;

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
