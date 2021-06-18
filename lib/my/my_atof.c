/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_atof
*/

#include "my.h"

int my_char_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

double my_atof(const char *nptr)
{
    int sign;
    int i = 0;
    double value;
    double power;

    if (nptr[i] == '-')
        sign = -1;
    else
        sign = 1;
    if (nptr[i] == '+' || nptr[i] == '-')
        i++;
    for (value = 0.0; my_char_isdigit(nptr[i]) == 1; i++)
        value = 10.0 * value + (nptr[i] - 48);
    if (nptr[i] == '.')
        i++;
    for (power = 1.0; my_char_isdigit(nptr[i]) == 1; i++) {
        value = value * 10.0 + (nptr[i] - 48);
        power *= 10;
    }
    return (sign * value / power);
}