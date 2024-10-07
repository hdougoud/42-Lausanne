/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:46:55 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/03 11:48:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (nb == 0)
		return (0);
	while (power-- != 0)
		i *= nb;
	return (i);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_iterative_power(16, -4));
}*/