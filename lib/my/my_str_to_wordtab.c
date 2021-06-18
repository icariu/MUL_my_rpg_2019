/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** str_to_word_array
*/

#include <stdlib.h>

int symb_checker(char c, char *symb)
{
    for (int i = 0; symb[i]; i++)
        if (symb[i] == c || !c)
            return (42);
    return (0);
}

int word_count(char *str, char *symb)
{
    int nb_word = 0;

    if (!symb_checker(str[0], symb))
        nb_word++;
    for (int i = 0; str[i]; i++)
        if (symb_checker(str[i], symb) && !symb_checker(str[i + 1], symb) != 0)
            nb_word++;
    return (nb_word);
}

int sizeof_word(char *str, int i, char *symb)
{
    int size = 0;

    for (size = 0; str[i]; i++, size++) {
        if (symb_checker(str[i], symb))
            return (size);
    }
    return (size);
}

char **str_to_wordtab(char *str, char *symb)
{
    int nb_word = word_count(str, symb);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int y = 0;
    int step = 0;
    int i = 0;

    for (step = 0; step < nb_word; step++, i++) {
        for (; symb_checker(str[i], symb); i++);
        tab[step] = malloc(sizeof(char) * (sizeof_word(str, i, symb) + 1));
        for (y = 0; str[i] && !symb_checker(str[i], symb); y++, i++)
            tab[step][y] = str[i];
        tab[step][y] = '\0';
    }
    tab[step] = NULL;
    return (tab);
}