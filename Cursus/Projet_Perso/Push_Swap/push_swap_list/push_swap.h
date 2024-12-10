/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/10 13:46:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//#define malloc test_malloc //DEBUG FUNCTION

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

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
void	sort_three_nodes(t_stack **stack_a, t_stack **stack_b);

/*-------------------------Opeartor--------------------------------*/

void	swap(t_stack *stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_src, t_stack **stack_dest);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	double_reverse(t_stack **stack_a, t_stack **stack_b);


#endif