/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:34:06 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/24 10:09:33 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}

/*int main(void)
{
	int	a;
	int	b;

	a = 14;
	b = 4;

	ft_ultimate_div_mod(&a, &b);
	printf("%d", a);
	printf("\n");
	printf("%d", b);
	return (0);
}*/
