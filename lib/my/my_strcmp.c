/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my version of _strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int	i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] && s2[i]; i++);
    return (s1[i] - s2[i]);
}
