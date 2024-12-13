#include <unistd.h>
#include <stdio.h>

static void print_bytes(int nb)
{
	int i;
	char byte;
	
	i = 31;
	while(i >= 0)
	{
		byte = ((nb >> i) & 1) + '0';
		write(1, &byte, 1);
		i--;
	}
}

int main(void)
{
	int bits;
	int nb = 2;
	//print_bytes(nb);
	bits = ((nb) & 1);
	printf("%d\n", bits);
}