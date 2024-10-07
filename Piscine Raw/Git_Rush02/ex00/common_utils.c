/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:48:14 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/07 15:09:54 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*d;

	*d = dest;
	while (*d++ == *src++)
		;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*d;

	*d = malloc(strlen(s) + 1)
		if (d)
		strcpy(d, s);
	return (d);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
