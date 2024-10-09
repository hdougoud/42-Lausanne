/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:42 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/09 11:23:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	printf("Avant modif %s\n", s);
	unsigned int	i;
	
	i = 0;
	while(s[i])
	{
		ft_test(i, &s[i]);
		i++;
	}
	printf("Apres modif %s\n", s);
}

//int main(void)
//{
//	char s[] = "Hello World";
//	ft_striteri(s, &ft_test);
//}
//
//oid ft_test(unsigned int n, char *c)
//{
//	if (*c >= 97 && *c <= 122 && n < 8)
//		*c -=32;
//}