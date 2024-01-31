/*

Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Écrire un programme nommé hidenp qui prend en paramètres deux chaînes de
caractères et qui affiche 1 suivi de '\n' si la première chaîne est cachée dans
la deuxième chaîne. Sinon il affiche 0 suivi de '\n'.

Soit s1 et s2 des chaînes de caractères. On dit que la chaîne s1 est cachée
dans la chaîne s2 si on peut trouver chaque caractère de s1 dans s2 et ce dans
le même ordre que dans s1. En outre, la chaîne vide est cachée dans n'importe
quelle chaîne.

Si le nombre de paramètres transmis est différent de 2, le programme affiche
'\n'.

Exemples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/

void hidenp(char *s1, char *s2)
{
    while (*s2)
    {
        if (*s1 && *s1 == *s2)
            s1++;
        s2++;
    }

    if (!*s1)
        write(1, "1\0", 2);
    else
        write(1, "0\0", 2);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        hidenp(av[1], av[2]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
}