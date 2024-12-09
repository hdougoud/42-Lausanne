/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/09 15:05:31 by hdougoud         ###   ########.fr       */
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

t_stack	*create_list(int argc, char **argv, t_stack *stack_a);


void	show_error(int n);
void	swap(t_stack *stack);
void	check_duplicate(t_stack *stack);
void	check_errors(int argc, char **argv);

#endif