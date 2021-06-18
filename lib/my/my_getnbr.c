/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** converts a string to an int
*/

int my_get_nbr_bis(int negative, int nb)
{
    if (negative % 2 == 0)
        return (nb);
    else
        return (-nb);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int negative = 0;
    int nb_bis = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (nb > 0 && (str[i] < '0' || str[i] > '9'))
            break;
        if (str[i] == '-' )
            negative++;
        if (str[i] <= '9' && str[i] >= '0') {
            nb_bis = nb;
            nb = (nb * 10) + (str[i] - 48);
            if (nb / 10 != nb_bis && nb != -2147483648)
                return (0);
            if (nb == 214748364 && str[i + 1] == '8' && negative % 2 == 0)
                return (0);
        }
    }
    return (my_get_nbr_bis(negative, nb));
}