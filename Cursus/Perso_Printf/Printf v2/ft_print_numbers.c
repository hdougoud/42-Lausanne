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

#include "ft_printf.h"

int putnbr_pf(int nb, int *value)
{
	if (nb == -2147483648)
	{
		(*value) = putstr_pf("-2147483648", (*value));
		if ((*value) == -1)
			return (-1);
		return ((*value));
	}
	if (nb < 0)
	{
		nb = -nb;
		(*value) = putchar_pf('-', (*value));
		if ((*value == -1))
			return (-1);
	}
	if (nb > 9)
		putnbr_pf(nb / 10, value);
	(*value) = putchar_pf(nb % 10 + '0', (*value));
	if ((*value) == -1)
		return (-1);
	return ((*value));
}

int unsigned_putnbr_pf(unsigned int nb, int *value)
{
	if (nb > 9)
		unsigned_putnbr_pf(nb / 10, value);
	(*value) = putchar_pf(nb % 10 + '0', (*value));
	if ((*value) == -1)
		return (-1);
	return ((*value));
}

int	hexlow_pf(unsigned long un, int *value)
{
	int				mod;
	static char		*dict;

	dict = "0123456789abcdef";
	if (un >= 16)
		hexlow_pf(un / 16, value);
	mod = un % 16;
	(*value) = putchar_pf(dict[mod], (*value));
		if ((*value) == -1)
			return (-1);
	return (*value);
}

int	hexup_pf(unsigned long un, int *value)
{
	int				mod;
	static char		*dict;

	dict = "0123456789ABCDEF";
	if (un >= 16)
		hexlow_pf(un / 16, value);
	mod = un % 16;
	(*value) = putchar_pf(dict[mod], (*value));
	if ((*value) == -1)
		return (-1);
	return (*value);
}