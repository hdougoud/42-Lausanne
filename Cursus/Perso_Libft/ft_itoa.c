/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:06 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/08 11:43:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int it_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		result;
	
	i = 0;
	result = 0;
	if (it_is_negative(n))
		n = -n;
	while (!(n >= 1 && n <= 9))
	{
		n = n / 10;
		result++;
		printf("%d\n", result);
	}
	str = malloc(sizeof(char) * (i + it_is_negative(n) + 2));
	if (str == 0)
		return (NULL);
	while (result >= 0)
	{
		str[i] = (n * 10) + '0';
		i++;
		result--;
	}
	str[i] = '\0';
	return (str);
//	i = 0;
//	if (it_is_negative(n) == 1)
//	{
//		str[i] = '-';
//		i++;
//	}
//	while (div > 0)
//	{
//		str[i] = ((result % 10) + '0');
//		result = 
//		i++;
//		div = div / 10;
//	}
//	str[i] = (n % 10) + '0';
//	i++;
//	str[i] = '\0';
//	return (str);
}

int main(void)
{
	int nb = 12345;
	printf("Final %s\n", ft_itoa(nb));
	 //2147483647;
}