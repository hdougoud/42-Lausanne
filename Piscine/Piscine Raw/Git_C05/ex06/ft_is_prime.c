/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:39:07 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/03 11:50:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	prime;
	int	mod;

	prime = 2;
	if (nb <= 1)
		return (0);
	if (nb >= 2)
	{
		while (prime <= (nb / 2))
		{
			mod = nb % prime;
			prime ++;
			if (mod == 0)
				return (0);
		}
	}
	return (1);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_is_prime(11));
}*/