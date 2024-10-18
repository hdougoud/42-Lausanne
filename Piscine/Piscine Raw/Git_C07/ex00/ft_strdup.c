/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:58:32 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/08 13:13:55 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*memory;

	i = 0 - 1;
	memory = 0;
	memory = malloc(sizeof(src + 1));
	if (memory == 0)
		return (memory);
	while (src[++i])
		memory[i] = src[i];
	memory[i] = '\0';
	return (memory);
}

/*#include <stdio.h>

int main(void)
{
	printf("%s", ft_strdup("hello"));
	return(0);
}*/