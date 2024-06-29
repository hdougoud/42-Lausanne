#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;
	char tab[11];

	i = 0;
	if (nb > 2147483647 || nb < -2147483648)
		return;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 12);
		return;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb > 9)
	{
		tab[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (nb >= 0 && nb <= 9)
		tab[i++] = nb + '0';
	while (0 < i)
		ft_putchar(tab[--i]);
}

int main()
{
	ft_putnbr(5000);
	return (0);
}