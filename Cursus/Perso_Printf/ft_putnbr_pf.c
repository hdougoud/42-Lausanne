/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lausanne42 <lausanne42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:47:59 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/22 18:30:29 by lausanne42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_int_putnbr_pf(int n, int *value)
{
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	if (n < 0)
	{
		n = -n;
		value += ft_putchar_pf('-');
	}
	if (n > 9)
		ft_int_putnbr_pf(n / 10, value);
	(*value) += ft_putchar_pf(n % 10 + '0');
	return ((*value) + 1);
}

int	ft_unsigned_putnbr_pf(unsigned int n, int *value)
{
	if (n > 9)
		ft_unsigned_putnbr_pf(n / 10, value);
	(*value) += ft_putchar_pf(n % 10 + '0');
	return ((*value) + 1);
}

int	ft_hexlow_putnbr_pf(int n, int *value)
{
	int			mod;
	static char	*dict;

	dict = "0123456789abcdef";
	if (n > 16)
		ft_hexlow_putnbr_pf(n / 16, value);
	mod = n % 16;
	(*value) += ft_putchar_pf(dict[mod]);
	return (*value);
}

int	ft_hexup_putnbr_pf(int n, int *value)
{
	int			mod;
	static char	*dict;

	dict = "0123456789ABCDEF";
	if (n > 16)
		ft_hexup_putnbr_pf(n / 16, value);
	mod = n % 16;
	(*value) += ft_putchar_pf(dict[mod]);
	return ((*value));
}
