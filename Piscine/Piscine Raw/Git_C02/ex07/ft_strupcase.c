/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:38:23 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/25 18:11:58 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] -32;
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int main(void)
{
	char str[] = "Hello World";
	ft_strupcase(str);
	printf("%s", str);
	return (0);
}*/