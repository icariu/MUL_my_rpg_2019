/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_str_isnum.c
*/

int	my_str_isnum(char *str)
{
    int i;

    for (i = 0; str[i] != '\0';) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}