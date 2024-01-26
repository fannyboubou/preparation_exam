#include <stdio.h>
/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int j;
    unsigned int temp;
    unsigned int i = 0;
    while (i < size - 1)
    {
        j=i+1;
        while(j < size)
        {
            if (tab[i] > tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int i = 0;
    int tab[]={4, 3, 2, 1};
    printf("%s\n", "original array");
    while (i < 4)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    sort_int_tab(tab, 4);
    i = 0;
    printf("%s\n", "sorted_array");
    while (i < 4)
    {
        printf("%d\n", tab[i]);
        i++;
    }
}
