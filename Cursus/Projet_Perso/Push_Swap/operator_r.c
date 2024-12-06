/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:23:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/06 16:03:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_tab *tab)
{ 	
	int	i;
	int	temp;

	i = 0;
	temp = tab->array[0];
	if ((tab->size) == 1)
		return ;
	while (i < (tab->size))
	{
		tab->array[i] = tab->array[i + 1];
		i++; 
	}
	tab->array[i - 1] = temp;
}

void	double_rotate(t_tab *tab_a, t_tab *tab_b)
{
	rotate(tab_a);
	rotate(tab_b);
}

void	reverse_rotate(t_tab *tab)
{
	int	i;
	int	temp; 

	i = (tab->size - 1);
	temp = tab->array[tab->size - 1];
	while (i > 0)
	{
		tab->array[i] = tab->array[i - 1];
		i--;
	}
	tab->array[0] = temp;
}

void	double_reverse(t_tab *tab_a, t_tab *tab_b)
{
	reverse_rotate(tab_a);
	reverse_rotate(tab_b);
}