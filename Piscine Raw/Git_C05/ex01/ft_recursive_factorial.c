/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:04:49 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/02 17:32:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{	
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	return (0);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_recursive_factorial(5));
	return (0);
}*/