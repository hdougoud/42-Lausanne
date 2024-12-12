/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/12 13:58:33 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

//#define malloc test_malloc //DEBUG FUNCTION
void print_list(t_stack *stack_a, t_stack *stack_b); //DEBUG FUNCTION

t_stack	*new_node(int n);
t_stack	*create_list(int argc, char **argv, t_stack *stack_a);

void	*test_malloc(size_t size); //DEBUG FUNCTION

void	show_error(int n);
void	free_stack(t_stack *stack);
void	check_duplicate(t_stack *stack);
void	check_errors(int argc, char **argv);
void	check_sort(t_stack **stack_a, t_stack **stack_b);

/*------------------------------Sort-------------------------------*/

void	sort_two_nodes(t_stack *stack_a);
void	sort_three_nodes(t_stack **stack_a);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/*-------------------------Opeartor--------------------------------*/

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack **stack_src, t_stack **stack_dest);
void	push_b(t_stack **stack_src, t_stack **stack_dest);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	double_reverse(t_stack **stack_a, t_stack **stack_b);

#endif