/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:53:35 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/27 15:47:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0 ;
	n = 0;
	while (dest[i])
		i++;
	n = i;
	i = 0;
	while (src[i])
	{
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

/*#include <stdio.h>

int main(void)
{
	char dest[11] = "Hello";
	char src[] = "World";
	char *result = ft_strcat(dest, src);
	printf("%s", result);
	return (0);
}*/