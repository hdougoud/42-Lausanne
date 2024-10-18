/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:39:20 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/03 14:28:09 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_negative(char *str)
{
	int	i;
	int	count;

	i = 0 - 1;
	count = 0;
	while (str[++i] && (!(str[i] >= '0' && str[i] <= '9')))
		if (str[i] == '-')
			count++;
	count = count % 2;
	return (count);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0 - 1;
	nb = 0;
	while (str[++i])
	{
		if (!(((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
				|| (str[i] == '+' || str[i] == '-') // fonction pour stopper apres espace
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
			while (str[i] >= '0' && str[i] <= '9')
			{
				nb = (nb * 10 + (str[i] - 48));
				i++;
			}	
	}
	if (ft_negative(str) == 1)
		nb = -nb;
	return (nb);
}

#include <stdio.h>

int	main(void)
{
	//printf("%d\n", ft_atoi("help"));
	// printf("\n");
	//printf("%d\n", ft_atoi("test123456"));
	// printf("\n");
	printf("%d\n", ft_atoi("12345test5698"));
	printf("%dAtoi\n", atoi("12345test5698"));
	// printf("\n");
	//printf("%d\n", ft_atoi("-- 1325632167"));
	// printf("\n");
	//printf("%d\n", ft_atoi("+0"));
	// printf("\n");
	//printf("%d\n", ft_atoi("-2147483648"));
	// printf("\n");
	return (0);
}