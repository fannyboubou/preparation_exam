#include <unistd.h>

int str_chr(char *s1, char c, int i)
{

    int j = i;
    while (s1[j])
    {
        if (s1[j - 1] == c)
            return 0;
        j--;
    }
    return 1;
}

void appear_both(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                if (str_chr(s1, s1[i], i))
                {
                    write(1, &s1[i], 1);
                    break;
                }
            }
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{

    int i = 0;
    if (ac == 3)
    {
        appear_both(av[1], av[2]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
}