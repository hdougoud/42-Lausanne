/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/08 03:00:02 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_tab
{
	int	*array;
	int	size;
}		t_tab;

void	show_error(void);
void	swap(int **array);
void	rotate(t_tab *tab);
void	reverse_rotate(t_tab *tab);
void	sort_tab(t_tab tab_a, t_tab tab_b);
void	push(t_tab *source, t_tab *destination);
void	double_swap(int **array_a, int **array_b);
void	double_rotate(t_tab *tab_a, t_tab *tab_b);
void	double_reverse(t_tab *tab_a, t_tab *tab_b);

int		*check_errors(int argc, char **argv, int *tab_size);
int		*check_duplicate(int argc, char **argv, int *tab_size);


#endif