/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:06 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/08 15:24:24 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_min_int(int n)
{
	char	*str;

	str = malloc(12 * sizeof(char));
	if (str == 0)
		return (NULL);
	str = "-2147483648"; // faire un = correcte
	return (str);
}

int	ft_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_convert(int n, int len, char *str, int negative)
{
	int	div;

	div = 1;
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		len --;
		n /= 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		div;
	int		negative;

	div = 1;
	len = 1;
	negative = 0;
	if (n == -2147483647)
		return (ft_min_int(n));
	if (ft_is_negative(n))
	{
		n = -n;
		negative = 1;
	}
	while (n / div >= 9)
	{
		len++;
		div *= 10;
	}
	str = malloc((len + 1 + negative) * sizeof(char));
	if (str == 0)
		return (NULL);
	return (ft_convert(n, len + negative, str, negative));
}

//int main(void)
//{
//	int nb = -214748364;  
//	printf("Final %s\n", ft_itoa(nb));
//}