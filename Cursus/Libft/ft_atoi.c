/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:15:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/04 11:48:44 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	total;

	i = 0;
	is_neg = 0;
	total = 0;
	if (!(str[0] >= '0' && str[0] <= '9' || str[1] >= '0' && str[1] <= '9'))
		return (0);
	if (str[i] == '-')
		isNeg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - 48);
		i++;
	}
	if (is_neg == 1)
			total = -total;
	return (total);
}

//int main(void)
//{
//	//printf("%d ft_atoi\n", ft_atoi("12345ABCD0000"));
//	//printf("%d ft_atoi1\n", ft_atoi("1234567890"));
//	//printf("%d ft_atoi2\n ", ft_atoi("--+1234567890"));
//	//printf("%d ft_atoi3\n ", ft_atoi("-+1234567890"));
//	printf("%d ft_atoi4\n ", ft_atoi("+1234567890"));
//	//printf("%d ft_atoi5\n ", ft_atoi("++1234567890"));
//	//printf("%d ft_atoi6\n", ft_atoi("-1234567890"));
//	//printf("%d atoi1\n", atoi("12345test67890"));
//	//printf("%d atoi2\n", atoi("--+1234567890"));
//	//printf("%d atoi3\n", atoi("-+1234567890"));
//	printf("%d atoi4\n", atoi("+1234567890"));
//	//printf("%d atoi5\n", atoi("++1234567890"));
//	//printf("%d atoi6\n", atoi("-1234567890"));
//}
