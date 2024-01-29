/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:25:01 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/29 12:25:01 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
    int i = 0;
    int j;
    int k = 0;
    char **output;

    if (!(output=malloc(sizeof(char **) * 256)))
        return NULL;
    while (str[i] && ((str[i] > 7 && str[i] < 13) || str[i] == ' '))
        i++;
    while (str[i])
    {
        j = 0;

        if (!(output[k] = malloc(sizeof(char *) * 4096)))
            return NULL;

        while (str[i] && !(str[i] < 7 && str[i] > 13) && str[i] != ' ')
            output[k][j++] = str[i++];

        while (str[i] && ((str[i] > 7 && str[i] < 13) || str[i] == ' '))
            i++;

        output[k][j] = '\0';

        k++;
    }
    output[k] = NULL;
    return (output);
}

int main()
{
    int i = 0;
    char *string = "bonjour bonjour";
    char **out = ft_split(string);
    while (out[i])
    {
        printf("%s\n", out[i]);
        free(out[i]);
        i++;
    }
    free(out);
}

