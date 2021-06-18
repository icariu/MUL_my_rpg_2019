/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_str_ isupper.c
*/

int	my_str_isupper(char *str)
{
    int i;

    for (i = 0; str[i] != '\0';) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}