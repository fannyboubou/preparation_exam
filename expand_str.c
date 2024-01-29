#include <unistd.h>

void expand(char *s)
{
    int j = 0;
    int i = 0;
    int start = 0;

    while (s[i++] == 32)
        start++;

    while (s[i])
        i++;

    while (((s[i - 1] >= 7 && s[i - 1] <= 13) || s[i - 1] == 32))
        i--;

    j = i;

    i = start;
    while (i < j)
    {
        if (!((s[i] >= 7 && s[i] <= 13) || s[i] == 32))
        {
            write(1, &s[i], 1);
        }
        else
        {
            while (((s[i] >= 7 && s[i] <= 13) || s[i] == 32))
            {
                i++;
            }
            write(1, "   ", 3);
            i--;
        }
        i++;
    }
}

// int main(int ac, char **av)
// {
//     if (ac == 2)
//     {
//         expand(av[1]);
//         write(1, "\n", 1);
//     }
//     else
//         write(1, "\n", 1);
// }

int main()
{
    char s[] = " more complex  . ";
    expand(s);
}