/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/12 16:19:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_bytes(int nb)
{
	int i;
	char byte;
	
	i = 7;
	while(i >= 0)
	{
		byte = ((nb >> i) & 1) + '0';
		write(1, &byte, 1);
		i--;
	}
	write(1, "\n", 1);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *index;
	int 	byte;
	int		i;

	i = 500;
	byte = 0;
	print_list(*stack_a, *stack_b);
	while (byte < 9)
	{
		while(i > 0)
		{
			if ((((*stack_a)->nb >> byte) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			i--;
		}
		i = 500;
		while(*stack_b)
			push_b(stack_b, stack_a);
		byte++;
	}
	print_list(*stack_a, *stack_b);
}

