#include <unistd.h>

//Assignment name  : union
//		Expected files   : union.c
//		Allowed functions: write
//--------------------------------------------------------------------------------
//
//Ècrire un programme nommé union qui prend en paramètre deux chaînes de
//		caractères et qui affiche, sans doublon, les caractères qui apparaissent dans
//l'une ou dans l'autre.
//
//L'affichage se fera dans l'ordre d'apparition dans la ligne de commande.
//
//L'affichage doit etre suivi d'un retour à la ligne.
//
//Si le nombre de paramètres transmis est différent de 2, le programme affiche
//\n.
//
//Exemple:
//
//$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
//		zpadintoqefwjy$
//$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
//		df6vewg4thras$
//$>./union "rien" "cette phrase ne cache rien" | cat -e
//		rienct phas$
//		$>./union | cat -e
//		$
//$>
//$>./union "rien" | cat -e
//		$
//$>

#include <unistd.h>

#include <unistd.h>

int found(char *s, char c)
{
	s = (s + 1);
	while (*s)
	{
		if (*s == c)
			return 1;
		s++;
	}
	return 0;
}

int found_other_sentence(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return 1;
		s++;
	}
	return 0;
}

void ft_union(char *s, char *s2)
{
	char *original = s;
	while (*s)
	{
		if (!found(s, *s))
			write(1, s, 1);
		s++;
	}

	while (*s2)
	{
		if (!found(s2, *s2) && !found_other_sentence(original, *s2))
			write(1, s2, 1);
		s2++;
	}
}

int main()
{
	char *av1 = "zpadinton";
	char *av2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
	ft_union(av1, av2);
	return 0;
}


// 2 string
// display the char that appear in one or the other
//no double
/*
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
}*/