/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:47:53 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/06 12:33:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_is_prime(int nbr)
{
	int	mod;
	int	result;

	mod = 2;
	while (mod <= nbr / 2)
	{
		result = nbr % mod;
		mod++;
		if (result == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	mod;
	int	result;
	int	valid;

	mod = 2;
	valid = 0;
	if (ft_find_is_prime(nb) == 1)
		return (nb);
	if (nb >= 1 && nb <= 2)
		return (2);
	while (valid != ((nb - 2) / 2))
	{	
		result = (nb + 1) % mod;
		mod++;
		if (mod > (nb + 1) / 2)
		{
			nb++;
			mod = 2;
		}
		if (result != 0)
			valid++;
		else
			valid = 0;
	}
	return (nb);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_find_next_prime(14));
	return (0);
}*/