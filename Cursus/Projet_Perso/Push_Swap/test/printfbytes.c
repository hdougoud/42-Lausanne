#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char result;
	int octet = 10;
	int test_octet = -10;
	int i = 7;

	printf("%d\n", (351 / 2));

	write (1, "unsigned  ", 11);
	while(i >= 0)
	{
		result = ((octet >> i) & 1) + '0';
		write (1, &result, 1);
		i--;
	}
	write (1, "\n", 1);
	write (1, "int       ", 11);
	i = 7;
	while(i >= 0)
	{
		result = ((test_octet >> i) & 1) + '0';
		write (1, &result, 1);
		i--;
	}
	write (1, "\n", 1);
}