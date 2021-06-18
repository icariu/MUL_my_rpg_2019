/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_str_isprintable.c
*/

int	my_str_isprintable(char *str)
{
    int i;

    for (i = 0; str[i] != '\0';) {
        if (str[i] >= 32 && str[i] != 127)
            i++;
        else
            return (0);
    }
    return (1);
}