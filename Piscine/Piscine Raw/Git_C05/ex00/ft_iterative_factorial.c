/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:04:27 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/02 17:37:30 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else if (nb > 1)
	{
		while (nb != 1)
		{
			result *= nb;
			nb = nb - 1;
		}
	}
	return (result);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_iterative_factorial(5));
	return (0);	
}*/