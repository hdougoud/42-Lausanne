/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:45:57 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/27 15:54:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;
	int	d;

	i = 0;
	d = 0;
	while (to_find[d])
		d++;
	if (d == 0)
		return (str);
	while (str[i])
	{
	n = 0;
		while (str[i + n] == to_find[n])
		{
			n++;
			if (n == d)
				return (&str[i]);
		}
	i++;
	}
	return (0);
}

/*#include <stdio.h>

int main(void)
{
	char *a;
	a = ft_strstr("Bonjour, commen comment allez vous ?", "Hello");
	printf("%s", a);
	return (0);	
}*/