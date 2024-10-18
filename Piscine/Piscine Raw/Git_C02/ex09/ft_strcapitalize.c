/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:54:11 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/27 12:37:04 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
	while (str[i++])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	i = 1;
	while (str[i])
	{
		if (!((str[i -1] >= 'a' && str[i -1] <= 'z')
				|| (str[i -1] >= '0' && str[i -1] <= '9')
				|| (str[i -1] >= 'A' && str[i -1] <= 'Z')))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

/*int main()
{
    char str[] = "sAluT, coMment tu vas ? 42mots quarANte-deux; Cinquante+et+un";
    ft_strcapitalize(str);
    printf("%s" ,str);
    return (0);
}*/