/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:52:07 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/12 00:13:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_result(t_stack *stack)
{
	while(stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	execute_args(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp("sa\n", line, 3) == 0)
		swap(*stack_a);
	else if (ft_strncmp("sb\n", line, 3) == 0)
		swap(*stack_b);
	else if (ft_strncmp("ss\n", line, 3) == 0)
		double_swap(*stack_a, *stack_b);
	else if (ft_strncmp("pa\n", line, 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp("pb\n", line, 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp("ra\n", line, 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp("rb\n", line, 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp("rr\n", line, 3) == 0)
		double_rotate(stack_a, stack_b);
	else if (ft_strncmp("rra\n", line, 4) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp("rrb\n", line, 4) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp("rrr\n", line, 4) == 0)
		double_reverse(stack_a, stack_b);
}

void	free_stack(t_stack *stack)
{
	t_stack *backup;

	backup = stack;
	while (stack)
	{
		backup = backup->next;
		free (stack);
		stack = backup;
	}
}

int main(int argc, char **argv)
{
	char	*line;
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	check_errors(argc, argv);
	stack_a = create_list(argc, argv, stack_a);
	check_duplicate(stack_a);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break;
		execute_args(&stack_a, &stack_b, line);
		free(line);
	}
	if (check_result(stack_a) == 1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		show_error(2);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return(0);
}
