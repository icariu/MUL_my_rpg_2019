/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** freetab
*/

#include <stdlib.h>
#include "my.h"

int free_double_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return (0);
}