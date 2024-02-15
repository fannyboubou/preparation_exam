#include <unistd.h>

void rostring(char *str)
{
    int i = 0;
    int flag = 0;
    int start;
    int end;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    start = i;
    while (str[i] != ' ' && str[i] != '\t')
        i++;
    end = i;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i])
    {
        while ((str[i] == ' '  && str[i + 1] == ' ') || (str[i] == '\t' && str[i + 1] == '\t'))
            i++;
        if (str[i] == ' ' || str[i] =='\t')
            flag = 1;
        write(1, &str[i], 1);
        i++;
    }
    if (flag == 1)
        write(1, " ", 1);
    while (start < end)
    {
        write(1, &str[start], 1);
        start++;;
    }
    write(1, "\n", 1);
}

int main()
{
    char *av = "Que la      lumiere soit et la lumiere fut";
    rostring(av);
}

