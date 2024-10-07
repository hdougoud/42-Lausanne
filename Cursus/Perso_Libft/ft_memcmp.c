/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:47:30 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/03 13:59:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	while (n > 1)
	{
		if (a[i] > b[i])
			return (1);
		if (a[i] < b[i])
			return (-1);
		i++;
		n--;
	}
	return (0);
}

//int main(void)
//{
//	char s1[] = "This is a Test";
//	char s2[] = "This is a Test";
//	printf("%d\n", ft_memcmp(s1, s2, 15));
//	return (0);
//}