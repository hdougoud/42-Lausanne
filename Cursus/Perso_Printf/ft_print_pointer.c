/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lausanne42 <lausanne42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:14:25 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/22 18:30:55 by lausanne42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_pointer(void *p, int *value)
{
	int				mod;
	static char		*dict;
	unsigned long	adr;

	adr = (unsigned long) p;
	dict = "0123456789abcdef";
	if (adr > 16)
		ft_print_pointer((void *)(adr / 16), value);
	mod = adr % 16;
	(*value) += ft_putchar_pf(dict[mod]);
	return ((*value));
}
