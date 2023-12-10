#include <unistd.h>

int main()
{
    char str[] = "here_is_a_snake_case_world";
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '_')
        {
            if (str[i + 1] != '\0')
                str[i + 1] -= 32;
        }
        i++;
    }
    i=0;
    while(str[i])
    {
        if (str[i] != '_')
            //newstring[i] = str[i];
            write(1, &str[i], 1);
        i++;
    }
}
