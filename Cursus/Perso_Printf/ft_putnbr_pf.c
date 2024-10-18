/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:47:59 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/18 14:09:23 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_pf(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648", fd));
	if (n < 0)
	{
		n = -n;
		ft_putchar_pf('-', fd);
	}
	if (n > 9)
		ft_putnbr_pf(n / 10, fd);
	ft_putchar_pf(n % 10 + '0', fd);
}