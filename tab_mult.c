#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *s)
{
	int i;
	int sign;
	int res;

	i = 0;
	res = 0;
	sign = 1;

	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
	       	i++;	
	}
	while (s[i] != '\0')
	{
		res = res * 10 + (s[i] - '0');
	       i++;	
	}
	return (res * sign);
}


void putnbr(int i)
{
	char i_inchar;
	if(i < 10)
	{
		i_inchar = i + '0';
		write(1, &i_inchar, 1);
	}
	else
	{
		putnbr(i / 10);
		putnbr(i % 10);
	}
}

int ft_strlen(char *mult)
{
	int i = 0;
	while (mult[i])
		i++;
	return i;
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i;
		i = 1;
		int nb;
		nb = ft_atoi(av[1]);

		while (i < 10)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(nb);
			 write(1, " = ", 3);
			 putnbr(nb * i);
			 write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}
