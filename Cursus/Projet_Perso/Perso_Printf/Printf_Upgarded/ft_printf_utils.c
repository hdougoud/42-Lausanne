/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:19:12 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/04 10:41:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_char(char c)
{
	c -= c;
	return (c + 1);
}

size_t	count_int(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		count++;
	while (nb > 9 || nb < -9)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

size_t	count_unsigned_int(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

size_t	count_pointer(void *p)
{
	unsigned long	ul;
	int				count;

	ul = (unsigned long) p;
	count = 2;
	while (ul >= 16)
	{
		ul /= 16;
		count++;
	}
	count++;
	return (count);
}

size_t	count_hexa(int nb)
{
	int	count;

	count = 0;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	count++;
	return (count);
}
