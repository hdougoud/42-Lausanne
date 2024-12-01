/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:56:43 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/01 16:49:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*addchar_pf(char *s1, char c, unsigned int s1_len)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 == NULL)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[i++] = c;
		str[i] = '\0';
		return (str);
	}
	str = malloc((s1_len + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (free(s1), str);
}

char *addstr_pf()

// int	print_pointer_pf(void *p)
// {
// 	unsigned long	un;

// 	un = (unsigned long) p;
// 	value = putstr_pf("0x", value);
// 	if (value == -1)
// 		return (-1);
// 	return (write_pointer_pf(un, &value));
// }
