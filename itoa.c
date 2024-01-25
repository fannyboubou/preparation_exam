#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

char *ft_itoa(int nbr)
{
    if (nbr == INT_MIN)
        return("-2147483648\0"); 
    int n = nbr;
    int len = 0;
    char *result;

    if (nbr <= 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    if (nbr == 0)
    {
      result[0] = '0';
      return (result);
    }
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = -nbr;
    }
    while (nbr)
    {
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

int main()
{
    char *result = ft_itoa(50);
    printf("%s", result);
}