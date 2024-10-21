/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:14:25 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 15:31:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_pointer(unsigned long *s)
{
	int	i;
	int	value;

	i = 0;	
	write(1, "0x", 2);
	value = 2;
	while (s[i])
	{
		ft_putchar_pf(s[i]);
		i++;
		value++;
	}
	return (value);
}
