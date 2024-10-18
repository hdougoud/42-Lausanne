/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:21:05 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/11 15:39:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(int size, char *str)
{
	int		i;
	char	*strcopy;

	i = 0;
	strcopy = malloc(sizeof(char) * size + 1);
	if (strcopy == NULL)
		return (NULL);
	while (str[i])
	{
		strcopy[i] = str[i];
		i++;
	}
	strcopy[i] = '\0';
	return (strcopy);
}

int	ft_strleng(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{	
	int			i;
	int			j;
	int			strsize;
	t_stock_str	*stock;

	j = 0;
	i = 0;
	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	while (j < ac)
	{
		strsize = ft_strleng(av[j]);
		stock[i].size = strsize;
		stock[i].str = av[j];
		stock[i].copy = ft_strdup(strsize, av[j]);
		j++;
		i++;  //erreur ici (maintenant corrigée)
	}
	stock[i].str = 0;
	return (stock);
}

/*int main(int ac, char **av)
{
	//char *av[] = {"nomfichier", "Hello", "World", "test"};
    //int ac = 3;
	ft_strs_to_tab(ac, av);
	return (0);
}*/