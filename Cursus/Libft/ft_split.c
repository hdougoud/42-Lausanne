/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:54:38 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/07 14:17:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_memory(char const *str, int n)
{
	(str = malloc(sizof(char) * n + 1));
	if (str == 0)
		return (0)
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		leng;
	int		i;
	int		j;
	
	while (s[i] == ' ' || s[i] == '\0');
	
	return (tab);
}

int main(void)
{
	char s[] = "Hello world this is a test";
	ft_split(s, ' ');
}