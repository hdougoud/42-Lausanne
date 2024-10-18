/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:51:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/25 17:05:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
	i++;
	}
	return (1);
}

/*#include <stdio.h>


int main (void)
{
	int a = ft_str_is_lowercase("abcdef");
	printf("%d", a);
	return (0);
}*/
