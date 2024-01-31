#include <unistd.h>

void rot13(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' + 13) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + 13) % 26 + 'A';
        i++;
    }
    write(1, s, i);
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        rot13(av[1]);
    else
        write(1, "\n", 1);
}