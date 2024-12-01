/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:11:35 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/02 00:36:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t count_args(char format, va_list args, size_t len)
{
	if (format == 'c')
		len += count_char(va_arg(args, int));
	else if (format == 's')
		len += ft_strlen(va_arg(args, char*));
	else if (format == 'd' || format == 'i' || format == 'u')
		len += count_int(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len += 10;
	return (len);
}

size_t count_len(const char *format, va_list args)
{
	int len;
	int i;
	
	i = 0;
	len = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			len = count_args(format[i + 1], args, len);
			i += 2;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t		total_len;
	va_list		args;
	
	total_len = 0;
	va_start(args, format);
	total_len = count_len(format, args);
	va_end(args);
	return (total_len);
}

int main(void)
{
	char c = 'c';
	char *s = "this";
	
	printf("\n%d\n", ft_printf("Hello%cWolrd%s",c , s));
	printf("\n%d\n",  printf("Hello%cWorld%s",c , s));
	printf("\n%d\n", ft_printf("Hello %s Wolrd", s));
	printf("\n%d\n",  printf("Hello %s World", s));
	printf("\n%d\n", ft_printf("Hello %d Wolrd", -12345));
	printf("\n%d\n",  printf("Hello %d World", -12345));
}
