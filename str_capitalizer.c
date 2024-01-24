#include <unistd.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void strcapital(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && 'Z' >= s[i])
            s[i] += 32;
        i++;
    }
    i = 0;
    while (s[i])
        {
            if ((s[i] == ' ' || s[i] == '\t') && s[i + 1] >= 'a' && 'z' >= s[i + 1])
                s[i + 1] -= 32;
            i++;
        }
    if (s[0] >= 'a' && 'z' >= s[0])
                s[0] -= 32;
    write(1, s, ft_strlen(s));
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac > 1)
    {
        while (av[++i])
        {
            strcapital(av[i]);
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
}