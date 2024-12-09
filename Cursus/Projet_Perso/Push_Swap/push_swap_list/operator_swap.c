/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:28:10 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/09 23:08:03 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack *current;
	int temp;
	
	if (stack == NULL || stack->next == NULL)
		return ;
	current = stack;
	current = current->next;
	temp = stack->nb;
	stack->nb = current->nb;
	stack = stack->next;
	stack->nb = temp;
}

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
