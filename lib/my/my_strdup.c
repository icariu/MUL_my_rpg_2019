/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest = malloc((my_strlen(src) + 1) * sizeof(char));

    my_strcpy(dest, src);
    return (dest);
}
