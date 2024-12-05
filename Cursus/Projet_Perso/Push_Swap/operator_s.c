/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:25:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/05 19:20:56 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **array)
{
	int	temp;

	if (*array == NULL || array[0] == NULL || array[1] == NULL)
		return;
	temp = (*array)[0];
	(*array)[0] = (*array)[1];
	(*array)[1] = temp;
}

void	double_swap(int **array_a, int **array_b)
 {
 	swap(array_a);
 	swap(array_b);
 }
