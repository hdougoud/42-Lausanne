/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:23:18 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/06 14:53:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_tab *source, t_tab *destination)
{
	int	i;

	i = (destination->size);
	if ((source->size) == 0)
		return ;
	while(i > 0)
	{
		destination->array[i] = destination->array[i - 1];
		i--;
	}
	destination->array[0] = source->array[0];
	i = 0;
	while(i < (source->size))
	{
		source->array[i] = source->array[i + 1];
		i++;
	}
	destination->size++;
	source->size--;
}
