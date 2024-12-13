/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:47:49 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 16:45:20 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	if (*stack == NULL || stack == NULL)
		return ;
	first = *stack;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	*stack = (*stack)->next;
	first->next = NULL;
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
