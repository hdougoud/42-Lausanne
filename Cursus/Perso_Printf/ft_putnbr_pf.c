/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:47:59 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 17:09:24 by hdougoud         ###   ########.fr       */
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
		ft_putchar_pf('-');
		(*value)++;
	}
	if (n > 9)
		ft_int_putnbr_pf(n / 10, value);
	ft_putchar_pf(n % 10 + '0');
	(*value)++;
	return ((*value) + 1);
}

int	ft_unsigned_putnbr_pf(unsigned int n, int *value)
{
	if (n > 9)
		ft_unsigned_putnbr_pf(n / 10, value);
	ft_putchar_pf(n % 10 + '0');
	(*value)++;
	return ((*value) + 1);
}

int	ft_long_putnbr_pf(int n, int *value)
{
	int			mod;
	static char	*dict[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"
	"a", "b", "c", "d", "e", "f"};

	n = n / 16;
	
	n = n / 4;
	 
}

/*int	ft_putnbr_pf(int n, char c)
{
	int	*value:
	
	value = 0;
	if (c == i || d)
	ft_int_putnbr_pf(int n, value);
	if (c == u)
	ft_unsigned_putnbr_pf(n, value);
	return (value);
}*/