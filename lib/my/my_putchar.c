/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** put ascii char from a number
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
