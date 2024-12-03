/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:53 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/03 19:13:16 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add_str(char *str, char *format, int *str_i)
{
	int i;

	i = 0;
	printf("%d\n", *str_i);
	while (format[i])
	{
		str[*str_i] = format[i];
		(*str_i)++;
		i++;
	}
	return (str); //TODO : CONVERT i TO A POINTER INT
}