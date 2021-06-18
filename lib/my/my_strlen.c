/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** function that counts and returns number of characters found in string
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
