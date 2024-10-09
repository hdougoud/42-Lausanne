/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:54:33 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/09 12:21:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && s1[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1); // A verifier 
		if (s1[i] < s2[i])
			return (-1); // A verifier
		i++;
		n--;
	}
	return (0);
}

//int main(void)
//{
//	char s1[] = "Hello World";
//	char s2[] = "Hello World";
//	printf("%d\n", ft_strcmp(s1, s2, 20));
//	return (0);
//}