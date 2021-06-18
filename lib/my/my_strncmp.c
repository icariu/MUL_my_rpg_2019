/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] && s2[i] && i + 1 < n; i++);
    return (s1[i] - s2[i]);
}