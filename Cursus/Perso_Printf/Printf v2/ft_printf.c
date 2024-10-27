/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:16 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/27 16:26:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c, int value)
{
	if (write(1, &c, 1) == -1)
		return (value = -1);
	return (++value);
}

int	check_args(const char *format, va_list list, int return_val, int i)
{
	if (format[i] == 'c')
		return_val += ft_putchar_pf(va_arg(list, int), return_val);
	return (return_val);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		return_value;
	int		i;

	i = 0;
	return_value = 0;
	va_start (list, format);
	while (format[i] != '\0')
	{
		if (return_value == -1)
			return (-1);
		if (format[i] != '%')
			return_value = ft_putchar_pf(format[i++], return_value);
		else
		{
			return_value = check_args(format, list, return_value, ++i);
			i++;
		}
	}
	va_end (list);
	return (return_value);
}

int main (void)
{
	char c = c;

	printf("custom	%d\n", ft_printf("char %c", c));
	printf("printf	%d\n", printf("char %c", c));
}