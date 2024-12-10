/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:23:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/10 13:45:33 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_nodes(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa");
}

void	sort_three_nodes(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nb > ((*stack_a)->next->nb))
		sort_two_nodes;
}