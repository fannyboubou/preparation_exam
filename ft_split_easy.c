#include <stdlib.h>
#include <stdio.h>

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

int count_letters(const char *s, int c)
{
    int count = 0;
    int i = 0;
    while (s[i])
    {
        if (s[i] != c)
            count++;
        i++;
    }
    return count;
}

char **ft_split_easy(char *str, char sep)
{
    char **split;
        int i;
    int len;
    int j;

    i = 0;
    j = 0;
    printf("%d", count_letters(str, sep));
    split = malloc(sizeof(char **) * count_letters(str, sep) + 1);
    if (split == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        if (str[i] != sep)
        {
            len = 0;
            while (str[i + len] && str[i + len] != sep)
                len++;
            split[j] = ft_substr(str, i, len);
            if (split[j] == NULL)
                return NULL;
            j++;
            i += len;
        } else
            i++;
    }
    split[j] = NULL;
    return split;
}

int main()
{
    char *s = "hola_que_tal";
    char sep = '_';
    char **split;
    int i = 0;

    split = ft_split_easy(s, sep);
    while (split[i] != NULL)
    {
        printf("%s", split[i]);
        i++;
    }
}