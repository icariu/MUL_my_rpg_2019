/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_realloc
*/

#include <stdlib.h>

char **my_realloc_tab(char **tab, int add_l)
{
    int c = 0;
    for (c = 0; tab[c]; c++);
    int i;
    int size = (c + add_l + 1);

    char **dup_tab = malloc(sizeof(char *) * size);
    if (dup_tab == NULL)
        return (NULL);
    for (i = 0; tab[i]; i++)
        dup_tab[i] = tab[i];
    dup_tab[i] = "\n\0";
    dup_tab[i+1] = NULL;
    return (dup_tab);
}

