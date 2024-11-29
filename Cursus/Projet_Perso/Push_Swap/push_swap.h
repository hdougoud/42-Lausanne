/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/29 16:16:59 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	switch_first(int argc, int *tab);
void	check_errors(int argc, char **argv);
void	ss(int argc, int *tab_a, int *tab_b);

long	ft_atol(const char *str);

typedef struct s_tab
{
	int	*tab;
	int	size;
}		t_tab;

#endif