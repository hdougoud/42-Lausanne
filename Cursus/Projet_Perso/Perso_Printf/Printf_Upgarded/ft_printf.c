/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:11:35 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/04 00:20:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add_args(char format, char *str, va_list args, int *i)
{
	if (format == 'c')
		str = add_char(str, va_arg(args, int), i);
	else if(format == 's')
		str = add_str(str, va_arg(args, char *), i);
	else if (format == 'p')
		str = add_pointer(str, va_arg(args, void *), i);
	// else if (format == 'x')
	// 	str = add_hexa(str, va_arg(args, void *), i, 'x');
	// else if (format == 'X')
	// 	str = add_hexa(str, va_arg(args, void *), i, 'X');
	return (str);
}

char *manage_args(const char *format, char *str, va_list args)
{
	int	i;
	int form_indx;

	i = 0;
	form_indx = 0;
	while(format[form_indx])
	{
		if (format[form_indx] == '%')
		{
			form_indx++;
			str = add_args(format[form_indx], str, args, &i);
			form_indx++;
		}
		str[i++] = format[form_indx++];
	}
	str[i] = '\0';
	return (str);
}

size_t count_args(char format, va_list args, size_t len)
{
	if (format == 'c')
		len += count_char(va_arg(args, int));
	else if (format == 's')
		len += ft_strlen(va_arg(args, char *));
	else if (format == 'p')
		len += count_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += count_int(va_arg(args, int));
	else if (format == 'u')
		len += count_unsigned_int(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += count_hexa(va_arg(args, unsigned int));
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
	char		*str;
	
	total_len = 0;
	va_start(args, format);
	total_len = count_len(format, args);
	va_end(args);
	str = malloc(sizeof(char) * total_len + 1);
	if (!str)
		return (-1);
	va_start(args, format);
	str = manage_args(format, str, args);
	if (write(1, str, total_len) == -1)
		return (-1);
	free(str);
	va_end(args);
	return (total_len);
}

int main(void)
{
	char c = 'c';
	char *s = "this";
	unsigned int un = -12345;
	void *p = "test afin de verifier la longeur de l'adresse d'un pointeur";
	
	//printf("\n%d\n", ft_printf("Hello%cWolrd",c));
	//printf("\n%d\n",  printf("Hello%cWorld",c));
	//printf("\n%d\n", ft_printf("Hello %s World", s));
	//printf("\n%d\n",  printf("Hello %s World", s));
	// printf("\n%d\n", ft_printf("Hello %d Wolrd", -12345));
	// printf("\n%d\n",  printf("Hello %d World", -12345));
	// printf("\n%d\n", ft_printf("Hello %u Wolrd", un));
	// printf("\n%d\n",  printf("Hello %u World", un));
	printf("\n%d\n", ft_printf("%p", p));
	printf("\n%d\n",  printf("%p", p));
	// printf("\n%d\n", ft_printf("%x", 104756));
	// printf("\n%d\n",  printf("%x", 104756));
	// printf("\n%d\n", ft_printf("%X", 65748));
	// printf("\n%d\n",  printf("%X", 65748));
}
