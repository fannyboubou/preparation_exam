#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *s)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;

	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int square(int nb)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			if (i > 46340)
				return (0);
			i++;
		}
	}
	return (i);
}

int prime(int nb)
{
	int i;

	if (nb <= 0)
		return 0;
	i = 2;
	if (nb == i)
		return (1);
	while (i < nb)
	{
		if (nb % i == 0)
			return (i);
		i++;
	}
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nb;
		nb = ft_atoi(av[1]);
		while (prime(nb) <= square(nb))
		{
			printf("%d", prime(nb));
			printf("*");
			nb = nb / prime(nb);
		}
		printf("%d\n", nb);
	}
	else
		printf("\n");
	return 0;
}