#include <unistd.h>

/* SUBJECT

Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void strcapital(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && 'Z' >= s[i])
            s[i] += 32;
        i++;
    }
    i = 0;
    while (s[i])
        {
            if ((s[i] == ' ' || s[i] == '\t') && s[i + 1] >= 'a' && 'z' >= s[i + 1])
                s[i + 1] -= 32;
            i++;
        }
    if (s[0] >= 'a' && 'z' >= s[0])
                s[0] -= 32;
    write(1, s, ft_strlen(s));
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac > 1)
    {
        while (av[++i])
        {
            strcapital(av[i]);
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
}