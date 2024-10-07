/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:36:33 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/07 11:12:31 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc((len + 1) * sizeof(char));
	while (len > 0)
	{
		str[i] = s[start];
		start++;
		i++;
		len --;
	}
	str[i] = '\0';
	return (str);
}

//int main(void)
//{
//	char s[] = "Hello this is a test";
//	printf("%s\n", ft_substr(s, 7, 8));
//	return (0);
//}