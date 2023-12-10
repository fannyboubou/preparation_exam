#include <unistd.h>

int ft_strlen(char *string)
{
	int i = 0;
	while (string[i])
		i++;
	return i;
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		i = 0;
		while (av[1][i] != '\0')
		{
		    	if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] -= 32;
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += 32;
			i++;
		}
		write(1, av[1], ft_strlen(av[1]));
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return 0;
}
