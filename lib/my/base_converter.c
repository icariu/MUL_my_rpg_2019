/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** base_converter
*/

#include "my.h"

unsigned int convert_to_binary(unsigned int number)
{
    unsigned int result = number % 2;
    unsigned int mult = 10;

    while ((number /= 2) > 0) {
        result += (number % 2) * mult;
        mult *= 10;
    }
    return (result);
}

char *convert_to_hex(unsigned long int number)
{
    char h[200000];
    int i = 0;
    int k;

    while (number != 0) {
        k = number % 16;
        if (k > 9)
            h[i] = (char)(k + 87);
        else
            h[i] = (char)(k + 48);
        number /= 16;
        i++;
    }
    while (i >= 0) {
        my_putchar(h[i]);
        i--;
    }
}

int convert_to_octal(int number)
{
    int o = 0;
    int i = 1;

    while (number != 0) {
        o += (number % 8) * i;
        number /= 8;
        i *= 10;
    }
    return (o);
}

char *convert_to_big_hex(int number)
{
    char h[200000];
    int i = 0;
    int k;

    while (number != 0) {
        k = number % 16;
        if (k > 9)
            h[i] = (char)(k + 55);
        else
            h[i] = (char)(k + 48);
        number /= 16;
        i++;
    }
    while (i >= 0) {
        my_putchar(h[i]);
        i--;
    }
}