/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lausanne42 <lausanne42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:31:01 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/15 15:24:49 by lausanne42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n > 0)
	{
		if (*us == uc)
			return (us);
		us++;
		n--;
	}
	return (NULL);
}

//int main(void)
//{
//	char s[] = "hello World";
//	printf("%s\n", ft_memchr(s, 'W', 11));
//	return (0);
//}