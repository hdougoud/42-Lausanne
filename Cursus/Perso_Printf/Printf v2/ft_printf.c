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

int	putstr_pf(char *s, int value)
{
	int	i;

	i = 0;
	while (s[i])
	{
		value = putchar_pf(s[i++], value);
		if (value == -1)
			return (-1);
	}
	return (value);
}

int	print_pointer_pf(void *p, int value)
{
	unsigned long un;

	un = (unsigned long) p;
	value = putstr_pf("0x", value);
	if (value == -1)
		return (-1);
	return (hexlow_pf(un, &value));
}

static int	check_args(const char *format, va_list list, int return_val, int i)
{
	if (format[i] == 'c')
		return_val = putchar_pf(va_arg(list, int), return_val);
	else if (format[i] == 's')
		return_val = putstr_pf(va_arg(list, char *), return_val);
	else if (format[i] == 'p')
		return_val = print_pointer_pf(va_arg(list, void *), return_val);
	else if (format[i] == 'd' || format[i] == 'i')
		return_val = putnbr_pf(va_arg(list, int), &return_val);
	else if (format[i] == 'u')
		return_val = unsigned_putnbr_pf(va_arg(list, int), &return_val);
	else if (format[i] == 'x')
		return_val = hexlow_pf(va_arg(list, unsigned long), &return_val);
	else if (format[i] == 'X')
		return_val = hexup_pf(va_arg(list, unsigned long), &return_val);
	else if (format[i] == '%')
		return_val = putchar_pf('%', return_val);
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
	void			*p = "void test"; 
	int				i = -746534;
	int				d = 6344479;
	unsigned int	u = 42326849;
	int				x = 2516748;
	int				X = 1541610;

	printf("\ncustom %d\n", ft_printf("char %c", c));
	printf("\nprintf %d\n", printf("char %c", c));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("string %s", s));
	printf("\nprintf %d\n", printf("string %s", s));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("char %p", p));
	printf("\nprintf %d\n", printf("char %p", p));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("decimal %d", d));
	printf("\nprintf %d\n", printf("decimal %d", d));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("integer %i", i));
	printf("\nprintf %d\n", printf("integer %i", i));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("unsigned int %u", u));
	printf("\nprintf %d\n", printf("unsigned int %u", u));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("char %x", x));
	printf("\nprintf %d\n", printf("char %x", x));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("char %X", X));
	printf("\nprintf %d\n", printf("char %X", X));
	write (1, "\n", 1);
	printf("\ncustom %d\n", ft_printf("pourcent %%"));
	printf("\nprintf %d\n", printf("pourcent %%"));
}