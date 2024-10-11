/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:31:01 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/11 10:18:09 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;

	a = (char *) s;
	while (n > 1)
	{
		if (*a == c)
			return (a);
		a++;
		n--;
	}
	return (0);
}

//int main(void)
//{
//	char s[] = "hello World";
//	printf("%s\n", ft_memchr(s, '3', 11));
//	return (0);
//}