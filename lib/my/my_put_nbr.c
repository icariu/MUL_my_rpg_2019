/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char letter);

int my_put_nbr(int nb)
{
    int division_rest;

    division_rest = 1;
    if (nb < 0) {
        write(1, "-", 1);
        if (nb == -2147483648) {
            write(1, "2", 1);
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10){
        my_put_nbr(nb / 10);
        division_rest = (nb % 10);
        my_putchar(division_rest + 48);
    }
    return (nb);
}
