/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/16 00:27:46 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FAIRE UN TABLEAU QUI CONVERTI 200 50 350 300 en 2 1 4 3;


static int	get_binary(long nb)
{
	int bits;

	bits = 0;
	if (nb == 0)
		return(1);
	while(nb != 0)
	{
		nb /= 2;
		bits++;
	}
	return (bits);
}

static int	get_max_bits(t_stack *stack)
{
	long	max;

	max = stack->nb;
	while(stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (get_binary(max));
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	int		bits;
	int		bnodes;
	int 	max_bits;

	bnodes = nodes;
	max_bits = get_max_bits(*stack_a);
	convert_list(*stack_a);
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
}
