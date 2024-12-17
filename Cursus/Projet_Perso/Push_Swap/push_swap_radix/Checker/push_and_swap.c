/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:28:10 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 13:25:31 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *stack)
{
    t_stack	*current;
    int		temp;

    if (stack == NULL || stack->next == NULL)
        return ;
    current = stack->next;
    temp = stack->nb;
    stack->nb = current->nb;
    current->nb = temp;
	printf("swap in function");
}

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if ((*stack_src) == NULL)
		return ;
	temp = (*stack_src);
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dest;
	(*stack_dest) = temp;
}
