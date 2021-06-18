/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_str_islower
*/

int my_strlen(char const *str);

int	my_str_islower(char *str)
{
    int i;

    for (i = 0; str[i] != '\0';) {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
