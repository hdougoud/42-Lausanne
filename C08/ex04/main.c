#include <unistd.h>
#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putstr(char    *str)
{
    while (*str)
    {
        write (1, str, 1);
        str++;
    }
    write (1, "\n", 1);
}

void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {    
        ft_putchar('-');
        ft_putchar('2');
        nb = 147483648;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb > 10)
    {
        ft_putnbr (nb / 10);
        ft_putnbr (nb % 10);
    }
    else
        ft_putchar(nb + '0');
}

void    ft_show_tab(struct s_stock_str *par)
{
    int    i;

    i = 0;
    while (par[i].str)
    {
        ft_putstr(par[i].str);
        ft_putnbr(par[i].size);
        ft_putchar('\n');
        ft_putstr(par[i].copy);
        i++;
    }
}

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
	}
	stock[i].str = 0;
	return (stock);
}

int    main(int argc, char **argv)
{
    t_stock_str    *stock;
    
    if (argc == 3)
    {
        stock = ft_strs_to_tab(argc, argv);
        ft_show_tab(stock);
        return (0);
    }
}