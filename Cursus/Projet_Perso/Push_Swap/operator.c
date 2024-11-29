/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:25:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/29 16:10:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_first(int argc, tab_a test)
{
	int	temp;

	if (tab[0] == NULL || tab[1] == NULL)
		return ;
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

void	ss(int argc, int *tab_a, int *tab_b)
{
	switch_first(argc, tab_a);
	switch_first(argc, tab_b);
}
