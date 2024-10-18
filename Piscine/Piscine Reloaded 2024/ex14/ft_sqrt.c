int ft_sqrt(int nb);

int ft_sqrt(int nb)
{
	int i;
	int result;

	i = 0;

	if (nb == 0)
		return (0);
	if	(nb < 0)
		return (0);
	while (result != nb)
	{
		if (i > nb)
			return (0);
		i++;
		result = i * i;
	}
	return (i);
}