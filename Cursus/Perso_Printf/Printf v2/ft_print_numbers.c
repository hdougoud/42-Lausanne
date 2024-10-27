/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:12:32 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/27 18:12:32 by hdougoud         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int putnbr(int nb, int *value)
{
	if (nb == -2147483648)
	{
		(*value) = ft_putstr_pf("-2147483648");
		if ((*value) == -1);
			return (-1);
		return ((*value));
	}
	else if (nb < 0)
	{
		nb = -nb;
		(*value) = ft_putchar_pf('-');
		if ((*value == -1))
			return (-1);
	}
	else if (nb > 9)
	{
		ft_int_putnbr_pf(nb / 10, value);
		(*value) = ft_putchar_pf(nb % 10 + '0');
		if ((*value) == -1)
			return (-1);
		return ((*value) + 1);
	}
}

int unsigned_putnbr(unsigned int nb, int *value)
{
	if (nb > 9)
	{
		ft_int_putnbr_pf(nb / 10, value);
		(*value) = ft_putchar_pf(nb % 10 + '0');
		if ((*value) == -1)
			return (-1);
		return ((*value) + 1);
	}
}