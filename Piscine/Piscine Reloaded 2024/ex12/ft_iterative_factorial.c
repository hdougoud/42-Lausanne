int ft_iterative_factorial(int nb);

int ft_iterative_factorial(int nb)
{
	int f;
	int result;

	f = nb;
	result = nb;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while(f > 1)
		{
			f = f - 1;
			result = result * f;
		}
	return	(result);
}