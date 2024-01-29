#include <unistd.h>

void last_word(char *s)
{
    int i = 0;
    int j = 0;

    while (s[i])
        i++;

    j = i;
    while ((s[i - 1] >= 7 && s[i -1 ] <= 13) || s[i - 1] == 32)
    {
        s[i] = '\0';
        i--;
    }

    while ((s[i - 1] < 7 || s[i - 1] > 13) && s[i - 1] != 32)
        i--;   

    write(1, s + i, j - i);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        last_word(av[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
}