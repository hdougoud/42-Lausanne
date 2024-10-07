/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:06 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/07 17:08:20 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_itoa(int n)
{
	int result;
	int	div

	div = 1000000000
	while (result < 1)
		result = n / 1000000000;
	printf("%d\n", result);
	div = div / 10;
	
}

int main(void)
{
	int nb = 2147483647;
	printf("%s\n", ft_itoa(nb));
} 