/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:28:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/11 16:05:39 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int i;
	int result;
	int size;
	char *str;
	int is_min = 0;

	i = 1000000000;
	result = 0;
	size = 0;
	if (nbr == -2147483648)
	{
		nbr += 1;
		is_min = 1;
	}
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while(i >= 10)
	{
		result = nbr / i;
		if (result <= 0)
			i = i / 10;
		else
		{
			i = i / 10;
			size++;
		}
	}
	size++;
	str = malloc(sizeof(char) * size + 1);
	if (str == 0)
	{
		str = NULL;
		return (str);
	}
	i = 1000000000;
	result = 0;
	size = 0;
	if (is_min == 1)
	{
		str[size] = '-';
		size++;
	}
	while(i >= 10)
	{
		result = nbr / i;
		if (result <= 0)
			i = i / 10;
		else
		{
			str[size] = (result % 10) + '0';
			i = i / 10;
			size++;
		}
	}
	if (is_min == 1)
		str[size] = (nbr % 10) + '1';
	else
	str[size] = (nbr % 10) + '0';
	size ++;
	str[size] = '\0';
	return (str);
}

int main(void)
{
	char *str;
	str = ft_itoa(2147483647);
	printf("%s", str);
	free(str);
	
	return (0);
}