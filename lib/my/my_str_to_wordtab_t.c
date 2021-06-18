/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_to_wordtab
*/

#include <stdlib.h>

int symb(char *str, int i)
{
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        return (1);
    return (0);
}

int word_count_t(char *str)
{
    int nb_word = 1;
    for (int i = 0; str[i]; i++)
        if (symb(str, i) != 0) {
            for (; symb(str, i) != 0; i++);
            nb_word++;
        }
    return (nb_word);
}

int size_t_word(char *str, int i)
{
    int count = 0;
    for (; str[i]; count++) {
        if (symb(str, i) != 0 || str[i] == '\0')
            return (count);
        i++;
    }
    return (count);
}

char **my_str_to_wordtab_t(char *str)
{
    int nb_word = word_count_t(str);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int i = 0;
    int y;
    int step;

    for (step = 0; step < nb_word; step++) {
        for (; symb(str, i) != 0 && str[i]; i++);
        tab[step] = malloc(sizeof(char) *(size_t_word(str, i)+1));
        for (y = 0; symb(str, i) == 0 && str[i]; y++, i++) {
            tab[step][y] = str[i];
        }
        tab[step][y] = '\0';
    }
    tab[step] = NULL;
    return (tab);
}