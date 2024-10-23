/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:48 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/23 15:46:54 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static int	check_args(const char *format, va_list list, int return_val, int i)
{
	if (format[i] == 'c')
		return_val += ft_putchar_pf(va_arg(list, int));
	else if (format[i] == 's')
		return_val += ft_putstr_pf(va_arg(list, char *));
	else if (format[i] == 'p')
	{
		return_val += ft_putstr_pf("0x");
		ft_print_pointer(va_arg(list, void *), &return_val);
	}
	else if (format[i] == 'd' || format[i] == 'i')
		ft_int_putnbr_pf(va_arg(list, int), &return_val);
	else if (format[i] == 'u')
		ft_unsigned_putnbr_pf(va_arg(list, unsigned int), &return_val);
	else if (format[i] == 'x')
		ft_hexlow_putnbr_pf(va_arg(list, unsigned int), &return_val);
	else if (format[i] == 'X')
		ft_hexup_putnbr_pf(va_arg(list, unsigned int), &return_val);
	else if (format[i] == '%')
		return_val += ft_putchar_pf('%');
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
		if (format[i] != '%')
			return_value += ft_putchar_pf(format[i++]);
		else
		{
			return_value = check_args(format, list, return_value, ++i);
			i++;
		}
	}
	va_end (list);
	return (return_value);
}

//int main(void)
//{
	//char			c = 'c';
	//char			*s = "Hello World";
	//void			*p = "void"; 
	//int				i = -124564514;
	//int				d = 1554416;
	//unsigned int	u = 123456789;
	//int				x = 562145;
	//int				X = 1541610;
	//
	//printf("\nft_printf	%d\n", ft_printf("test sans format"));
	//printf("\nprintf		%d\n", printf("test sans format"));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %c encore un test 1234", c));
	//printf("\nprintf		%d\n", printf("test %c encore un test 1234", c));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %s encore un test 1234", s));
	//printf("\nprintf		%d\n", printf("test %s encore un test 1234", s));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %p encore un test 1234", p));
	//printf("\nprintf		%d\n", printf("test %p encore un test 1234", p));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d	\n", ft_printf("test %d encore un test 1234", d));
	//printf("\nprintf		%d\n", printf("test %d encore un test 1234", d));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d	\n", ft_printf("test %i encore un test 1234", i));
	//printf("\nprintf		%d\n", printf("test %i encore un test 1234", i));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %u encore un test 1234", u));
	//printf("\nprintf		%d\n", printf("test %u encore un test 1234", u));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %x encore un test 1234", x));
	//printf("\nprintf		%d\n", printf("test %x encore un test 1234", x));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %X encore un test 1234", X));
	//printf("\nprintf		%d\n", printf("test %X encore un test 1234", X));
	//write (1, "\n", 1);
	//printf("\nft_printf	%d\n", ft_printf("test %% encore un test 1234"));
	//printf("\nprintf		%d\n", printf("test %% encore un test 1234"));
	//write (1, "\n", 1);
	//printf("%d\n", printf(" %d ", -1));
	//printf("%d\n", ft_printf(" %d ", -1));
	//write (1, "\n", 1);
	//printf("%d\n", ft_printf("%s %d", (char *)NULL, 20));
	//printf("%d\n", printf("%s %d", (char *)NULL, 20));
	//write (1, "\n", 1);
	//printf("%d\n", ft_printf("%d\n", -2147483648));
	//printf("%d\n", printf("%d\n", -2147483648));
//	printf("%d\n", ft_printf("%X\n", -9));
//	printf("%d\n", printf("%X\n", -9));	
//}
