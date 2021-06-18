/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int buffer;

    buffer = *a;
    *a = *b;
    *b = buffer;
}
