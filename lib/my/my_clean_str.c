/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_clean_str
*/

#include <stdlib.h>
#include "my.h"

int count_precise_size(char *str)
{
    int count = my_strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\t' || str[i] == '\n') {
            count--;
        }
    }
    return (count);
}

char *clean_str(char *str)
{
    int x = 0;
    int size = count_precise_size(str);
    char *new_str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; str[i]; i++) {
        if (str[i] != '\t' && str[i] != '\n') {
            new_str[x] = str[i];
            x++;
        }
    }
    new_str[x] = '\0';
    return (new_str);
}