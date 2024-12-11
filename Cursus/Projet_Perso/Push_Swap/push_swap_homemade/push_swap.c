/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:57:00 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/11 17:21:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	check_errors(argc, argv);
	stack_a = create_list(argc, argv, stack_a);
	check_duplicate(stack_a);
	print_list(stack_a, stack_b);
	check_sort(&stack_a, &stack_b);
	print_list(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
