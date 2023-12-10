#include <stdlib.h>

char *ft_substr(char *s1, unsigned int start, size_t len)
{
    int i = 0;
    char *substr;
    substr = malloc(sizeof(char) * len);
    while (i < len)
    {
        substr[i] = s1[start];
        i++;
        start++;
    }
    substr[i] = '\0';
    return substr;
}

#include <stdio.h>
int main()
{
    char *big = "lacola";
    char *little = "co";

    printf(ft_substr(big, 2, 2));
}