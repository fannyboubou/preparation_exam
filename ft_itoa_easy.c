#include <stdio.h>
#include <stdlib.h>

int ft_intlen(int n)
{
    int i = 1;
    n /= 10;
    while (n != 0)
    {
        i++;
        n /= 10;
    }
    return i;
}

char *ft_itoa(int n)
{
    char *itoa;
    size_t intlen;
    long int nb;

    nb = n;
    intlen = ft_intlen(n);
    if (n < 0)
    {
        nb = -nb;
        intlen++;
    }
    itoa = malloc(sizeof(char) * (intlen + 1));
    if (itoa == NULL)
        return (NULL);
    itoa[intlen] = '\0';
    while (intlen--)
    {
        itoa[intlen] = nb % 10 + '0';
        nb /= 10;
    }
    if (n < 0)
        itoa[0] = '-';
    return itoa;
}

#include <limits.h>

int main()
{
    printf("%s\n", ft_itoa(12345));
    printf("%s\n", ft_itoa(-1234));
     printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(INT_MIN));
}