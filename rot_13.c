#include <unistd.h>
#include <string.h>

void rot13(char *s)
{
	char *original = s;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			*s = (*s - 'a' + 13) % 26 + 'a';
			write(1, s, 1);
		}
		else if (*s >= 'A' && *s <= 'Z')
			*s = (*s - 'A' + 13) % 26 + 'A';
		s++;
	}
//	write(1, original, strlen(original));
	write(1, "\n", 1);
}

int main()
{
	char av[3] = "abc";
	rot13(av);
}

//int main(int ac, char **av)
//{
//	if (ac == 2)
//		rot13(av[1]);
//	else
//		write(1, "\n", 1);
//}

