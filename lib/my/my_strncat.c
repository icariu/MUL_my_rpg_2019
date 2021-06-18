/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_strncat
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, const char *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; i < nb && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}