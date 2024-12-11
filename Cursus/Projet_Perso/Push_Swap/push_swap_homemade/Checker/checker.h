/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:24:04 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/11 18:37:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

void	check_duplicate(t_stack *stack);

void	swap(t_stack *stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack **stack_src, t_stack **stack_dest);
void	rotate(t_stack **stack);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);

#endif