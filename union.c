#include <unistd.h>

// 2 string
// display the char that appear in one or the other
//no double

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}


int str_chr_same_string(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return 1;
        s++;
    }
    return 0;
}


void appear_in_one_or_other(char *s1, char *s2)
{
    char newstring[ft_strlen(s1) + ft_strlen(s2)];
    int i = 0;
    int j = 0;
    int k = 0;
    while (s1[i])
    {
        if (!str_chr_same_string(newstring, s1[i]))
            {
                newstring[k] = s1[i];
                k++;
            }
        i++;
    }
    while (s2[j])
    {
        if (!str_chr_same_string(newstring, s2[j]))
            {
                newstring[k] = s2[j];
                k++;
            }
        j++;
    }
    while (newstring[k])
    {
        newstring[k]='\0';
        k++;
    }
    write(1, newstring, ft_strlen(newstring));
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        appear_in_one_or_other(av[1], av[2]);
    }
    else
       write(1, "\n", 1);
}