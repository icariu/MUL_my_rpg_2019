/*
** EPITECH PROJECT, 2019
** paul.fermey@epitech.eu
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    char buffer = 0;
    int first = 0;
    int last = 0;

    for (last = 0; str[last]; last++);
    last = last - 1;
    while (first < last) {
        buffer = str[first];
        str[first] = str[last];
        str[last] = buffer;
        first++;
        last--;
    }
    return (str);
}