/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:45:06 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/03 11:49:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	mul;
	int	result;

	mul = 1;
	result = 0;
	while (result <= nb)
	{
		if (result == nb)
			return (mul - 1);
		result = mul * mul;
		mul++;
	}
	return (0);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_sqrt(4096));
	printf("\n");
	printf("%d", ft_sqrt(4567));
	return (0);
}*/