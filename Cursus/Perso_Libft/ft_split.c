/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:54:38 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/14 15:18:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i + 1] != c && s[i + 1 != '\n'])
				word++;
		}
		else
			i++;
	}
	return (word + 1);
}

int	ft_word_len(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_fill_tab(char **tab, char const *s, char c, int word)
{
	unsigned int	word_len;
	unsigned int	j;	

	j = 0;
	while (word > 0)
	{
		word_len = ft_word_len(s, c);
		tab[j] = malloc((word_len + 1) * sizeof(char));
		if (!tab[j])
			return (NULL);
		tab[j] = ft_memmove(tab[j], s, word_len);
		tab[j][word_len] = '\0';
		s += word_len;
		while (*s == c)
			s++;
		word--;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	word;

	while (*s == c)
	s++;
	word = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (word + 1));
	if (tab == 0)
		return (NULL);
	return (ft_fill_tab(tab, s, c, word));
}

//int main(void)
//{
//	int 	i = 0;
//	int		nb = 0;
//	char	c = ' ';
//	char s[] = "   Hello       This      is a     test       ";
//	char **tab = ft_split(s, c);
//	while (tab[i] != NULL)
//	{
//		printf("%s\n", tab[i]);
//		i++;
//	}
//}