/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:48 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 00:19:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	int		return_value;
	int		i;
	va_list	list;
	
	i = 0;
	return_value = 0;
	while (format[i] != '%')
	{
		ft_putchar_pf(format[i]);
		i++;
		return_value++;
	}
	i++;
	va_start	(list, format);
	if (format[i] == 'd')
		ft_putnbr_pf(va_arg(list, int), &return_value);
	if (format[i] == 'c')
		ft_putchar_pf(va_arg(list, char));
	if (format[i] == 's')
		return_value += ft_putstr_pf(va_arg(list, char *));
	va_end		(list);
	return (return_value);
	
}

int main(void)
{
	int		n = 1234;
	printf("\n%s\n", ft_printf("H W %d", n));
	//printf("%c\n", c);
	//printf("%d\n", n);
	//printf("%s\n", s);
	
}