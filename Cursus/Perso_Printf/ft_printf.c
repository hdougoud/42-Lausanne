/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:48 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 16:34:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_args(const char *format, va_list list, int return_value, int i)
{
	if (format[i] == 'c')
		return_value += ft_putchar_pf(va_arg(list, int));
	if (format[i] == 's')
		return_value += ft_putstr_pf(va_arg(list, char *));
	//if (format[i] == 'p')
		//return_value += ft_long_putnbr_pf(va_arg(list, unsigned long *));
	if (format[i] == 'd' || format[i] == 'i')
		ft_int_putnbr_pf(va_arg(list, int), &return_value);
	if (format[i] == 'u')
		ft_unsigned_putnbr_pf(va_arg(list, unsigned int), &return_value);
	if (format[i] == '%')
		return_value += ft_putchar_pf('%');
	return (return_value);
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
		if (format[i] != '%')
		{
			ft_putchar_pf(format[i]);
			i++;
			return_value++;
		}
		else
		{
			return_value = check_args(format, list, return_value, ++i);
			i++;
		}
	}
	va_end (list);
	return (return_value);
}



int main(void)
{
	int				n = 1256;
	int				c = 'c';
	unsigned int	un = -1234;
	void *v = "test";
	printf("\n%d\n", ft_printf("Hello %d", n));
	printf("\n%d\n", printf("Hello %X", 124564514));
	//printf("%%\n");
	//printf("%d\n", n);
	//printf("%s\n", s);
}