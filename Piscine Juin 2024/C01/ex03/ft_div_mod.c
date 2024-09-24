/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:29:25 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/23 18:31:36 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int main(void)
{
	int a = 15;
	int b = 4;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d", div);
	printf ("\n");
	printf("%d", mod);
	return (0);
}*/
