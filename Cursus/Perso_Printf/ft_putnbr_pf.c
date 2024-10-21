/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:47:59 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 11:46:49 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_pf(int n, int *value)
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
		ft_putnbr_pf(n / 10, value);
	ft_putchar_pf(n % 10 + '0');
	(*value)++;
	return ((*value) + 1);
}
