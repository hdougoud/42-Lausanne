/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:18 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 11:38:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*backup;

	if (*stack == NULL || stack == NULL)
		return ;
	backup = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	while (backup->next->next != NULL)
		backup = backup->next;
	backup->next = NULL;
	last->next = (*stack);
	(*stack) = last;
}

void	double_reverse(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
