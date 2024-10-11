/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:36:33 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/11 16:08:03 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (start >= strlen(s))
		return ("0");
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	while (len > 0 && s[start] != '\0')
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
//	char s[] = "01234";
//	printf("%s\n", ft_substr(s, 10, 10));
//	printf("%s\n", substr(s, 10, 10));
//	return (0);
//}