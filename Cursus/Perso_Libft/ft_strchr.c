/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:11:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/14 15:19:39 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
	//memchr + 1 pour le nul
}

//int main(void)
//{
//	char s[] = "Hello World this is a test";
//	int res = 1;
//    printf("ft_strnchr	%s\n", ft_strchr("teste", 't'));
//    printf("ft_strnchr	%s\n", ft_strchr("teste", 'e'));
//    printf("ft_strnchr	%s\n", ft_strchr("teste", '\0'));
//    printf("ft_strnchr	%s\n", ft_strchr("teste", 'a'));
//    printf("ft_strnchr	%s\n", ft_strchr("teste", 'e' + 256));
//	printf("ft_strnchr	%s\n", ft_strchr("teste", 1024));
//	printf("\n\n");
//	printf("strnchr		%s\n", ft_strchr("teste", 't'));
//    printf("strnchr		%s\n", ft_strchr("teste", 'e'));
//    printf("strnchr		%s\n", ft_strchr("teste", '\0'));
//    printf("strnchr		%s\n", ft_strchr("teste", 'a'));
//    printf("strnchr		%s\n", ft_strchr("teste", 'e' + 256));
//	printf("strnchr		%s\n", ft_strchr("teste", 1024));
//}