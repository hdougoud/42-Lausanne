/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/05 16:09:42 by hdougoud         ###   ########.fr       */
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
void	double_swap(int **array_a, int **array_b);

int		*check_errors(int argc, char **argv, int *tab_size);
int		*check_duplicate(int argc, char **argv, int *tab_size);


#endif