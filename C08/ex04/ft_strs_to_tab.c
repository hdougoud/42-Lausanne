/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:18:25 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/10 19:09:24 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(int size, char *str)
{
	int i;
	char *strcopy;
	
	i = 0;
	strcopy = malloc(sizeof(char) * size + 1);
	if (strcopy == NULL)
		return (strcopy);
	while (str[i])
	{	
		strcopy[i] = str[i];
		i++;
	}
	strcopy[i] = '\0'; 
	return (strcopy);

}

int ft_strleng(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	char *strcopy;
	int j;
    int size;
	int acsize;
	
	j = 1;
    acsize = 0;
    while (acsize < ac)
    {
        size = ft_strleng(av[j]);
        strcopy = ft_strdup(size, av[j]);
        printf("%d\n", size );
        printf("%s\n", strcopy);
       /* while(av[i][j])
        {
            t_stock_str.size = size;
            t_stock_str.str = av;
            t_stock_str.strcopy = strcopy;
        }*/
        j++;
        acsize++;
    }
    return (0);
}

int main(/*int ac, char **av*/)
{
	char *av[] = {"nomfichier", "Hello", "World", "test"};
    int ac = 3;
	ft_strs_to_tab(ac, av);
	return (0);
}