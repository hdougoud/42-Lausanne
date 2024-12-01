/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:08:57 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/01 03:25:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*combine_str(size_t len, const char *format, char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (str == NULL)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, format, len + 1);
		return (str);	
	}
	new_str = ft_strjoin(str, format);
	if (!new_str)
	{
		safe_free(&str);
		return (NULL);
	}
	safe_free(&str);
	return (new_str);
}

// static void	check_args(const char *format, va_list list, int i)
// {
// 	if (format[i] == 'c')
// 		putchar_pf(va_arg(list, int));
// 	else if (format[i] == 's')
// 		putstr_pf(va_arg(list, char *));
// 	else if (format[i] == 'p')
// 		print_pointer_pf(va_arg(list, void *));
// 	else if (format[i] == 'd' || format[i] == 'i')
// 		putnbr_pf(va_arg(list, int));
// 	else if (format[i] == 'u')
// 		unsigned_putnbr_pf(va_arg(list, int));
// 	else if (format[i] == 'x' || format[i] == 'X')
// 		print_hex_pf(va_arg(list, unsigned long), format[i]);
// 	else if (format[i] == '%')
// 		putchar_pf('%');
// }

static char *manage_format(const char *format, va_list list, char *str)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			str = combine_str(i, format, str);
			if (!str)
				return (NULL);
			i++;
			format += i + 1;
			i = 0;
		}
		else 
			i++;
	}
	str = combine_str(i, format, str);
	if (!str)
		return (NULL);
	return (str);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	char	*str;
	int		len;
	
	
	str = NULL;
	len = 0;
	str = manage_format(format, list, str);
	if (!str)
		return (free(str), -1);
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (free(str), -1);
	va_end (list);
	free(str);
	return (len);
}

int main(void)
{
	char *s = "Hello%sWorld";
	
	printf("\n%d\n", ft_printf(s));
}

//#include <stdio.h>
//
//int main (void)
//{
//	char			c = 'c';
//	char			*s = "Hello World";
//	void			*p = "void test"; 
//	int				i = -746534;
//	int				d = 6344479;
//	unsigned int	u = 42326849;
//	int				x = 2516748;
//	int				X = 1541610;
//
//	printf("\ncustom %d\n", ft_printf(" hello char %c", c));
//	printf("\nprintf %d\n", printf("char %c", c));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("string %s", s));
//	printf("\nprintf %d\n", printf("string %s", s));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("char %p", p));
//	printf("\nprintf %d\n", printf("char %p", p));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("decimal %d", d));
//	printf("\nprintf %d\n", printf("decimal %d", d));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("integer %i", i));
//	printf("\nprintf %d\n", printf("integer %i", i));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("unsigned int %u", u));
//	printf("\nprintf %d\n", printf("unsigned int %u", u));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("char %x", x));
//	printf("\nprintf %d\n", printf("char %x", x));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("char %X", X));
//	printf("\nprintf %d\n", printf("char %X", X));
//	write (1, "\n", 1);
//	printf("\ncustom %d\n", ft_printf("pourcent %%"));
//	printf("\nprintf %d\n", printf("pourcent %%"));
//}