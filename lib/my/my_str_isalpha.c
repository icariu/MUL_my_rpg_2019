/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_str_isalpha
*/

int	my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
