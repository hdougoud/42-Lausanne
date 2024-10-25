/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:46:27 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/25 11:26:45 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c, int value)
{
	if (write(1, &c, 1) == - 1)
		return (-1);
	else
		return (++value);
}

int	ft_putstr_pf(char *s, int value)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		else
			return (value + 6);
	}
	while (s[i])
	{
		if (ft_putchar_pf(s[i], value) == -1)
			return (-1);
		else
			value++;
			i++;
	}
	return (value);
}

int	ft_print_pointer(void *p, int *value)
{
	int				mod;
	static char		*dict;
	unsigned long	adr;

	adr = (unsigned long) p;
	dict = "0123456789abcdef";
	if (adr >= 16)
		ft_print_pointer((void *)(adr / 16), value);
	mod = adr % 16;
	if (ft_putchar_pf(dict[mod], (*value)) == -1)
		return (-1);
	else 
		(*value)++;
	return ((*value));
}
