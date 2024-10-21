/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:48 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 11:57:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_args(const char *format, va_list list, int return_value, int i)
{
	if (format[i] == 'c')
	{
		ft_putchar_pf(va_arg(list, int));
		return_value++;
	}
	if (format[i] == 's')
		return_value += ft_putstr_pf(va_arg(list, char *));
	if (format[i] == 'd')
		ft_putnbr_pf(va_arg(list, int), &return_value);
	if (format[i] == 'u')
		ft_unsigned_putnbr_pf(va_arg(list, unsigned int), &return_value);
	if (format[i] == '%')
	{
		ft_putchar_pf('%');
		return_value++;
	}
	va_end		(list);
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
		if(format[i] != '%')
		{
			ft_putchar_pf(format[i]);
			i++;
			return_value++;
		}
		else
		{
			return_value = ft_check_args(format, list, return_value, ++i);
			i++;
		}
	}
	va_end (list);
	return (return_value);	
}



int main(void)
{
	int				n = -1234;
	int				c = 'c';
	unsigned int	un = -1234;
	printf("\n%d\n", ft_printf("%u", un));
	printf("\n%u\n", printf("%u", un));
	//printf("%%\n");
	//printf("%d\n", n);
	//printf("%s\n", s);
}