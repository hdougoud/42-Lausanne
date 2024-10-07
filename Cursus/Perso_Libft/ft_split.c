/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:54:38 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/07 16:37:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, int c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			word++;
		i++;
	}
	return (word + 1);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	int		inx;
	int		word;

	i = 0;
	j = 0;
	inx = 0;
	word = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * word + 1);
	if (tab == 0)
		return (NULL);
	while (word > 0)
	{
		if (s[i] == c || s[i] == '\0')
		{
			tab[j] = malloc(sizeof(char) * (i + 1));
			if (tab == 0)
				return (NULL);
			while (i > 0)
			{
				tab[j][inx] = s[inx];
				inx++;
				i--;
			}
			tab[j][inx] = '\0';
			j++;
			s = s + (inx + 1);
			inx = 0;
			word--;
		}
		i++;
	}
	tab[j] = NULL; //null a a fin du tableau
	return (tab);
}

int main(void)
{
	int i = 0;
	char s[] = "Cette phrase est un test";
	char **tab = ft_split(s, ' ');
	while (i < 6)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	
}