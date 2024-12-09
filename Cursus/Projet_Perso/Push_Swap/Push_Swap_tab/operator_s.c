/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:25:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/09 11:51:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_tab *tab)
{
	int	temp;

	if (tab->size < 2)
		return;
	temp = ((tab)->array)[0];
	((tab)->array)[0] = ((tab)->array)[1];
	((tab)->array)[1] = temp;
}

void	double_swap(t_tab *tab_a, t_tab *tab_b)
 {
 	swap(tab_a);
 	swap(tab_b);
 }
