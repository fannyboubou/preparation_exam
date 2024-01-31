#include <unistd.h>

void alpha(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (25 - (s[i] - 'a')) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (25 - (s[i] - 'A')) % 26 + 'A';
        i++;
    }
    write(1, s, i);
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        alpha(av[1]);
    else
        write(1, "\n", 1);
}