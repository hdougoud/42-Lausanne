/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lausanne42 <lausanne42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:54:38 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/15 16:06:27 by lausanne42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	unsigned int	word;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			word++;
		while ((*s != c && *s))
			s++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	word;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	word = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (word + 1)); //proteger contre le s vide ?
	if (tab == 0)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		if (*s)
		{
			while (s[i] != c && s[i])
				i++;
			tab[j++] = ft_substr(s, 0, i);
			s += i;
		}
	}
	tab[j] = NULL;
	return (tab);
}

//int main(void)
//{
//	int 	i = 0;
//	int		nb = 0;
//	char	c = '5';
//	char s[] = "  Hello    This is a             test"  ;
//	char **tab = ft_split(s, c);
//	while (tab[i] != NULL)
//	{
//		printf("%s\n", tab[i]);
//		i++;
//	}
//}