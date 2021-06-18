/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** copies a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    if (i < n) {
        dest[i] = '\0';
    }
    return (dest);
}
