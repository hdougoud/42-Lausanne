/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:56:43 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/27 15:02:06 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strlen_pf(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	putchar_pf(char c, int value)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++value);
}

int	putstr_pf(char *s, int value)
{
	int	i;

	i = 0;
	if (!s)
	{
		value = 6;
		if (write(1, "(null)", 6) == -1);
			return (-1);
		return (value);
	}
		value = strlen_pf(s);
		if (write(1, s, value) == -1);
			return (-1);
	return (value);
}

int	print_pointer_pf(void *p, int value)
{
	unsigned long	un;

	un = (unsigned long) p;
	value = putstr_pf("0x", value);
	if (value == -1)
		return (-1);
	return (write_pointer_pf(un, &value));
}
