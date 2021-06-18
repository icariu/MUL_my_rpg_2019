/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    char *buf = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest[i]; i++)
        buf[i] = dest[i];
    for (; src[j]; j++, i++)
        buf[i] = src[j];
    buf[i] = '\0';
    free(dest);
    return (buf);
}
