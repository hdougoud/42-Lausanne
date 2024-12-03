/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:53 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/04 00:22:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_char(char *str, char format, int *idx)
{
	str[*idx] = format;
	(*idx)++;
	return (str);
}

char	*add_str(char *str, char *format, int *idx)
{
	int	i;

	i = 0;
	while (format[i])
	{
		str[*idx] = format[i];
		(*idx)++;
		i++;
	}
	return (str); //TODO : CONVERT i TO A POINTER INT
}

static char	*convert_pointer(char *str, unsigned long ul, int *idx)
{
	int mod;
	char *dict = {"0123456789abcdef"};
	
	printf("%d\n", *idx);
	if (ul >= 16)
		convert_pointer(str, ul / 16, idx);
	mod = ul % 16;
	str[*idx] = dict[mod];
	(*idx)++;
	return (str);
}

char	*add_pointer(char *str, void *format, int *idx)
{
	unsigned long ul;

	ul = (unsigned long) format;
	str[*idx] = '0';
	(*idx)++;
	str[*idx] = 'x';
	(*idx)++;
	return (str = convert_pointer(str, ul, idx));
}