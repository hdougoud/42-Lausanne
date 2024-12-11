/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:21:33 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/09 23:08:21 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int n)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = n;
	new->next = NULL;
	return (new);
}

void free_stack(t_stack *stack)
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
