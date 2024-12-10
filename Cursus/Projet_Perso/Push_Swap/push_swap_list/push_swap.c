/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:57:00 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/10 13:28:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_list(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	printf("\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("TAB_A	[%d] %d		",i , stack_a->nb);
			stack_a = stack_a->next;
		}
		else
			printf("TAB_A[]	NULL		");
		if (stack_b)
		{
			printf("TAB_B[%d] %d\n",i , stack_b->nb);	
			stack_b = stack_b->next;
		}
		else
			printf("TAB_B[]	NULL\n");
		i++;
	}
	printf("_____________________________________________\n");
}

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
