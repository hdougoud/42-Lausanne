#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int b;
	int n;

	b = 0;
	n = 0;
	while (str[b])
	{
		if (str[b] == to_find[n])
		{
			n++;
		}
		if (n == 6)
			return ("mot trouvé");
		b++;

	}
	return ("le mot n'est pas trouvé");
}

int main(void)
{
    char *a;
    a = ft_strstr("Bonjour comment allez-vous ?", "comment");
    printf("%s", a);
    return 0;
}