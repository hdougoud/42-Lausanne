/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:11:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/09 15:42:05 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



//#include <stdio.h>
//
//int main(void)
//{
//	char s[] = "Hello World this is a test";
//	printf("%s\n", ft_strchr(s, '\0'));
//}