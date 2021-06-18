/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int length = 0;
    int tmp = nb;
    char *str = NULL;

    if (nb == 0) {
        str = "0\0";
        return (str);
    }
    for (length = 0; tmp > 0; length++)
        tmp /= 10;
    str = malloc(sizeof(char) * (length + 1));
    str[length] = '\0';
    while (length--) {
        str[length] = nb % 10  + 48;
        nb /= 10;
    }
    return (str);
}