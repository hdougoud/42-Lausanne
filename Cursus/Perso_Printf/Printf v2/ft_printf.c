/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:13:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/27 18:13:31 by hdougoud         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_pf(char c, int value)
{
	if (write(1, &c, 1) == -1)
		return (value = -1);
	return (++value);
}

int putstr_pf(char *s, int value)
{
	int	i;

	while (s[i])
	{
		value = putchar_pf(s[i++], value);
		if (value == -1)
			return (-1);
	}
	return (value);
}

static int print_pointer(void *p, int value)
{
	value = ft_putstr("0x");
	if (value == -1)
		return (-1);
	return (value);
}


static int	check_args(const char *format, va_list list, int return_val, int i)
{
	if (format[i] == 'c')
		return_val = putchar_pf(va_arg(list, int), return_val);
	if (format[i] == 's')
		return_val = putstr_pf(va_arg(list, char *), return_val);
	//if (format[i] == 'p')

	if (format[i] == 'd' || format[i] == 'd')
		return_val == putnbr(va_arg(list, int), &return_val);
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
			return_value = putchar_pf(format[i++], return_value);
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
	char			c = 'c';
	char			*s = "Hello World";
	//void			*p = "void test"; 
	int				i = -74653434;
	int				d = 6344479;
	//unsigned int	u = 42326849;
	//int				x = 2516748;
	//int				X = 1541610;

	printf("custom \n%d\n ", ft_printf("char %c", c));
	printf("printf \n%d\n ", printf("char %c", c));
	write (1, "\n", 1);
	printf("custom \n%d\n ", ft_printf("string %s", s));
	printf("printf \n%d\n ", printf("string %s", s));
	write (1, "\n", 1);
	//printf("custom \n%d\n ", ft_printf("char %p", p));
	//printf("printf \n%d\n ", printf("char %p", p));
	write (1, "\n", 1);
	printf("custom \n%d\n ", ft_printf("string %d", d));
	printf("printf \n%d\n ", printf("string %d", d));
	write (1, "\n", 1);
	printf("custom \n%d\n ", ft_printf("string %i", i));
	printf("printf \n%d\n ", printf("string %i", i));
	write (1, "\n", 1);
}