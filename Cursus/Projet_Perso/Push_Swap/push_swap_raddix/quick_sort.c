/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:23:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/12 13:55:21 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stack **stack_a)
{
	if ((*stack_a)->nb > (*stack_a)->next->next->nb 
		&& (*stack_a)->next->nb < (*stack_a)->next->next->nb)
		rotate_a(stack_a);
	if (((*stack_a)->nb < (*stack_a)->next->nb
		&& (*stack_a)->nb > (*stack_a)->next->next->nb)
		|| ((*stack_a)->next->nb > (*stack_a)->next->next->nb))
		reverse_rotate_a(stack_a);
	if ((*stack_a)->nb > ((*stack_a)->next->nb))
		swap_a(*stack_a);
}